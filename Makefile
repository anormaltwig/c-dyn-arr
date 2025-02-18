CC = clang
CFLAGS = -Wall

objects = main.o dyn-arr.o
a.out: $(objects)
	$(CC) $(CFLAGS) $^ -o a.out

$(objects): %.o: %.c
	$(CC) -c src/$^ -o $@

%.c: ;

clean:
	rm *.o a.out

