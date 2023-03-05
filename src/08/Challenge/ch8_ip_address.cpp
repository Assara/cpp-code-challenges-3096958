// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){

    std::string::iterator dots[5];

    dots[0] = ip.begin()-1;
    dots[4] = ip.end();
    int i = 0;
    for (std::string::iterator it = ip.begin(); it < ip.end(); it++) {
        if((*it) == '.') {
            i++;
            dots[i] = it;  
            if (i>3){
                return false;
            }
        } else if((*it) < '0' || (*it)> '9') {

            return false;
        }
    }
    // not enough dots
    if (i < 3) {
        return false;
    }
    for (int i = 0; i< 4; i++) {
        if (dots[i]+1 == dots[i+1]) {
            return false;
        }

        std::string s (dots[i]+1, dots[i+1]);
        long n = std::stol(s , nullptr, 10);
        if (n > 255) {

            return false;
        }
    }
    // Write your code here
    return true;
}

// Main function
int main(){
    std::string s;
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}
