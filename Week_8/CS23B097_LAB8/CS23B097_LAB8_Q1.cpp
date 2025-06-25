#include<bits/stdc++.h>

using namespace std; 

#define rep(i,a,b) for(int i=a;i<b;i++)

template <typename Element>
class Deque
{
  private: 
    int curSize;
    int fronti;
    int backi;
    vector<Element> arr;
  public: 
    Deque(int maxSize=100) 
    {
      arr.resize(maxSize); 
      curSize = 0; 
      fronti = 0; 
      backi = -1; 
    }

    bool isEmpty() const
    {
      return (curSize==0);
    } 
    
    void push_front(const Element &val){
    	if(curSize < arr.size()){
    		fronti--;
    		if(fronti<0) fronti = arr.size()-1;
    		arr[fronti] = val;
    		curSize++;
    	} else{
    		cout << "Deque is full\n";
    	}
    	return;
    }
    
    void push_back(const Element &val)
    {
      if (curSize < arr.size())
      {
        backi++; 
        if (backi == arr.size()) {  backi = 0;  }  //wrap-around
        arr[backi] = val; 
        curSize++; 
      }
      else 
      {
        cout << "Deque is full\n"; 
      }
      return; 
    }

    void pop_front()
    {
      if (curSize > 0)
      {
      	cout<<arr[fronti]<<'\n';
        fronti++; 
        if (fronti == arr.size()) {  fronti = 0;  }  //wrap-around
        curSize--; 
      }
      else
      {
        cout << "Deque is empty\n";
      }
      return;
    }
    
    void pop_back()
    {
    	if(curSize>0){
    		cout<<arr[backi]<<'\n';
    		backi--;
    		if(backi<0) backi = arr.size()-1;
    		curSize--;
    	}else cout<<"Deque is empty\n";
    	return;
    }
    Element &front(){
    	return arr[fronti];
    }
    void print()
    {
      Deque<Element> tmpq = *this;
      while (!tmpq.isEmpty())
      {
        cout << tmpq.front()<<' ';
        tmpq.pop_front();
      }
      cout << endl; 
    }
};

int main()
{
  int n,m; cin>>n>>m;
  Deque<int> dq(n);
  rep(i,0,m){
  	string s;cin>>s;
  	if(s=="push_back"){
  	int k; cin>>k;
  	dq.push_back(k);
  	continue;
  	}
  	if(s=="push_front"){
  	int k; cin>>k;
  	dq.push_front(k);
  	continue;
  	}
  	if(s=="pop_front"){dq.pop_front();}
  	if(s=="pop_back"){dq.pop_back();}
  	if(s=="isEmpty"){
  		if(dq.isEmpty()) cout<<"True\n";
  		else cout<<"False\n";
  	}
  }
} 



