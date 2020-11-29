#include <iostream>

using namespace std;

void swap_sort_ptr_addr(int** a, int** b, int** c, bool ascdes);

int dblp_main()
{
	int a = 7, b = 6, c = 1;
	int* p1 = &a, * p2 = &b, * p3 = &c;
	swap_sort_ptr_addr(&p1, &p2, &p3, true);
	cout << *p1 << " " << *p2 << " " << *p3;    // Points "1 6 7"
	return 0;
}

void swap_sort_ptr_addr(int** a, int** b, int** c, bool order)
{
	int* temp = new int(sizeof(*a));

	if (order == 1)
	{
		if (!(**a <= **b && **b <= **c))
		{
			if (*a > * b)
			{
				*temp = **b;
				**b = **a;
				**a = *temp;
			}
			if (**b > **c)
			{
				*temp = **c;
				**c = **b;
				**b = *temp;
			}
			swap_sort_ptr_addr(a, b, c, order);
		}

	}
	else
	{
		if (!(**a >= **b && **b >= **c))
		{
			if (**a < **b)
			{
				*temp = **b;
				**b = **a;
				**a = *temp;
			}
			if (**b < **c)
			{
				*temp = **c;
				**c = **b;
				**b = *temp;
			}
			swap_sort_ptr_addr(a, b, c, order);
		}
	}
	delete temp;
}