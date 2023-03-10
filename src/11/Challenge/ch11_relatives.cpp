// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main() {
    const int MAX_NAME_LENGTH = 50;

    std::fstream file ("names.csv", std::ios::in);
    // Read the CSV file.
    std::unordered_map<std::string,std::string> name_map;

    if(file.is_open()){
        char s[MAX_NAME_LENGTH]; 
        // Write your code here
        while (!file.eof()){
            file.getline(s,MAX_NAME_LENGTH,',');
            std::string str(s);
            int k = str.find(' ');
            std::string first_name(str.begin(), str.begin()+k);

            std::string last_name(str.begin()+k+1, str.end());

            if(name_map[last_name].empty()) {
                name_map[last_name] = first_name;
            } else {
                std::cout << "Found possible relatives: " 
                << name_map[last_name] << " " << last_name << std::endl 
                << first_name << " "  << last_name << std::endl
                << std::flush;
                file.close();
                return 0;
            }
        }
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    // Write your code here

    std::cout << "No relatives found.\n\n" << std::flush;    
    return 0;
}
 