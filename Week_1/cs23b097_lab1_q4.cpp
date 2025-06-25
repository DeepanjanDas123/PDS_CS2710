#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
signed main(){
	int n;
	cin>>n;
	vector<int>reg(n);
	rep(i,0,n){
		cin>>reg[i];
		if(i==0) continue;
		if(reg[i]<reg[i-1]) {cout<<i-1<<'\n'; return 0;}
	}
}
