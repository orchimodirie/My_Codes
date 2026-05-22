
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main (){
    vector <string> processdata;
    ifstream ifile;
    ifile.open("name.txt");

    if(!ifile.is_open())
    {
        cout<<"Can't open the file"<<endl;
        return 0;
    }

    string data;
    string cleandata;
    while(ifile >> data)
    {
        for(char c: data)
        {
            if(isalpha(c))
            {
                cleandata += c;
            }
        }

        processdata.push_back(cleandata);
        cleandata.clear();
    }

    for(string s: processdata)
    {
        cout<<s<<" ";
    }
    
    
    return 0;

}