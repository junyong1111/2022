// 백준(1157) 단어 공부
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 1000000
int main(){
    int len = 0;
    char str[MAX_SIZE];
    int alpha[26] = {0};
    int temp = 0;
    int max = 0;
    char ans[1];
    int cnt = 0;
    
    scanf("%s", str);
    len = strlen(str);
    for(int i=0; i<len; i++)
        if (str[i] >= 65 && str[i] <= 90) { str[i] = str[i] + 32; } //대문자를 소문자로
    for(int i=0; i<len; i++){
        temp = str[i]-97;
        alpha[temp]++;
    } // 각 알파벳이 나온 빈도 체크
    for(int i=0; i<26; i++){
        if(max <= alpha[i]) {
            max = alpha[i];
            ans[0] = i+97;
        } //가장 많이 나온 알파벳 체크
    }
    for(int i=0; i<26; i++){
        if(max == alpha[i]) {cnt++;}  // 최대가 중복이면 ?출력
    }
    if(cnt >1){ printf("?\n");}
    else{
        printf("%c\n", ans[0]-32);
    } //그게 아닐경우 대문자 출력
    return 0;
}