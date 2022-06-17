#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Student = 0 ;
    cin >> Student;

    vector<int>ans(Student);
        
    for(int i=1; i<=Student; i++){
        int com = 0;
        cin >> com;    
        ans.insert(ans.begin()+com, i);
    }
    // 주어진 위치에 insert

    for(int i = Student-1; i>=0; i--)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}