#include <iostream>
#define MAX_SIZE 101
#define MAX(a,b) ((a)>(b)?(a):(b))

int L[MAX_SIZE][MAX_SIZE];
int S[MAX_SIZE][MAX_SIZE];

using namespace std;

int Len(char *str);
int LCS_DP(char *str1, char *str2, int M, int N);
void printLCS(char *str1, char *str2,int M, int N);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt" , "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        char str1[MAX_SIZE];
        char str2[MAX_SIZE];
        cin >> str1 >> str2;
        int M = Len(str1);
        int N = Len(str2);
        int answer = LCS_DP(str1,str2,M,N);
        cout << answer << " "; 
        printLCS(str1,str2,M,N);
        cout <<"\n";
    }


    return 0;
}

int Len(char *str){
    int cnt = 0;
    char * temp = str;
    while(*temp!=0){
        cnt++;
        temp++;
    }
    return cnt;
}

int LCS_DP(char *str1, char *str2, int M, int N){
    for(int i=0; i<=M; i++)
        L[i][0] = 0;
    for(int i=0; i<=N; i++)
        L[0][i] = 0;
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            if(str1[i-1] == str2[j-1]){
                L[i][j] = L[i-1][j-1]+1; // 문자가 같으면 대각선 +1
                S[i][j] = 0;
            }
            else{
                L[i][j] = MAX(L[i][j-1], L[i-1][j]);  //다르면 왼쪽 오른쪽 중 큰거
                if(L[i][j] == L[i][j-1])
                    S[i][j] = 1;
                else
                    S[i][j] = 2;
            }
        }
    }
    return L[M][N];
}

void printLCS(char *str1, char *str2,int M, int N){
    if(M==0 || N==0)
        return;
    if(S[M][N] ==0){
        printLCS(str1, str2, M-1, N-1);
        cout << str1[M-1];
    }
    else if(S[M][N]==1)
        printLCS(str1, str2, M, N-1);
    else if(S[M][N]==2)
        printLCS(str1, str2, M-1, N);
}