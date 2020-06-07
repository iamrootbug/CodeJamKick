#include <bits/stdc++.h>
using namespace std;
int B;
void solve(){
  string ans; 
  cout << ans << endl;

  
  
  string res;
  cin >> res;
  if(res == "N"){
    cerr << "ERROR" << endl;
  }else{
    cerr << "DONE" << endl;
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t = 1;
  cin >> t >> B;
  cerr << t << " " << B << endl;
  for(int i = 1; i<=t; i++){
    //cout << "Case #" << i << ": ";
    solve();
  } 
}
