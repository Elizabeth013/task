#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node (int _val) : val(_val), next (nullptr) {}
};

struct list {
	Node* first;
	Node* last;
	list() : first (nullptr), last (nullptr) {}

bool empty () {
	return first == nullptr;
}

Node* find (int _val) {
	Node* ptr = first;
	while(ptr!=nullptr) {
	    if(ptr->val==_val) break;
	    else
	    ptr=ptr->next;
	}
	return ptr;
}

void push_back (int _val) {
	Node* ptr = new Node( _val);
	if ( empty() ) {
		first=ptr;
		last=ptr;
		return;
	} else	{
	last->next=ptr;
	last=ptr;
	}
}

void print() {
	if (empty()) return;
	Node* ptr = first;
	while (ptr!=nullptr) {
		cout<<ptr->val<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}

void remove_last() {
	if (empty()) return;
	if (first == last) {
		remove_first();
		return;
	}
	Node *ptr= first;
	while (ptr->next != last) ptr=ptr->next;
	ptr->next=nullptr;
	delete last;
	last= ptr;
}

void remove_first() {
	if (empty()) return;
	Node* ptr=first;
	first=ptr->next;
	delete ptr;
}

void remove_val (int _val) {
	if (empty()) return;
	if (first->val == _val) {
		remove_first();
		return;
	}
	else if (last->val == _val) {
		remove_last();
		return;
	}
	else
	{
        	Node* ptr=first;
        	if (ptr->next==nullptr) return;
        	while(ptr->next!=nullptr)
        	{
        	    if(ptr->next->val==_val) break;
        	    else ptr=ptr->next;
        	}
        	if(ptr->next!=nullptr)
        	{
        	    	Node* t=ptr->next;
        	    	ptr->next=t->next;
        	    	delete t;
        	}
	}
}

Node *operator [] (const int index) {
	if (empty()) return nullptr;
	Node* ptr=first;
	for (int i=0;i<index;i++) {
		ptr=ptr->next;
		if (!ptr) return nullptr;
	}
	return ptr;
}

void change()
{
    Node *ptr=first;
    while(ptr!=nullptr)
    {
        if(ptr->val%2==0) ptr->val=ptr->val/2; else ptr->val=ptr->val*3-1;
        ptr=ptr->next;
        
    }
}

void push_front(int _val)
{
   	Node* ptr = new Node( _val);
    ptr->next=first;
    first=ptr;
}

int count()
{
    int k=0;
    Node *ptr=first;
    while(ptr!=nullptr)
    {
       k++;
        ptr=ptr->next;
        
    }
    return k;
}
};

void revers(list &l)
{
    list l1;
    for(int i=0;i<l.count(); i++)
    {
        l1.push_front(l[i]->val);
       
    }
    // l1.print();
    l=l1;
}

int f(list l)
{
   int k=2;
    for(int i=1;i<l.count()-1; i++)
    {
        if(l[i-1]<=l[i]&& l[i]<=l[i+1]) k++;
       
    }
   if(k==l.count()) return 0;
   else if(k==l.count()-2) return 1;
   else return -1;
}

int main() {
	list l;
	cout<<l.empty()<<endl;
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.print();
	cout<<l.empty()<<endl;
//	l.remove("123");
	l.print() ;
	l.push_back(6);
	l.remove_first();
	l.print();
	l.remove_last();
	l.print();
	for(int i=0;i<10;i++) 	l.push_back(i);
	l.print();
	cout<<l[7]->val<<endl;
	l.remove_val(4);
	l.remove_val(9);
	l.remove_val(2);
	l.print();
	if(l.find(7)!=nullptr) cout<<"+"; else cout<<"-"<<endl;
	if(l.find(14)!=nullptr) cout<<"+"; else cout<<"-"<<endl;
	l.change();
	l.print();
	l.push_front(13);
	l.print();
	revers(l);
	l.print();
	int up=f(l);
	switch(up)
	{
	    case 0: cout<<"up"<<endl;break;
	    case 1: cout<<"+"<<endl;break;
	    case -1: cout<<"-"<<endl;break;
	};
	l.remove_first();
	l.remove_first();
	l.remove_first();
	l.remove_first();
	l.remove_first();
	l.remove_first();
	l.print();
	 up=f(l);
	switch(up)
	{
	    case 0: cout<<"up"<<endl;break;
	    case 1: cout<<"+"<<endl;break;
	    case -1: cout<<"-"<<endl;break;
	};
	return 0;  
}
