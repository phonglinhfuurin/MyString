// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include "MyString.h"


int outlength(char *a) 
{
	int dodai = 0;
	for (int i = 0; a[i] != '\0'; i++)
	{
		dodai++;
	}
	return dodai;
}
int MyString::length(char *a) const
{
	int dodai = 0;
	for (int i = 0; a[i] != '\0'; i++)
	{
		dodai++;
	}
	return dodai;
}
void StrCopy(char *con, char *nguon)
{
	int L = outlength(nguon);
	for (int i = 0; i <= L; i++)
	{
		con[i] = nguon[i];
	}
	con[L+1] = '\0';
}
MyString MyString::SubStr(int vitridau, int numChar) const
{
	if (vitridau + numChar > strLength)
	{
		cout << "loi";
		return 0;
	}

	char *StrAtPos = new char[numChar + 1];
	for (int i = 0; i < numChar; i++) {
		StrAtPos[i] = _string[vitridau + i];
	}
	StrAtPos[numChar] = '\0';
	MyString returnString(StrAtPos);
	delete[] StrAtPos;
	return returnString;
}

//constructor: 
MyString::MyString()
{
	capacity = 16;
	strLength = 0;
	_string = new char[capacity + 1];
	_string[strLength] = '\0';
}
MyString::MyString(const MyString &inStr)
{
	capacity = inStr.capacity;
	strLength = inStr.strLength;
	_string = new char[capacity + 1]; 
	char *temp = new char[inStr.strLength + 1]; 
	temp = inStr._string; 
	temp[inStr.strLength] = '\0';
	strcpy(_string,  temp);
	_string[strLength] = '\0';
}
MyString::MyString(const char *astring)
{
	int aLenght = length((char *)astring);
	if (aLenght > 16) { capacity = aLenght; }
	else capacity = 16;
	strLength = aLenght;
	_string = new char[capacity + 1];
	strcpy(_string, astring);
	_string[strLength] = '\0';
}
MyString::MyString(int numChar)
{
	capacity = numChar;
	strLength = 0;
	_string = new char[capacity + 1];
	_string[strLength] = '\0';
}
MyString::MyString(char chuoi)
{
	strLength = 2;
	capacity = 3;
	_string[0] = chuoi;
	_string[1] = '\0';
}
//destructor
MyString::~MyString()
{
	delete[] _string;
}

