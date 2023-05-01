FILE=main

all: compile run clean

compile:
		gcc $(FILE).c bubblesort.c ../miscellaneous.c -o $(FILE)
run:
	./$(FILE)
clean:
		rm $(FILE)