    #include <iostream>
    using namespace std;


    //function tells how many digitis the number and ex
    int main ()
    {
        int n;
        cout<<"Enter your number: ";
        cin>>n;

        if (n<=0)
        {
            cout<<"your number is non positive number"<<endl;
        }

            else if (n<10)
            {
                cout<<"it's a postive number with a 1 digit"<<endl;
            }

            else if (n<100)
            {
                cout<<"it's a postive number with a 2 digit"<<endl;
            }

            else if (n<1000)
            {
                cout<<"it's a postive number with a 3 digit"<<endl;
            }

            else if (n<10000)
            {
                cout<<"it's a postive number with a 4 digit"<<endl;
            }
        
        else
        {
            cout<<"Sorry, it's more than 4 digits number"<<endl;

        }

        return 0;
    }