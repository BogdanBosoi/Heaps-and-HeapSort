#include "Heap.hpp"

int main()
{
	int v[] = { 34, 11, 15, 18, 20 };
	Heap h(v, 5);
	h.print();

	int *vec = h.Sort();
	for (int i = 1; i <= h.getLen(); i++)
		std::cout << vec[i] << " ";
	system("PAUSE");
	return 0;


}