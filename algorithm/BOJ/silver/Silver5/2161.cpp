#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    
    int N = 0;
    cin >> N;

    queue<int>Q;

    vector<int>V;
    for(int i=1; i<=N; i++)
        Q.push(i);
    while(Q.size() !=1){
       V.push_back(Q.front());
       Q.pop();
       int temp = Q.front();
       Q.pop();
       Q.push(temp);
    }
    for(auto v : V){
        cout << v << " ";
    }
    cout << Q.front() <<"\n";
    

    return 0;
}