#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

template<class Node> class List;

template <typename Element>
class Node
{
  private:
    Element val;
    Node *next;
  public:
    Node() {  next = NULL;  }
    Node(Element v) {  val = v; next = NULL;  }
    Node(Element v, Node *n) {  val = v; next = n;  }
    void print() {  cout << val << " ";  }
    void extra_print()
    {
      for (Node *ptr=this; ptr != NULL; ptr=ptr->next)
        ptr->print();
    }
  friend class List<Node>;
};

template <typename Node>
class List
{
  private:
    Node *head;
  public:
    List() {  head = NULL;  }
    ~List() {  makeEmpty();  }
    void print()
    {
      for (Node *ptr = head; ptr != NULL; ptr = ptr->next)
      {
        ptr->print(); 
      }
      cout << endl;
    }
   
    void insert_begin(const Node &n){
    	Node *toAdd = new Node(n.val);
    	if(head==NULL){head = toAdd;return;}
    	Node*hn = head;
    	head = toAdd;
    	head->next = hn;
    }

    void insert_end(const Node &n)
    {
      Node *toadd = new Node(n.val);
      assert(toadd->next==NULL);

      if (head==NULL)
      {
        head = toadd;
        return;
      }
      Node *cur;
      for (cur=head; cur->next != NULL; cur=cur->next)
      {
      }
      cur->next = toadd;
      return;
    }
    void remove(const Node &n)
    {
      if(head==NULL) return;
      Node *previous = NULL;
      for (Node *ptr = head; ptr;) {
	if (ptr->val == n.val) {
		Node *toberemoved = ptr;
		if (previous) {
		previous->next = ptr->next;
		} else head = ptr->next;
		ptr = ptr->next;
		delete toberemoved;
		return;
	} else {
		previous = ptr;
		ptr = ptr->next;
	}
       }
    }

    void makeEmpty()
    {
      Node *cur, *prev;
      if (head == NULL) return;
      for (prev = head, cur = head->next;
           cur != NULL;
           prev = cur, cur = cur->next)
      {
        delete prev;
      }
      delete prev;
      return;
    }

    int minimum_d(){
	    int d;
	    int min_d = 1005;
	    int prev_loc_min = -1;
	    Node*pre = head;
	    int i=0;
	    for(Node*ptr = head->next;ptr->next!=NULL;ptr=ptr->next){
		    if(ptr->val < pre->val && ptr->val < ptr->next->val){
			    if(prev_loc_min==-1){
				prev_loc_min = i;
				}
			    else{d = i - prev_loc_min;
			    min_d = min(min_d,d);
			    prev_loc_min = i;
			}
			}
		    pre = ptr;
		    i++;
		   }
	    if(min_d == 1005) return -1;
	    else return min_d;
	   }
    int maximum_d(){
	    int d;
	    int max_d = -1;
	    int prev_loc_min = -1;
	    Node*pre = head;
	    int i=0;
	    for(Node*ptr = head->next;ptr->next!=NULL;ptr=ptr->next){
		    if(ptr->val < pre->val && ptr->val < ptr->next->val){
			    if(prev_loc_min==-1){
				prev_loc_min = i;
				}
			    else{d = i - prev_loc_min;
			    max_d = max(max_d,d);
			}
			}
		    pre = ptr;
		    i++;
		   }
	    return max_d;
	   }
};

signed main(){
	int k; cin>>k;
	List<Node<int>> l;
	rep(i,0,k){
		int a; cin>>a;
		Node<int>n(a);
		l.insert_end(n);
	}
	cout<<l.minimum_d()<<' '<<l.maximum_d()<<'\n';
}
