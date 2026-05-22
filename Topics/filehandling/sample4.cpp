#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

// Tubig Marka ni Shantidope.
// @ https://github.com/SLCLS
// https://github.com/SLCLS/WORKSPACE/blob/main/PERSONAL/C%2B%2B/MAJOR/NUMBER_SYSTEM.cpp

// TODO: Refactor Program and implement GUI using QT Framework.
namespace validator
{
    bool valid_input(string &input, int base);                // Error check, Pass by reference on input for performance.
    string remove_whitespace(const string &input);            // Trim whitespace from input string, used inside valid_input function.
    void prefix_checking(string &cleaned_input, int base);    // Check for prefixes like 0b, 0o, 0x and ask user for confirmation.
    bool validate_syntax(string input, int base);             // Final syntax validation after prefix checking.
}

namespace navigation
{
    void menu(string &menu_option, int &option_case);                                                 // Main Menu
    void conversion(string &conversion_option, int &conversion_case, bool &return_request);           // Conversion Menu
    void calculator(string &calculator_mode, int &calculator_case, bool &return_request);             // Calculator Menu
    void conversion_handler(int conversion_case, string &num1, string &target_base, string &result);  // Conversion Sub Menu           
    void calculator_handler(int calculator_case);                                                     // Calculator Sub Menu
}

namespace computation
{
    // Utility functions
    int char_to_num(char character); // Convert character to integer (real-math) value.
    char num_to_char(int number);    // Convert integer (real-math) value to character.

    // Main Conversion functions
    double to_decimal(const string original_input, int base);
    string from_decimal(double decimal_number, int target_base);

    // Calculator functions
    void basic();
    void advanced();
    double arithmetic(double num1, double num2, string operation);
}

namespace utility
{
    // Utility for Calculator (Prompt Helper)
    void calculator_help();
    int get_base_selection(string prompt);
}

// Colored output for errors and logs.
struct RedBuf : std::streambuf
{
    std::streambuf* dest;
    bool colored = false;

    RedBuf(std::streambuf* d) : dest(d) {}

    int overflow(int c) override
    {
        if (!colored)
        {
            dest->sputn("\033[31m", 5); // Start red
            colored = true;
        }
        if (c == '\n')
        {
            dest->sputn("\033[0m", 4); // Reset color
            colored = false;
        }
        return dest->sputc(c);
    }
};

RedBuf redbuf_cerr(std::cerr.rdbuf());
RedBuf redbuf_clog(std::clog.rdbuf());

int main()
{
    // Red logs and errors for main.
    std::cerr.rdbuf(&redbuf_cerr);
    std::clog.rdbuf(&redbuf_clog);

    cout << "\n***********************************************\n" << "----->>>>>>>     MADE BY SLCLS     <<<<<<<-----";
    cout << "\n***********************************************\n" << "       https://github.com/SLCLS/WORKSPACE      ";
    cout << "\n***********************************************\n" << ">>>>>>     Press any key to continue     <<<<<<\n\n\n\n";
    system("PAUSE"); system("CLS");

    start_main:

    string menu_option; int option_case;         // Main menu variables
    string conversion_option, calculator_mode;   // Sub-menu option variables
    string exit_option;                          // Exit option variable
    int conversion_case, calculator_case;        // Sub-menu switch variables
    bool return_request = false;                 // Return request to main menu
    string num1, num2, target_base, result;      // Calculation variables

    num1 = ""; num2 = ""; target_base = ""; result = ""; // Clear variables

    navigation::menu(menu_option, option_case);  // Main menu

    start_logic:
    switch (option_case) // Main Menu Selection
    {
        case 1: // Conversion Menu
            navigation::conversion(conversion_option, conversion_case, return_request);
            break;
        case 2: // Calculator Menu
            navigation::calculator(calculator_mode, calculator_case, return_request);
            break;
        case 3: // Exit Program
            cout << "\nExiting the program...\n";
            system("PAUSE");
            return 0;
            break;
        default: // Fail-safe
            cerr << "\nWARNING: An unexpected error occurred.\n" << "Press any key to restart the program...\n";
            system("PAUSE");
            system("CLS");
            break;
    }

    if (return_request == true) // Sub-menu return request
    {
        return_request = false;
        goto start_main;
    }

    // Sub-menu Selection
    if (option_case == 1)
    {
        system("CLS");
        navigation::conversion_handler(conversion_case, num1, target_base, result);
        cout << "\nResult: " << result << "\n";
    }
    else if (option_case == 2)
    {
        system("CLS");
        navigation::calculator_handler(calculator_case);
    }

    // Exit Prompt
    cout << "\n***********************************************";
    cout << "\n Enter 'B' to go back to Number System Menu...\n";
    cout << " Enter any other key to return to Main Menu...";
    cout << "\n***********************************************\n";
    cout << "\nPlease choose your action: ";
    cin >> exit_option;

    if (exit_option == "B" || exit_option == "b")
    {
        system("CLS");

        // Clear variables
        num1 = ""; num2 = ""; target_base = ""; result = "";

        goto start_logic;
    }
    else
    {
        system("CLS");
        goto start_main;
    }

    return 0;
}

