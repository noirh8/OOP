#include <iostream>
#include <string.h>
using namespace std;

class Candidate
{
private:
	char ID[100];
	char Name[100];
	int DayOfBirth;
	int MonthOfBirth;
	int YearOfBirth;
	float MathGrade;
	float LitGrade;
	float EngGrade;
public:
	void set();
	bool Sumscore();
	void print();
};

void Candidate::set()
{
	cout << "Student's ID: ";
	cin >> this->ID;
	cin.ignore();
	cout << "Name of Student: ";
	cin.getline(this->Name, 100);
	cout << "Date of Birth: ";
	cin >> this->DayOfBirth >> this->MonthOfBirth >> this->YearOfBirth;
	cout << "Student has the grade of Math: ";
	cin >> this->MathGrade;
	cout << "Student has the grade of Literature: ";
	cin >> this->LitGrade;
	cout << "Student has the grade of English: ";
	cin >> this->EngGrade;
	cout << endl;
}

bool Candidate::Sumscore()
{
	if ((this->MathGrade + this->EngGrade + this->LitGrade) >= 15)
		return true;
    return false;
}

void Candidate::print()
{
	cout << "Name of Student: " << this->Name << endl;
	cout << "Student's ID: " << this->ID << endl;
	cout << "Date of Birth: " << this->DayOfBirth << " / " << this->MonthOfBirth << " / " << this->YearOfBirth << endl;
	cout << "Math Grade: " << this->MathGrade << endl;
	cout << "Literature Grade: " << this->LitGrade << endl;
	cout << "English Grade: " << this->EngGrade << endl;
}

class TestCandidate
{
public:
	void inputStudent(int n, Candidate x[1000]);
	void printStudent(int n , Candidate x[1000]);
};

void TestCandidate::inputStudent(int n, Candidate x[1000])
{
	for (int i = 0; i < n; i++) {
		x[i].set();
	}
	cout << endl;
}

void TestCandidate::printStudent(int n, Candidate x[1000])
{
	for (int i = 0; i < n; i++)
		if (x[i].Sumscore() == true)
			x[i].print();
    cout << endl;
}

int main()
{
	int n;
	cout << "Nums of Student: ";
	cin >> n; cout << endl;
	Candidate a[100];
	TestCandidate b;
	b.inputStudent(n, a);
	cout << "List of Student that has total grade >=15: " << endl;
	b.printStudent(n, a);
	return 0;
}
