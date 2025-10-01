#pragma once
class MyString
{
	char* str;
	int length;
public:
	MyString();
	MyString(int size);
	MyString(const char* s);
	MyString(const MyString& obj);
	~MyString();
	void Print();

	bool MyStrStr(const char* st);
	void Input();

	void MyStrcpy(MyString& obj);
	int MyChr(char c);
	int MyStrLen();
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);

	static void PrintCount();
	static int count;
	MyString operator+ (MyString& obj);
	MyString operator+ (const char* obj);
	MyString operator- (const MyString& obj);
	MyString operator+ (char c);

	bool operator>(MyString& obj);
	bool operator<(MyString& obj);
	bool operator==(MyString& obj);
	bool operator>(const char* str);
};

