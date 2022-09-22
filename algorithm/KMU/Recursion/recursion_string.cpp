#include <iostream>

using namespace std;

void recursion_string(char *ch, int start, int end);
int len(char *ch);
void swap(char *ch, int a, int b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt","r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        char *ch = new char;
        cin >> ch ;
        int size = len(ch);

        recursion_string(ch,0,size-1);
        cout << ch << "\n";
    }

    return 0;
}

int len(char *ch){
    char * temp = ch;
    int cnt = 0;
    while(*temp !=0){
        temp ++;
        cnt ++;
    }
    return cnt;
}

void recursion_string(char *ch, int start , int end){
    if(start<end){
        swap(ch, start, end);
        start++;
        end--;
        recursion_string(ch,start, end);
    }
}

void swap(char *ch, int a, int b){
    char temp = ch[a];
    ch[a] = ch[b];
    ch[b] = temp;
}