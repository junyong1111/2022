// 백준(2753) 윤년

#include <stdio.h>
#include <stdlib.h>

int main(){
  int n ;
  scanf("%d", &n);
  if(n%4==0 && (n%100!=0 || n%400 ==0)){
      printf("%d\n",1);
  }
  else printf("%d\n",0);

  return 0;
}