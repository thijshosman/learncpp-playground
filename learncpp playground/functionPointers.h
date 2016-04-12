#pragma once

int foo();
int goo(int i);

void selectionSort(int *array, int size, bool(*comparisonFcn)(int, int));

bool ascending(int x, int y);
bool descending(int x, int y);

void printArray(int *array, int size);
