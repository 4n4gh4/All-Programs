#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLOCK_SIZE 8
#define KEY_SIZE 64
#define MAX_BINARY_LENGTH 65

// Round keys for DES
char round_keys[16][49];

// Initial and final permutation tables
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
    40, 8, 48, 16, 56, 24, 32, 0,
    41, 9, 49, 17, 57, 25, 33, 1,
    42, 10, 50, 18, 58, 26, 34, 2,
    43, 11, 51, 19, 59, 27, 35, 3,
    44, 12, 52, 20, 60, 28, 36, 4,
    45, 13, 53, 21, 61, 29, 37, 5,
    46, 14, 54, 22, 62, 30, 38, 6,
    47, 15, 55, 23, 63, 31, 39, 7
};

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
        result[i] = right[i] ^ key[i]; // Simplified operation for demonstration
    }
}

// DES encryption function
void des_encrypt(char* block, char* key) {
    generate_keys(key);
    char permuted_block[65];
    permute(block, initial_permutation, 64, permuted_block);

    char left[33], right[33];
    strncpy(left, permuted_block, 32);
    left[32] = '\0';
    strncpy(right, permuted_block + 32, 32);
    right[32] = '\0';

    for (int i = 0; i < 16; i++) {
        char feistel_result[33];
        feistel(right, round_keys[i], feistel_result);
        
        // Swap left and right
        for (int j = 0; j < 32; j++) {
            right[j] = left[j] ^ feistel_result[j];
            left[j] = right[j];
        }
    }

    char final_block[65];
    strncpy(final_block, right, 32);
    strncpy(final_block + 32, left, 32);
    final_block[64] = '\0';
    
    permute(final_block, final_permutation, 64, block);
}

// DES decryption function
void des_decrypt(char* block, char* key) {
    generate_keys(key);
    char permuted_block[65];
    permute(block, initial_permutation, 64, permuted_block);

    char left[33], right[33];
    strncpy(left, permuted_block, 32);
    left[32] = '\0';
    strncpy(right, permuted_block + 32, 32);
    right[32] = '\0';

    for (int i = 15; i >= 0; i--) { // Reverse order for decryption
        char feistel_result[33];
        feistel(right, round_keys[i], feistel_result);
        
        // Swap left and right
        for (int j = 0; j < 32; j++) {
            right[j] = left[j] ^ feistel_result[j];
            left[j] = right[j];
        }
    }

    char final_block[65];
    strncpy(final_block, right, 32);
    strncpy(final_block + 32, left, 32);
    final_block[64] = '\0';
    
    permute(final_block, final_permutation, 64, block);
}

int main() {
    char key[KEY_SIZE + 1] = "1010101010111011000010010001100000100111001101101100110011011101"; // Fixed binary key
    char block[BLOCK_SIZE + 1]; // Message block (8 bytes)

    // Get user input for the message
    printf("Enter a message (max 8 characters): ");
    fgets(block, sizeof(block), stdin);
    
    // Remove newline character if present
    block[strcspn(block, "\n")] = 0;

    // Ensure the block is exactly 8 bytes (pad if necessary)
    for (int i = strlen(block); i < BLOCK_SIZE; i++) {
        block[i] = '\0'; // Padding with null characters
    }
    block[BLOCK_SIZE] = '\0';

    // Encrypt the message
    printf("Original Message: %s\n", block);
    des_encrypt(block, key);
    printf("Encrypted Message: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X ", (unsigned char)block[i]); // Print in hexadecimal
    }
    printf("\n");

    // Decrypt the message
    des_decrypt(block, key);
    printf("Decrypted Message: %s\n", block);

    return 0;
}
