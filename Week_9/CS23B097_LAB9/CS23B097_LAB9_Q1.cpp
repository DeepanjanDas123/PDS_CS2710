#include"BinaryNewickParser.hpp"
#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

signed main(){
	string newick; cin>>newick;
	size_t pos = 0;
	TreeNode *root = parseNewick(newick,pos);
	if(root == NULL) return 0;
	queue<pair<int,TreeNode*>> q;
	q.push({0,root});
	int lastlev=1;
	TreeNode *lastpop = root;
	vector<string> sol;
	while(!q.empty()){
		auto curr = q.front().second;
		int currlev = q.front().first;
		q.pop();
		if(currlev == lastlev){
			sol.push_back(lastpop->label);
			lastlev++;
		}
		if(curr->left != NULL) q.push({currlev+1,curr->left});
		if(curr->right!=NULL) q.push({currlev+1,curr->right});
		lastpop = curr;
	}
	sol.push_back(lastpop->label);
	rep(i,0,sol.size()) cout<<sol[i]<<' ';
	cout<<endl;
}
		
