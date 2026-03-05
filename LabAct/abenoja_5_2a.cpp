#include <iostream>
using namespace std;

int main(){

    int month, day;
    double m, d;
    string sMonth, zodiac;
    char answerYN;


do {
    cout<<"Enter month: ";

    if (!(cin>>m)){         
        cout<<"invalid";
        cin.clear();
        cin.ignore(1000, '\n');
         goto tryagain; 
    }

    if (m != int(m)) {
        cout << "Invalid\n";
         goto tryagain;
    }

    month = int(m);


    if (month < 1 || month > 12){ 
    cout<<"Invalid";
     goto tryagain;
    }


    cout<<"Enter day: ";
    if (!(cin>>d)){         
        cout<<"invalid";
        cin.clear();
        cin.ignore(1000, '\n');
         goto tryagain; 
    }

    if (d != int(d)) {
        cout << "Invalid\n";
         goto tryagain;
    }

 
     day = int (d);
     

    if ( (day < 1 || day >  31 ) || (month == 2 && day > 29 ) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) { // checekr for false
        cout<<"Invalid";
         goto tryagain;
    }

 


 switch (month){    
    case 1:
        sMonth = "January";
        if (day >= 20 && day <= 31){
            zodiac = "Aquarius";
        }
        else{
            zodiac = "Capricorn";
        }
        break;
    case 2:
     sMonth = "February";
        if(day >= 19 && day <= 29){
            zodiac = "Pisces";
        }
        else{
            zodiac = "Aquarius";
        }
        break;
    case 3:
     sMonth = "March";
        if (day >= 21 && day <= 31){
            zodiac = "Aries";
        }
        else{
            zodiac = "Pisces";
        }
        break;
    case 4:
     sMonth = "April";
        if (day >= 20 && day <= 30){
            zodiac = "Taurus";
        }
        else{
            zodiac = "Aries";
        }
        break;
    case 5:
     sMonth = "May";
        if (day >= 21 && day <= 31){
            zodiac = "Gemini";
        }
        else{
            zodiac ="Taurus";
        }
        break;
    case 6:
     sMonth = "June";
        if (day >= 21 && day <= 30){
            zodiac = "Cancer";
        }
        else{
            zodiac ="Gemini";
        }
        break;
    case 7:
     sMonth = "July";
        if (day >= 23 && day <= 31){
            zodiac = "Leo";
        }
        else{
            zodiac ="Cancer";
        }
        break;
    case 8:
     sMonth = "August";
        if (day >= 23 && day <= 31){
            zodiac = "Virgo";
        }
        else{
            zodiac ="Leo";
        }
        break;
    case 9:
     sMonth = "September";
        if (day >= 23 && day <= 30){
            zodiac = "Libra";
        }
        else{
            zodiac ="Virgo";
        }
        break;
    case 10:
     sMonth = "October";
        if (day >= 21 && day <= 31){
            zodiac = "Scorpio";
        }
        else{
            zodiac ="Libra";
        }
        break;
    case 11:
     sMonth = "November";
        if (day >= 22 && day <= 30){
            zodiac = "Sagitaurus";
        }
        else{
            zodiac ="Scorpio";
        }
        break;
    case 12:
     sMonth = "December";
        if (day >= 21 && day <= 31){
            zodiac = "Capricorn";
        }
        else{
            zodiac ="Sagitaurus";
        }
        break;
    default:
        cout<<"Invalid";

        

 }
    cout<<"Zodiac sign for "<<sMonth<<" "<<day<<" is "<<zodiac<<endl;


    tryagain:
    cout<<"\nDo you want to enter again [Y|N]: ";
    cin>>answerYN;

}while(answerYN == 'Y' || answerYN == 'y');

if(answerYN == 'N' || answerYN == 'n'){
    cout<<"===== End of Program ====="<<endl;
}
else{
    cout<<"Invalid\n";
    goto tryagain;
}


return 0;
    
}


