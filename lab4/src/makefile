CC=gcc
CFLAGS=-I.

parallel_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o parallel_min_max utils.o find_min_max.o parallel_min_max.c $(CFLAGS)

utils.o : utils.h
	$(CC) -o utils.o -c utils.c $(CFLAGS)

find_min_max.o : utils.h find_min_max.h
	$(CC) -o find_min_max.o -c find_min_max.c $(CFLAGS)

result_task_3: utils.o sum.h utils.h sum.o
	$(CC) -o result_task_3 sum.o utils.o parallel_sum.c -lpthread

sum.o: sum.h
	$(CC) -o sum.o -c sum.c

proc_mem:
	$(CC) -o proc_mem process_memory.c

clean :
	rm proc_mem parallel_min_max result_task_3