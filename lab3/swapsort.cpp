#include <iostream>

using namespace std;

void swap_sort(int* a, int* b, int* c, bool* order);

int svp_main()
{
	int a, b, c;
	int* ap, * bp, * cp;
	bool * orderp;
	char c_order = 'a';
	bool order;

	while (true)
	{
		cout << "Enter a (0 to quit): ";
		cin >> a;
		if (a == 0)
			break;
		cout << "Enter b: ";
		cin >> b;
		cout << "Enter c: ";
		cin >> c;
		cout << "ascending or descending [a/d]: ";
		cin >> c_order;

		if (c_order == 'a')
			order = 1;
		else order = 0;

		ap = &a;
		bp = &b;
		cp = &c;
		orderp = &order;

		swap_sort(ap, bp, cp, orderp);
		cout << "Result: " << *ap << ',' << *bp << ',' << *cp << endl;
	}

	cout << "Bye bye!" << endl;
	return 0;
}

void swap_sort(int* a, int* b, int* c, bool* order)
{
	int* temp = new int(sizeof(*a));

	if (*order == 1)
	{
		if (!(*a <= *b && *b <= *c))
		{
			if (*a > *b)
			{
				*temp = *b;
				*b = *a;
				*a = *temp;
			}
			if (*b > * c)
			{
				*temp = *c;
				*c = *b;
				*b = *temp;
			}
			swap_sort(a, b, c, order);
		}

	}
	else
	{
		if (!(*a >= *b && *b >= *c))
		{
			if (*a < *b)
			{
				*temp = *b;
				*b = *a;
				*a = *temp;
			}
			if (*b < *c)
			{
				*temp = *c;
				*c = *b;
				*b = *temp;
			}
			swap_sort(a, b, c, order);
		}
	}
	delete temp;
}