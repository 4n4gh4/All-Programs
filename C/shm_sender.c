#include <stdio.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main() {
    // Generate a unique key
    key_t key = ftok("shmfile", 65);

    //to store user input
	char buffer[100];
    
    // Create a shared memory segment with size 1024 bytes
    /*shmget creates a shared memory segment with:
Key 1234 (used for identification).
Size 1024 bytes.
Permissions 0666 (read and write access for everyone).
IPC_CREAT flag, which creates the shared memory segment if it doesn’t already exist.
shmid stores the shared memory segment identifier.
*/
    int shmid = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);

    /*shmat attaches the shared memory segment to the process’s address space and returns a pointer to it (str).
NULL and 0 specify that the operating system chooses the address and default read/write access.*/

    char *str = (char *) shmat(shmid, NULL, 0);




    // Write a message to the shared memory
    printf("Writing to shared memory...\n");

    /*printf notifies that data is being written to shared memory.
read(0, buffer, 100) reads up to 100 bytes from standard input (0 refers to stdin) into buffer.
strcpy(str, buffer) copies the content of buffer to the shared memory segment pointed to by str.*/

	read(0, buffer, 100);
    strcpy(str, buffer);



    // Detach the shared memory segment
    shmdt(str);

    printf("Message written to shared memory.\n");
    return 0;
}
