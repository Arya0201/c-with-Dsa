#include<bits/stdc++.h>
using namespace std;
class trienode{
  public:
   char ch;
   trienode* child[26];
   bool isterminal;

   trienode(char ch)
   {
     this->ch=ch;
     for (int i = 0; i < 26; i++)
     {
        child[i]=NULL;
     }
     isterminal=false;
   }
};

class trie{
  private:

   trienode *root;
  
   void insert(string word,trienode* root)
  {
    //base case
    if(word.length()==0)
    {
        root->isterminal=true;
        return;
    }

    int index=word[0]-'a';
    trienode *child;
    if(root->child[index]!=NULL)
    {
      child=root->child[index];
    }else{
        child = new trienode(word[0]);
        root->child[index]=child;
    }

    insert(word.substr(1),child);
  }

  bool  search(string word,trienode *root)
   {
      if(word.length()==0)
      {
        return root->isterminal;
      }

      int index=word[0]-'a';
      trienode *child;

      if(root->child[index]==NULL)
      {
        return false;
      }
      child=root->child[index];
      return search(word.substr(1),child);
   }

   public:
 
  trie()
  {
    root= new trienode('\0');
  }

  void insertword(string word)
  {
     insert(word,root);
  }
   
  bool  searchword(string word)
  {
    return search(word,root);
  }
};
int main(){
string s="abcd";
  trie *t= new trie();
  t->insertword(s);
  t->insertword("acde");
   
   cout<<"check word:"<<t->searchword("acde");
    return 0;
}