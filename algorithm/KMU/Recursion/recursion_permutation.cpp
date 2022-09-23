#include <iostream>

using namespace std;

int ord(char *ch, int size);
int len(char *ch);
void swap(char *ch, int a, int b);
void recursion_permutation(char *ch, int begin, int end);

int cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        char *ch = new char;
        cin >> ch ;
        int size = len(ch);
        recursion_permutation(ch,0,size);
        cout << cnt << "\n";
        cnt = 0;
    }


    return 0;
}

void recursion_permutation(char *ch, int begin, int end){
    int range = end -begin;

    if(range==1){
        if(ord(ch,end) >0){
            cnt++;
        }
    }
    else{
        for(int i=0; i<range; i++){
            swap(ch,begin, begin+i); // swap
            recursion_permutation(ch,begin+1, end); 
            swap(ch,begin, begin+i); // swap했던 스트링 복구
        }
    }
}

int ord(char *ch, int size){
    bool check = true;
    int sum = 0;
    for(int i=0; i<size; i++){
        int temp = ch[i]-97;
        if(!check){
            temp = temp * -1;
        }
        if(check){check = false;}
        else{check = true;}
        sum += temp;
    }
    return sum;
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


void swap(char *ch, int a, int b){
    char temp = ch[a];
    ch[a] = ch[b];
    ch[b] = temp;
}