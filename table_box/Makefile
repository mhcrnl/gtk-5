CC = gcc
MAINC = table.c
EXEC = table

CFLAGS = `pkg-config --cflags --libs gtk+-2.0`

main:
	$(CC) $(MAINC) -o $(EXEC) $(CFLAGS)
clean:
	rm $(EXEC) -rf