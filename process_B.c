#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "/tmp/my_fifo"

int main()
{
    printf("[Process B] Opening FIFO to read...\n");

    // Open FIFO for reading
    int fd = open(FIFO_NAME, O_RDONLY);

    char buffer[100];

    // Read message
    read(fd, buffer, sizeof(buffer));

    printf("[Process B] Received: %s\n", buffer);

    // Close FIFO
    close(fd);

    // Delete FIFO
    unlink(FIFO_NAME);

    return 0;
}
