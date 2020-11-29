#include <iostream>

using namespace std;

void replace_chars(char* str, char searchChar, char replaceChar);

int crep_main()
{
	char str[] = "hello world";

	cout << "Before: " << str << endl;
	replace_chars(str, 'l', 'z');
	cout << "After: " << str << endl;
	return 0;
}


void replace_chars(char* str, char searchChar, char replaceChar)
{
	while (*str != '\0')
	{
		if (*str == searchChar)
			*str = replaceChar;
		str++;
	}
}