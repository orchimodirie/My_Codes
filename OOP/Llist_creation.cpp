#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


class List {
    private:
        struct Node
        {
            string data;
            Node* next;
        };

        Node* head = nullptr;

        
    public:

    void add(string nodeData){
        Node* temp;
        Node* newNode = new Node(); //creating a new node
        newNode->data = nodeData;
        newNode->next = nullptr;

        if(head == nullptr){
            head = newNode; //this will create the first node and the head will leave on it
            temp = head;
        }
        else
        {
            temp = head;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode; //prior 
        }
    }

    void addBegin(string nodeData)
    {
        Node* newNode = new Node();
        newNode->data = nodeData;
        newNode->next = head;

        head = newNode;
    }

    void deleteNode(string targetValue){
        //middle 
        Node *temp = head;

        while(temp->next->data != targetValue) //traverse
        {
            temp = temp->next;
        }

        Node *toDelete = temp->next;

        temp->next = temp->next->next;
        delete toDelete;
    }

    void display()
    {
        Node* tracker = head;
        cout<<"Linked list"<<endl;
        int i = 1;
        while(tracker != nullptr)
        {
            cout<<"Data "<<i<<" "<<tracker->data<<endl;

            tracker = tracker->next;
            i++;
        }

    }
};









int main () {
List list;

string nodeData;
int size;
cout<<"Enter the size: ";
cin>>size;
cin.ignore();

for(int i = 0; i<size; i++){
    cout<<"Enter the data: ";
    getline(cin, nodeData);

    //addfuncitonm
    list.add(nodeData);
}

list.display();

cout<<"Add in the beginning"<<endl;
list.addBegin("John");
list.deleteNode("20");

list.display();


}