#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;

void *routine_add()
{
    for (int i = 0; i < 10; i++)
    {
        int x;
        x = mails;
        x += 1;
        sleep(1);
        mails = x;
        printf("Addition iteration: %i. Mails: %i\n", i, mails);
    }
}

void *routine_sub()
{
    for (int i = 0; i < 10; i++)
    {
        int y;
        y = mails;
        y -= 1;
        sleep(2);
        mails = y;
        printf("\tSubstraction iteration: %i. Mails: %i\n", i, mails);
    }
}

int main(int argc, char *argv[])
{
    pthread_t t1, t2;

    if (pthread_create(&t1, NULL, &routine_add, NULL) != 0)
    {
        return 1;
    };

    if (pthread_create(&t2, NULL, &routine_sub, NULL) != 0)
    {
        return 2;
    };

    if (pthread_join(t1, NULL) != 0)
    {
        return 3;
    };

    if (pthread_join(t2, NULL) != 0)
    {
        return 4;
    };

    printf("Final mails: %i\n", mails);

    return 0;
}