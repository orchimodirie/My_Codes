#include <iostream>
const int CHARCAP = 100;

class ArrayADT {
private:
    char a [CHARCAP];
    char b [CHARCAP];

    
public:
    ArrayADT() {
        a[0] = '\0';
        b[0] = '\0';
        
    }

    void StringLength() {
        std::cout<<"Enter a string: ";
        std::cin.getline(a, CHARCAP);

        char* chPTR = a;

        int counter = 0;
        while(*chPTR != '\0'){
            counter++;
            chPTR++;
        }

        std::cout<<"Length of the string is: "<<counter<<std::endl;


    }

    void Compare() {
        std::cout<<"Enter the first string: ";
        std::cin.getline(a, CHARCAP);

        std::cout<<"Enter the second string: ";
        std::cin.getline(b, CHARCAP);

        char* A_ptr = a;
        char* B_ptr = b;

        // Traverse both strings while the characters match and we haven't reached the end
        while(*A_ptr != '\0' && *B_ptr != '\0' && *A_ptr == *B_ptr) {
            A_ptr++;
            B_ptr++;
        }

        if (*A_ptr == *B_ptr) {
            std::cout<<"Both strings are equal"<<std::endl;
        } else if (*A_ptr < *B_ptr) {
            std::cout<<"The first string is smaller"<<std::endl;
        } else {
            std::cout<<"The second string is smaller"<<std::endl;
        }
    }

    void Concatenate() {
        std::cout<<"Enter the first string: ";
        std::cin.getline(a, CHARCAP);

        std::cout<<"Enter the second string: ";
        std::cin.getline(b, CHARCAP);

        char* A_ptr = a;
        char* B_ptr = b;

        while(*A_ptr != '\0') {
            A_ptr++;
        }

        while(*B_ptr != '\0') {
            *A_ptr = *B_ptr;
            A_ptr++;
            B_ptr++;
        }

        *A_ptr = '\0';

        std::cout<<"Concatenated string: "<<a<<std::endl;
    }

    void Run () {
        int choice;
        bool isLooping = true;
        while (isLooping) {
            std::cout<<"\nWhat do you want to do? \n"
                    << "[1] Find the string length \n"
                    << "[2] Compare two strings \n"
                    << "[3] Concatenate two strings \n"
                    << "[4] Exit \n" 
                    << "Enter your choice: ";
            
            if (!(std::cin >> choice)) {
                std::cout<<"Invalid Input! Try Again"<<std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }
            std::cin.ignore(1000, '\n');

            if(choice == 1){
                StringLength();
            } else if(choice == 2) {
                Compare();
            } else if(choice == 3) {
                Concatenate();
            } else if (choice == 4) {
                std::cout<<"Exiting program..."<<std::endl;
                isLooping = false;
            } else {
                std::cout<<"Error Input! Try Again"<<std::endl;
            }
        }
    };
};


int main () {
    ArrayADT array;
    array.Run();
}