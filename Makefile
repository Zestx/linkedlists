CC = gcc
CFLAGS = -I. -O1
linked2: link2.o
	$(CC) $(CFLAGS) -static $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $^ -c -o $@

%.s: %.c
	$(CC) $(CFLAGS) $^ -S -o $@
