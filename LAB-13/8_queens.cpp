#include <iostream>
using namespace std;

#define MAX 20

int N;
int board[MAX][MAX];

void print_matrix(int a[MAX][MAX], int n){
    int i, j;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            if(a[i][j])
                cout << " Q ";
            else
                cout << " . ";
        }
        cout << "\n";
    }
}

bool isSafe(int r, int c){
    int i, j;

    for(i = 0 ; i < r ; i++){
        if(board[i][c] == 1)
            return false;
    }

    for(i = r - 1, j = c - 1 ; i >= 0 && j >= 0 ; i--, j--){
        if(board[i][j] == 1)
            return false;
    }

    for(i = r - 1, j = c + 1 ; i >= 0 && j < N ; i--, j++){
        if(board[i][j] == 1)
            return false;
    }

    return true;
}

bool solve(int row){
    int i;

    if (row == N){
        print_matrix(board, N);
        return true;
    }

    for(i = 0 ; i < N ; i++){
        if (isSafe(row, i)){
            board[row][i] = 1;

            if (solve(row + 1))
                return true;

            board[row][i] = 0;
        }
    }

    return false;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (!solve(0))
        cout << "No solution exists";

    return 0;
}
