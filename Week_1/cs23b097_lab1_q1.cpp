#include<bits/stdc++.h>

using namespace std;

void solve() {
	string dept, batch,degree,rno,name,surname;
	cin>>dept>>batch>>degree>>rno>>name>>surname;
	cout<<"Welcome to PDS Lab, "<<name<<' '<<surname<<' '<<rno<<'\n';
}

signed main() {
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
