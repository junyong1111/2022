#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    string light;
    cin >> light;
    int answer = 0;
    int len = light.length();

    for(int i=1; i<=len; i++)
    {
        if(light[i-1] == 'Y'){
            answer ++;
            for(int j= i; j<= len; j = j+i)
            {
                if(light[j-1] == 'Y')
                    light[j-1] = 'N';
                else
                    light[j-1] = 'Y';
            }
        }
    }
    cout << answer << "\n";
    return 0;
}