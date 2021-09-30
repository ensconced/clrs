#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "./linked-lists/node.h"

void assertArraysEqual(int* received, int* expected, int length);
void assertListEqualToArray(struct node* listHead, int* array, int length);
void assertIntEqual(int received, int expected);
