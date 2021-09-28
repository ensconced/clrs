# -*- Makefile -*-

# TODO - I'm sure this whole file could be made much simpler if I learn a bit about make...
# TODO - we should also be including header files as prerequisites...

clean: clean-object-files clean-test-executables

clean-object-files:
	find . -name "*.o" -exec rm {} ';'

clean-test-executables:
	find . -name "*.test" -exec rm {} ';'

# insertion sort

INSERTION_SORT_TEST_OBJECTS = ./projects/sorting/insertion-sort/insertion-sort.test.o ./projects/sorting/sort.test.o ./projects/test-utils.o ./projects/sorting/insertion-sort/insertion-sort.o

test-insertion-sort: ./projects/sorting/insertion-sort/insertion-sort.test
	./projects/sorting/insertion-sort/insertion-sort.test

./projects/sorting/insertion-sort/insertion-sort.test: $(INSERTION_SORT_TEST_OBJECTS)
	clang $(INSERTION_SORT_TEST_OBJECTS) -o ./projects/sorting/insertion-sort/insertion-sort.test

./projects/sorting/insertion-sort/insertion-sort.test.o: ./projects/sorting/insertion-sort/insertion-sort.test.c
	cd ./projects/sorting/insertion-sort && clang -c insertion-sort.test.c

./projects/sorting/insertion-sort/insertion-sort.o: ./projects/sorting/insertion-sort/insertion-sort.c
	cd ./projects/sorting/insertion-sort && clang -c insertion-sort.c

# merge sort

MERGE_SORT_TEST_OBJECTS = ./projects/sorting/merge-sort/merge.o ./projects/test-utils.o ./projects/sorting/merge-sort/merge-sort.o ./projects/sorting/merge-sort/merge-sort.test.o

test-merge-sort: ./projects/sorting/merge-sort/merge-sort.test
	./projects/sorting/merge-sort/merge-sort.test

./projects/sorting/merge-sort/merge-sort.test: $(MERGE_SORT_TEST_OBJECTS)
	clang $(MERGE_SORT_TEST_OBJECTS) -o ./projects/sorting/merge-sort/merge-sort.test

./projects/sorting/merge-sort/merge-sort.test.o: ./projects/sorting/merge-sort/merge-sort.test.c
	cd ./projects/sorting/merge-sort && clang -c merge-sort.test.c

./projects/sorting/merge-sort/merge-sort.o: ./projects/sorting/merge-sort/merge-sort.c
	cd ./projects/sorting/merge-sort && clang -c merge-sort.c

# merge

MERGE_TEST_OBJECTS = ./projects/sorting/merge-sort/merge.o ./projects/test-utils.o ./projects/sorting/merge-sort/merge.test.o

test-merge: ./projects/sorting/merge-sort/merge.test
	./projects/sorting/merge-sort/merge.test

./projects/sorting/merge-sort/merge.test: $(MERGE_TEST_OBJECTS)
	clang $(MERGE_TEST_OBJECTS) -o ./projects/sorting/merge-sort/merge.test

./projects/sorting/merge-sort/merge.test.o: ./projects/sorting/merge-sort/merge.test.c
	cd ./projects/sorting/merge-sort && clang -c merge.test.c

./projects/sorting/merge-sort/merge.o: ./projects/sorting/merge-sort/merge.c
	cd ./projects/sorting/merge-sort && clang -c merge.c

# other stuff

./projects/sorting/sort.test.o: ./projects/sorting/sort.test.c
	cd ./projects/sorting && clang -c sort.test.c

./projects/test-utils.o: ./projects/test-utils.c
	cd ./projects && clang -c test-utils.c

