#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Before exec()\n");
    printf("PID: %d\n", getpid());

    execl("/bin/ls", "ls", "-l", NULL);

    printf("exec failed\n");

    return 0;
}
