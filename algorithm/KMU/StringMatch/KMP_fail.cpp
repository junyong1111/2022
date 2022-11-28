#include <iostream>
#include <vector>
#define MAX_SZIE 1000

using namespace std;

int *getFail(char *pattern, int len);
vector<int>kmp(char *text, char *pattern);
int stringLen(char *str);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;
    
    while(testCase--){
        char str1[MAX_SZIE];
        char str2[MAX_SZIE];
        cin >> str1 >> str2; 

        vector<int>Answer = kmp(str2,str1);
        
        cout << Answer.size() <<"\n";
        
    }
    return 0;
}

int *getFail(char *pattern,int len){
    char *temp = pattern;
    while(*temp!=0){
        len ++;
        temp++;
    }

    int j=0;
    int * fail = new int[len];
    for(int i=0; i<len; i++)
        fail[i] = 0;
    
    for(int i = 1; i< len ; i++)
    {
        while(j > 0 && pattern[i] != pattern[j])
            j = fail[j-1];
        if(pattern[i] == pattern[j])
            fail[i] = ++j; 
    }   
    
    return fail;
}

vector<int> kmp(char *text, char *pattern)
{
    vector<int>ans;
    int textlen = stringLen(text);
    int patternlen = stringLen(pattern);
    int *fail = getFail(pattern, patternlen); // failure function

    for(int i=0; i<patternlen; i++){
        cout << fail[i] << " ";
    }
    cout << "\n";

    int j =0; // j : index of pattern

    for(int i=0; i< textlen; i++) //i:indexoftext
    {
        while(j>0 && (text[i] != pattern[j]))
            j = fail[j-1];
        if(text[i] == pattern[j])
        {
            if(j==(patternlen-1))              // pattern matching is found
            {
                ans.push_back(i-j);
                j = fail[j]; 
            }
            else
                j++;
        }
    }
    return ans; 
}

int stringLen(char *str)
{
    char * temp = str;
    int len = 0;
    while(*temp!=0){
        temp ++;
        len ++;
    }
    return len;
}