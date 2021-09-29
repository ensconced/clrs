# -*- Makefile -*-

# TODO - we should also be including header files as prerequisites...

SHELL = /bin/sh
CC = clang

SOURCES = $(shell find . -name "*.c")

all: test-insertion-sort test-merge test-merge-sort

clean:
	find . \( -name "*.test" -o -name "*.d" -o -name "*.o" \) -exec rm {} ';'

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


# Automatic prerequisite generation

# Here we use the MM dependency-generation option of our C compiler to create an
# extra ".d" Makefile for each ".c" source file. Unfortunately the generated
# Makefile isn't quite complete - we also need to add the ".d" file itself as a
# target. Initially the only target is the ".o" object file. So we find the
# string for the ".o" file in the generated ".d" Makefile. And then get the
# name of the ".d" file, and finally insert the ".d" dependency as a target,
# following the existing ".o" one.

# For more info on this general approach, see:
# https://www.gnu.org/software/make/manual/html_node/Automatic-Prerequisites.html
%.d: %.c
	$(CC) -MM $(CPPFLAGS) $< > $@ && \
	object_file=$$(cat $@ | head -n 1 | grep -oP '^.*o(?=:)') && \
	dep_file=$$(echo $$object_file | sed 's,\.o$$,.d,g') && \
	sed -i s,$$object_file:,$$object_file\ $$dep_file:, $@

# Include all the auto-generated ".d" Makefiles
include $(SOURCES:.c=.d)

