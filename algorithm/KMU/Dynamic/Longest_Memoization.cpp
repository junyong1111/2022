#include <iostream>
#define MAX_SIZE 101
#define MAX(a,b) ((a)>(b)?(a):(b))

int L[MAX_SIZE][MAX_SIZE];

using namespace std;

int Len(char *str);
int LCS_Memoization(char *str1, char *str2, int M, int N);
void init();

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
        init();
        int answer = LCS_Memoization(str1,str2,M,N);
        cout << answer << "\n";
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

int LCS_Memoization(char *str1, char *str2, int M, int N){
    if(M==0 || N==0)
        return 0;
    if(L[M-1][N-1]!=-1)
        return L[M-1][N-1];
    else{
        if((M>0 && N>0) && (str1[M-1]) == (str2[N-1])){
            L[M-1][N-1] = (LCS_Memoization(str1,str2, M-1, N-1))+1;
            return L[M-1][N-1];
        }
            
        else if((M>0 && N>0) && (str1[M-1]) != (str2[N-1])) {
            int left = LCS_Memoization(str1,str2,M,N-1);
            int right = LCS_Memoization(str1,str2,M-1,N);
            int max = MAX(left, right);
            L[M-1][N-1] = max;
            return L[M-1][N-1];
        }
        else
            return 0;
    }
    
}


void init(){
    for(int i=0; i<MAX_SIZE; i++){
        for(int j=0; j<MAX_SIZE; j++){
            L[i][j] = -1;
        }
    }
}