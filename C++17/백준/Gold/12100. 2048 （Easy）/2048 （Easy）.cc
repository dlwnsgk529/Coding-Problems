#include <iostream>
#include <vector>
#include <queue>
#define MAX 20
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int N;
int maxScore = 0;

std::vector<std::vector<int>> rotate(std::vector<std::vector<int>> board){
    std::vector<std::vector<int>> rotatedBoard(N, std::vector<int>(N,0));
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            rotatedBoard[y][x] = board[N-1 -x][y];
        }
    }

    
    return rotatedBoard;
}

std::vector<std::vector<int>> move(int dir, std::vector<std::vector<int>> board){
    std::vector<std::vector<int>> rotatedBoard = board;
    for(int i = 0; i < dir; i++){
        rotatedBoard = rotate(rotatedBoard);
    }

    std::queue<int> numbers;
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            int numCount = 0;
            if(rotatedBoard[y][x] != 0){
                numbers.push(rotatedBoard[y][x]);
                rotatedBoard[y][x] = 0;
            }
        }
        int currX = 0;
        int frontNumber;
        while( !numbers.empty() ){
            frontNumber = numbers.front();
            if(rotatedBoard[y][currX] == 0){
                rotatedBoard[y][currX] = frontNumber;
            }
            else if(rotatedBoard[y][currX] == frontNumber){
                rotatedBoard[y][currX] += frontNumber;
                if(rotatedBoard[y][currX] > maxScore){
                    maxScore = rotatedBoard[y][currX];
                }
                currX++;
            }
            else if(rotatedBoard[y][currX] != frontNumber){
                currX++;
                rotatedBoard[y][currX] = frontNumber;
            }
            numbers.pop();
        }
    }
    
    return rotatedBoard;
}

void playGame(int leftMove, std::vector<std::vector<int>> board){
    while(leftMove > 0){
        leftMove--;
        std::vector<std::vector<int>> nextBoard;
        for(int i = 0; i < 4; i++){
            nextBoard = move(i, board);
            playGame(leftMove, nextBoard);
        }
    }
}

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    std::vector<std::vector<int>> board(N, std::vector<int>(N,0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++ ){
            std::cin >> board[i][j];
            if(maxScore < board[i][j]){
                maxScore = board[i][j];
            }
        }
    }
    // func(board);
    playGame(5, board);

    std::cout << maxScore << "\n";

    return 0;
}