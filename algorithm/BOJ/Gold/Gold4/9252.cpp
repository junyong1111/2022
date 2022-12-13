#include <iostream>
#define MAX_SIZE 1001
#define MAX(a,b) ((a)>(b)?(a):(b))

using namespace std;

int L[MAX_SIZE][MAX_SIZE];
// str1 == str2이 같다면 대각선에서 
// str != str2이 다르다면 왼쪽과 위쪽 둘 중 더 큰값

int S[MAX_SIZE][MAX_SIZE];
// 0 => 왼쪽 대각
// 1 => 왼쪽
// 2 => 위
// 문자가 올 수 있는 위치 => 왼쪽 대각, 왼쪽, 위쪽

void LcsPrint(char *str1, char *str2, int n, int m);
int Len(char *str1);
int LCS2(char *str1, char *str2, int n, int m);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    char * str1 = new char[MAX_SIZE];
    char * str2 = new char[MAX_SIZE];
    cin >> str1 >> str2;

    int str1Len = Len(str1);
    int str2Len = Len(str2);

    // cout << str1Len << " " << str2Len << "\n";    
    int answerNum = 0;
    answerNum = LCS2(str1, str2, str1Len, str2Len);
    cout << answerNum << "\n";
    LcsPrint(str1, str2, str1Len, str2Len);
    cout <<"\n";

    return 0;
}

int LCS2(char * str1, char * str2, int n, int m)
{
    for(int i=0; i<=n; i++)
        L[i][0] = 0;
    for(int j=0; j<=m; j++)
        L[0][j] = 0;

    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)
        {
            if(str1[i-1] == str2[j-1]){
                L[i][j] = L[i-1][j-1] +1;
                S[i][j] = 0;
            }
            else
            {
                L[i][j] = MAX(L[i][j-1], L[i-1][j]); //왼쪽과 위 중 더 큰 값
                if(L[i][j] == L[i][j-1])  // 만약 왼쪽에서 온 경우 1
                    S[i][j] = 1;
                else 
                    S[i][j] = 2;
            }
        }
    }
    return L[n][m];
}

int Len(char *str1)
{
    char * temp = str1;
    int cnt = 0;
    while(*temp!=0)
    {
        temp ++;
        cnt++;
    }
    return cnt;
}
void LcsPrint(char *str1, char *str2, int n, int m)
{
    if(n==0 || m ==0)
        return;
    if(S[n][m] == 0) // 문자가 같았던 경우 다시 대각선으로 올라감
    {
        LcsPrint(str1, str2, n-1, m-1);
        cout << str1[n-1] ;
    }
    else if(S[n][m]==1) // left
        LcsPrint(str1, str2, n, m-1);
    else
        LcsPrint(str1, str2, n-1, m);
}