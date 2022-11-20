#include <iostream>
#define MAX_SIZE 4
using namespace std;

void Sudoku(int n);
void PrintSudoku();
int isValid(int n, int x, int y);
void MakedSudoku();

int S[MAX_SIZE][MAX_SIZE];
bool flag = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);


    int testCase = 0;
    cin >> testCase;
    while (testCase--) {
        MakedSudoku();
        Sudoku(0);
    }
}

void Sudoku(int n) {
    if (n == MAX_SIZE*MAX_SIZE) {
        PrintSudoku();
    }
    else {
        int x = n / MAX_SIZE;
        int y = n % MAX_SIZE;
        if (S[x][y] == 0) {
            for (int i = 1; i <= MAX_SIZE; i++) {
                if (isValid(i, x, y) == 1) {
                    S[x][y] = i;
                    Sudoku(n+1);
                    S[x][y] = 0;
                }

            }
        }
        else {
            Sudoku(n+1);
        }
    }
}

void PrintSudoku() {
    if (flag == false) {
        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) 
                cout << S[i][j] << " ";
            cout << endl;
        }
        flag = true;
    }
}

int isValid(int n, int x, int y) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (n == S[x][i]) {
            return 0;
        }
        else if (n == S[i][y]) {
            return 0;
        }
    }
    int row = x / 2 * 2;
    int col = y / 2 * 2;
    for (int i = row; i < row + 2; i++) {
        for (int j = col; j < col + 2; j++) {
            if (n == S[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void MakedSudoku(){
    for(int i=0; i<MAX_SIZE; i++){
        for(int j=0; j<MAX_SIZE; j++){
            cin >> S[i][j];
        }
    }
    flag = false;
}