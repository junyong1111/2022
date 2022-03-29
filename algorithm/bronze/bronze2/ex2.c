// 백준(1152) 단어의 개수

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000000

int main(void){
    int i, len;
    int cnt = 1;
    char str[MAX_SIZE]; 
    scanf("%[^\n]", str); 
    len = strlen(str);
    if(len == 1) { 
        if(str[0] == ' ') {
             printf("0\n"); 
             return 0; 
        } 
    } 
    for(i = 1; i < len-1; i++) { 
        if(str[i] == ' ') 
        cnt++; 
    } 
    printf("%d\n", cnt); 
    return 0; 
    }