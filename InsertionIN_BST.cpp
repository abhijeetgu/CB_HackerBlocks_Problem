#include<iostream>
#include<queue>

using namespace std;

class node
{
public:
    node* left;
    node* right;

    int data;

    node(int d)
    {
        data=d;
        right=left=NULL;
    }
};
//Accepts the old root node & data and returns the new node
node* InsertInBST(node *root,int data)
{
    //Base case
    if(root==NULL)
    {
        return new node(data);
    }
    //Rec case - Insert in the subtree and update pointers

    if(data<=root->data)
    {
        root->left=InsertInBST(root->left,data);
    }
    else
    {
        root->right=InsertInBST(root->right,data);
    }

    return root;
}
node* build()
{
    //read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin>>d;

    node*root=NULL;
    while(d!=-1)
    {
        root=InsertInBST(root,d);
        cin>>d;
    }

    return root;
}

void Inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }

    Inorder(root->left);
    cout<<root->data<<", ";
    Inorder(root->right);

}
//Print the BST Level By Level
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
            node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
     return;
}
int main()
{
    node* root=build();

    Inorder(root);
    cout<<endl;

    bfs(root);

    return 0;
}