//Modifier 
void MyString::Append(const char *astring)
{
	int  tongLeng = strlen(astring) + strLength;
	if (strLength < tongLeng) {
		capacity = tongLeng;
		char * strTemp = new char[capacity + 1];
		strcpy(strTemp, _string);
		delete[] _string;
		_string = strTemp;
	}
	strcat(_string, astring);
	strLength = tongLeng;
	_string[strLength] = '\0';
}
void MyString::Append(const MyString  &astring)
{
	MyString temp = MyString(astring);
	int tongLength = strLength + temp.strLength;
	char *temp1 = new char[astring.strLength + 1]; 
	if (capacity < tongLength)
	{
		capacity = tongLength;
		char *buff = new char[capacity + 1];
		strcpy(buff, _string);
		delete[] _string;
		_string = buff;
	}
	temp1 = astring._string; 
	temp1[astring.strLength] = '\0';
	strcat(_string, temp1);
	strLength = tongLength;
	_string[strLength] = '\0';

}
void MyString::Assign(const MyString & astring)
{

	MyString temp = MyString(astring);
	delete[] _string;
	capacity = temp.capacity;
	strLength = temp.strLength;
	_string = new char[capacity + 1];
	strcpy(_string, temp._string);
	_string[strLength] = '\0';
}
void MyString::Assign(const char *astring)
{
	int numChar = strlen(astring);

	if (numChar > capacity) {
		capacity = numChar;
		delete[] _string;
		_string = new char[capacity + 1];
	}
	strcpy(_string, astring);
	strLength = numChar;
}
char MyString::At(int ind) const
{
	if ((ind < 0) || (ind >= strLength))
	{
	cout << " so nhap vao sai" << endl;
	return 0;
	}
	char letterAt = _string[ind];
	return letterAt;
}
void MyString::Clear()
{
	strLength = 0;
	_string[strLength] = '\0';
}
void MyString::Reserve(int newCap)
{
	if (newCap < 0)
	{
		cout << "\n loi vi tri be hon 0";
		exit(1);
	}
	strLength = 0;
	capacity = newCap;
	_string[strLength] = '\0';
}
int MyString::Compare(const MyString &astring)
{
	return strcmp(_string, astring._string);
}
bool MyString::Compare(const MyString & astring) const
{
	if (astring.strLength != strLength)
		return false;
	for (int i = 0; i < astring.strLength; i++)
	{
		if (_string[i] != astring._string[i])
			return false;
	}
	return true;

}
bool MyString::Compare(const char *const inString) const
{
	MyString buff(inString);
	if (buff.strLength != strLength)
		return false;
	for (int i = 0; i < buff.strLength; i++)
	{
		if (_string[i] != buff._string[i])
			return false;
	}
	return true;
}
int MyString::Find(const MyString &astring) const
{
	int index = 0;
	if (astring.strLength == 0 || astring.strLength > strLength)
		return -1;
	bool timthay = true;
	for (int i = 0; i < strLength; i++)
	{
		timthay = true;
		for (int j = 0; j < astring.strLength; j++) {
			if (_string[i + j] != astring._string[j]) {
				timthay = false;
				break;
			}
		}
		if (timthay)
			return i;
	}
	if (!timthay)
		return -1;
}
void MyString::Insert(const MyString & astring, int index)
{
	if ((index > strLength) || (index < 0))
	{
		cout << " Loi ! ";
		exit(1);
	}

	MyString buffstring = astring;
	MyString returnString = MyString();
	MyString subString = MyString(SubStr(index, strLength - index));

	returnString.Assign(SubStr(0, index));
	returnString.Append(buffstring);
	returnString.Append(subString);
	Assign(returnString);

}
int MyString::Length(void) const
{
	return strLength;
}
void MyString::Replace(int vitridau, int soluong, const MyString & astring)
{
	int chieudai = capacity;
	if ((vitridau >= strLength) || (vitridau + soluong > strLength) || (astring.strLength < soluong))
	{
		cout << "\nLoi ";
		exit(1);
	}
	if (astring.strLength > capacity) {
		chieudai = astring.strLength + capacity;
		capacity = chieudai;
		MyString temp(*this);
		delete[] _string;
		_string = new char[capacity + 1];
		Assign(temp._string);
	}

	for (int i = 0; i < soluong; i++)
		_string[i + vitridau] = astring[i];

}
void MyString::push_back(char c)
{
	*this += c;
} 

/*void MyString::push_back(char *chuoi)
{
	*this += chuoi; 
} */
bool MyString::empty() const
{
	if (*this->_string == '\0' && this->strLength == 0)
	{
		return true;
	}
	return false;
}
char & MyString::back()
{
	if (strLength != 0)
	{
		return _string[strLength - 1];
	}
}
int MyString::size() const
{
	return this->strLength;
}


//Operator 
MyString MyString::operator = (const MyString & astring)
{
	Assign(astring._string);
	return *this;
}
MyString MyString::operator = (const char *  const astring)
{
	Assign(astring);
	return *this;
}
MyString MyString::operator + (const MyString & astring)
{
	MyString buff;
	buff.Append(this->_string);
	buff.Append(astring);
	return buff;
}
MyString MyString::operator += (const MyString & astring)
{
	this->Append(astring);
	return *this;
}
//[]
char & MyString::operator [] (int index) const
{
	return _string[index];
}
bool MyString::operator > (const MyString & astring) {
	int result = Compare(astring);
	if (result == 1 && _string != astring._string)
		return true;
	else
		return false;
}
bool MyString::operator < (const MyString & astring) {
	int result = Compare(astring);
	if (result == -1 && _string != astring._string)
		return true;
	else
		return false;
}
bool MyString::operator >= (const MyString & astring) {
	int result = Compare(astring);
	if (result == 1)
		return true;
	else
		return false;
}
bool MyString::operator <= (const MyString & astring) {
	int result = Compare(astring);
	if (result == -1)
		return true;
	else
		return false;
}
bool MyString::operator == (const MyString & astring)
{
	if (_string == astring._string)
		return true;
	else
		return false;
}
bool MyString::operator != (const MyString & astring)
{
	if (_string != astring._string) {
		return true;
	}
	else
		return false;
}
ostream & operator << (ostream &os, const MyString &astring)
{
	os << astring._string;
	return os;
}
istream & operator >> (istream &is, MyString &astring)
{
	char buff[80];
	astring.Clear();
	if (is.peek() != '\n') {
		do {
			is.get(buff, 80);
			astring.Append(buff);
		} while ((int)strlen(buff) == 79);
	}
	if (is.peek() == '\n')
		is.get();
	return is;
}


