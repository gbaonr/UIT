#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define BUFFER_SIZE 10
int main(int argc, char *argv[])
{
    //Create a shared memory segment for the buffer
    const char *shm_name = "/shared_buffer";
    int shm_fd = shm_open(shm_name, O_CREATE | O_RDWR, S_IRUSR | S_IWUSR);
    ftruncate(shm_fd, BUFFER_SIZE * sizeof(int));
    int *buffer = (int *)mmap(0, BUFFER_SIZE * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // Initialize buffer
    for (int i = 0; i < BUFFER_SIZE; i++){
        buffer[i] = 0;
    }

    pid_t pid = fork();

    if (pid == -1){
        perror("fork");
        exit(1);

    }
    else if (pid == 0)  // Child process (consumer)
    {
        int total = 0;
        while (total <= 100)
        {
            for (int i = 0; i < BUFFER_SIZE; i++)
            {
                if (buffer[i] > 0) 
                {
                    int value = buffer[i];
                    buffer[i] = 0;
                    print("Consumer: %d\n", value);
                    total += value;
                    printf("Sum: %d\n", total);

                    if (total > 100)
                        break;
                }
            }
        }
    }
    else // Parent process (Producer)
    {
        srand(time(NULL));
        while (1) 
        {
            int value = rand() % 11 + 10; // random number in [10,20]
            for (int i = 0; i < BUFFER_SIZE; i++)
                if (buffer[i] == 0)
                {
                    buffer[i] = value;
                    printf("Producer %d\n", value);
                    break;
                }
        }
    }
    munmap(buffer, BUFFER_SIZE * sizeof(int));
    close(shm_fd);
    shm_unlink(shm_name);

    return 0;
}