void navigation::menu(string &menu_option, int &option_case) // Main Menu
{
    system("CLS");
    cout << "\n***********************************************\n" << "     NUMBER SYSTEM CONVERSION & CALCULATOR     ";
    cout << "\n***********************************************\n";
    cout << "\n    [1] Number System Conversion" << "\n    [2] Number System Calculator";
    cout << "\n\n***********************************************";
    cout << "\n-------- Press 'X' to exit the program --------\n" << "***********************************************\n";
    cout << "\nChoose a menu option: ";

    std::cin >> menu_option;
    
    while (menu_option != "1" && menu_option != "2" && menu_option != "X" && menu_option != "x")
    {
        clog << "\nERROR: Invalid input, please choose a valid menu option.\n";
        system("PAUSE");
    	system("CLS");
        menu(menu_option, option_case);
    }

    if (menu_option == "1")
    {
        option_case = 1;
    }
    else if (menu_option == "2")
    {
        option_case = 2;
    }
    else if (menu_option == "X" || menu_option == "x")
    {
        option_case = 3;
    }
}

void navigation::conversion(string &conversion_option, int &conversion_case, bool &return_request) // Conversion Menu
{
    system("CLS");

    start_conversion:
    cout << "\n***********************************************\n" << "        NUMBER SYSTEM CONVERSION MODULE        ";
    cout << "\n***********************************************\n" << "\n     Select the number system:\n";
    cout << "\n    [1] Decimal" << "\n    [2] Binary" << "\n    [3] Octal" << "\n    [4] Hexadecimal";
    cout << "\n\n***********************************************";
    cout << "\n------- Press 'X' to return to main menu ------\n" << "***********************************************\n";
    cout << "\nPlease choose a number system: ";

    std::cin >> conversion_option;

    while (conversion_option != "1" && conversion_option != "2" && conversion_option != "3" && conversion_option != "4" && conversion_option != "X" && conversion_option != "x")
    {
        clog << "\nERROR: Invalid input, please choose a valid conversion option.\n";
        system("PAUSE");
    	system("CLS");
        goto start_conversion;
    }

    if (conversion_option == "1")
    {
        conversion_case = 1;
    }
    else if (conversion_option == "2")
    {
        conversion_case = 2;
    }
    else if (conversion_option == "3")
    {
        conversion_case = 3;
    }
    else if (conversion_option == "4")
    {
        conversion_case = 4;
    }
    else if (conversion_option == "X" || conversion_option == "x")
    {
        system("CLS");
        return_request = true;
        return;
    }
}

void navigation::calculator(string &calculator_mode, int &calculator_case, bool &return_request) // Calculator Menu
{
    system("CLS");

    start_calculator:
    cout << "\n***********************************************\n" << "        NUMBER SYSTEM CALCULATOR MODULE        ";
    cout << "\n***********************************************\n" << "\n   Please select the calculator mode:\n";
    cout << "\n    [1] Basic Arithmetic" << "\n    [2] Advanced Mode" << "\n    [3] Help (What's the difference?)";
    cout << "\n\n***********************************************";
    cout << "\n------- Press 'X' to return to main menu ------\n" << "***********************************************\n";
    cout << "\nChoose a menu option: ";

    std::cin >> calculator_mode;

    while (calculator_mode != "1" && calculator_mode != "2" && calculator_mode != "3" && calculator_mode != "X" && calculator_mode != "x")
    {
        clog << "\nERROR: Invalid input, please choose a valid calculator mode.\n";
        system("PAUSE");
    	system("CLS");
        goto start_calculator;
    }

    if (calculator_mode == "1")
    {
        calculator_case = 1;
    }
    else if (calculator_mode == "2")
    {
        calculator_case = 2;
    }
    else if (calculator_mode == "3")
    {
        system("CLS");
        utility::calculator_help();
        system("PAUSE");
        system("CLS");
        goto start_calculator;
    }
    else if (calculator_mode == "X" || calculator_mode == "x")
    {
        system("CLS");
        return_request = true;
        return;
    }
}

