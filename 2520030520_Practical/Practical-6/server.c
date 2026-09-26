#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
int main()
{
char message[100];
char response[100];
mkfifo("myfifo", 0666);
mkfifo("responsefifo", 0666);
printf("Server started...\n");
while(1)
{
int fd = open("myfifo", O_RDONLY);
read(fd, message, sizeof(message));
close(fd);
printf("Client: %s", message);
printf("Processing message...\n");
int fd2 = open("responsefifo", O_WRONLY);
write(fd2, "Server processed: ", 18);
write(fd2, message, sizeof(message));
close(fd2);
printf("Response sent to Client\n");
}
return 0;
}
