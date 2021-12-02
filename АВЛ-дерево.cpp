#include <iostream>
using namespace std;

struct Node {
	int val;
	unsigned char height;
	Node *left;
	Node *right;
	Node (int _val) {val=_val; left=right=0;height=1;}
};
unsigned char height(Node *ptr) {
	return p?p->height:0;
}
int bfactor (Node *ptr) {
	return height(ptr->right)-height(ptr->left);
}
void fixheight (Node *ptr) {
	unsigned char hl=height(ptr->left);
	unsigned char hr=height(ptr->right);
	ptr->height= (hl>hr ? hl:hr)+1;
}
Node *rotate_right (node *ptr) {
	Node *q=ptr->left;
	ptr->left=q->right;
	q->right=ptr;
	fixheight(ptr);
	fixheight(q);
	return q;
}
Node *rotate_left (node *q) {
	Node *ptr=q->right;
	q->right=ptr->left;
	ptr->left=q;
	fixheight(q);
	fixheight(ptr);
	return ptr;
}
Node *balance(node *ptr) {
	fixheight(ptr);
	if (bfactor(ptr)==2) {
		if (bfactor(ptr->right)<0)
		ptr->right=rotate_right(ptr->right);
		return rotate_left(ptr);
	}
	if (bfactor(ptr)==-2) {
		if (bfactor(ptr->left)>0)
		ptr->left=rotate_left(ptr->left);
		return rotate_right(ptr);
	}
	return ptr;
}
Node *insert( Node *ptr, int _val) {
	if ( !ptr) return new Node(_val);
	if (_val<ptr->val) ptr->left=insert(p->left,_val);
	else p->right=insert(p->right,_val);
	return balance(ptr);
}
Node *find_min(Node *ptr) {
	return ptr->left ? find_min(ptr->left):ptr;
}
Node *remove_min (Node *ptr) {
	if (ptr->left==0) return p->right;
	ptr->left=remove_min(ptr->left);
	return balance(ptr);
}
Node *remove (Node *ptr, int _val) {
	if ( !ptr ) return 0;
	if (_val<ptr->val) ptr->left = remove(ptr->left,_val);
	else if (_val>ptr->val) ptr->right = remove (ptr->right,_val);
	else {
		Node *a = ptr->left;
		Node *b = ptr->right;
		delete ptr;
		if ( !b ) return a;
		Node *min=find_min(b);
		min->right=remove_min(b);
		min->left=a;
		return balance(min);
	}
	return balace(ptr);
}
int main() {
	
	return 0;
}


