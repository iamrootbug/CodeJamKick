#include <bits/stdc++.h>
using namespace std;
void solve(){
  int N, P;
  cin >> N >> P;
  vector<int> n(N);
  for(int i=0; i<N; i++)
    cin >> n[i];
  sort(n.begin(), n.end(), [](int a, int b){return a>b;});
  vector<int> s(N,0);
  s[0] = n[0];
  for(int i=1; i<N; i++)
    s[i] = s[i-1]+n[i];
  int mini = 987654321;
  for(int i=0; i+P-1<N; i++){
    int cur = P*n[i]-(i>0 ? s[i+P-1]-s[i-1] : s[i+P-1]);
    mini = min(mini, cur);
  }
  cout << mini << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  cin >> t;
  for(int i = 1; i<=t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }
}