void navigation::conversion_handler(int conversion_case, string &num1, string &target_base, string &result)
{
    int source_base_int = 0;

    start_conversion_handler:

    cout << "\n***********************************************\n" << "        NUMBER SYSTEM CONVERSION MODULE        ";
    cout << "\n***********************************************\n" << "\n     Select the number system:\n";
    cout << "\n    [1] Decimal" << "\n    [2] Binary" << "\n    [3] Octal" << "\n    [4] Hexadecimal";
    cout << "\n\n***********************************************";
    cout << "\n------- Press 'X' to return to main menu ------\n" << "***********************************************\n\n";

    switch (conversion_case) // Error checking & Input Cleaning.
    {
        case 1: // Decimal Conversion
            source_base_int = 10;
            do
            {
                cout << "Enter decimal number: ";

                if (std::cin.peek() == '\n') std::cin.ignore(); // Clears enter key, prevents skipped input on next iteration.
                std::getline(std::cin, num1);
            }
            while (!validator::valid_input(num1, 10));
            break;
        
        case 2: // Binary Conversion
            source_base_int = 2;
            do
            {
                cout << "Enter binary number: ";

                if (std::cin.peek() == '\n') std::cin.ignore();
                std::getline(std::cin, num1);
            }
            while (!validator::valid_input(num1, 2));
            break;
        
        case 3: // Octal Conversion
            source_base_int = 8;
            do
            {
                cout << "Enter octal number: ";

                if (std::cin.peek() == '\n') std::cin.ignore();
                std::getline(std::cin, num1);
            }
            while (!validator::valid_input(num1, 8));
            break;
        
        case 4: // Hexadecimal Conversion
            source_base_int = 16;
            do
            {
                cout << "Enter hexadecimal number: ";

                if (std::cin.peek() == '\n') std::cin.ignore();
                std::getline(std::cin, num1);
            }
            while (!validator::valid_input(num1, 16));
            break;
        
        default: // Fail-safe
            cerr << "\nWARNING: An unexpected error occurred in conversion handler.\n" << "Press any key to restart the program...\n";
            system("PAUSE");
            system("CLS");
            goto start_conversion_handler;
            break;
    }

    // Target Base Selection.
    int target_base_int = 0;
    bool valid_target = false;

    do
    {
        cout << "\nEnter target number system (1-4): ";
        std::cin >> target_base;

        if (target_base == "1") 
        {
            target_base_int = 10; // Choice 1 -> Base 10, Decimal.
            valid_target = true;
        }
        else if (target_base == "2") 
        {
            target_base_int = 2;  // Choice 2 -> Base 2, Binary.
            valid_target = true;
        }
        else if (target_base == "3") 
        {
            target_base_int = 8;  // Choice 3 -> Base 8, Octal.
            valid_target = true;
        }
        else if (target_base == "4") 
        {
            target_base_int = 16; // Choice 4 -> Base 16, Hexadecimal.
            valid_target = true;
        }
        else 
        {
            clog << "\nERROR: Invalid choice. Please enter 1 (Dec), 2 (Bin), 3 (Oct), or 4 (Hex).\n";
            std::cin.clear();
            if (std::cin.peek() == '\n') std::cin.ignore();
        }

        if (valid_target && target_base_int == source_base_int) {
             cout << "NOTE: Source and Target bases are the same. Result will be identical.\n";
        }
    
    } while (!valid_target);

    // Conversion Process
    double decimal_value = computation::to_decimal(num1, source_base_int);
    result = computation::from_decimal(decimal_value, target_base_int);
}

