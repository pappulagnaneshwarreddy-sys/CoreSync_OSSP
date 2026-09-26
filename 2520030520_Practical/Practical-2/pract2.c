#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int source, destination;
    char buffer[100];
    int n;

    source = open("sample.txt", O_RDONLY);

    destination = open("copy.txt", O_WRONLY | O_CREAT, 0644);

    n = read(source, buffer, 100);

    write(destination, buffer, n);

    close(source);
    close(destination);

    printf("File copied successfully\n");

    return 0;
}
