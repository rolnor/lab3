#include <iostream>

int string_lenght(char* pointer);

using namespace std;

int slen_main()
{
	char arr[] = "computer";
	char* ptr = arr;
	cout << "Lenght: " << string_lenght(ptr);
	return 0;
}

int string_lenght(char* pointer)
{
	int i = 0;
	for (i; *pointer != '\0';i++)
	{
		pointer++;
	}
	return i;
}