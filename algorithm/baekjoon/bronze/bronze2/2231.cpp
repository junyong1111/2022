#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int Sum(int n)
{
    int sum = n;
    while(n!=0)
    {
        sum += n%10;
        n = n/10;
    }
    return sum;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int>answer;
    bool check = false;
    int n ;
    cin >> n;
    for(int i=2; i<n; i++)
    {
        int temp = Sum(i);
        if(temp == n)
            {
                answer.push_back(i);
                check = true;
            }
    }
    if(check == true)
    {
        sort(answer.begin(), answer.end());
        cout << answer[0] <<"\n";
    }
    else
        cout << 0 << "\n";
    return 0;
}
