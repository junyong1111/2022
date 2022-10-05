#include <iostream>
using namespace std;

void bulidList(int *arr, int size);
void checkList(int *arr, int size);
int findingMax(int *arr, int start, int end);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;
    
    while(testCase--){
        int * arr = new int;
        int size = 0;
        cin >> size ;
        bulidList(arr,size);
        cout << findingMax(arr,0,size-1) <<"\n";
    }
    return 0;
}

void bulidList(int *arr, int size){
    for(int * temp = arr; temp<arr+size; temp++){
        int num = 0;
        cin >> num;
        *temp = num;
    }
}

void checkList(int *arr, int size){
    for(int * temp = arr; temp<arr+size; temp++){
        cout << *temp  << " ";
    }
    cout << "\n";
}

int findingMax(int *arr, int start,int end){
    if(start>=end)
        return arr[start];
    else{
        int mid = (start+end)/2;
        int left_max = findingMax(arr, start, mid);
        int right_max = findingMax(arr, mid+1, end);
        return left_max<right_max?right_max:left_max;
    }
}