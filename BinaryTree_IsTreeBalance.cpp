#include <iostream>
#include<cmath>

using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

//Is Tree is Balanced>>>>|h1-h2|<=1
class HBpair
{
public:
    int height;
    bool balance;
};
HBpair isTreeBalance(node* root)
{
    HBpair p;
    if(root==NULL)
    {
        p.height=0;
        p.balance=true;
        return p;
    }
    //Recursive Case

    HBpair left=isTreeBalance(root->left);
    HBpair right=isTreeBalance(root->right);

    p.height=max(left.height,right.height)+1;

    if(abs(left.height-right.height)<=1 && left.balance && right.balance )
    {
        p.balance=true;
    }
    else
    {
        p.balance=false;
    }
    return p;

}

int main(){
    node* root = buildTree();
    if(isTreeBalance(root).balance)
    {
        cout<<"Balance"<<endl;
    }
    else
    {
        cout<<"Not Balance"<<endl;
    }

return 0;
}












