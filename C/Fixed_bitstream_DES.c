#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 100

// Message structure for message queue
struct message_buffer {
    long message_type;
    char message_text[MAX];
};

// Array to hold the 16 keys for DES
char round_keys[16][49];

// Function to do a circular left shift by 1
void shift_left_once(char* key_chunk) {
    char shifted[29];
    for (int i = 1; i < 28; i++) {
        shifted[i - 1] = key_chunk[i];
    }
    shifted[27] = key_chunk[0];
    shifted[28] = '\0';
    strcpy(key_chunk, shifted);
}

// Function to do a circular left shift by 2
void shift_left_twice(char* key_chunk) {
    shift_left_once(key_chunk);
    shift_left_once(key_chunk);
}

// Function to generate 16 round keys for DES
void generate_keys(char* key) {
    int pc1[56] = {
        57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27,
        19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29,
        21, 13, 5, 28, 20, 12, 4
    };

    int pc2[48] = {
        14, 17, 11, 24, 1, 5,
        3, 28, 15, 6, 21, 10,
        23, 19, 12, 4, 26, 8,
        16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55,
        30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53,
        46, 42, 50, 36, 29, 32
    };

    char perm_key[57];
    for (int i = 0; i < 56; i++) {
        perm_key[i] = key[pc1[i] - 1];
    }
    perm_key[56] = '\0';

    char left[29], right[29];
    strncpy(left, perm_key, 28);
    left[28] = '\0';
    strncpy(right, perm_key + 28, 28);
    right[28] = '\0';

    for (int i = 0; i < 16; i++) {
        if (i == 0 || i == 1 || i == 8 || i == 15) {
            shift_left_once(left);
            shift_left_once(right);
        } else {
            shift_left_twice(left);
            shift_left_twice(right);
        }

        char combined_key[57];
        strncpy(combined_key, left, 28);
        strncpy(combined_key + 28, right, 28);
        combined_key[56] = '\0';

        for (int j = 0; j < 48; j++) {
            round_keys[i][j] = combined_key[pc2[j] - 1];
        }
        round_keys[i][48] = '\0';
    }
}

// Function to perform initial and final permutation
void permute(char* block, const int* table, int size, char* result) {
    for (int i = 0; i < size; i++) {
        result[i] = block[table[i] - 1];
    }
    result[size] = '\0';
}

// Simplified Feistel function
void feistel(char* right, char* key, char* result) {
    for (int i = 0; i < 32; i++) {
        result[i] = (right[i] == key[i]) ? '0' : '1';
    }
    result[32] = '\0';
}

// Function to perform DES encryption or decryption
void des_block(char* block, char round_keys[16][49], int decrypt) {
    int initial_permutation[64] = {
        58, 50, 42, 34, 26, 18, 10, 2,
        60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6,
        64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17, 9, 1,
        59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5,
        63, 55, 47, 39, 31, 23, 15, 7
    };

    int final_permutation[64] = {
        40, 8, 48, 16, 56, 24, 64, 32,
        39, 7, 47, 15, 55, 23, 63, 31,
        38, 6, 46, 14, 54, 22, 62, 30,
        37, 5, 45, 13, 53, 21, 61, 29,
        36, 4, 44, 12, 52, 20, 60, 28,
        35, 3, 43, 11, 51, 19, 59, 27,
        34, 2, 42, 10, 50, 18, 58, 26,
        33, 1, 41, 9, 49, 17, 57, 25
    };

    char permuted_block[65];
    permute(block, initial_permutation, 64, permuted_block);

    char left[33], right[33], temp_right[33];
    strncpy(left, permuted_block, 32);
    left[32] = '\0';
    strncpy(right, permuted_block + 32, 32);
    right[32] = '\0';

    for (int i = 0; i < 16; i++) {
        strcpy(temp_right, right);
        char feistel_output[33];
        feistel(right, decrypt ? round_keys[15 - i] : round_keys[i], feistel_output);

        for (int j = 0; j < 32; j++) {
            right[j] = (left[j] == feistel_output[j]) ? '0' : '1';
        }
        right[32] = '\0';

        strcpy(left, temp_right); // Swap halves
    }

    char combined_block[65];
    strncpy(combined_block, right, 32);
    strncpy(combined_block + 32, left, 32);
    combined_block[64] = '\0';

    permute(combined_block, final_permutation, 64, block);
}

// Message queue sender (Producer)
void message_queue_send(char* message) {
    key_t key;
    int msgid;
    struct message_buffer msg;
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msg.message_type = 1;
    strcpy(msg.message_text, message);
    msgsnd(msgid, &msg, sizeof(msg), 0);
    printf("Encrypted message sent: %s\n", message);
}

// Message queue receiver (Consumer)
void message_queue_receive(char* received_message) {
    key_t key;
    int msgid;
    struct message_buffer msg;
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msgrcv(msgid, &msg, sizeof(msg), 1, 0);
    strcpy(received_message, msg.message_text);
    msgctl(msgid, IPC_RMID, NULL);
}

// Shared memory reader (Receiver)
void shared_memory_receive(char* received_message) {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget((key_t)1234, 1024, 0666);
    
    if (shmid == -1) {
        perror("Shared memory access failed");
        return;
    }

    // Attach the shared memory segment to our process' address space
    char* str = (char*) shmat(shmid, NULL, SHM_RDONLY);
    if (str == (char*)-1) {
        perror("Shared memory attachment failed");
        return;
    }

    // Copy the message from shared memory to the received_message buffer
    strcpy(received_message, str);

    // Detach from the shared memory segment
    if (shmdt(str) == -1) {
        perror("Shared memory detachment failed");
    }

    // Optionally, remove the shared memory segment after reading the message
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("Failed to remove shared memory");
    }
}
int main() {
    char key[] = "1010101010111011000010010001100000100111001101101100110011011101";
    char message[] = "1100110000000000110011001111111111001100101010101111000010101010";
    char encrypted_message[65], decrypted_message[65];
    
    // Generate DES round keys
    generate_keys(key);

    // Encrypt the message
    strcpy(encrypted_message, message);
    des_block(encrypted_message, round_keys, 0);  // Encrypt
    printf("Encrypted message: %s\n", encrypted_message);

    // Send encrypted message through message queue
    message_queue_send(encrypted_message);

    // Receive the message from the queue
    char received_message[MAX];
    message_queue_receive(received_message);
    printf("Received encrypted message: %s\n", received_message);

    // Decrypt the message
    strcpy(decrypted_message, received_message);
    des_block(decrypted_message, round_keys, 1);  // Decrypt
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}