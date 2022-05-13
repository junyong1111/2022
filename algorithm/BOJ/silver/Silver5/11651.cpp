#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct {
    int x;
    int y;
}point;

bool compare(const point &a, const point &b){
    if(a.y < b.y){
        return true; // y를 기준으로 오름차순 정렬
    }
    else if(a.y == b.y){
        return a.x < b.x; //y가 같다면 x를 기준으로 오름차순 정렬
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;
    int N = testCase;
    vector<point>ans(testCase);
    int idx = 0;
    while(testCase--){
        int x, y;
        cin >> x >> y;
        ans[idx].x = x;
        ans[idx++].y = y;
    } //testCase
    stable_sort(ans.begin(), ans.end(), compare);

    for(int i=0; i<N; i++){
        cout << ans[i].x << " " << ans[i].y << "\n";
    }
    return 0;
}
