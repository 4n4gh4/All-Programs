#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    // Generate the same unique key as the writer
    key_t key = ftok("shmfile", 65);

    // Access the shared memory segment created by the writer
    int shmid = shmget((key_t)1234, 1024, 0666);

    // Attach the shared memory segment to the process's address space

    /*shmat attaches the shared memory segment identified by shmid to the process’s address space.
NULL lets the system choose the attachment address.
SHM_RDONLY specifies read-only access.
str now points to the start of the shared memory segment, allowing the process to read from it.*/

    char *str = (char *) shmat(shmid, NULL, SHM_RDONLY);

    // Read the message from shared memory
    printf("Reading from shared memory...\n");
    printf("Data: %s\n", str);

    // Detach from the shared memory segment
    shmdt(str);

    // Destroy the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    printf("Shared memory destroyed.\n");
    return 0;
}
