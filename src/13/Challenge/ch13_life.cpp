// C++ Code Challenges, LinkedIn Learning

// Challenge #13: Conway's Game of Life
// Write an application that runs Conway's Game of Life, the best-known cellular automaton.
// Do this for a 10x10 grid.
// The grid wraps around in all directions, like the Pac-Man world.

// Rules:
// Any live cell with fewer than two live neighbors dies, as if by underpopulation.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#define N 10
#define M 10

// Conway's Game of Life, main()
// Summary: This application is a simulation of Conway's game of life.


int to1(int n, int m) {
    return (10*((n+N)%N) + (m+M)%M);
}

void reset_map(int map[], int n, int m) {
    for(int i = 0; i< n*m; i++) {
        map[i] = 0;
     }
}

//fills the neighbours of n,m
void fill_neighbour_map(int map[], int n, int m) {
    map[to1(n+1, m+1)] ++;
    map[to1(n+1, m)] ++;
    map[to1(n+1, m-1)] ++;
    map[to1(n, m+1)] ++;
    map[to1(n, m-1)] ++;
    map[to1(n-1, m+1)] ++;
    map[to1(n-1, m)] ++;
    map[to1(n-1, m-1)] ++;                
}



// Rules:
// Any live cell with fewer than two live neighbors dies, as if by underpopulation.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
char new_status(char status, int neighbours){
    if (status == 'X') {
        if (neighbours == 2 || neighbours == 3) {
            return 'X';
        } else {
            return '-';
        }
    }
    if (neighbours == 3) {
       return 'X';
    }
    return '-';
}


int main(){    
    // The game, initialized with a glider and a blinker.
    char game[N][M];  
    std::memset(game,'-',N*M); // Initialize game with dashes.

    // A glider     // - - - - - - - - - -
    game[1][1]='X'; // - X - - - - - - - -
    game[2][2]='X'; // - - X - - - - - - -
    game[3][0]='X'; // X X X - - - - - - -
    game[3][1]='X';
    game[3][2]='X';

    // A blinker    // - - - - - - - - - -
    game[3][6]='X'; // - - - - - - - - - -
    game[3][7]='X'; // - - - - - - - - - -
    game[3][8]='X'; // - - - - - - X X X -
    
    int generation = 0;
    std::string go_on;

    int neighbour_map[N*M];

    for(int n = 0; n < N; n++) {
        std::cout << std::endl;
        for(int m = 0; m < M; m++) {
            std::cout << neighbour_map[to1(n,m)]<< " ";
        }
    }

    do{
        std::cout << "Generation #" << generation++ << "\n";
        for (auto &str : game){
            for (auto &ch : str)
                std::cout << " " << ch;
            std::cout << "\n";
        }
        std::cout << "\n";

        reset_map(neighbour_map,N,M);

        for(int n = 0; n < N; n++) {
            for(int m = 0; m < M; m++) {
                if(game[n][m] == 'X') {
                    fill_neighbour_map(neighbour_map, n, m);
                }
            }
        }

        for(int n = 0; n < N; n++) {
            for(int m = 0; m < M; m++) {
                game[n][m] = new_status(game[n][m], neighbour_map[to1(n,m)]);
            }
        }
        
        std::cout << "Press Enter for the next generation, or type \"Exit\": " << std::flush;
        std::getline(std::cin,go_on);
        std::transform(go_on.begin(), go_on.end(), go_on.begin(), toupper);
        std::cout << "\n" << std::flush;
    }while(go_on.compare("EXIT")!=0);
    
    return 0;
}
