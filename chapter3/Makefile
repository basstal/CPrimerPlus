include ../Make.defines

EXERCISE = escape_sequence ex1 ex2 ex3 ex4 ex5 ex6 ex7

all:$(EXERCISE)

escape_sequence:escape_sequence.o
	$(CC) $(CFLAGES) -o $@ escape_sequence.o
ex1:ex1.o
	$(CC) $(CFLAGES) -o $@ ex1.o
ex2:ex2.o
	$(CC) $(CFLAGES) -o $@ ex2.o
ex3:ex3.o
	$(CC) $(CFLAGES) -o $@ ex3.o
ex4:ex4.o
	$(CC) $(CFLAGES) -o $@ ex4.o
ex5:ex5.o
	$(CC) $(CFLAGES) -o $@ ex5.o
ex6:ex6.o
	$(CC) $(CFLAGES) -o $@ ex6.o
ex7:ex7.o
	$(CC) $(CFLAGES) -o $@ ex7.o
	
clean:
	rm -f $(EXERCISE) $(CLEANFILES)
