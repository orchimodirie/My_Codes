
#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};


void print(Node* header){
    int counter = 1;
    while(header != nullptr)
    {
        cout<<"\nList "<<counter<<": "<<header->data<<endl;
        header = header->next;
        counter++;
    }
}

void print(Node* header, int number){
    int counter = 1;
        //number-1 is to access the elemeent of number
    for(counter; counter<number; counter++)
    {
        header = header->next;
    }

    cout<<"\nList "<<counter<<": "<<header->data<<endl;
}


void Print(Node* header)
{
    system("cls");
    int choice;
    cout<<"[1] Do you want to print specific element? or \n[2] Print all?"<<endl;

    while(true)
    {
        if(!(cin>>choice))
        {
            cout<<"Invalid input"<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        else
        {
            if(choice>2 || choice<1)
            {
                cout<<"choose either 1 or 2 only"<<endl;
                continue;
            }

            if(choice == 1)
            {
                int number;
                cout<<"Which number on the list?: ";
                cin>>number;
                print(header, number);
            }
            else if(choice == 2)
            {
                print(header);
            }

            break;
        }
    }
}
 
void addNode(Node* &header, Node* &tail)
{
    string dat;
    cout<<"Input your data: ";
    cin>>dat;

    Node* newNode = new Node();
    newNode->data = dat;

    if(header == nullptr)
    {
        header = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}







int main() {
    Node* header = nullptr;
    Node* tail;

    bool islooping = true;
    while(islooping)
    {
        system("cls");
        int option;
        cout<<"===== MENU ====="<<endl;
        cout<<"[1] Add List "<<endl;
        cout<<"[2] Print "<<endl;
        cout<<"[3] Exit "<<endl;
        cout<<"================"<<endl;
        cout<<"Choice your option: ";
        cin>>option;

        switch (option)
        {
        case 1:
            addNode(header, tail);
            break;
        case 2:
            Print(header);
            break;
        case 3:
            cout<<"exit";
            islooping = false;
            break;
        default:
            cout<<"Invalid Input!"<<endl;
            cin.clear();
            cin.ignore(100, '\n');
            break;
        }

        system("pause");
    }

    







    

  
     

}