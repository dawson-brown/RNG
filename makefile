CC=gcc
CFLAGS=-I.
DEPS = parser.h
OBJ = urandom.o urandom_parser.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o urandom $^ $(CFLAGS)
