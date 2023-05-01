FILE=main

all: compile run clean

compile:
		gcc $(FILE).c csv_sorter.c ../sorting_algorithms/miscellaneous.c ../sorting_algorithms/bubble_sort/bubblesort.c -o $(FILE)
run:
	./$(FILE)
clean:
		rm $(FILE)