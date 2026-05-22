#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main(){
    FILE *file;
    file = fopen("legacy_systems.txt", "w");
    
    if(!file)
    {
        cout<<"can't open the file"<<endl;
        exit(1);
    }

    for(int i =0; i<3; i++)
    {
        if(i%2 == 0)
            fprintf(file, "System ID: %d | Status: Active\n", i+101);
        else
            fprintf(file, "System ID: %d | Status: Offline\n", i+101);
    }
    
    fclose(file);
    return 0;
}