void navigation::calculator_handler(int calculator_case)
{
    start_calculator_handler:
    switch (calculator_case)
    {
        case 1: // Basic Arithmetic Module
            computation::basic();
            break;
        case 2: // Advanced Mode Module
            computation::advanced();
            break;
        default: // Fail-safe
            cerr << "\nWARNING: An unexpected error occurred in calculator handler.\n" << "Press any key to restart the program...\n";
            system("PAUSE");
            system("CLS");
            goto start_calculator_handler;
            break;
    }
}

int utility::get_base_selection(string prompt)
{
    string choice;
    int base = 0;
    bool valid = false;

    do
    {
        cout << prompt;
        cin >> choice;

        if (choice == "1") { base = 10; valid = true; }       // Decimal
        else if (choice == "2") { base = 2; valid = true; }   // Binary
        else if (choice == "3") { base = 8; valid = true; }   // Octal
        else if (choice == "4") { base = 16; valid = true; }  // Hex
        else
        {
            clog << "\nERROR: Invalid choice. Enter 1 (Dec), 2 (Bin), 3 (Oct), or 4 (Hex).\n";
            std::cin.clear();
            if (std::cin.peek() == '\n') std::cin.ignore();
        }
    } while (!valid);

    return base;
}

void utility::calculator_help()
{
    cout << "\n***********************************************\n" << "          CALCULATOR MODE HELP SECTION         ";
    cout << "\n***********************************************\n" << "\n [1] Basic Arithmetic Mode:\n";
    cout << " 1. Performs addition, subtraction, division,\n";
    cout << " and multiplication (basic arithmetic).\n";
    cout << " 2. Operation only support same number system.\n";
    cout << "\n [1] Advanced Arithmetic Mode:\n";
    cout << " 1. Performs addition, subtraction, division,\n";
    cout << " and multiplication (basic arithmetic).\n";
    cout << " 2. Supports different number system\n";
    cout << " 3. Answers in preferred number system.\n";
    cout << "\n\n***********************************************";
    cout << "\n>>>>>>     Press any key to continue     <<<<<<\n" << "***********************************************\n\n";
}

int computation::char_to_num(char character)
{
    if (character >= '0' && character <= '9')
    {
        return character - '0';
    }
    else
    {
        return toupper(character) - 'A' + 10; // toupper converts lowercase to uppercase.
    }
}

char computation::num_to_char(int number)
{
    if (number >= 0 && number <= 9)
    {
        return '0' + number;
    }
    else
    {
        return 'A' + (number - 10);
    }
}

double computation::to_decimal(const string original_input, int base)
{
    string input = original_input;

    bool is_negative = false;

    // Negative sign checking and temporary stripping.
    if (input[0] == '-')
    {
        is_negative = true;
        input = input.substr(1);
    }
    else if (input[0] == '+')
    {
        input = input.substr(1);
    }

    // Separating integer and fractional parts. "npos" stands for "no position".
    size_t decimal_point = input.find('.');
    string integer_part = (decimal_point == string::npos) ? input : input.substr(0, decimal_point);
    string fractional_part = (decimal_point == string::npos) ? "" : input.substr(decimal_point + 1);

    // Computation for integer part.
    double total_value = 0.0;

    for (char c : integer_part) // Horner's Method, instead of summation, we use logic. See notebook for formula. 
    {
        total_value = (total_value * base) + char_to_num(c);
    }

    // Computation for fractional part.
    double divisor = base;

    for (char c : fractional_part) {
        total_value += (char_to_num(c) / divisor);
        divisor *= base;
    }

    return is_negative ? -total_value : total_value;
}

