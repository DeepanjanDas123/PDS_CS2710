#include<bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)

signed main(){
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	rep(i,0,n) cin>>a[i];
	int sum = 0, maxs = 0;
	rep(i,0,k) sum+=a[i];
	int p1=1, p2 = k;
	while(p2<n){
		sum-=a[p1-1];
		sum+=a[p2];
		maxs = max(maxs,sum);
		p1++;p2++;
	}
	cout<<maxs;
}
