// 백준(1550) 16진수

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    int answer = 0;
    char *ch = malloc(6);
    scanf("%s", ch);
    if(*ch == 'A'){
        answer = 10;
    }
    else if(*ch == 'B'){
        answer = 11;
    }
    else if(*ch == 'C'){
        answer = 12;
    }
    else if (*ch == 'D'){
        answer = 13;
    }
    else if (*ch == 'E'){
        answer = 14;
    }
    else if (*ch == 'F'){
        answer = 15;
    }
    else {
        answer = atoi(ch);
    }
    printf("%d\n", answer);
    
    return 0;
}


/* c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

int main(){
    string str;
    vector<int>ans;
    vector<int>:: iterator it = ans.begin();
    cin >> str;
    //-48
    int len = str.length();

    for(int i=0; i<len; i++){
        if(str[i]>=48 && str[i]<=57)
        {
            ans.push_back(str[i] - 48);
        }
        else if(str[i]>=65 && str[i]<=70){
            ans.push_back(str[i]-55);
        }
        else{
            return -1;
        }
    }
    int sum = 0;
    for(it = ans.begin(); it!=ans.end(); it++)
    {
        sum = sum *16;
        sum = sum + *it;
    }
    cout << sum;
    return 0;
}


*/