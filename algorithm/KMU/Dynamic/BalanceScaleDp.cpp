#include <iostream>

#define MAX_SIZE 10000000
#define INF 2100000000
#define ABS(a) ((a)<0?(a*-1):(a))

using namespace std;
void init();
void BuildArray(int *Arr, int size);
int BlackScale(int N);

int DP[MAX_SIZE];
int masses[7] = {100,50,20,10,5,2,1};

int main(){
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;
    
    init();
    while(testCase--){
        int size = 0;
        cin >> size;
        int *Arr = new int[size];
        BuildArray(Arr,size);

        int stack1 = Arr[0];
        int stack2 = Arr[1];

        for(int i=2; i<size; i++){
            if(stack1 == stack2)
                stack1 += Arr[i];
            else if(stack1<stack2)
                stack1+= Arr[i];
            else
                stack2 += Arr[i];
        }
        

        int diff = stack1 - stack2;
        diff = ABS(diff);

        cout << BlackScale(diff) <<"\n";

    }
    return 0;
}

void BuildArray(int *Arr, int size){
    for(int i=0; i<size; i++)
        cin >> Arr[i];
}

int BlackScale(int N){
    if(N<0)
        return INF;
    if(N==0)
        return 0;
    if(DP[N]!=0)
        return DP[N];
    
    int min = INF;
    for(int i=0; i<7; i++){
        int temp = BlackScale(N-masses[i]);
        if(temp < min){
            min = temp;
        }
    }
    DP[N] = min+1;
    return DP[N];
    
}

void init(){
    for(int i=0; i<7; i++){
        DP[masses[i]] = 1;   
    }
}