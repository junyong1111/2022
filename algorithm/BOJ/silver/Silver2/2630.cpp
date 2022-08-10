#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int Blue;
int White;

void print(vector<vector<int> >&Map, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << Map[i][j] <<" ";
        }
        cout <<"\n";
    }
} //확인용 


bool findMap(vector<vector<int> >&Map){
    if(Map.size()==1){return true;}
    int check = Map[0][0];
    for(int i=0; i<Map.size(); i++){
        for(int j=0; j<Map[i].size(); j++){
            if(check != Map[i][j]){return false;}
        }
    }
    return true;
} //모두 정사각형이 같은 색이면 1 아니면 0


void makeMap(vector<vector<int> >&Map){
    if(findMap(Map)!=1){
        int SZ = Map.size()/2;
        // 정사각형이므로 size/2만 해준다.

        vector<vector<int> >New_A(SZ, vector<int>(SZ, 0));
        vector<vector<int> >New_B(SZ, vector<int>(SZ, 0));
        vector<vector<int> >New_C(SZ, vector<int>(SZ, 0));
        vector<vector<int> >New_D(SZ, vector<int>(SZ, 0));

        //4등분 하므로 4개의 벡터 생성

        for(int i=0; i<SZ; i++){
            for(int j=0; j<SZ; j++){
                New_A[i][j] = Map[i][j];
            }
        } //1
        int x = 0;
        int y = 0;
        for(int i=0; i<SZ; i++){
            x = 0;
            for(int j=SZ; j<Map.size(); j++){
                New_B[i][x++] = Map[i][j];
            }
        } //2

        for(int i=SZ; i<Map.size(); i++){
            for(int j=0; j<SZ; j++){
                New_C[y][j] = Map[i][j];
            }
            y++;
        }//3
        x = 0;
        y = 0;
        for(int i=SZ; i<Map.size(); i++){
            x = 0;
            for(int j=SZ; j<Map.size(); j++){
                New_D[y][x++] = Map[i][j];
            }
            y++;
        }
        // 4등분한 정사각형 벡터에 각각의 값들을 삽입

        makeMap(New_A);
        makeMap(New_B);
        makeMap(New_C);
        makeMap(New_D);
        // 4등분한 정사각형을 다시 찾음

    } //if
    else{
        if(Map[0][0] ==1){Blue++;}
        else{White++;}
        // 만약에 같은 색으로 나눠졌다면 
        // 1이면 파란색이므로 파란색 1추가
        // 0이면 하얀색이므로 하얀색 1추가
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int N = 0;
    cin >> N;
    vector<vector<int> >Map(N, vector<int>(N,0));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> Map[i][j];
    makeMap(Map);

    cout << White <<"\n" << Blue ;
    return 0;

}
