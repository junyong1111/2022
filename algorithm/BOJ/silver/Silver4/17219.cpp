#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int N,M;
    cin >> N >> M;

    map<string ,string>Passward;

    for(int i=0; i<N; i++){
        string site;
        string pw;
        cin >> site >> pw;
        Passward.insert(make_pair(site, pw));
    }

    for(int i=0; i<M; i++){
        string site;
        cin >> site;
        cout << Passward[site] <<"\n"; 
    }
    return 0;
}