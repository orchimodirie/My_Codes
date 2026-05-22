#include <iostream>
using namespace std;

class List {
private:
    class Node {
        public:
        int DATA;
        Node* next;
    };

    Node* head;
    public:
    List() { head = nullptr; } //constructor list

    ~List() { //destrutor
        Node *nodePTR, *nextNode;

        nodePTR = head;

        while(nodePTR != nullptr) {
            nextNode = nodePTR->next; // assign the node next to this variable before deleting the node
            delete nodePTR; // delete the node
            nodePTR = nextNode; // move the node to next a node;
        }

        head = nullptr;
    }

    // append function

    void AppendNode (int dat) {
        Node* newNode, *nodePTR; // *nodePTR is like a runner in this program

        //memory allocation for the new node
        newNode = new Node();
        newNode->DATA = dat;
        newNode->next = nullptr;

        if(head == nullptr) {// if list is empty
            head = newNode;
        } else { // if not empty then
            nodePTR = head;

            while(nodePTR->next != nullptr) {
                nodePTR = nodePTR->next;
            }
            nodePTR->next = newNode;
        } cout<<"Input has appended"<<endl;
    }

    void DisplayList () {
        Node* NodePTR;

        if(head == nullptr) {
            cout<<"The list is empty!"<<endl;
        } else {

            NodePTR = head;
            int counter = 1;
            while(NodePTR != nullptr){
                cout<<"The data at Node "<<counter<<": "<<NodePTR->DATA<<endl;;
                NodePTR = NodePTR->next;
                counter++;
            }
        }
    }


};

int main() {
 List list;

 list.AppendNode(2);
 list.AppendNode(4);
 list.AppendNode(5);

 list.DisplayList();

 return 0;
}