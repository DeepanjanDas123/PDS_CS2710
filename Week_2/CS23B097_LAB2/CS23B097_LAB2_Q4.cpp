#include<bits/stdc++.h>

using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)

signed main(){
	int n,x,y;
	cin>>n>>x>>y;
	int mint = (x<y)*(x-y) + y, maxt = x+y-mint;
	int tmint = (n-1)*mint, tmaxt = 0;
	while(tmint>mint){
	        if(tmint<(tmaxt+maxt)) break;
	        tmint-=mint;
	        tmaxt+=maxt;
	}
	cout<<mint + max(tmint,tmaxt);
}
			
		
			
