 #include<bits/stdc++.h>
 
 using namespace std;
 
 #define rep(i,a,b) for(int i=a;i<b;i++)
 
 signed main(){
 	int k; cin>>k;
 	int n; cin>>n;
 	string p; cin>>p;
	stack<char>s;
	int rm_c = 0;
	rep(i,0,n){
		if(s.empty() || s.top()<p[i] || rm_c==k) s.push(p[i]);
		else{
			while(!s.empty() && s.top()>p[i] && rm_c<k){
				s.pop();
				rm_c++;
			}
			s.push(p[i]);
		}
	}
	vector<char>new_p;
	while(!s.empty()){
		new_p.push_back(s.top());
		s.pop();
	}
	reverse(new_p.begin(),new_p.end());
	bool head = 0;
	rep(i,0,n-k){
		if(new_p[i]=='0' && head==0) continue;
		else {
			if(head==0){ head = 1;}
			cout<<new_p[i];
		}
	}
	if(!head) cout<<0<<'\n';
	else cout<<'\n';
}
 		
 		
