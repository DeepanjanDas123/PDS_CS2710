#include <bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)

signed main(){
	int n, x, maxc = 0, minc = 0x3f3f3f3f3f3f;
	cin>>n>>x;
	string s;
	cin>>s;
	rep(i,0,n) {
		if(s[i]=='L'){
			x--;
			minc = min(minc,x);
		}
		else {
			x++;
			maxc = max(maxc, x);
		}
	}
	cout<<maxc - minc + 1<<'\n';
}
