#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 1000001

using namespace std;

void Init(vector<int> &arr );

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;
    vector<int>Note(MAX_SIZE,0);
    while(testCase--){
        int n = 0;
        cin >> n;
        for(int i=0; i<n; i++){
            int idx = 0;
            cin >> idx ;
            Note[idx-1] ++;
        }
        int m = 0;
        cin >> m;
        for(int i=0; i<m; i++){
            int idx = 0;
            cin >> idx;
            if(Note[idx-1]!=0){
                Note[idx-1]--;
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        Init(Note);
    }

    return 0;
}
void Init(vector<int> &arr ){
    for(int i=0; i<MAX_SIZE; i++){
        arr[i] = 0;
    }
}