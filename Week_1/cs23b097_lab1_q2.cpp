#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
signed main() {
	int n;
	cin>>n;
	int min_l, count=0;
	vector<int> arr(n);
	rep(i,0,n) {
		cin>>arr[i];
		if(i==0){
			min_l = arr[i];
			continue;
		}
		if(arr[i]<min_l){
			min_l = arr[i];
			count++;
		}
	}
	cout<<count<<'\n';
}
