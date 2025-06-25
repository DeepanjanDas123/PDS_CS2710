#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

bool open(char c){
	if(c=='(' || c=='{' || c=='[') return 1;
	else return 0;
}
signed main(){
	int k; cin>>k;
	string p; cin>>p;
	stack<int> s;
	rep(i,0,p.size()){
		if(open(p[i])) s.push(i);
		else{
			if(s.top()==k){
				cout<<i<<'\n';
				return 0;
			}
			s.pop();
			}
		}
	}
