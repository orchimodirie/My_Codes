#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    int score;

public:
    Student(string n, int s)
    {
        name = n;
        score = s;
    }

    void displayInfo()
    {
        cout << "Name: " << name << ", Score: " << score << endl;
    }
};

int main()
{
    Student s1("Anna", 88);
    Student s2("Mark", 92);

    s1.displayInfo();
    s2.displayInfo();
}