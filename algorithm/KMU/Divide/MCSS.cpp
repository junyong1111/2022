#include <iostream>
#define MIN_VALUE -2100000000
#define MAX(a,b) (a<b?b:a)

using namespace std;

void buildArray(int *Arr, int size);
void checkArray(int *Arr, int size);
int MCSS(int *Arr, int start , int end);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int size = 0;
        cin >> size;
        int *Arr = new int;
        buildArray(Arr, size);
        int maxSum = MCSS(Arr,0,size-1);
        if(maxSum<0)
            cout << 0 << "\n";
        else
            cout << maxSum << "\n";
        // MCSS(Arr,0,size-1);
        // checkArray(Arr,size);
    }


    return 0;
}

int MCSS(int *Arr, int start , int end){
    if(start>=end)
        return Arr[start];
    else{
        int mid = (start+end)/2;
        int sum = 0;
        int leftMax = MIN_VALUE;
        
        for(int i=mid; i>=start; i--){
            sum += Arr[i];
            leftMax = MAX(leftMax, sum); 
        }
        // cout << "leftMax is " << leftMax << " ";
        sum = 0;
        int rightMax = MIN_VALUE;
        for(int i=mid+1; i<=end; i++){
            sum += Arr[i];
            rightMax = MAX(rightMax,sum);
        }
        // cout << "rightMax is " << rightMax << " ";

        int Max = MAX(MCSS(Arr,start,mid), MCSS(Arr,mid+1, end));
        // cout << "max is " <<  Max << " ";
        return MAX(leftMax+rightMax , Max);
    }
}

void buildArray(int *Arr, int size){
    for(int i=0; i<size; i++)
        cin >> Arr[i];
}

void checkArray(int *Arr, int size){
    for(int i=0; i<size; i++)
        cout << Arr[i] << " ";
    cout <<"\n";
}
