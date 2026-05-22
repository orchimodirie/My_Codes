#include <iostream>
#include <cstring>
using namespace std;

void substring(char str[])
{
    cout << str << endl;
}

void substring(char str[], int start)
{
    int len = strlen(str);
    
    if(start < 0 || start > len){
        cout << "Invalid index range!"<<endl;
        return;
    }

    for (int i = start; i < len; i++)
    {
        cout << str[i];
    }
    cout<<endl;
}

void substring(char str[], int start, int end)
{
    int len = strlen(str);

    if(start < 0 || end >= len || start > end){
        cout << "Invalid index range!"<<endl;
        return;
    }

    for (int i = start; i <= end; i++)
    {
        cout << str[i];
    }
    cout<<endl;
}
int main()
{
    int start, end;
    char str[] = {"the quick brown fox jumps over the dog..."};

    cout << "Orignal string value:" << '\n'
         << str << endl;
    cout << "String lenght: " << strlen(str) << endl;

    cout << "\nEnter start index: ";
    cin >> start;
    cout << "Enter end index: ";
    cin >> end;

    cout << "\nfunction substring(str): " << '\n';
    substring(str);

    cout << "\nfunction substring(str, "<<start<<"): " << '\n';
    substring(str, start);

    cout << "\nfunction substring(str, "<<start<<", "<<end<<"): " << '\n';
    substring(str, start, end);

    return 0;
}
