#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// 전체 합 - 두 명의 난쟁이 = 100을 찾는다.
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N =  9;
    int sum =  0;
    vector<int>ans(N,0);
    int del1 = 0;
    int del2 = 0;
    for(int i=0; i<N; i++){
        cin >> ans[i];
        sum = sum+ans[i];
    }     //모든 난쟁이의 합

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            int check = ans[i] + ans[j];
            if(((sum - check) == 100)){ //총합 - 두 명의 합 == 100인 Index를 찾아 인덱스를 저장 후 종료
                del1 = i;
                del2 = j;
                break;
            }
            }
        }
ans.erase(ans.begin() + del1); // 원소 삭제 
ans.erase(ans.begin() + del2-1); //위에서 한 번 삭제했으므로 길이가 1 줄어들었음
sort(ans.begin(), ans.end()); //오름차순 정렬
for(vector<int>::iterator it = ans.begin(); it!=ans.end(); it++){
    cout << *it <<"\n";
}
    return 0;
}