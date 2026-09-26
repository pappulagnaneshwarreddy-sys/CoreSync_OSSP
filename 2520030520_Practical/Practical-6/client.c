#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
char message[100];
char response[100];
int fd = open("myfifo", O_WRONLY);
printf("Enter message: ");
fgets(message, sizeof(message), stdin);
write(fd, message, sizeof(message));
close(fd);
int fd2 = open("responsefifo", O_RDONLY);
read(fd2, response, sizeof(response));
printf("Server: %s\n", response);
close(fd2);
return 0;
}
