#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>

void *roll_dice()
{
    int value = (rand() % 6) + 1;
    int *output = malloc(sizeof(int));
    *output = value;
    return (void *)output;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    pthread_t th;
    int *res;

    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
    {
        return 0;
    };

    if (pthread_join(th, (void **)&res) != 0) // takes pointer to pointer. in other words, an address of pointer
    {
        return 1;
    };

    printf("Dice: %i\n", *res);

    free(res); // FREE MEMORY allocated from the inside of foll_dice

    return 0;
}