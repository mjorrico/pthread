#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *routine()
{
    printf("Test from threads\n");
    sleep(1);
    printf("Ending thread\n");
}

int main(int argc, char *argv[])
{
    int N_threads = atoi(argv[1]);
    pthread_t *th = (pthread_t *)malloc(N_threads * sizeof(pthread_t)); // list of thread IDs

    for (int i = 0; i < N_threads; i++)
    {
        if (pthread_create(th + i, NULL, &routine, NULL) != 0)
        {
            return i;
        };

        // DO NOT DO pthread_join HERE!
    }

    for (int i = 0; i < N_threads; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            return N_threads + i;
        };
    }

    return 0;
}
