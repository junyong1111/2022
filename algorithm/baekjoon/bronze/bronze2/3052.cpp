#include <iostream>
#include <algorithm>
#include <vector>
#define N 10;

using namespace std;


int main(){

    int it = N;
    vector<int> arr;
    vector<int>::iterator iter = arr.begin();

    while(it!=0){
        int Number = 0;
        cin >> Number;
        arr.push_back(Number%42);
        it--;
    }
    sort(arr.begin(), arr.end()); //정렬
    arr.erase( unique(arr.begin(), arr.end() ), arr.end());// 중복값 제거 정렬 후 사용하여야 함
    cout << arr.size() << endl; // 벡터의 사이즈를 리턴

    

    return 0;
}