int MyString::rfind(const MyString & astring, int pos) const
{
	int temp = Find(astring);
	int timthay = -1;
	while (temp < pos)
	{
		timthay = temp;
		temp = Find(astring[temp + 1]);
	}
	if (timthay != -1)
		return timthay;
	return -1;
}
int MyString::rfind(const char * s, int pos) const
{
	MyString str(*this);
	return rfind(str, pos);
}
int MyString::find_first_of(const MyString & astring, int pos) const
{
	for (int i = pos; i < strLength; i++)
	{
		if (astring.Find(_string[i]) != -1)
			return i;
	}
	return -1;
}
int MyString::find_first_of(const char * s, int pos) const
{
	MyString str(*this);
	return find_first_of(str, pos);
}
int MyString::find_first_of(char chuoi, int pos) const
{
	for (int i = pos - 1; i >= 0; i--)
	{
		if (_string[i] == chuoi)
			return i;
	}
	return -1;
}
int MyString::find_last_of(const MyString & astring, int pos) const
{
	int timthay = rfind(astring,0);
	for (int i = 1; i < astring.strLength; i++)
	{
		int temp = rfind(astring,i);
		if (timthay < temp)
			timthay = temp;
	}
	return timthay;
}
int MyString::find_last_of(const char * s, size_t pos) const
{
	MyString str(*this);
	return find_last_of(str, pos);
}
int MyString::find_last_of(char chuoi, int pos) const
{
	for (int i = pos - 1; i >= 0; i--)
	{
		if (_string[i] == chuoi)
			return i;
	}
	return -1;
}
int MyString::find_first_not_of(const MyString & astring, int pos) const
{
	for (int i = pos; i < strLength; i++)
	{
		if (astring.Find(_string[i]) == -1)
			return i;
	}
	return -1;
}
int MyString::find_first_not_of(const char * s, int pos) const
{
	MyString str(*this);
	return find_first_not_of(str, pos);
}
int MyString::find_first_not_of(char chuoi, int pos) const
{
	for (int i = pos; i < strLength; i++)
	{
		if (_string[i] != chuoi)
			return i;
	}
	return -1;
}
int MyString::find_last_not_of(const MyString & astring, int pos) const
{
	int temp = find_first_not_of(astring,0);
	int timthay = -1;
	while (temp < pos)
	{
		timthay = temp;
		temp = find_first_not_of(astring,temp + 1); 
	}
	if (timthay != -1)
		return timthay;
	return -1;
}
int MyString::find_last_not_of(const char * s, int pos) const
{
	MyString str(*this);
	return find_last_not_of(str, pos);
}
int MyString::find_last_not_of(char chuoi, int pos) const
{
	if (pos == -1)
		pos = strLength;
	for (int i = pos - 1; i >= 0; i--)
	{
		if (_string[i] != chuoi)
			return i;
	}
	return -1;
} 

MyString::iterator MyString::begin()
{
	return this->_string; 
}
MyString::iterator MyString::end()
{
	return this->_string + this->strLength;
}
MyString::iterator MyString::rbegin()
{
 
	return  this->_string + this->strLength;
}
MyString::iterator MyString::rend()
{
	return  this->_string;
}

///////////////////////////////////////////