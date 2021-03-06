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

static const size_t npos = -1;

size_t outlength(char *a);
class MyString
{
private:
	char* _string;
	size_t capacity;
	size_t strLength;

public:
	// constructor
	MyString();
	MyString(const MyString &inStr);
	MyString(size_t numchar);
	MyString(const char *astring);
	MyString(char chuoi);

	// destructor
	~MyString();

	// Method
	void Append(const MyString & MyStr);
	void Append(const char * CStr);
	void Assign(const MyString & MyStr);
	void Assign(const char *  mySrtr);
	char At(size_t ind) const;
	void Clear();
	void Reserve(size_t newCap);
	size_t Compare(const MyString &astring);
	bool Compare(const MyString & astring) const;
	bool Compare(const char *const inString) const;
	size_t Find(const MyString &astring) const;
	void Insert(const MyString & astring, size_t index);
	void Replace(size_t vitridau, size_t soluong, const MyString & astring);
	size_t rfind(const MyString& astring, size_t pos);
	size_t rfind(const char * s, size_t pos) const;
	char & back();
	void push_back(char c);
	size_t size() const;
	size_t Length(void) const;
	size_t rfind(const MyString & astring, size_t pos) const;
	bool empty() const; 
	void resize(size_t n);
	size_t copy(char* outstring, int leng, int pos);


	size_t find_first_of(const MyString & astring, size_t pos) const;
	size_t find_first_of(const char * s, size_t pos) const;
	size_t find_first_of(char chuoi, size_t pos) const  ;
	size_t find_last_of(const MyString & astring, size_t pos) const;
	size_t find_last_of(const char * s, size_t pos) const;
	size_t find_last_of(char chuoi, size_t pos) const;
	size_t find_first_not_of(const MyString & astring, size_t pos) const;
	size_t find_first_not_of(const char * s, size_t pos) const;
	size_t find_first_not_of(char c, size_t pos) const;
	size_t find_last_not_of(const MyString & astring, size_t pos) const;
	size_t find_last_not_of(const char * s, size_t pos) const;
	size_t find_last_not_of(char chuoi, size_t pos) const;


	// operator = 
	MyString operator = (const MyString & astring);
	MyString operator = (const char *  const astring);
	MyString operator+ (const MyString & astring);
	MyString operator+= (const MyString & astring);
	char & operator [] (size_t index) const;
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
	
	
	MyString SubStr(size_t vitridau, size_t numChar) const;
 	size_t length(char *a) const;

};

//size_t length(char *a) const;

#endif //PCH_H
