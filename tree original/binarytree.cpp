#include<iostream>
#include<queue>
using namespace std;
class node{
public:
   int data;
   node* left;
   node* right;

   node(int d)
   {
    this->data=d;
    this->left=NULL;
    this->right=NULL;
   }
  
};
 node* createTree(node* root){
        cout<<"Enter the data : "<<endl;
        int d;
        cin>>d;
        root= new node(d);

        if(d==-1){
            return NULL;
        } 
        cout<<" Enter the data for inserting  in left of "<<d<<endl;
        root->left=createTree(root->left);
        cout<<"Enter the data for inserting in right of "<<d<<endl;
        root->right=createTree(root->right);
        return root;
   }
  void buildFromLevelOrder(node* root)
  {
    queue<node*> q;
    cout<<"Enter the data of root: "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp =q.front();
        q.pop();

        cout<<"Enter left node for :"<<temp->data<<endl;
        int leftnode;
        cin>>leftnode;

        if(leftnode!=-1)
        {
            temp->left=new node(leftnode);
            q.push(temp->left);
        }
        cout<<"Enter right node for :"<<temp->data<<endl;
        int rightnode;
        cin>>rightnode;
        if(rightnode!=-1)
        {
            temp->right=new node(rightnode);
            q.push(temp->right);
        }
    }
  }
   void levelOrderTraversal(node* root)
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
    
   void preorder(node * root)
   {
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
   }
   void postorder(node * root)
   {
    if(root==NULL)
    {
        return;
    }

    postorder(root->right);
    cout<<root->data<<" ";
    postorder(root->left);
   }
int main()
{  node* root= NULL;
   root= createTree(root);
   //1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1
   cout<<"Print level order travelsar: "<<endl;
   levelOrderTraversal(root);
   
   cout<<"print inorder travelsar: "<<endl;
   inorder(root);
    return 0;
}