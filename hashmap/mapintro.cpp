#include<iostream>
using namespace std;
#include<map>
#include<unordered_map>
int main()
{   //creation
    unordered_map<string,int> m;
    
    //insertion
    //1
    pair<string,int> p =make_pair("arya",3);
    m.insert(p);

    //2
    pair<string,int> p2("patel",1);
    m.insert(p2);
     
    //3
    m["hii"]=1;

     //what if
     m["hii"]=2;

     //search 
     cout<<m["hii"]<<endl;
     cout<<m.at("patel")<<endl;

     //cout<<m.at("unknown")<<endl;       it will give error    
     cout<<m["unknown"]<<endl;
     cout<<m.at("unknown")<<endl; 

     //size
     cout<<m.size()<<endl;

     //to check present
     cout<<m.count("find")<<endl;
     cout<<m.count("unknown")<<endl;
      
      //erase
      m.erase("hii");
      cout<<m.size()<<endl;
      
    return 0;
}