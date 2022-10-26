#include <iostream>

using namespace std;

void buildArr(int *arr, int sz);
int secondMax(int *arr, int start, int end, int &sMax);

int Max;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;
    while(testCase--){
        int size = 0;
        cin >> size ;
        Max = 0;
        int sMax = 0;
        int *arr = new int[size];
        buildArr(arr,size);
        secondMax(arr,0,size-1,sMax);
        cout<< sMax << "\n";

    }

    return 0;

}

void buildArr(int *arr, int sz){
    for(int i=0; i<sz; i++){
        cin >> arr[i];
    }
}

int secondMax(int *arr, int start, int end, int &sMax){
    if(start>=end)
        return arr[start];
    else{
        int mid = (start+end)/2;
        int left = secondMax(arr,start,mid,sMax);
        int right = secondMax(arr,mid+1,end,sMax);
        int ltmp = 0;
        int rtmp = 0;
        if(left <right){
            rtmp = right;
        }
        else{
            ltmp=left;
        }
        if(Max<ltmp){
            Max = ltmp;
            if(sMax < right)
                sMax = right;
        }
        else{
            Max = rtmp;
            if(sMax <left)
                sMax = left;
        }
    }
    return Max;
}