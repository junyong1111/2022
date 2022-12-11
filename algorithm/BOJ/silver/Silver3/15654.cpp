#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 9
#define MAX_SIZE 10001

using namespace std;

int arr[MAX];
bool isUsed[MAX_SIZE];

void NandM5(vector<int>&v, int k, int n, int m);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int N = 0;
    int M = 0;
    cin >> N >> M;
    vector<int>v(N, 0);
    for(int i=0; i<N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    NandM5(v, 0, N, M);

    return 0;
}

void NandM5(vector<int>&v, int k, int n, int m)
{
    if(k==m){
        for(int i=0; i<m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return ;
    }
    for(int i=0; i<n; i++){
        if(isUsed[v[i]] == false){
            arr[k] = v[i];
            isUsed[v[i]] = true;
            NandM5(v, k+1, n, m);
            isUsed[v[i]] = false;
        }
    }
}