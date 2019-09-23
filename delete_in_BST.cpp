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
node* deleteInBST(node* root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    //search in left subtree for data
    else if(data<root->data)
    {
        root->left=deleteInBST(root->left,data);
        return root;
    }
    //if data is found
    else if(data==root->data)
    {
       //found the node to delete 3 cases
       //1.node with 0 children - leaf node
       if(root->left==NULL && root->right==NULL)
       {
           delete root;
           return NULL;
       }

       //2. case only 1 child
       if(root->left!=NULL && root->right==NULL)
       {
           node* temp=root->left;
           delete root;
           return temp;
       }
       if(root->left==NULL && root->right!=NULL)
       {
           node* temp=root->right;
           delete root;
           return temp;
       }
       //3. case 2 children

       node* replace=root->right;
       //find the inorder successor from right subtree
       while(replace->left!=NULL)
       {
           replace=replace->left;
       }

       root->data=replace->data;
       root->right=deleteInBST(root->right,replace->data);
       return root;
    }
    else
    {
        root->right=deleteInBST(root->right,data);
        return root;
    }
}

int main()
{
    node* root=build();

    Inorder(root);
    cout<<endl;

    int s;
    cin>>s;

    root=deleteInBST(root,s);
    Inorder(root);




    return 0;
}


