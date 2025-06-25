#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
template<class Node> class List;  //forward declaration

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
  friend class List<Node>; //no errors due to fwd decln. above
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
        ptr->print();  //(*ptr).print()  
      }
      cout << endl; 
    }
    //insert n.val at beginning of list
    void insert_begin(const Node &n){
    	Node *toAdd = new Node(n.val);
    	if(head==NULL){head = toAdd;return;}
    	Node*hn = head;
    	head = toAdd;
    	head->next = hn;
    }
    //insert n.val at end of list
    void insert_end(const Node &n) //void insert(Element e)
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
    void remove(const Node &n) //remove Element n.val
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
}; 

signed main(){
	int n;
	cin>>n;
	List<Node<int>> l;
	rep(i,0,n){
		string s;
		cin>>s;
		if(s=="NEW") continue;
		if(s=="PUSH_BEGIN") {
			int k;
			cin>>k;
			l.insert_begin(Node<int>(k));
		}
		if(s=="PUSH_END") {
			int k;
			cin>>k;
			l.insert_end(Node<int>(k));
		}
		if(s=="DELETE") {
			int k;
			cin>>k;
			l.remove(Node<int>(k));
		}
	}
	l.print();
	return 0;
}
