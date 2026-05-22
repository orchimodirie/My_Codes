#include <iostream> 

#include <limits> 

using namespace std; 

 

int main(){ 

    int month, day; 

    string sMonth, zodiac; 

 

    // Input validation for month 

    cout << "Enter month: "; 

    cin >> month; 

 

    if (cin.fail() || month < 1 || month > 12) { 

        cout << "Invalid" << endl; 

        return 0; 

    } 

 

    // Input validation for day 

    cout << "Enter day: "; 

    cin >> day; 

 

    if (cin.fail() || day < 1 || day > 31) { 

        cout << "Invalid" << endl; 

        return 0; 

    } 

 

    // Check if the month-day combination is valid for each month 

    if ((month == 2 && day > 29) || (month == 4 || month == 6 || month == 9 || month == 11) && day > 30) { 

        cout << "Invalid" << endl; 

        return 0; 

    } 

 

    // Check for invalid day in February 

    if (month == 2 && day > 28) { 

        if ((month == 2 && day > 29)) { 

            cout << "Invalid" << endl; 

            return 0; 

        } 

    } 

 

    // Switch to determine the zodiac sign based on month and day 

    switch (month){ 

        case 1: 

            sMonth = "January"; 

            if (day >= 20 && day <= 31) { 

                zodiac = "Aquarius"; 

            } else { 

                zodiac = "Capricorn"; 

            } 

            break; 

        case 2: 

            sMonth = "February"; 

            if (day >= 19 && day <= 29) { 

                zodiac = "Pisces"; 

            } else { 

                zodiac = "Aquarius"; 

            } 

            break; 

        case 3: 

            sMonth = "March"; 

            if (day >= 21 && day <= 31) { 

                zodiac = "Aries"; 

            } else { 

                zodiac = "Pisces"; 

            } 

            break; 

        case 4: 

            sMonth = "April"; 

            if (day >= 20 && day <= 30) { 

                zodiac = "Taurus"; 

            } else { 

                zodiac = "Aries"; 

            } 

            break; 

        case 5: 

            sMonth = "May"; 

            if (day >= 21 && day <= 31) { 

                zodiac = "Gemini"; 

            } else { 

                zodiac = "Taurus"; 

            } 

            break; 

        case 6: 

            sMonth = "June"; 

            if (day >= 21 && day <= 30) { 

                zodiac = "Cancer"; 

            } else { 

                zodiac = "Gemini"; 

            } 

            break; 

        case 7: 

            sMonth = "July"; 

            if (day >= 23 && day <= 31) { 

                zodiac = "Leo"; 

            } else { 

                zodiac = "Cancer"; 

            } 

            break; 

        case 8: 

            sMonth = "August"; 

            if (day >= 23 && day <= 31) { 

                zodiac = "Virgo"; 

            } else { 

                zodiac = "Leo"; 

            } 

            break; 

        case 9: 

            sMonth = "September"; 

            if (day >= 23 && day <= 30) { 

                zodiac = "Libra"; 

            } else { 

                zodiac = "Virgo"; 

            } 

            break; 

        case 10: 

            sMonth = "October"; 

            if (day >= 21 && day <= 31) { 

                zodiac = "Scorpio"; 

            } else { 

                zodiac = "Libra"; 

            } 

            break; 

        case 11: 

            sMonth = "November"; 

            if (day >= 22 && day <= 30) { 

                zodiac = "Sagittarius"; 

            } else { 

                zodiac = "Scorpio"; 

            } 

            break; 

        case 12: 

            sMonth = "December"; 

            if (day >= 21 && day <= 31) { 

                zodiac = "Capricorn"; 

            } else { 

                zodiac = "Sagittarius"; 

            } 

            break; 

        default: 

            cout << "Invalid" << endl; 

            return 0; 

    } 

 

    // Output the zodiac sign and month 

    cout << "Zodiac sign for " << sMonth << " " << day << " is " << zodiac << endl; 

 

    return 0; 

} 