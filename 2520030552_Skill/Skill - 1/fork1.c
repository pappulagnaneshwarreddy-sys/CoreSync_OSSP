#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    printf("Process started\n");
    printf("Parent Process ID: %d\n", getpid());

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0)
    {
        printf("\nChild Process\n");
        printf("Child Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
    }
    else
    {
        printf("\nParent Process\n");
        printf("Parent Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", pid);

        printf("Child process completed\n");
    }

    return 0;
}
