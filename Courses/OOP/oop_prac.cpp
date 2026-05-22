#include <iostream>
using namespace std;

class linkedlist {
    struct Node
    {
        int data;
        Node *next;
    };

    Node *head = nullptr;
    Node *temp; // temnp pointer that modify each node
    
    public:

    void addNode(int dat)
    {
        Node* newNode = new Node();
        newNode->data = dat; // this is to hold the data

        if(head == nullptr)
        {
            head = newNode;
            temp = head; // this should be included always if not it will cause an segmentation error
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    void displayall()
    {
        Node* walker = head;

        int counter = 1;
        while(walker != nullptr)
        {
            
            cout<<"Data "<< counter<<" "<<walker->data<<endl;
            walker = walker->next;
            counter++;
        }
    }

    void findMin ()
    {
        Node* walker = head;

        int counter = 1;
        int compvalue = walker->data;//comparative value

        while(walker != nullptr)
        {
            if(compvalue > walker->data)
            {
                compvalue = walker->data;
            }
            
            walker = walker->next;
            counter++;
        }

        cout<<"the smallest value is at "<<counter-1<<" with a data of "<<compvalue<<endl;
    }

    void delNode(){
        if(head == nullptr){
            cout<<"The list is empty!"<<endl;
            return;
        }

        Node *tempDel = head;
        Node *del;
        int n;
        cout<<"Want No. of node you want to delete?: ";
        cin>>n;

        //traversal
        for(int i = 1; i<n-1; i++)
        {

            if(n == 1)
            {
                head = head->next;
                delete tempDel;
                return;
            }

            if(i<n)
            {
                tempDel = tempDel->next;
                continue;
            }
            
            //the current position is the preceeding node of the deleting node
            // we are going to reassign the next node of pre
            del = tempDel->next;
            tempDel->next = tempDel->next->next;
            delete del;

        }
    }


};


int main () {
    linkedlist linkedList;
    int size;
    cout<<"Enter size: ";
    cin>>size;
        for(int i =0; i<size; i++){
            int dat;
            cout<<"Enter the data: ";
            cin>>dat;
            linkedList.addNode(dat);
        }


    linkedList.displayall();
    linkedList.findMin();
    linkedList.delNode();
    linkedList.displayall();
}



// priorrly the tail hold nothing
// for the first implementation the tail.next will point to the newNode
    // this means that the tail is actively pointing to the newNode
    // then you gonna set the tail address with the address of newNode
        // this means that you curenttly inplace of the newNode and actively modifying the it