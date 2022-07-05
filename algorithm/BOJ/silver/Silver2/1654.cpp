#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll K = 0;
    ll NeedK = 0;
    cin >> K  >> NeedK;
    vector<ll>LAN(K,0);

    for(int i=0; i<K; i++)
        cin >> LAN[i];
    stable_sort(LAN.begin(), LAN.end());

    ll low = 1;
    ll high = LAN[K-1];
    ll mid = 0;
    ll ans = 0;

    while(low <= high){
        mid = (low+high) /2;
        ll cnt = 0;
        for(int i=0; i<K; i++){
            cnt += LAN[i]/mid;
        }
        if(cnt >= NeedK){
            low = mid +1;
            if(ans < mid) ans = mid;
        }
        else{
            high = mid -1;
        }
    }

    cout << ans << "\n";

    return 0;
}