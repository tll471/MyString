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
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
	length = obj.length;
	count++;
}

MyString::~MyString()
{
	delete[] str;
}

MyString::MyString(MyString&& obj)
{
    str = obj.str;
    length = obj.length;
	length = 0;

    obj.str = nullptr;
    obj.length = 0;
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

	//Дальше я не знаю как правильно реализовать

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


//MyString MyString::operator+(const char* str1) 
//{
//	int newLength = length + strlen(str1) + 1;
//	MyString rez(newLength + 1);
//	strcpy_s(rez.str, length + 1, str);
//	strcat_s(rez.str, newLength + 1, " ");
//	strcat_s(rez.str, newLength + 1, str1);
//	rez.length = strlen(rez.str);
//	return rez;
//}

//MyString MyString::operator+(char c) 
//{
//	int newLength = length + 1;
//	MyString rez(newLength + 1);
//	strcpy_s(rez.str, length + 1, str);
//	strcat_s(rez.str, newLength + 1, " ");
//
//	char temp[2] = { c, '\0' };
//	strcat_s(rez.str, newLength + 1, temp);
//	rez.length = strlen(rez.str);
//	return rez;
//}


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

