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

    cout << "Конструктор переноса: " << endl;
    MyString objLast = move(obj2);
    objLast.Print();

    cout << MyString::count << endl;
}