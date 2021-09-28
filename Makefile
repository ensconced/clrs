# -*- Makefile -*-

insertion-sort: ./projects/sorting/insertion-sort/insertion-sort.c ./projects/sorting/sort.test.c ./projects/test-utils.c
	clang projects/sorting/insertion-sort/insertion-sort.c ./projects/sorting/sort.test.c ./projects/test-utils.c -o ./projects/sorting/insertion-sort/insertion-sort
