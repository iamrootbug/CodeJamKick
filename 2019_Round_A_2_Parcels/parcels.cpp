#include <bits/stdc++.h>

using namespace std;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
void solve(){
  int R, C;
  cin >> R >> C;
  vector<vector<int>> m(R,vector<int>(C,R+C+1));
  queue<vector<int>> q;
  for(int y=0; y<R; y++){
    string s; cin >> s;
    for(int x=0; x<C; x++){
      if(s[x]=='1') {m[y][x]=0; q.push({y,x});} 
    }
  }
  while(!q.empty()){
    int y = q.front()[0];
    int x = q.front()[1];
    q.pop();
    for(int i=0; i<4; i++){
      int ny = y+dy[i];
      int nx = x+dx[i];
      if(ny<0||ny>R-1||nx<0||nx>C-1) continue;
      if(m[y][x]+1<m[ny][nx]){
        m[ny][nx] = m[y][x]+1;
        q.push({ny,nx,m[ny][nx]});
      }
    }
  }
  auto GEA = [&](int d)->vector<int>{
    int Xmax = -R-C-1;
    int Xmin = R+C+1;
    int Ymax = -R-C-1;
    int Ymin = R+C+1;
    for(int y=0; y<R; y++){
      for(int x=0; x<C; x++){
        if(m[y][x]>d){
          Xmax = max(Xmax, x+y); 
          Xmin = min(Xmin, x+y); 
          Ymax = max(Ymax, x-y); 
          Ymin = min(Ymin, x-y); 
        }
      }
    }
    return {Xmax, Xmin, Ymax, Ymin};
  };
  auto check = [&](vector<int>& a, int d)->bool{
    for(int y=0; y<R; y++){
      for(int x=0; x<C; x++){
        int Xc = x+y;
        int Yc = x-y;
        int dmax = max({a[0]-Xc, Xc-a[1], a[2]-Yc, Yc-a[3]});
        if(dmax<=d) return true;
      }
    }
    return false;
  };
  //l = false, h = true
  int l(-1), h(R+C);
  while(l+1<h){
    int m = (l+h)/2;
    vector<int> area = GEA(m);
    if(check(area, m)) h = m;
    else l = m;
  }
  cout << h << endl;
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

