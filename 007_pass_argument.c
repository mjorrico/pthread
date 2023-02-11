#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *func(void *arg)
{
    int index = *(int *)arg;
    printf("%i\n", primes[index]);
    free(arg);
}

int main(int argc, char *argv[])
{
    const int N_threads = 10;
    pthread_t th[N_threads];

    for (int i = 0; i < N_threads; i++)
    {
        int *idx = malloc(sizeof(int));
        *idx = i;
        if (pthread_create(th + i, NULL, &func, idx) != 0)
        {
            return i;
        }
    }

    for (int i = 0; i < N_threads; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            return N_threads + i;
        }
    }

    return 0;
}