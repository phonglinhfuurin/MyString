// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <iostream>
#include <conio.h>
#include <string.h>


using namespace std;

int outlength(char *a);
class MyString
{
private:
	char* _string;
	int capacity;
	int strLength;

public:
	// constructor
	MyString();
	MyString(const MyString &inStr);
	MyString(int numchar);
	MyString(const char *astring);
	MyString(char chuoi);

	// destructor
	~MyString();

	// Method
	void Append(const MyString & MyStr);
	void Append(const char * CStr);
	void Assign(const MyString & MyStr);
	void Assign(const char *  mySrtr);
	char At(int ind) const;
	void Clear();
	void Reserve(int newCap);
	int Compare(const MyString &astring);
	bool Compare(const MyString & astring) const;
	bool Compare(const char *const inString) const;
	int Find(const MyString &astring) const;
	void Insert(const MyString & astring, int index);
	void Replace(int vitridau, int soluong, const MyString & astring);
	int rfind(const MyString& astring, int pos);
	int rfind(const char * s, int pos) const;
	char & back();
	void push_back(char c);
	int size() const;
	int Length(void) const;
	int rfind(const MyString & astring, int pos) const;
	bool empty() const; 
	void resize(int n);

	int find_first_of(const MyString & astring, int pos) const;
	int find_first_of(const char * s, int pos) const;
	int find_first_of(char chuoi, int pos) const  ;
	int find_last_of(const MyString & astring, int pos) const;
	int find_last_of(const char * s, size_t pos) const;
	int find_last_of(char chuoi, int pos) const;
	int find_first_not_of(const MyString & astring, int pos) const;
	int find_first_not_of(const char * s, int pos) const;
	int find_first_not_of(char c, int pos) const;
	int find_last_not_of(const MyString & astring, int pos) const;
	int find_last_not_of(const char * s, int pos) const;
	int find_last_not_of(char chuoi, int pos) const;


	// operator = 
	MyString operator = (const MyString & astring);
	MyString operator = (const char *  const astring);
	MyString operator+ (const MyString & astring);
	MyString operator+= (const MyString & astring);
	char & operator [] (int index) const;
	bool operator > (const MyString & astring);
	bool operator < (const MyString & astring);
	bool operator >= (const MyString & aMyString);
	bool operator <= (const MyString & astring);
	bool operator == (const MyString & astring);
	bool operator != (const MyString & astring);
	friend ostream & operator<< (ostream & os, const MyString & aMyString);
	friend istream & operator>> (istream & is, MyString & aMyString);

	// iterator 
	typedef char* iterator;
	typedef const char* const_iterator;
	typedef MyString::iterator iterator;
	iterator begin();
	iterator end();
	iterator rbegin();
	iterator rend();
	
	///
	MyString SubStr(int vitridau, int numChar) const;
 	int length(char *a) const;

};

//int length(char *a) const;

#endif //PCH_H
