#include <stdio.h>
#include <stdlib.h>

void Hanoi(int n, char from, char temp, char to){
    if(n==1) printf("Disk:%d Move from %c → to %c", from , to); // 원반이 1개 남았으면 시작 → 목적지로 보내기
    Hanoi(n-1, from, to, temp); // 시작 위치에서 임시 기둥으로 n-1개를 옮기기
    printf("Disk:%d Move from %c → to %c", from, to); // 제일 큰 원반을 시작 → 목적지로 보내기
    Hanoi(n-1, temp, from, to); // 임시에 옮겨놨던 n-1개의 원반을 목적지로 보내기
}


int main(){
    int n = 0;
    scanf("%d",&n);
    char from = 'A' ;
    char temp = 'B';
    char to = 'C';
    Hanoi(n, from ,temp, to);

    return 0;
}