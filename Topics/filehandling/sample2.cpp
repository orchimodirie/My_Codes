#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream ifile("legacy_systems.txt");
    ofstream ofile("active_systems.txt");

    string data;
    string fLine;
    while(getline(ifile, data))
    {
        if(data.find("Active") != string::npos)
        {
            ofile << data <<endl;
        }
    }

    ifile.close();
    ofile.close();

    //part three

    fstream myfile;
    myfile.open("active_systems.txt", ios::app);
     if(!myfile.is_open())
    {
        cout<<"cant open the file!"<<endl;
        exit(1);
    }

    myfile <<"Migration Complete"<<endl;
    if(!remove("legacy_systems.txt"))
    {
        cout<<"successfully deleted"<<endl;
    }
    else cout <<"failed to delete"<<endl;
    
    return 0;
}