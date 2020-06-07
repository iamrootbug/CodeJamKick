#include <bits/stdc++.h>
using namespace std;
struct Fenwick{
  int n;
  vector<long long> t;
  Fenwick(int _n){
    n = _n;
    t = vector<long long>(n+1,0);
  }
  void update(int ix, int diff){
    for(int i=ix; i<=n; i+=(i&-i)){
      t[i] += diff;
    }
  }
	long long getSum(int ix){
		long long ret = 0;
		for(int i=ix; i>0; i-=(i&-i)){
			ret += t[i];
		}
		return ret;
	};
	long long query(int l, int r){
		return getSum(r)-getSum(l-1);
	};
};
void solve(){
  int N, Q; cin >> N >> Q;
	Fenwick f1(N);
	Fenwick f2(N);
	long long ret = 0;

	for(int i=1; i<=N; i++){
		int temp; cin >> temp;
		f1.update(i, temp*(i%2==1 ? 1 : -1));
		f2.update(i, temp*(i%2==1 ? 1 : -1)*(i));
	}
	for(int i=0; i<Q; i++){
		char c; cin >> c;
		if(c=='U'){
			int ix; long long val; cin >> ix >> val;
      long long ori1 = f1.query(ix,ix);
      long long ori2 = f2.query(ix,ix);
			f1.update(ix, val*(ix%2==1 ? 1 : -1)-ori1);
			f2.update(ix, val*(ix%2==1 ? 1 : -1)*(ix)-ori2);
		}else{
			int l; int r; cin >> l >> r;
			long long q1 = f1.query(l,r);
			long long q2 = f2.query(l,r);
			ret += (l%2==1 ? 1 : -1)*(q2-q1*(l-1));			
		}
	}
	cout << ret << endl;
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
