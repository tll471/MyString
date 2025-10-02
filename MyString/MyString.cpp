#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString()
{
	length = 80;
	str = new char[length];
	count++;
}

MyString::MyString(int size)
{
	length = size;
	str = new char[length];
	count++;
}

MyString::MyString(const char* s)
{
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length + 1, s);
	count++;
}

MyString::MyString(const MyString& obj)
{
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
	count++;
}

MyString::~MyString()
{
	delete[] str;
}

int MyString::count = 0;
void MyString::PrintCount()
{
	cout << "Count" << count << endl;
}

MyString MyString::operator+(MyString& obj)
{
	int newDlina = length + obj.length;
	char* temp = new char[newDlina + 1];

	strcpy_s(temp, newDlina + 1, str);
	strcat_s(temp, newDlina + 1, obj.str);

	MyString rez(temp);
	return rez;
}

MyString MyString::operator+(const char* obj)
{
	int dlina_str = strlen(obj);
	int newDlina = length + dlina_str;

	char* temp = new char[newDlina + 1];

	strcpy_s(temp, newDlina + 1, str);
	strcat_s(temp, newDlina + 1, obj);

	MyString rez(temp);
	return rez;
}

MyString MyString::operator-(const MyString& obj)
{
	int newDlina = length - obj.length;
	char* temp = new char[newDlina + 1];

	for (int i = 0; i < newDlina; i++) 
	{
		temp[i] = str[i];
	}
	temp[newDlina] = '\0';

	MyString result(temp);
	return result;
}

MyString MyString::operator+(char c)
{
	int newLength = length + 1;
	char* temp = new char[newLength + 1];

	strcpy_s(temp, newLength + 1, str);

	MyString rez(temp);
	return rez;
}

bool MyString::operator> (MyString& obj)
{
	if (length > obj.length)
	{
		return true;
	}
	return false;
}

bool MyString::operator<(MyString& obj)
{
	if (length < obj.length)
	{
		return true;
	}
	return false;
}

bool MyString::operator==(MyString& obj)
{
	if (strcmp(str, obj.str) == 0)
	{
		return true;
	}
	return false;
}

bool MyString::operator>(const char* st)
{
	int rez = strcmp(str, st);

	if (rez > 0)
	{
		return true;
	}
	return false;
}
MyString MyString::operator++(int)
{
	MyString temp = *this;
	char* newStr = new char[length + 2];

	strcpy_s(newStr, length + 2, str);

	newStr[length] = ' ';
	newStr[length + 1] = '\0';

	str = newStr;
	length += 1;

	return temp;
}
MyString MyString::operator++()
{
	int newDnila = length + 2;
	char* newStr = new char[newDnila + 1];

	newStr[0] = ' ';
	newStr[1] = ' ';

	strcpy_s(newStr + 2, length + 1, str);

	str = newStr;
	length = newDnila;

	return *this;
}
MyString MyString::operator--(int)
{
	MyString temp = *this;
	length -= 1;

	str[length] = '\0';

	return temp;
}
MyString MyString::operator--()
{
	for (int i = 0; i < length; i++)
	{
		str[i] = str[i + 1];
	}

	return *this;
}
void MyString::Print()
{
	cout << str << endl;
}

bool MyString::MyStrStr(const char* st)
{
	char* temp = strstr(str, st);
	if (temp != nullptr)
	{
		return true;
	}
	return false;
}

void MyString::Input() 
{
	str = new char[100];
	cin >> str;
	length = strlen(str);
	count++;
}

void MyString::MyStrcpy(MyString& obj) 
{
	delete[] str;
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
}
int MyString::MyChr(char c) 
{
	for (int i = 0; i < length; i++) 
	{
		if (str[i] == c)
		{
			return i;
		}
	}
	return -1;
}
int MyString::MyStrLen() 
{
	int count = 0;

	while (str[count] != '\0')
	{
		count++;
	}
	return count;
}
void MyString::MyDelChr(char c) 
{
	int j = 0;
	for (int i = 0; i < length; i++) 
	{
		if (str[i] != c) 
		{
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
	length = j;
}

int MyString::MyStrCmp(MyString& b) 
{
	int cmp = strcmp(str, b.str);
	if (cmp < 0) 
	{
		return -1;
	}
	if (cmp > 0) 
	{
		return 1;
	}
	return 0;
}