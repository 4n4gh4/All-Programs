#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

#define MAX 100

// Message structure
struct message_buffer {
    long message_type;
    char message_text[MAX];
};

int main() {
    key_t key;
    int msgid;
    struct message_buffer message;

    // Generate a unique key
    key = ftok("progfile", 65);

    // Access the message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Receive the message

    /*msgrcv receives a message from the message queue.
msgid: Specifies the message queue to receive the message from.
&message: Pointer to the message structure where the received message will be stored.
sizeof(message): Specifies the size of the message structure.
1: Specifies the type of message to receive (message_type = 1).
0: Specifies no special flags (0), meaning the function will wait until a message of type 1 is available in the queue.*/
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    // Display the message
    printf("Received message: %s\n", message.message_text);

    // Destroy the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
