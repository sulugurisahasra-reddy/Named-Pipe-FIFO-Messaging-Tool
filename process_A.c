#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "/tmp/my_fifo"

int main()
{
    // Create FIFO
    mkfifo(FIFO_NAME, 0666);

    printf("[Process A] Opening FIFO to write...\n");

    // Open FIFO for writing
    int fd = open(FIFO_NAME, O_WRONLY);

    char message[] = "Hello from Process A!";

    // Write message
    write(fd, message, strlen(message) + 1);

    printf("[Process A] Sent: %s\n", message);

    // Close FIFO
    close(fd);

    return 0;
}
