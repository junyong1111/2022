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