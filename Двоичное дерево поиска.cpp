#include <iostream>
#include <cstdlib>
 
struct Tree {
    int   val;
    Tree *left;
    Tree *right;
};
 
Tree* InsertNode(Tree* Node, int val);
void  PrintNode(std::ostream& _out, const Tree* Node);
void  ClearNode(Tree* Node);

Tree* InsertNode(Tree* Node, int val){
    if(Node == nullptr){
        Node = new (std::nothrow) Tree();
        if(Node != nullptr){
            Node->val  = val;
            Node->left = Node->right = nullptr;
        }
        return Node;
    }
 
    if(val < Node->val)
        Node->left  = InsertNode(Node->left, val);
    else
        Node->right = InsertNode(Node->right, val);
    return Node;
}

void PrintNode(std::ostream& _out, const Tree* Node){
    if(Node != nullptr){
        if(Node->left != nullptr)
		PrintNode(_out, Node->left);
        _out << Node->val << ' ';
        if(Node->right != nullptr)
        PrintNode(_out, Node->right);
    }
}
 
void ClearNode(Tree* Node){
    if(Node != nullptr){
        if(Node->left != nullptr)
            ClearNode(Node->left);
        if(Node->right != nullptr)
            ClearNode(Node->right);
        delete Node;
    }
}
//deletion
Tree* DeleteNode(Tree* Node, int val){
    if(Node == nullptr)
        return Node;
 
    if(val == Node->val){
 
        Tree* tmp;
        if(Node->right == nullptr)
            tmp = Node->left;
        else {
 
            Tree* ptr = Node->right;
            if(ptr->left == nullptr){
                ptr->left = Node->left;
                tmp = ptr;
            } else {
 
                Tree* pmin = ptr->left;
                while(pmin->left != NULL){
                    ptr  = pmin;
                    pmin = ptr->left;
                }
                ptr->left   = pmin->right;
                pmin->left  = Node->left;
                pmin->right = Node->right;
                tmp = pmin;
            }
        }
        delete Node;
        return tmp;
    } else if(val < Node->val) Node->left  = DeleteNode(Node->left, val);
    else Node->right = DeleteNode(Node->right, val);
    return Node;
}
 
 
int main(){
    Tree* tree = nullptr;
    for(int i = 0; i < 20; ++i) tree = InsertNode(tree, std::rand() % 10);
    
    PrintNode(std::cout, tree);
    std::cout << std::endl;
 
    tree = DeleteNode(tree, 5);
    tree = DeleteNode(tree, 2);
    tree = DeleteNode(tree, 9);
    
    PrintNode(std::cout, tree);
    ClearNode(tree);
    return 0;
}
