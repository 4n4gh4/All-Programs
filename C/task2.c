#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

extern int errno;

int main()
{
	int fd, sz;
	char* c = (char*)calloc(100, sizeof(char));
	fd=open("memoo.txt", O_RDWR | O_CREAT);

if (c == NULL) {
        perror("calloc failed");
        exit(1);
    }

    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    sz = write(fd, "Anagha B Prasanth\nCB.SC.U4CYS23002", 35);
    if (sz == -1) {
        perror("Error writing to file");
        close(fd);
        exit(1);
    }

    lseek(fd, 0, SEEK_SET);

    sz = read(fd, c, 35);
    if (sz == -1) {
        perror("Error reading from file");
        close(fd);
        exit(1);
    }

    c[sz] = '\0';

    printf("Called read(%d, c, 35). Returned %d bytes.\n", fd, sz);
    printf("Those bytes are as follows: %s\n", c);

    free(c);
    close(fd);

    return 0;
}
