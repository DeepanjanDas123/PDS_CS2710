#include <iostream>
#include <filesystem>
#include <cassert>
#include <string>
using namespace std;
using namespace std::filesystem;
#define rep(i,a,b) for(int i=a;i<b;i++)
void list_all(string dirname, int root)
{
	assert(exists(dirname));
	assert(is_directory(dirname));
	if(root==1) cout << dirname << " [dir]" << endl;
for (const auto& curEntry : directory_iterator(dirname))
{
	const string fullname = curEntry.path().string();
	const string filename = curEntry.path().filename().string();
	if (curEntry.is_directory()) {
		rep(i,0,2*root) cout<<' ';
		cout << filename << " [dir]"<<endl;
		list_all(curEntry.path().string(), root+1);
	}
	else if (curEntry.is_regular_file()) {
		rep(i,0,2*root) cout<<' ';
		cout<< filename << endl;
	}
	else {
		rep(i,0,2*root) cout<<' ';
		cout<< filename << " [unknown_type]"<<endl;
	}
}
return;
}

void find_suff(string dirname, string suff){
	assert(exists(dirname));
	assert(is_directory(dirname));
for (const auto& curEntry : directory_iterator(dirname))
{
	const string fullname = curEntry.path().string();
	const string filename = curEntry.path().filename().string();
	string str(filename.rbegin(),filename.rend());
	string ss = str.substr(0,suff.length());
	string suffrev(suff.rbegin(),suff.rend());
	bool t = ss.compare(suffrev);
	if (curEntry.is_directory()) {
		find_suff(curEntry.path().string(), suff);
	}
	else {
		if(t==0){
			cout<<dirname<<filename<<endl;
		}
	}
}
return;

}

int main()
{
string dirname, suff;
cin >> dirname>>suff;
list_all(dirname,1);
find_suff(dirname,suff);
return 0;
}
