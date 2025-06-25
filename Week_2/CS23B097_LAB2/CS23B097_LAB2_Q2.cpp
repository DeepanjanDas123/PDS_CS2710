#include <bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)

signed main(){
	int n,t;
	cin>>n>>t;
	vector<int> a(n);
	rep(i,0,n) cin>>a[i];
	int p1=0, p2=1;
	int sum = a[0], minl = LONG_LONG_MAX;
	while(p2<=n){
		if(sum>=t){
			minl = min((p2-p1), minl);
			sum-=a[p1];
			p1++;
			continue;
		}
		sum+=a[p2];
		p2++;
	}
	if(minl == LONG_LONG_MAX) cout<<'0';
	else cout<<minl;
}
		
