#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void VectorP(vector<vector<int> >V, int N, int M);


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin );

    int N = 0;
    int M = 0;
    cin >> N >> M;

    vector<vector<int> >V(N, vector<int>(M,0));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> V[i][j];
        }
    }

    int addCount = 0;
    int X = 0;
    int Y = 0;
    cin >> addCount;

    for(int i=0; i<addCount; i++){
        cin >> N >> M >> X >> Y ;
        int sum = 0;
        for(int j=N-1; j<=X-1; j++){
            for(int k=M-1; k<=Y-1; k++){
                sum += V[j][k];
            }
        }
        cout << sum  << "\n";
    }



   
}   


void VectorP(vector<vector<int> >V, int N, int M){
    for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cout << V[i][j] << " ";
            }
            cout << "\n";
        }
}