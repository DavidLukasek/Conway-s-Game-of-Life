CFLAGS = -pedantic -Wall -Werror -std=gnu99 -O2
VALFLAGS = --log-file=valgrind_log.txt --leak-check=full --show-leak-kinds=all

main: main.o conway.o
	clang main.o conway.o -o main
#	valgrind --log-file=valgrind_log.txt --leak-check=full --show-leak-kinds=all ./main
#	cat valgrind_log.txt

main.o: main.c conway.h
	clang $(CFLAGS) -c main.c

conway.o : conway.c conway.h
	clang $(CFLAGS) -c conway.c
run:
	valgrind $(VALFLAGS) ./main
val:
	cat valgrind_log.txt