// https://www.hackerrank.com/challenges/variable-sized-arrays/problem?isFullScreen=true
//  Vector of Vector Practice

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void memory(int n, vector<vector<int>>& var){
int k;

    for (int i = 0; i < n; i++)
        {
            
                cin >> k;
                vector<int> temp_row(k);
            
            for (int j = 0; j < k; j++)
            {
                cin >> temp_row[j];
            }
            var.push_back(temp_row);
        }
}







int main()
{
    int n, k, q;
    vector<vector<int>> var;
   
    cin >> n;
    
    cin>> q;
    memory(n, var);

    

    vector <int> elements;
    
    for (int i = 0; i < q; i++)
    {
        int row, col;
      
        cin>>row;
      
        cin>>col;

        elements.push_back(var[row][col]);
    }


    for(int i = 0; i < q; i++){
        cout<< elements[i] <<endl;
    }
    return 0;
}
