# -*- Makefile -*-

# TODO - we should also be including header files as prerequisites...

SHELL = /bin/sh
CC = clang

clean: clean-object-files clean-test-executables

clean-object-files:
	find . -name "*.o" -exec rm {} ';'

clean-test-executables:
	find . -name "*.test" -exec rm {} ';'

# insertion sort

test-insertion-sort: ./projects/sorting/insertion-sort/insertion-sort.test
	./projects/sorting/insertion-sort/insertion-sort.test

INSERTION_SORT_TEST_OBJECTS = \
	./projects/sorting/insertion-sort/insertion-sort.test.o \
	./projects/sorting/sort.test.o \
	./projects/test-utils.o \
	./projects/sorting/insertion-sort/insertion-sort.o

./projects/sorting/insertion-sort/insertion-sort.test: $(INSERTION_SORT_TEST_OBJECTS)

# merge sort

test-merge-sort: ./projects/sorting/merge-sort/merge-sort.test
	./projects/sorting/merge-sort/merge-sort.test

MERGE_SORT_TEST_OBJECTS = \
	./projects/sorting/merge-sort/merge.o \
	./projects/test-utils.o \
	./projects/sorting/merge-sort/merge-sort.o \
	./projects/sorting/merge-sort/merge-sort.test.o

./projects/sorting/merge-sort/merge-sort.test: $(MERGE_SORT_TEST_OBJECTS)

# merge

test-merge: ./projects/sorting/merge-sort/merge.test
	./projects/sorting/merge-sort/merge.test

MERGE_TEST_OBJECTS = \
	./projects/sorting/merge-sort/merge.o \
  ./projects/test-utils.o \
	./projects/sorting/merge-sort/merge.test.o

./projects/sorting/merge-sort/merge.test: $(MERGE_TEST_OBJECTS)