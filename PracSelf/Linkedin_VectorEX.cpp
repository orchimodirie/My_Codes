#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> distances;
    vector<int> result;
    int checkpointIndex, n, temp;

    cout<<"Size: ";
    cin>>n;
    cout<<"Checkppoint index: ";
    cin>>checkpointIndex;


    // I choose reserve than resize for faster program
    distances.reserve(n);

    for(int i = 0; i < n; i++){
        cin>>temp;
        distances.push_back(temp);
    }


    //getting the first element
    result.push_back(distances.front());

    //getting the checkpoint element
    result.push_back(distances[checkpointIndex]);

    //getting the last element
    result.push_back(distances.back());



    // printing the vector element "result"
    for(int num: result){
        cout<<num<<" ";
    }
    return 0;
}