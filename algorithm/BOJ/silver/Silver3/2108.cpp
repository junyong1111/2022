#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

void fun1(vector<int>&A, int size);
void fun2(vector<int>&A, int size);
void fun3(vector<int>&A, int size);
void fun4(vector<int>&A, int size);

typedef struct Dic
{
    int Cnt;
    int Num;
}Dic;

vector<Dic>V(500001);

bool com(const Dic &a, const Dic &b){
    if (a.Cnt > b.Cnt)
        return true;
    else if(a.Cnt == b.Cnt)
        return a.Num <= b.Num;
    return false;
}

int main(){
    // freopen("input.txt", "r", stdin);
    int testCase = 0;
    scanf("%d", &testCase);

    vector<int>A(testCase, 0);
    for(int i=0; i<testCase; i++)
        scanf("%d", &A[i]);
    stable_sort(A.begin(), A.end());

    fun1(A,testCase);
    fun2(A,testCase);
    fun3(A,testCase);
    fun4(A,testCase);
    return 0;
}

void fun1(vector<int>&A, int size){ //산술평균
    double mean = 0; // float 보다 double이 정확도가 높다..
    for(int i=0; i<size; i++)
        mean += A[i];
    if(round(mean/size) == -0){
            cout << 0 <<"\n";
}
    else
        cout << round(mean/size) <<"\n";
}

void fun2(vector<int>&A, int size){ // 중간값
    int mid = size/2;
    printf("%d\n", A[mid]);
}

void fun3(vector<int>&A, int size){ //최빈값
    for(int i=0; i<size; i++){

        if(A[i]<0){ //음수인경우 
            int temp = 4000 - A[i];  
            V[temp].Cnt += 1;   // 빈도수
            V[temp].Num = A[i]; // 인덱스
        }
        else{
            V[A[i]].Cnt += 1; //빈도 수 
            V[A[i]].Num = A[i];// 인덱스
        }
    }
    stable_sort(V.begin(), V.end(), com); // 가장 많이 나온 순서로 정렬 만약 같다면 인덱스값을 오름차순으로 정렬


    if(V[0].Cnt != V[1].Cnt)
        cout << V[0].Num <<"\n"; // 만약 최빈값이 중복이 없다면 바로 출력
        
    else 
        cout << V[1].Num <<"\n";   //중복이 있다면 2번째로 작은 수 출력    
}

void fun4(vector<int>&A, int size){
    int max = *max_element(A.begin(), A.end());
    int min = *min_element(A.begin(), A.end());
    int answer = max-min;

    cout << answer <<"\n";
}
