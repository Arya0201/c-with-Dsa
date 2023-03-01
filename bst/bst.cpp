
#include<iostream>
using namespace std;
#include<queue>
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
      this->data=data;
      this->left=NULL;
      this->right=NULL;
    }
};
void levelOrderTravelser(node* root)
{
   queue<node*> q;
     q.push(root);
     q.push(NULL);
     while(!q.empty())
     {
        node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }else{
        cout<< temp->data<<" ";
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        }
     } 
 }
node* createNode(node* root,int d)
{
   if(root==NULL)
   {
    return new node(d);
   }

   if(root->data > d)
   {
    root->left=createNode(root->left,d);
   }else{
    root->right=createNode(root->right,d);
   }
   return root;
}
void takeInput(node* &root)
{
    int d;
    cout<<"Enter the root element:"<<endl;
    cin>>d;

    while(d != -1)
    {  
        root=createNode(root ,d);
        cin>>d;
    }
}
void printBst(node* root)
{
     if(root==NULL)
      {
        cout<<"tree is null ";
        return;
      }
       
      queue<node*> q;
      q.push(root);
      while(!q.empty())
      {
        node* temp=q.front();
        q.pop();

        cout<<temp->data<<" ";

        if(temp->left)
        {
            q.push(temp->left);
        }

        if(temp->right)
        {
            q.push(temp->right);
        }
      } 

}
bool search(node* root,int x)
{
    if(root==NULL)
     return false;

    if(root->data==x)
    return true;

    if(root->data > x)
      return search(root->left,x);
    else
      return search(root->right,x);   
}
node* minVal(node* root)
{
    node* temp=root;

    while(temp->left!=NULL)
      temp=temp->left;

   return temp;   
}
node* maxVal(node* root)
{
    node* temp=root;

    while(temp->right!=NULL)
      temp=temp->right;

   return temp;   
}
node* deleteNode(node* root, int d)
{
  if(root==NULL)
   return NULL;

  if(root->data==d)
  {
     //case 1 
     if(root->left==NULL && root->right==NULL)
     {
      delete root;
      return NULL;
     }
    //case 2 
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
    //case 3
    if(root->left!=NULL && root->right!=NULL)
    {
      int mini= minVal(root->right)->data;
      root->data=mini;
      root->right= deleteNode(root->right,mini);
      return root;
    }
  }
  else if(root->data > d)
  {
       root->left=deleteNode(root->left,d);
       return root;
  }else {
    root->right=deleteNode(root->right,d);
    return root;
  } 
}
int main()
{
   node* root=NULL;
   takeInput(root); //time complexity for creating bst  is o(H);
   cout<<"Print Binary search tree :"<<endl;
  // printBst(root);
   levelOrderTravelser( root);
   cout<<"node is present or not? :"<<search(root,5); //time complexity for searching a node is o(log n);
   
   cout<<endl<<"min value:"<<minVal(root)->data;
   cout<<endl<<"min value:"<<maxVal(root)->data;

   cout<<endl<<"delete node:"<<endl;
   root=deleteNode(root,10);
   levelOrderTravelser( root);



   return 0;
}