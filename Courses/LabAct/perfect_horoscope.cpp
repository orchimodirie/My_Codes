
#include <iostream>
#include <cstdlib>
using namespace std;

int mosChecker();
int dayChecker(int mos);
void switcher(int month, int day);

int main()
{

    int month, day;
    char answerYN;

    do
    {

        system("cls");

        month = mosChecker();
        day = dayChecker(month);

        switcher(month, day);

        cout << "\nDo you want to enter again [Y|N]: ";
        cin >> answerYN;

    if (answerYN == 'N' || answerYN == 'n')
    {
        cout << "===== End of Program =====" << endl;
    }
    else
    {
        do{
        cout << "Invalid input, try again\n";

        cout << "Do you want to enter again [Y|N]: ";
        cin >> answerYN;
        }while (!(answerYN == 'N' || answerYN == 'n') && !(answerYN == 'y'));
        cout << "===== End of Program =====" << endl;
    }
        
    } while (answerYN == 'Y' || answerYN == 'y');

  
    return 0;
}

int mosChecker()
{
    double m;
    int month;
    bool valid = true;

    cout << "Enter month: ";

    while (valid)
    {
        if (!(cin >> m) || (m != int(m)))
        { // check if the input is non-integer and decimal
            cout << "Invalid\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter Valid month: ";
            valid = true;
            continue;
        }

        month = int(m);

        if (month < 1 || month > 12)
        {
            cout << "Invalid\n";
            cout << "Enter Valid Month: ";

            valid = true;
            continue;
        }
        else
        {
            valid = false;
        }
    }

    return month;
}

int dayChecker(int mos)
{
    double d;
    bool valid = true;
    int month = mos, day;

    cout << "Enter day: ";
    while (valid)
    {
        if (!(cin >> d) || d != int(d))
        {
            cout << "Invalid\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter day: ";
            valid = true;
            continue;
        }

        day = int(d);

        if ((day < 1 || day > 31) || (month == 2 && day > 29) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
        { // checekr for false
            cout << "Invalid\n";
            cout << "Enter day: ";
            valid = true;
            continue;
        }
        else
        {
            valid = false;
        }
    }
    return day;
}

void switcher(int month, int day)
{
    string sMonth, zodiac;

    switch (month)
    {
    case 1:
        sMonth = "January";
        zodiac = (day >= 20 && day <= 31) ?  "Aquarius":"Capricorn";
        break;
    case 2:
        sMonth = "February";
        zodiac = (day >= 19 && day <= 29) ? "Pisces":"Aquarius";
        break;
    case 3:
        sMonth = "March";
        zodiac = (day >= 21 && day <= 31) ? "Aries":"Pisces";
       break;
    case 4:
        sMonth = "April";
        zodiac = (day >= 20 && day <= 30) ? "Taurus":"Aries";
        break;
    case 5:
        sMonth = "May";
        zodiac = (day >= 21 && day <= 31) ? "Gemini":"Taurus";
        break;
    case 6:
        sMonth = "June";
        zodiac = (day >= 21 && day <= 30) ? "Cancer":"Gemini";
        break;
    case 7:
        sMonth = "July";
        zodiac = (day >= 23 && day <= 31) ? "Leo":"Cancer";
        break;
    case 8:
        sMonth = "August";
        zodiac = (day >= 23 && day <= 31) ? "Virgo":"Leo";
    case 9:
        sMonth = "September";
        zodiac = (day >= 23 && day <= 30) ?  "Libra":"Virgo";
        break;
    case 10:
        sMonth = "October";
        zodiac = (day >= 21 && day <= 31) ?  "Scorpio":"Libra";
        break;
    case 11:
        sMonth = "November";
        zodiac = (day >= 22 && day <= 30) ?  "Sagittarius":"Scorpio";
        break;
    case 12:
        sMonth = "December";
        zodiac = (day >= 21 && day <= 31) ?  "Capricorn":"Sagittarius";
        break;
    default:
        cout << "Invalid";
    }
    cout << "Zodiac sign for " << sMonth << " " << day << " is " << zodiac << endl;
}