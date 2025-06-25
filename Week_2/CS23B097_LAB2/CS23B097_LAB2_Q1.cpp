#include <bits/stdc++.h>

using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)

signed main(){
	int n,t;
	cin>>n>>t;
	vector<int>a(n);
	rep(i,0,n) cin>>a[i];
	int minl = LONG_LONG_MAX;
	int sum = 0;
	rep(i,0,n){
		rep(j,i,n){
			sum+=a[j];
			if(sum>=t){
				minl = min(j-i+1, minl);
				break;
			}

		}
		sum = 0;
	}
	if(minl==LONG_LONG_MAX) cout<<'0';
	else cout<<minl;
}
		
