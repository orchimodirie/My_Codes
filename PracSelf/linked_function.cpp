// Linked_CodeChallenge
#include <iostream>
#include <cstdint>
#include <vector>

// Uncomment these macros to control whether you see
// the expected result and/or hints.
//#define showExpectedResult
//#define showHints

// Function to calculate score based on milliseconds difference 
// You still need to make the bonus multiplier optional with a default value
double CalculateScore(int millisecondsDiff, double bonusMultiplier) {
    double score = 0.0;

    if(millisecondsDiff <= 50){ //50 pababa
        score = 100;
    }
    else if (millisecondsDiff <= 100) {
        score = 70;
    }
    else if (millisecondsDiff <= 200) {
        score = 50;
    }
    else{
        score = 0;
    }
    // Write your code here
    return bonusMultiplier*score;
}

double CalculateScore(int millisecondsDiff) {
    double score = 0.0;

    if(millisecondsDiff <= 50){ //50 pababa
        score = 100;
    }
    else if (millisecondsDiff <= 100) {
        score = 70;
    }
    else if (millisecondsDiff <= 200) {
        score = 50;
    }
    else{
        score = 0;
    }
    // Write your code here
    return score;
}

// Overloaded function to calculate score based on seconds difference 
// You still need to make the bonus multiplier optional with a default value
double CalculateScore(double secondsDiff, double bonusMultiplier) {
    double score = 0.0;
    double ms = secondsDiff*1000.0;

    if(ms <= 50){ //50 pababa
        score = 100;
    }
    else if (ms <= 100) {
        score = 70;
    }
    else if (ms <= 200) {
        score = 50;
    }
    else{
        score = 0;
    }
    // Write your code here
    return bonusMultiplier*score;
}

double CalculateScore(double secondsDiff) {
    double score = 0.0;
    double ms = secondsDiff*1000.0;

    if(ms <= 50){ //50 pababa
        score = 100;
    }
    else if (ms <= 100) {
        score = 70;
    }
    else if (ms <= 200) {
        score = 50;
    }
    else{
        score = 0;
    }
    // Write your code here
    return 1.5*score;
}




// Function to call both overloaded functions and return a vector of results
std::vector<double> GetScores(int millisecondsDiff, double secondsDiff, double bonusMultiplier1, double bonusMultiplier2) {
    std::vector<double> results;
    results.push_back(CalculateScore(millisecondsDiff));                   // Call the function using milliseconds with the default multiplier
    results.push_back(CalculateScore(millisecondsDiff, bonusMultiplier1));  // Call the function using milliseconds with a custom multiplier
    results.push_back(CalculateScore(secondsDiff));                        // Call the function using seconds with the default multiplier
    results.push_back(CalculateScore(secondsDiff, bonusMultiplier2));       // Call the function using seconds with a custom multiplier
    
    return results;
}





// This is how your code will be called.
// You can edit this code to try different testing cases.
 int main()
 {
    // Example 1
    int millisecondsDiff = 110;    // Input for the function using milliseconds
    double secondsDiff = 0.08;    // Input for the function using seconds
    double bonusMultiplier1 = 1.8;  // Custom multiplier for the function using milliseconds
    double bonusMultiplier2 = 1.7; // Custom multiplier for the function using seconds

    // Get the results from the GetScores function
    std::vector<double> learnerResult = GetScores(millisecondsDiff, secondsDiff, bonusMultiplier1, bonusMultiplier2);

    std::cout<<learnerResult.at(0)<<std::endl;
    std::cout<<learnerResult.at(1)<<std::endl;
    std::cout<<learnerResult.at(2)<<std::endl;
    std::cout<<learnerResult.at(3)<<std::endl;
    return 0;

 }