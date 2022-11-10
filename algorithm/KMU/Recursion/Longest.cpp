#include <iostream>
#include <string>

using namespace std;

int LCS_Recursion(char *str1, char *str2, int M, int N);
int Len(char *str);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;
    
    while(testCase--){
        char str1[10];
        char str2[10];
        cin >> str1 >> str2;
        int M = Len(str1);
        int N = Len(str2);
        int answer = LCS_Recursion(str1, str2, M-1,N-1);
        cout << answer << "\n";
    }

    return 0;
}

int LCS_Recursion(char *str1, char *str2, int M, int N){
    if(M==0 || N==0)
        return 0;
    else{
        if((M>0 && N>0) && (str1[M]) == (str2[N]))
            return LCS_Recursion(str1,str2, M-1, N-1);
        else {
            
        }
        
    }
    
    
    
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