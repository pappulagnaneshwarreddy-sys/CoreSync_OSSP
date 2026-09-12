#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
int pid;
pid=fork();
if(pid==0)
{
printf("Child process %d\n",getpid());
exit(0);
}
else {
printf("Parent process %d \n",getpid());
//sleep(30);
wait(NULL);
printf("Parent process completed");
}
}
