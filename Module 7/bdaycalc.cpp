#include <iostream>
#include <cstdlib>
using namespace std;
int firtYr(int month, int day, int year);
int betweenYr(int strYear, int endYear);
int finalYr(int month, int day, int year);

int main() {
    int month, day, year;
    int cmonth, cday, cyear, final;
    char cont;

    do {
        system("cls");
        cout << "\nEnter the B-month: ";
        cin >> month;
        cout << "Enter the B-day: ";
        cin >> day;
        cout << "Enter the B-year: ";
        cin >> year;

        cout << "\n============================================\n";

        cout << "Enter the current month: ";
        cin >> cmonth;
        cout << "Enter the current day: ";
        cin >> cday;
        cout << "Enter the current year: ";
        cin >> cyear;

        if (year == cyear) {
            final = finalYr(cmonth, cday, cyear);
        } else {
            final = firtYr(month, day, year) + betweenYr(year, cyear) + finalYr(cmonth, cday, cyear);
        }
        cout << "\nIt's been " << final << " days had passed" << endl;

        cout << "Press Y to continue or press any key to exit: ";
        cin >> cont;
} while (cont == 'y' ||cont == 'Y');

return 0;
}



int firtYr(int month, int day, int year) {
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        monthDays[1] = 29;
    }

    int result, accum = 0, final;
    int arrInd = month - 1;

    result = (monthDays[arrInd] - day);

    // second is looping through the month
    for (int i = arrInd + 1; i < 12; i++) {
        accum = accum + monthDays[i];
    }

    // first operation
    final = result + accum;

    return final;
}


int betweenYr(int strYear, int endYear) {
    int yrAccum = 0;

    for (int i = strYear + 1; i < endYear; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            yrAccum = 366 + yrAccum;
        } else {
            yrAccum = 365 + yrAccum;
        }
    }

    return yrAccum;
}

int finalYr(int month, int day, int year) {
    int dayaccum = 0;
    int arrInd = month - 1;

    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        monthDays[1] = 29;
    }

    for (int i = 0; i < arrInd; i++) {
        dayaccum = monthDays[i] + dayaccum;
    }

    int result = day + dayaccum;

    return result;
}