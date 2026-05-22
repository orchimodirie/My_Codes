#include <iostream>
#include <cstdio>
using namespace std;
 
int main(){
    FILE* file;
    char name[50];
    int age;
 
    //write to file
    file = fopen("userdata.txt", "w");
    if (file == nullptr)
    {
        cerr<<"Error opening file.\n";
        return 1;
    }
 
    cout<<"Enter your name:";
    cin.getline(name, 50);
    cout<<"Enter your age:";
    cin >> age;
 
    fprintf(file, "%s %d\n", name, age);
    fclose(file);
 
    //read from file
    file = fopen("userdata.txt", "r");
    if(file == nullptr)
    {
        cerr<<"Error opening file.\n";
        return 1;
    }
 
    fscanf(file, "%s %d", name, &age);
    cout << "\nData read from file:\n";
    cout << "Name: "<<name<<"\nAge: "<< age << "\n";
 
    fclose(file);
    return 0;
}