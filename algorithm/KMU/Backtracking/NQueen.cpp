#include <iostream>
#define MAX_SIZE 16

using namespace std;

void NQueen(int row);
int isPromising(int row);
void printNQueen();

bool flag = false;
int col[MAX_SIZE];
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" , stdin);

    int testCase = 0 ;
    cin >> testCase;
    while(testCase--) {
        cin >> N;
        flag = false;
        for (int i = 0; i < MAX_SIZE; i++) {
            col[i] = 0;
        }
        for(int i = 0; i < N; i++) {
            if (flag == false) {
                col[0] = i;
                NQueen(0);
            }
            else {
                break;
            }
        }
    }
}

void NQueen(int row) {
    int i = 0;
    if (isPromising(row) && flag == false) {
        if (row == N-1) {
            printNQueen();
        }
        else if (row < N-1){
            for (i = 0; i < N; i++) {
                col[row+1] = i;
                NQueen(row+1);
            }
        }
    }
}

int isPromising(int row) {
    int k = 0;
    int promising = 1;

    while(k<row && promising) {
        if(col[row] == col[k] || abs(col[row]-col[k]) == row-k){
            promising = 0;
        }
        k++;
    }
    return promising;
}

void printNQueen() {
    if (flag == false) {
        for (int i = 0; i < N; i++) {
            cout << col[i]+1 << " ";
        }
        cout << endl;
        flag = true;
    }
}