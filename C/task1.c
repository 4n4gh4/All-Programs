#include <stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	
if(fork()<0)
{
	printf("Error!\n");
}

	
else if (fork()==0)
{
wait(30);
printf("Child process \n");
printf("Process ID:%d \n Parent process ID: %d \n", getpid(), getppid());
}	
	
else
{
wait(40);
printf("Parent process \n");
printf("Process ID:%d \n Parent process ID: %d \n", getpid(), getppid());
}	

return 0;

}
