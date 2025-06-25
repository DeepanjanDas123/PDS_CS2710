#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

bool open(char c){
	if(c=='('||c=='{'||c=='[') return 1;
	else return 0;
}
bool match(char c1, char c2){
	if(c1=='('&&c2==')') return 1;
	if(c1=='{'&&c2=='}') return 1;
	if(c1=='['&&c2==']') return 1;
	else return 0;
}
signed main(){
	int n;
	cin>>n;
	string p;
	cin>>p;
	stack<int>s;
	bool form = 1;
	int height=0, max_h = -1;
	rep(i,0,n){
		if(s.empty()){
			if(open(p[i])) {s.push(p[i]);height++;max_h = max(max_h,height);}
			else {form=0; break;}
		}
		else{
			if(open(p[i])) {s.push(p[i]);height++;max_h = max(max_h,height);}
			else{
				if(match(s.top(),p[i])) {s.pop();height--;}
				else{form=0;break;}
			}
		}
	}
	if(!form) cout<<"False"<<'\n';
	else cout<<"True"<<'\n'<<max_h<<'\n';
}
	
