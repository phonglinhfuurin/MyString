
#include "MyString.h"



int main()
{
	MyString str1 = "Huynh Thanh Khai Tran";
	MyString str2 = "\n1712828";
	MyString str3 = "do an Mystring";
	MyString str4 = "blah bleh bluh";
	for (MyString::iterator i = str1.begin(); i != str1.end(); i++)
		cout << *i;
	char *temp1 = new char[10];
//	temp1 = "do an 1";
	str2 += str3;
	cout << str2 << endl;

	system("pause");
	return 0; 
}