string computation::from_decimal(double decimal_number, int target_base)
{
    if (decimal_number == 0)
    {
        return "0";
    }

    // Stripping negative sign temporarily for calculation.
    bool is_negative = false;
    if (decimal_number < 0) {
        is_negative = true;
        decimal_number = -decimal_number;
    }

    // Separating integer and fractional parts.
    double double_integer, fraction_part;
    fraction_part = modf(decimal_number, &double_integer); // Cmath "modf" function separates (e.g.) 10.5 into 10.0 and 0.5
    long long integer_part = (long long)double_integer; // '%' only works on integers, so we convert to long long.

    string result = "";

    // Integer Conversion.
    if (integer_part == 0)
    {
        result = "0";
    }
    else
    {
        while (integer_part > 0) // Same FEU Tech Formula for "from decimal" conversion.
        {
            int remainder = integer_part % target_base;
            result += num_to_char(remainder);
            integer_part /= target_base;
        }
        
        reverse(result.begin(), result.end()); // From left to right so we reverse.
    }

    // Fractional Conversion.
    if (fraction_part > 0)
    {
        result += ".";
        int precision_limit = 12; // Crash guard for infinite fractions (e.g. 1/3 in decimal is 0.3333...)

        while (fraction_part > 0 && precision_limit > 0) // Same FEU Tech formula.
        {
            fraction_part *= target_base;
            int digit = (int)fraction_part;
            result += num_to_char(digit);
            fraction_part -= digit;
            precision_limit--;
        }
    }

    if (is_negative)
    {
        result = "-" + result;
    }

    return result;
}

double computation::arithmetic(double num1, double num2, string operation)
{
    if (operation == "+") return num1 + num2;
    if (operation == "-") return num1 - num2;
    if (operation == "*") return num1 * num2;
    if (operation == "/") 
    {
        if (num2 == 0)
        {
            clog << "\nERROR: Division by zero is not allowed. Returning 0.\n";
            return 0;
        }
        return num1 / num2;
    }

    return 0; // Should not happen if validated
}

void computation::basic()
{
    system("CLS");
    cout << "\n***********************************************\n" << "            BASIC CALCULATOR MODULE            ";
    cout << "\n***********************************************\n" << "\n   Number System Options:\n";
    cout << "\n    [1] Decimal" << "\n    [2] Binary" << "\n    [3] Octal" << "\n    [4] Hexadecimal";
    cout << "\n\n***********************************************";
    cout << "\n------- Press 'X' to return to main menu ------\n" << "***********************************************\n";

    int base = utility::get_base_selection("\nSelect the number system for this operation: ");

    string num1_string, num2_string, operation;

    // Data Input with Validation.
    do
    {
        cout << "\nEnter first number: ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, num1_string);
    }
    while (!validator::valid_input(num1_string, base));

    bool valid_operation = false;

    do
    {
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        if (operation == "+" || operation == "-" || operation == "*" || operation == "/") valid_operation = true;
        else clog << "ERROR: Invalid operator.\n";
    }
    while (!valid_operation);

    do
    {
        cout << "Enter second number: ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, num2_string);
    }
    while (!validator::valid_input(num2_string, base));

    // Conversion to decimal for computation.
    double val1 = to_decimal(num1_string, base);
    double val2 = to_decimal(num2_string, base);

    // Computation.
    double result_val = computation::arithmetic(val1, val2, operation);

    // Conversion back to original base for output.
    string result_str = from_decimal(result_val, base);

    cout << "\n-----------------------------------------------";
    cout << "\nResult (" << num1_string << " " << operation << " " << num2_string << ") in Base " << base << " is:\n";
    cout << ">>    " << result_str << "   <<\n";
    cout << "-----------------------------------------------\n";
}

void computation::advanced()
{
    system("CLS");

    cout << "\n***********************************************\n" << "           ADVANCED CALCULATOR MODULE          ";
    cout << "\n***********************************************\n" << "\n   Number System Options:\n";
    cout << "\n    [1] Decimal" << "\n    [2] Binary" << "\n    [3] Octal" << "\n    [4] Hexadecimal";
    cout << "\n\n***********************************************";
    cout << "\n------- Press 'X' to return to main menu ------\n" << "***********************************************\n";

    string num1_string, num2_string, operation;

    // First Number.
    int base1 = utility::get_base_selection("\nSelect Base for First Number: ");
    do
    {
        cout << "Enter first number: ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, num1_string);
    }
    while (!validator::valid_input(num1_string, base1));

    // Operation.
    bool valid_op = false;
    do
    {
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        if (operation == "+" || operation == "-" || operation == "*" || operation == "/") valid_op = true;
        else clog << "ERROR: Invalid operator.\n";
    }
    while (!valid_op);

    // Second Number.
    int base2 = utility::get_base_selection("\nSelect Base for Second Number: ");
    do
    {
        cout << "Enter second number: ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, num2_string);
    }
    while (!validator::valid_input(num2_string, base2));

    // Target Base for Answer.
    int target_base = utility::get_base_selection("\nSelect Target Base for the Answer: ");

    // Convert to decimal for computation.
    double val1 = to_decimal(num1_string, base1);
    double val2 = to_decimal(num2_string, base2);

    // Computation.
    double result_value = computation::arithmetic(val1, val2, operation);

    // Convert back to target base for output.
    string result_string = from_decimal(result_value, target_base);

    cout << "\n-----------------------------------------------";
    cout << "\nCalculation: " << num1_string << " (Base " << base1 << ") " << operation << " " << num2_string << " (Base " << base2 << ")";
    cout << "\nResult in Base " << target_base << ":\n";
    cout << ">>    " << result_string << "    <<\n";
    cout << "-----------------------------------------------\n";
}

