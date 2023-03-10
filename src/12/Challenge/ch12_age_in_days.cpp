// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <time.h>
 
// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main(){
    int birth_y, birth_m, birth_d, today_y, today_m, today_d, age;


    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;
    
    if(birth_m < 1)
        birth_m = 1;
    if(birth_m > 12)
        birth_m = 12;


    std::time_t now = std::time({});
    //struct tm birth_day = {.tm_mday = birth_d, .tm_year= birth_y, .tm_mon = birth_m,};
    struct tm start = {.tm_mon = birth_m-1, .tm_year = birth_y-1900};

    start.tm_mday = birth_d;
    //start.tm_mday = birth_d;
    std::time_t birth_time = std::mktime(&start);

    std::time_t time_since_birth = now - birth_time;
    // Write your code here


    if(age < 43830)
        std::cout << "You are " << time_since_birth/(3600*24) << " days old.";
    else
        std::cout << "Come on. You can't be " << time_since_birth << " days old!";
    std::cout << "\n\n" << std::flush;
}
