FILE=main

all: compile run clean

compile:
		gcc $(FILE).c merge_sort.c ../miscellaneous.c -o $(FILE)
run:
	./$(FILE)
clean:
		rm $(FILE)