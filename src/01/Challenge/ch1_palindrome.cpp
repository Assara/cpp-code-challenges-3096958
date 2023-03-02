// C++ Code Challenges, LinkedIn Learning

// Challenge #1: Checking for Palindromes
// Write a function to check if a string is a palindrome or not.
// Examples: civic, radar, level.

#include <iostream>
#include <algorithm>

// is_palindrome()
// Summary: This function receives a string and returns true if the string is a palindrome, false otherwise.
// Arguments:
//           str: The string to analyze.
// Returns: A boolean value. True for palindromes, false otherwise.
bool is_palindrome(std::string str){
    std::string::iterator itB = str.begin();
    std::string::iterator itE = str.end()-1;

    while (itB < itE) {
        if (std::tolower((*itB)) != std::tolower((*itE))) {
            return false;
        }
        itB++;
        itE--;
    }
    return true;
}

// Main function
int main(){
    std::string s;
    std::cout << "Enter a string: " << std::flush;
    std::getline(std::cin,s);
    std::cout << "\n\"" << s << (is_palindrome(s) ? "\" is" : "\" is not" ) << " a palindrome.\n\n";
    return 0;
}
