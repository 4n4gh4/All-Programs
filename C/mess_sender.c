#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

#define MAX 100

// Message structure

/*#define MAX 100: Sets a maximum message size (100 characters in this case).
struct message_buffer: Defines the structure of a message. Each message has:
message_type: A long integer that represents the type of message.
message_text: A character array that holds the actual message content.*/

struct message_buffer {
    long message_type;
    char message_text[MAX];
};

int main() {
    key_t key;
    int msgid;
    struct message_buffer message; //creating an instance of struct

    // Generate a unique key
    key = ftok("progfile", 65);

    // Create a message queue

    /*msgget creates a new message queue (or accesses an existing one) associated with key.
0666: Sets the permissions for the queue (read and write access for the owner, group, and others).
IPC_CREAT: Ensures the queue is created if it doesn’t already exist.
msgid holds the identifier of the message queue.
message.message_type = 1;:
Sets the message_type field to 1. This is arbitrary but should match between sender and receiver if filtering by message type.*/
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.message_type = 1;

    // Get the message from user
    printf("Enter a message to send: ");
    scanf("%s", message.message_text);

    // Send the message
    msgsnd(msgid, &message, sizeof(message), 0);
    
    printf("Message sent: %s\n", message.message_text);
    
    return 0;
}
