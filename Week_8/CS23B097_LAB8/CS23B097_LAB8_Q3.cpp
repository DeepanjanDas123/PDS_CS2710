#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

bool op(char c){
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^') return 1;
	else return 0;
}
signed main(){
	string in; cin>>in;
	stack<string> st;
	string s;
	rep(i,0,in.size()){
		if(op(in[i])){
			string s2 = st.top(); st.pop();
			string s1 = st.top(); st.pop();
			s = '('+s1+in[i]+s2+')';
			st.push(s);
		}else {
			string p = in.substr(i,1);
			st.push(p);
		}
	}
	cout<<s<<'\n';
	rep(i,0,in.size()){
		if(op(in[i])){
			string s2 = st.top(); st.pop();
			string s1 = st.top(); st.pop();
			s = in[i]+s1+s2;
			st.push(s);
		}else {
			string p = in.substr(i,1);
			st.push(p);
		}
	}
	cout<<s<<'\n';
}
	
