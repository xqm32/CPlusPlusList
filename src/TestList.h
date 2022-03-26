#ifndef __TESTLIST_H_
#define __TESTLIST_H_

#include <iostream>

#include "LinkedList.h"
#include "SequenceList.h"

#define GENERATE_SIZE 1024
#define GENERATE_MAX 1024

void testLinkedList();
void testSequenceList();
void generateList(List<int> &, size_t n = GENERATE_SIZE);

#endif