bool validator::valid_input(string &input, int base)
{
    string cleaned_input = remove_whitespace(input); // Remove whitespace.

    if (cleaned_input.empty()) // Check for empty input.
    {
        clog << "\nERROR: Input cannot be empty.\n";
        return false;
    }

    prefix_checking(cleaned_input, base); // Check for prefixes.

    if (!validate_syntax(cleaned_input, base)) // Final Syntax Validation.
    {
        return false;
    }

    input = cleaned_input; // Lazy refactoring malala.
    return true;
}

string validator::remove_whitespace(const string &input)
{
    string cleaned = "";

    for (char c : input)
    {
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r')
        {
            cleaned += c;
        }
    }

    return cleaned;
}

void validator::prefix_checking(string &cleaned_input, int base)
{
    string prefix; char choice;
    int offset = 0;

    if (!cleaned_input.empty() && (cleaned_input[0] == '+' || cleaned_input[0] == '-'))
    {
        offset = 1; // Adjust offset if there's a sign.
    }

    if (cleaned_input.size() >= (2 + offset) && cleaned_input[offset] == '0')
    {
        prefix = cleaned_input.substr(offset, 2);

        bool isBin = (prefix == "0b" || prefix == "0B");
        bool isOct = (prefix == "0o" || prefix == "0O");
        bool isHex = (prefix == "0x" || prefix == "0X");

        bool detected = (isBin && base == 2) || (isOct && base == 8) || (isHex && base == 16);

        if (detected)
        {
            start_prefix:
            cout << "\nPrefix '" << prefix << "' detected. Crop prefix and proceed? [y/n]: ";
            std::cin >> choice;
            
            if (choice == 'y' || choice == 'Y')
            {
                cleaned_input.erase(offset, 2);
            }
            else if (choice == 'n' || choice == 'N')
            {
                cout << "\nNOTE: Proceeding without cropping prefix.\n";
                return;
            }
            else
            {
                clog << "\nERROR: Invalid choice. Please enter 'y' or 'n'.\n";
                system("PAUSE");
                goto start_prefix;
            }
        }
    }
}

bool validator::validate_syntax(string input, int base)
{
    if (input[0] == '-' || input[0] == '+') // Sign removal for easier syntax validation.
    {
        input.erase(0, 1);
    }

    if (input.empty()) // Check if the user only inputted a sign.
    {
        clog << "\nERROR: Input contains a sign but no numbers.\n";
        return false;
    }

    if (input == ".") // Check if the input is just a decimal point.
    {
         clog << "\nERROR: Input cannot be just a decimal point.\n";
         return false;
    }

    bool has_decimal = false;

    for (char c : input) // Check for multiple decimal points.
    {
        if (c == '.')
        {
            if (has_decimal) 
            {
                clog << "\nERROR: Multiple decimal points detected.\n";
                return false;
            }

            has_decimal = true;
            continue;
        }

        int digit_value = -1; // Sentinel value that resets every iteration.

        if (isdigit(c)) // Converting digit character from computer value to integer value [computer_value - '0' (ASCII)].
        {
            digit_value = c - '0';
        }
        else if (isalpha(c)) // Converting alphabet character to Upper case (toupper(c)) and then from computer value to integer value.
        {
            digit_value = toupper(c) - 'A' + 10;
        }

        if (digit_value == -1 || digit_value >= base) // digit_value == -1 ensures that invalid input is caught if it pass through the if conditions above.
        {
            clog << "\nERROR: Character '" << c << "' is not valid for Base " << base << ".\n";
            return false;
        }
    }

    return true;
}