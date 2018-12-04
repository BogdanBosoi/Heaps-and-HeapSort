#pragma once

#include <iostream>

class Heap
{
	
	int v[100];
	int n;
	void pushDown(int pos);
	void pushUp(int);
	
public:
	int getLen();
	Heap(int v2[], int n);
	Heap(int v2[]);
	Heap();
	void insert(int);
	void makeHeap();
	void print();
	void delHead();
	int getHead();
	int* Sort();
};

