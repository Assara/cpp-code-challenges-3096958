// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
bool on_board(std::string knight) {
    char letter = knight[0];
    char  number = knight[1];
    if (letter >= 'a' && letter <= 'h' ) {
        if (number>= '1' && number <= '8'){
            return true;
        }
    }
    return false;
}

std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;
    char letter = knight[0];
    char number = knight[1];

    for( char sign_l : {-1,1}) {
        for(char sign_n : {-1,1}) {
            std::string move1 = {letter+(sign_l*(char)1), number + (sign_n*(char)2)};
            std::string move2 = {letter+(sign_l*(char)2), number + (sign_n*(char)1)};
            if (on_board(move1)) {
                moves.push_back(move1);
            }
            if (on_board(move2)) {
                moves.push_back(move2);
            }
        }
    }

    // Write your code here

    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}