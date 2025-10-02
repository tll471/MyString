#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    MyString obj1("Hello world");
    obj1.Print();

    MyString obj2;
    cout << "Enter string for obj2: " << endl;
    obj2.Input();
    obj2.Print();

    MyString obj3(20);
    cout << "Enter string for obj3: " << endl;
    obj3.Input();
    obj3.Print();

    obj3.MyStrcpy(obj1);
    cout << "obj3 after copy (obj1): " << endl;
    obj3.Print();
    
    cout << endl;
    cout << "Поиск 'world' в obj1? " << obj1.MyStrStr("world") << endl;
    cout << "Поиск 'test' в obj1? " << obj1.MyStrStr("test") << endl;
    
    cout << endl;
    cout << "Поиск 'o' в obj1: " << obj1.MyChr('o') << endl;
    cout << "Поиск 'z' в obj1: " << obj1.MyChr('z') << endl;
    
    cout << endl;
    cout << "Длина obj1: " << obj1.MyStrLen() << endl;
   
    cout << endl;
    obj1.MyDelChr('o');
    cout << "В obj1 удаляем 'o' если есть: " << endl;
    obj1.Print();


    cout << endl;

    MyString obj5("Friend");
    cout << "obj1 и obj5: " << obj1.MyStrCmp(obj5) << endl;
    cout << "obj5 и obj1: " << obj5.MyStrCmp(obj1) << endl;
    cout << "obj5 и obj5: " << obj5.MyStrCmp(obj5) << endl;

    cout << MyString::count << endl;

    MyString rez = obj1 + obj2;
    MyString rez2 = obj2 + "!!!";
    MyString rez3 = obj2 + "&";

    MyString obj6("Hello world");
    MyString rez4 = obj6 - " world";

    cout << "YEEEEEEEEE" << endl;
    rez.Print();
    rez2.Print();
    rez3.Print();
    rez4.Print();

    cout << endl;
    rez4.Print();
    obj2.Print();
    cout << endl;

    if (rez4 > obj2)
    {
        cout << "Obj1 > obj2" << endl;
    }
    if (rez4 < obj2)
    {
        cout << "Obj1 < obj2" << endl;
    }
    if (rez4 == obj2)
    {
        cout << "Obj1 == obj2" << endl;
    }

    MyString obj7("Hello world");
    if (obj2 > "Hello")
    {
        cout << "Yes";
    }
    cout << endl;

	MyString obj10("Hello");
	MyString obj11 = obj10++;

    obj10.Print();
    obj11.Print();

    MyString obj12("Hello");
    MyString obj13 = ++obj12;

    obj12.Print();
    obj13.Print();

    MyString obj14("Hello");
    MyString obj15 = obj14--;

    obj14.Print();
    obj15.Print();

    MyString obj16("Hello");
    MyString obj17 = --obj16;

    obj16.Print();
    obj17.Print();
}