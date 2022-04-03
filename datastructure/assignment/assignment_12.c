#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct
{
    char data[SIZE];
    int top;
}StackType;

void init(StackType * S)
{   
    S->top = -1; //배열이 아닌 배열의 밖을 지정해주는 행위
}

int isEmpty(StackType * S)
{
    return S->top == -1; //비었는지 안 비었는지 리턴
}

int isFull(StackType * S)
{
    return S->top == SIZE-1; // 꽉 차있는지 
}

void push(StackType * S, char elem)
{
    if(isFull(S))
        printf("Overflow!!\n");
     // 여기서는 주소연산자를 사용 안함 이미 주소를 받았기 때문에
    else
        S->top++;
        S->data[S->top] = elem;
    
}

char pop(StackType * S)
{
    if(isEmpty(S))
       { printf("Empty!!\n");
        return -1;
       }
    char elem = S->data[S->top];
    S->top--;
	//printf("elem is %c\n" , elem);
    return elem;
} //값을 리턴하고 제거

char peek(StackType * S)
{
    if(isEmpty(S))
       { printf("Empty!!\n");
        return -1;
       }
    return S->data[S->top];
} //값만 리턴

void print(StackType * S)
{
    for(int i=0; i<=S->top; i++){
        printf("%c ", S->data[i]);
    }
    printf("\n");
}


int main(){
	char str[100];
	char temp = 0;
	int cnt = 1;
	scanf("%s", str);
    StackType S1;
    StackType S2;
	init(&S1);
    init(&S2);
	
	int len = strlen(str);
    for(int i=0; i<len; i++){
		if(str[i] >64 && str[i]<97)
			str[i] = str[i] + 32;
		push(&S1, str[i]);
    }
	temp = pop(&S1);
	for(int i=1; i<len; i++){
		if(temp == peek(&S1)){
			cnt ++;
			pop(&S1);
		}
		else{
			push(&S2, temp);
			push(&S2, cnt+'0');
			temp = pop(&S1);
			cnt = 1;
		}
	}
	push(&S2, temp);
	push(&S2, cnt+'0');

	while(isEmpty(&S2) !=1 ){
        printf("%c",pop(&S2));
    }
	printf("\n");
	return 0;
}