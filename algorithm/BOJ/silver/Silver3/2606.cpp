#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void DFS(vector<int>Graph[], vector<int> &Virus, stack<int> &S, int Start, int &cnt);
void Print(vector<int>Grpah[], int N);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);

    int numOfcumputer = 0;
    int numOfEdge = 0;

    cin >> numOfcumputer >> numOfEdge ;
    vector<int>Graph[numOfcumputer+1]; //0 버림
    vector<int>Virus(numOfcumputer+1, 0);
    
    for(int i=0; i<numOfEdge; i++){
        int A,B = 0;
        cin >> A >> B;
        Graph[A].push_back(B);
        Graph[B].push_back(A);
    }

    for(int i=1; i<numOfcumputer; i++)
        stable_sort(Graph[i].begin(), Graph[i].end());

    stack<int>S;
    S.push(1);
    int cnt = 0 ;
    

    DFS(Graph,Virus, S,1,cnt) ;
    cout << cnt-1 << "\n";
    // Print(Graph, numOfcumputer);

    return 0;
}

void DFS(vector<int>Graph[],vector<int> &Virus, stack<int> &S, int Start, int &cnt){
    if(!S.empty()){
        cnt++;
        Virus[Start] = 1;
        S.pop();

        for(vector<int>::iterator it = Graph[Start].begin(); it != Graph[Start].end(); it++){
            if(Virus[*it] == 0){ //바이러스 감염이 안된경우
                S.push(*it);
                // cout << "Cnt is " << cnt << "  "  << "index is "  << *it << "\n";
                DFS(Graph, Virus, S, *it, cnt);
            }
        }
    }
}

void Print(vector<int>Grpah[], int N){
    for(int i=1; i<=N; i++){
        cout << i << ": ";
        for(vector<int>::iterator it = Grpah[i].begin(); it != Grpah[i].end(); it++)
            cout << *it << "--->";
        cout << "\n";  
    }
}