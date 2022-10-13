#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" , stdin);

    vector<string>V(8);
    V[0] = "c=";
    V[1] = "c-";
    V[2] = "dz=";
    V[3] = "d-";
    V[4] = "lj";
    V[5] = "nj";
    V[6] = "s=";
    V[7] = "z=";

    string alpha;
    cin >> alpha;
    int idx =0 ;
    // ljes=njak
    for(int i = 0; i < V.size(); i++)
    {
        while(1){
            idx = alpha.find(V[i]);
            if(idx == string::npos)
                break;
            alpha.replace(idx,V[i].length(),"#");
        }
    }
    cout << alpha.length();

    return 0;
}