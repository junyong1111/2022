// 백준(4344) 평균은 넘겠지
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int testcase ;
    float mean = 0;
    int cnt = 0;
    scanf("%d", &testcase);

    for(int i=0; i<testcase; i++){
        int student = 0;
        cnt = 0;
        mean = 0;
        scanf("%d", &student);
        int arr[student];
        for(int j=0; j<student; j++){
            scanf("%d", &arr[j]);
            mean += arr[j];
        }
        mean = mean/student;
        for(int j=0; j<student; j++){
            if(mean <arr[j])
                cnt ++;      
        } // for_jj
        mean = (float)cnt / student;
        mean = mean * 100;
        printf("%.3f%%\n", mean);
    } //for_i

    return 0;
}