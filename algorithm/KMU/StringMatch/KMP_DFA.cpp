#include <iostream>
#include <string>
using namespace std;

void constructDFA(string pat, int dfa[3][1001]){
  int pat_len = pat.size();
 
  if(pat[0] == 'A')
    pat[0] = 0;
  else if(pat[0] == 'B')
    pat[0] = 1;
  else
    pat[0] = 2;

  dfa[pat[0]][0] = 1;
  int x, j;
  for (x = 0, j = 1; j < pat_len; j++)
  {
    for (int c = 0; c < 3; c++)
      dfa[c][j] = dfa[c][x];
    
    if(pat[j] == 'A')
      pat[j] = 0;
    else if(pat[j] == 'B')
      pat[j] = 1;
    else
      pat[j] = 2;
    
    dfa[pat[j]][j] = j + 1;
    x = dfa[pat[j]][x];
  }
  for(int c = 0; c < 3; c++)
    dfa[c][j] = dfa[c][x];  
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("input.txt", "r" ,stdin);

  int testcase = 0;
  cin >> testcase;


  for (int i = 0; i < testcase; i++)
  {
    string pattern, text;
    cin >> pattern >> text;
    int DFA[3][1001] = {0};

    constructDFA(pattern, DFA);
    int cnt = 0;
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k <= pattern.size(); k++)
      {
        if(DFA[j][k] != 0)
          cnt++;
      }
    }
    

    int answer = 0;
    int state = 0;
    for (int j = 0; j < text.size(); j++)
    {
      if (text[j]== 'A')
        text[j] = 0;
      else if (text[j] == 'B')
        text[j] = 1;
      else
        text[j] = 2;
      state = DFA[text[j]][state];

      if (state == pattern.size())
        answer++;
  }

    cout << cnt << " " << answer << "\n";
  }
  return 0;
}