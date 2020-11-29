#include <iostream>
float average_salary(int* const salaries, int employees);

using namespace std;

int avg_main()
{
	int employees;
	cout << "Enter number of employees: ";
	cin >> employees;

	int* salaries = new int[employees];
	cout << "Enter the " << employees << "salaries: " << endl;
	for (int i = 0; i < employees; i++)
	{
		cin >> salaries[i];
	}
	cout << "The average salary is: " << average_salary(salaries,employees);
	delete[] salaries;
	return 0;
}

float average_salary(int* const salaries, int employees)
{
	float sum = 0;
	for (int i = 0; i < employees; i++)
	{
		sum += salaries[i];
	}
	return sum/employees;
}