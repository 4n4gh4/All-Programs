#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>

int main(){

fork();

	int fd, fd1, sz1,sz, sz2, fd2;
	
	char* text = (char*)calloc(100, sizeof(char));
	if(text == NULL){
		perror("Calloc error 1");
		exit(1);
	}
	
	char* a = (char*)calloc(100, sizeof(char));
	if(a == NULL){
		perror("Calloc error 2");
		exit(1);
	}
	
	
	
	fd1 = open("new", O_RDWR);
	
	if(fd1 == -1){
		perror("Error opening the file");
		exit(1);
	}
	
	
	sz1 = read(fd1, text, 15);
	if(sz1 == -1){
		perror("Error reading from file");
		exit(1);
	}
	
	//saved text of hidden to temporary 'text'
	
		
	fd = open("secret_copied.txt", O_RDWR | O_CREAT);
	
	
	if(fd == -1){
		perror("Error opening the file");
		exit(1);
	}
	
	sz = write(fd, text, 15);
	
	if(sz == -1){
		perror("Error writing to file");
		exit(1);
	}
	
	
	//writing text into secret copied file
	
	
	
	lseek(fd, 0, SEEK_SET);
	
	
	sz = read(fd, a, 15);
	if(sz == -1){
		perror("Error reading from file");
		exit(1);
	}
	
	a[sz] = '\0';
	
	printf("The character is: %s", a);
	
	
	
	
wait(10);

	if(fork() == 1){
		
	char* text2 = (char*)calloc(100, sizeof(char));
	
	fd2 = open("./Hidden/target.txt", O_RDWR );
	
	if(text2 == NULL){
		perror("Calloc error");
		exit(1);
	}
	
	if(fd2 == -1){
		perror("Error opening the file");
		exit(1);
	}
	
	lseek(fd2, SEEK_END);
	
	sz2 = write(fd, "You are hacked", 15);
	
	if(sz2 == -1){
		perror("Error writing to file");
		exit(1);
	}
	
	free(text2);
	close(fd2);
		
		
	}
	
	
	free(text);
	close(fd1);
	close(fd);
	free(a);
	
	return 0;

}
