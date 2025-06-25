#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

signed main(){
	int n; cin>>n;
	vector<int>temp(n);
	rep(i,0,n){
		int t; cin>>t;
		temp[i] = t;
	}
	vector<int>ans(n,0);
	stack<int> s;
	rep(i,0,n){
		if(s.empty() || temp[s.top()]>=temp[i]) s.push(i);
		else{
			while(!s.empty() && temp[s.top()]<temp[i]){
				ans[s.top()] = i - s.top();
				s.pop();
			}
			s.push(i);
		}
	}
	rep(i,0,n){
		if(i==0)cout<<ans[i];
		else cout<<' '<<ans[i];
	}
	cout<<'\n';
}
