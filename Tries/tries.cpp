#include<bits/stdc++.h>
using namespace std;

class TrieNode{
   public:
   char data;
   TrieNode* children[26];
   bool isTerminal;

   TrieNode(char ch)
   {
      data=ch;
      for (int i = 0; i < 26; i++)
      {
        children[i]=NULL;
      }
      isTerminal=false;
   }
};

class Trie{
  public:
   TrieNode* root;
   
   Trie(){
    root= new TrieNode('\0');
   }

   void inserUtil(TrieNode* root , string word )
   {  //base case
      if(word.length()==0)
      {
        root->isTerminal=true;
        return;
      }

      //assumption, word will be in caps
      int index=word[0]-'A';
      TrieNode* child;
      //present
      if(root->children[index]!=NULL)
      {
         child=root->children[index];
      }else{
        child = new TrieNode(word[0]);
        root->children[index]=child;
      } 
      //recursion
      inserUtil(child,word.substr(1));
   }
   void insertWord(string word)
   {
     inserUtil(root,word);
   }
   
    bool searchUtil(TrieNode* root ,string word)
   {
    //base case
      if(word.length()==0)
      {
        return root->isTerminal;
      }
     
     int index=word[0]-'A';
     TrieNode* child;

     if(root->children[index] != NULL)
     {
        child= root->children[index];
     }else{
        return false;
     }

    return searchUtil(child,word.substr(1));
   }
   bool searchWord(string word)
   {
    return searchUtil(root,word);
   }

   void deleteWord(string word)
   {
    deleteUtil(root,word);
   }
   void deleteUtil(TrieNode* root,string word)
   {
    if(word.length()==0)
    {
        root->isTerminal=false;
        return;
    }
    int index=word[0]-'A';
    TrieNode* child;

    if(root->children[index] !=NULL)
    {
        child=root->children[index];
        deleteUtil(child,word.substr(1));
    }
   }
};
int main()
{    Trie* t=new Trie();
     t->insertWord("ABCD");
     cout<<"present or not:"<<t->searchWord("ABCD")<<endl;  
     t->deleteWord("ABCD");
     cout<<"present or not:"<<t->searchWord("ABCD")<<endl;  
    return 0;
}