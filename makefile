CC=gcc
CFLAGS=-Ofast
LDFLAGS=-lm -lpthread
OBJS=introduction race_condition mutex pthread_create

all: 001 003 004

001: 001_introduction.o
	$(CC) $(CFLAGS) -o introduction 001_introduction.o  $(LDFLAGS)

001_introduction.o: 001_introduction.c
	$(CC) $(CFLAGS) -c 001_introduction.c -o 001_introduction.o

003: 003_race_condition.o
	$(CC) $(CFLAGS) -o race_condition 003_race_condition.o $(LDFLAGS)

003_race_condition.o: 003_race_condition.c
	$(CC) $(CFLAGS) -c 003_race_condition.c -o 003_race_condition.o

004: 004_mutex.o
	$(CC) $(CFLAGS) -o mutex 004_mutex.o $(LDFLAGS)

004_mutex.o: 004_mutex.c
	$(CC) $(CFLAGS) -c 004_mutex.c -o 004_mutex.o

005: 005_pthread_create.o
	$(CC) $(CFLAGS) -o pthread_create 005_pthread_create.o $(LDFLAGS)

005_pthread_create.o: 005_pthread_create.c
	$(CC) $(CFLAGS) -c 005_pthread_create.c -o 005_pthread_create.o

clean:
	rm *.o $(OBJS)