#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    queue<int>Q;
    vector<int>V;

    int N,K = 0;
    cin >> N >> K;
    vector<int>visit(N+1, 0);
    K--;
    int idx = K;    
    for(int i=1; i<=N; i++)
        V.push_back(i);
    if(N==1){Q.push(1); }
    else{
        Q.push(V[idx]);
        visit[idx+1] = 1;
        V.erase(V.begin()+idx);
        
        while(V.size()!=0){
            idx = (idx+K)%V.size();
            if(visit[V[idx]]==0){
                visit[V[idx]]=1;
                Q.push(V[idx]);
                V.erase(V.begin()+idx);
            }
        }
    }
    
    cout << "<";
    while(!Q.empty()){
        if(Q.size()==1){
            cout << Q.front();    
            Q.pop();
        }
        else{
            cout << Q.front() << ", ";
            Q.pop();
        }
    }
    cout << ">\n";
    
    return 0;
}