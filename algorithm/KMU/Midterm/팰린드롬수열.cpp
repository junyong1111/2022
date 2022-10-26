#include <iostream>

using namespace std;

void buildArr(int *arr, int sz);
int Rec(int *arr, int start, int end);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int size = 0;
        cin >> size ;
        int *arr = new int[size];
        buildArr(arr,size);
        cout << Rec(arr,0,size-1) <<"\n";



    }

    return 0;
}

void buildArr(int *arr, int sz){
    for(int i=0; i<sz; i++){
        cin >> arr[i];
    }
}

int Rec(int *arr, int start, int end){
    if(start<end){
        if(arr[start] == arr[end]){
            return Rec(arr,start+1, end-1);
        }
        else{
            return 0;
        }
    }
    return 1;
}