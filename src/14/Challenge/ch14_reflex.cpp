// C++ Code Challenges, LinkedIn Learning

// Challenge #14: The Reflex Game
// Write an application that waits a random delay between 4 and 10 seconds, and then asks the user to type in a random word.
// This random word comes from a list of 10 3-letter words.
// If the user enters the correct word in less than 2 seconds, print a success message on the screen.
// Otherwise, print a failure message.
// Ignore the case ("CAT" = "cat" = "CaT").

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <thread>

std::string words[10]={"CAT","RAT","BAT","CAP","BAG","RAG","RAP","BET","BEG","LET"};

// The Reflex Game, main()
// Summary: This application measures the time it takes a user to type in a random 3-letter word.
int main(){
    std::cout << "\n";
    std::cout << "                   The Reflex Game\n";
    std::cout << "                   === ====== ====\n";
    std::cout << "After a random delay, you'll be asked to type in a 3-letter word.\n";
    std::cout << "When that happens, type in the word as fast as you can, and hit Enter.\n";
    std::cout << "Don't worry about the character case (\"CAT\" = \"cat\" = \"CaT\").\n\n";
    std::cout << "            Press Enter when you're ready to start." << std::flush;

    std::string try_again;
    std::getline(std::cin, try_again);
    srand((unsigned)time(0)); 
    do{
        int word, time;
        std::string str;

        time = (rand()%10000); 
        word = (rand()%10); 
        // Write your code here
        std::this_thread::sleep_for(std::chrono::milliseconds(time));


        std::cout << words[word] << std::endl;


        std::chrono::system_clock::time_point  chrono_start = std::chrono::system_clock::now();

        getline(std::cin, str);
    
        std::chrono::system_clock::time_point chrono_end = std::chrono::system_clock::now();

        std::chrono::duration<int64_t, std::nano> dur = chrono_end - chrono_start;
        std::transform(str.begin(), str.end(), str.begin(), toupper);


        double elapsed_seconds = (chrono_end-chrono_start).count()/1e9;
        std::cout << "it took: "<< elapsed_seconds << "seconds" << std::endl;
        if(elapsed_seconds > 2) {

            std::cout << "to slow!"<< std::endl; 
        } else if (str == words[word]){
             std::cout << "well done !"<< std::endl; 
        } else {
            std::cout << "wrong word: " << str <<  " != " << words[word] << std::endl; 
        }

        
       

        std::cout << "Try again? (Y/N): " << std::flush;
        std::getline(std::cin, try_again);
    }while(try_again[0]=='Y' || try_again[0]=='y');
    return 0;
}
