# -*- Makefile -*-

# TODO - I'm sure this whole file could be made much simpler if I learn a bit about make...

clean: clean-object-files clean-test-executables

clean-object-files:
	find . -name "*.o" -exec rm {} ';'

clean-test-executables:
	find . -name "*.test" -exec rm {} ';'

# insertion sort

test-insertion-sort: ./projects/sorting/insertion-sort/insertion-sort.test
	./projects/sorting/insertion-sort/insertion-sort.test

./projects/sorting/insertion-sort/insertion-sort.test: ./projects/sorting/insertion-sort/insertion-sort.test.o ./projects/sorting/sort.test.o ./projects/test-utils.o ./projects/sorting/insertion-sort/insertion-sort.o
	clang ./projects/sorting/insertion-sort/insertion-sort.test.o ./projects/sorting/insertion-sort/insertion-sort.o ./projects/sorting/sort.test.o ./projects/test-utils.o -o ./projects/sorting/insertion-sort/insertion-sort.test

./projects/sorting/insertion-sort/insertion-sort.test.o: ./projects/sorting/insertion-sort/insertion-sort.test.c
	cd ./projects/sorting/insertion-sort && clang -c insertion-sort.test.c

./projects/sorting/insertion-sort/insertion-sort.o: ./projects/sorting/insertion-sort/insertion-sort.c
	cd ./projects/sorting/insertion-sort && clang -c insertion-sort.c

# merge sort
test-merge-sort: ./projects/sorting/merge-sort/merge-sort.test
	./projects/sorting/merge-sort/merge-sort.test

./projects/sorting/merge-sort/merge-sort.test: ./projects/sorting/merge-sort/merge.o ./projects/test-utils.o ./projects/sorting/merge-sort/merge-sort.o ./projects/sorting/merge-sort/merge-sort.test.o
	clang ./projects/sorting/merge-sort/merge-sort.test.o ./projects/sorting/merge-sort/merge.o ./projects/test-utils.o ./projects/sorting/merge-sort/merge-sort.o -o ./projects/sorting/merge-sort/merge-sort.test

./projects/sorting/merge-sort/merge-sort.test.o: ./projects/sorting/merge-sort/merge-sort.test.c
	cd ./projects/sorting/merge-sort && clang -c merge-sort.test.c

./projects/sorting/merge-sort/merge-sort.o: ./projects/sorting/merge-sort/merge-sort.c
	cd ./projects/sorting/merge-sort && clang -c merge-sort.c

# merge

test-merge: ./projects/sorting/merge-sort/merge.test
	./projects/sorting/merge-sort/merge.test

./projects/sorting/merge-sort/merge.test: ./projects/sorting/merge-sort/merge.o ./projects/test-utils.o ./projects/sorting/merge-sort/merge.test.o
	clang ./projects/sorting/merge-sort/merge.o ./projects/test-utils.o ./projects/sorting/merge-sort/merge.test.o -o ./projects/sorting/merge-sort/merge.test

./projects/sorting/merge-sort/merge.test.o: ./projects/sorting/merge-sort/merge.test.c
	cd ./projects/sorting/merge-sort && clang -c merge.test.c

./projects/sorting/merge-sort/merge.o: ./projects/sorting/merge-sort/merge.c
	cd ./projects/sorting/merge-sort && clang -c merge.c

# other stuff

./projects/sorting/sort.test.o: ./projects/sorting/sort.test.c
	cd ./projects/sorting && clang -c sort.test.c

./projects/test-utils.o: ./projects/test-utils.c
	cd ./projects && clang -c test-utils.c

