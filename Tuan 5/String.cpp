#include <iostream>
#include <cstring>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;

class String
{
private:
	char* str;
	int dai;
	int num_string;
public:
	String& operator = (const String& s) {
		if (this == &s) return *this;
		dai = s.dai;
		delete[] str;
		str = new char[dai + 1];
		strcpy(str, s.str);
		return *this;
	}
	String& operator = (const char* s) {
		dai = strlen(s);
		delete[] str;
		str = new char[dai + 1];
		strcpy(str, s);
		return *this;
	}
	String(const char* s) {
		dai = strlen(s);
		str = new char[dai + 1];
		strcpy(str, s);
		num_string++;
	}
	String() {
		dai = 2;
		str = new char[1];
		str[0] = '\0';
		num_string++;
	}
	String(const String& s) {
		dai = s.dai;
		str = new char[dai + 1];
		strcpy(str,s.str);
		num_string++;
	}
	~String() {
		--num_string;
		delete[] str;
	}
	int GetLen() const {
		return dai;
	}
	
	char& operator[](int i) {
		return str[i];
	}
	const char& operator[](int i) const {
		return str[i];
	}
	
	//static function
	int HowMany() {
		return num_string;
	}
	void ReverseString() {
		char* TempStr = new char[dai + 1];
		int j = 0;
		for (int i = this->dai - 1; i >= 0; i--) {
			TempStr[j++] = this->str[i];
		}
		delete[] str;
		this->str = TempStr;
	}
	void ToUpperString() {
		for (int i = this->dai - 1; i >= 0; i--) {
			this->str[i] = toupper(this->str[i]);
		}
	}
	void ToLowerString() {
		for (int i = this->dai - 1; i >= 0; i--) {
			this->str[i] = tolower(this->str[i]);
		}
	}
	friend String operator+ (String& st1, String& st2) {
		char* TempStr = new char[st1.dai + st2.dai + 1];
		char* str1 = new char[st1.dai + 1];
		strcpy(str1, st1.str);
		char* str2 = new char[st2.dai + 1];
		strcpy(str2, st2.str);
		strcat(str1, str2);
		strcpy(TempStr, str1);
		String resStr(TempStr);
		return resStr;
	}
	friend ostream& operator << (ostream& os, const String& st) {
		os << st.str;
		return os;
	}
	friend istream& operator >>(istream& is, String& st) {
		char temp[80];
		is.get(temp, 80);
		if (is) {
			st = temp;
		}
		while (is && is.get() != '\n')
			continue;
		return is;
	}
};
int main() {
	String Name1;
	String Name2;
	cout << "Nhap vao chuoi thu nhat: ";
	cin >> Name1;
	cout << "Nhap vao chuoi thu hai: ";
	cin >> Name2;
	cout << "Chuoi 1: " << Name1 << endl;
	cout << "Chuoi 2: " << Name2 << endl;
	String Sum;
	Sum = Name1 + Name2;
	cout << "Sau khi noi 2 chuoi: " << Sum << endl;
	Sum.ReverseString();
	cout << "Sau khi dao 2 chuoi: " << Sum << endl;
	cout << "Chieu dai chuoi: " << Sum.GetLen();
	return 0;
}
