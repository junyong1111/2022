#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int>ans;
    while(N!=0){
        ans.push_back(N%10);
        N = N/10;
    }
    // 입력받은 정수의 자리수를 벡터에 담아준다. 
    sort(ans.rbegin(), ans.rend()); //내림차순으로 정렬
    vector<int>:: iterator it = ans.begin();

    for(; it!=ans.end(); it++){
        cout << *it;
    } //정렬된 값 출력
    return 0;
}