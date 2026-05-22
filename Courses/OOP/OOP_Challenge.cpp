#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
    private:
        string names;
        string type;
        int weight;
    public:
        void displayItem()
        {
            cout<<"Names: " << names <<"\nType: "  << type <<"\nWeight: " << weight <<endl;
        }
};

class Quest {
    private:
        string questName; 
        int rewardGold;
        bool isCompleted;
    public:

    //constructor
        Quest(){
            questName = "None";
            rewardGold = 0;
            isCompleted = true;
        }

        void markComplete(){
            
        }

        void getQuestDetails(){
            
        }

        friend class Player;
};

class Player{
    
    private: 
        string playerName;
        int gold;
        vector <Item> inventory[5];
        Quest activeQuest;
    public:
        

        Player()
        {
            playerName = "None";
            int gold = 0;
        }

        void addItem (Item newItem){
        
            if(inventory->size() != 5) {
                inventory->push_back(newItem);
            }
            else {
                cout<<"The item reached its capacity"<<endl;
            }

        }

        void assignQuest(Quest newQuest){
            if(activeQuest.questName != "None")
            {
                char option;
                cout<<"Do you wish to accept new quest? (y/n)"<<endl;
                cin>> option;
                option = tolower(option);

                if(option == 'y') {
                    activeQuest = newQuest;
                }
                else if ( option == )


            }
        }

        void showStats(){


        }
};

int main () {
    int option;
    if(!cin>>option)
    {
        cout<<"Invalid Input"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    switch (option)
    {
    case 1:
        //view plsyer stats
        break;
    case 2:
        //pick-up new item
        break;
    default:
        break;
    }
    return 0;
}