#include "Heap.hpp"

void swap(int &arg1, int &arg2) {
	int aux = arg1;
	arg1 = arg2;
	arg2 = aux;

}

int Heap::getLen()
{
	return n;
}

Heap::Heap(int v2[], int n)
{
	this -> n = n;
	for (int i = 0; i < n; i++)
		v[i + 1] = v2[i];
	makeHeap();
}		

Heap::Heap() {
	n = 0;
}

Heap::Heap(int v2[]) {
	n = sizeof(v2) / sizeof(int);
	std::cout << n;
	for (int i = 0; i < n; i++)
		v[i + 1] = v2[i];
	makeHeap();


}

void Heap::pushDown(int pos) {
	if (pos <= n / 2)
	{
		if (v[pos] < v[2 * pos])
			swap(v[pos], v[2 * pos]);

		if (2 * pos + 1 <= n && v[2 * pos] < v[2 * pos + 1]) {
			swap(v[2 * pos], v[2 * pos + 1]);
			pushDown(2 * pos + 1);
		}
		else
			pushDown(2 * pos);
	}
}

void Heap::insert(int val) {
	n++;
	v[n] = val;
	pushUp(n);
}

void Heap::pushUp(int pos) {
	if (pos / 2 >= 1 && v[pos] > v[pos / 2]) {
		swap(v[pos / 2], v[pos]);
		pushUp(pos / 2);
	}
}

void Heap::print() {
	for (int i = 1; i <= n; i++)
		std::cout << v[i] << " ";
	std::cout << "\n";
}

void Heap::delHead() {
	if (n > 0) {
		swap(v[1], v[n]);
		n--;
		pushDown(1);
	}
}

int Heap::getHead() {
	return v[1];
}

void Heap::makeHeap() {
	for (int i = n / 2; i >= 1; i--)
		pushDown(i);
}

int* Heap::Sort() {

	int oldHeap[100];
	int oldLen = n;
	int i;
	int *newVec = new int[n + 1];

	for (i = 1; i <= n; i++)
		oldHeap[i] = v[i];
	
	newVec[1] = getHead();
	i = 2;
	while (n != 0) {
		delHead();
		newVec[i] = getHead();
		i++;
	}
	n = oldLen;
	for (i = 1; i <= n; i++)
		v[i] = oldHeap[i];
	return newVec;
}