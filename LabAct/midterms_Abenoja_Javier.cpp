#include <iostream>
#include <string>
using namespace std;
//Activity by Javier, Abenoja


struct Addressto {
	string street;
	string city;
	string country;
};

struct Educationshould {
	string name;
	string degree;
	int year;
	
};

struct WorkExperience {
	string companyname;
	string jobtitle;
	int yearsWorked;
	
	 
};

struct Autobiography {
	string name = "None";
	int age;
	Addressto address;
	Educationshould education[3];
	WorkExperience works[2];
};


void addDetails(Autobiography &biography){
	cout<<"\nEnter name: ";
	getline(cin, biography.name);
	cout<<"Age: ";
	cin>>biography.age;
	cin.ignore(1000, '\n');
	
	cout<<"\nAddress:\n";
	cout<<"Street: ";
	getline(cin, biography.address.street);
	cout<<"City: ";
	getline(cin, biography.address.city);
	cout<<"Country: ";
	getline(cin, biography.address.street);
	
	
	cout<<"\nEducation History:" << endl;
	for(int i = 0; i<3; i++)
	{
		cout<<"\nSchool "<<i+1<< ":" << endl;
		cout<<"School Name: ";
		getline(cin, biography.education[i].name);
		cout<<"Degree: ";
		getline(cin, biography.education[i].degree);
		cout<<"Graduation Year: ";
		cin>>biography.education[i].year;
		cin.ignore();
		
	}
	
	cout<<"\nWork Experience:"<<endl;
	for(int i = 0; i<2; i++)
	{
		cout<<"\nJob "<<i+1<< ":" << endl;
		cout<<"Company Name: ";
		getline(cin, biography.works[i].companyname);
		cout<<"Job Title: ";
		getline(cin, biography.works[i].jobtitle);
		cout<<"Years Worked: ";
		cin>>biography.works[i].yearsWorked;
		cin.ignore(1000, '\n');
	}
	cout << "\nUser Input Saved!" << endl;
	system("PAUSE");
	
}

void printDetails (const Autobiography &biography){
	system("cls");
	
	if(biography.name == "None"){
		cout<<"No Details Yet!"<<endl;
		return;
	}
	
	cout<<"---Autobiography---"<<endl;
	cout<<"Name: "<<biography.name<<endl;
	cout<<"Age: "<<biography.age<<endl;
	
	cout<<"\nAddress: \n";
	cout<<"Street: "<<biography.address.street<<endl;
	cout<<"City: "<<biography.address.city<<endl;
	cout<<"Country: "<<biography.address.street<<endl;
	
	
	cout<<"\nEducation History:"<<endl;
	for(int i = 0; i<3; i++)
	{
		cout<<"\nSchool: "<<i+1<<endl;
		cout<<"School Name: "<<biography.education[i].name<<endl;;
		cout<<"Degree: "<<biography.education[i].degree<<endl;
		cout<<"Graduation Year: "<<biography.education[i].year<<endl;
	}
	
	cout<<"\nWork Experience:"<<endl;
	for(int i = 0; i<2; i++)
	{
		cout<<"\nJob: "<<i+1<<endl;
		cout<<"Company Name: "<<biography.works[i].companyname<<endl;
		cout<<"Job Title: "<<biography.works[i].jobtitle<<endl;
		cout<<"Graduation Year: "<<biography.works[i].yearsWorked<<endl;
	}
	system("pause");
}


int main()
{
	Autobiography biography;
	int choice;
	
	
	
	bool islooping = true;
	while(islooping){
		system("cls");
		cout<<"===================================="<<endl;
		cout<<"	       MENU"<<endl;
		cout<<"===================================="<<endl;
		cout<<"(1) Add Autobiography Details"<<endl;
		cout<<"(2) Display Autobiography"<<endl;
		cout<<"(3) Exit"<<endl;
		cout<<"====================================="<<endl;
		cout<<"Input your choice: ";
		cin>>choice;
		cin.ignore();
		
	
		switch(choice){
			case 1:
				addDetails(biography);
				break;
			case 2:
				printDetails(biography);
				break;
			case 3:
				cout<<"Exiting..."<<endl;
				islooping = false;
				break;
			default:
				cout<<"Invalid input!"<<endl;
				cin.clear();
				cin.ignore(100, '\n');
		}		
		
		if(!(choice >= 1 && choice <= 3))
		system("pause");
	}

return 0;
}
