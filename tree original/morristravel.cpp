#include<iostream>
using namespace std;
class Node{
     public:
    int data;
    Node* left;
    Node* right;

   

    Node(int data){
     this->data=data;
     this->left=NULL;
     this->right=NULL;
    }
};
void MorrisTraversal(Node* root)
{
     Node* curr=root;
     Node* pre;

     while(curr!=NULL)
     {
        if(curr->left==NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->right;
        }else{

            pre=curr->left;
            while (pre->right!=NULL && pre->right!=curr)
            {
                pre=pre->right;
            }
            
            if(pre->right==NULL)
            {
                pre->right=curr;
                curr=curr->left;
            }else{
                 pre->right=NULL;
                 cout << curr->data << " ";
                 curr=curr->right;
            }
        }
     }
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
 
    MorrisTraversal(root);
 
    return 0;
}