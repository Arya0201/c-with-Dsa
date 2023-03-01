#include<bits/stdc++.h>
using namespace std;
int f(int x, int *py, int **ppz) {
    int y, z;
    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;
    return x + y + z;
}
int main(){
  //  int arr[10]={2,5,9};
    /*
    cout<<"Address of first memory block:"<<arr<<endl;
    cout<<arr[0]<<endl;
    cout<<"Address of first memory block:"<<&arr[0]<<endl;
    cout<<*arr<<endl;
    cout<<*arr+1<<endl;
    cout<<*(arr+1)<<endl;
    cout<<arr[2]<<endl;
    cout<<*(arr+2)<<endl; // formula arr[i]=*(arr+i)
    cout<<2[arr]<<" "<<*(2+arr)<<endl;// or  i[arr]= *(i+arr)
    */
   /*int temp[10];
    cout<<sizeof(temp)<<endl;
   int *ptr=&temp[0];
   cout<<sizeof(ptr)<<endl;
*/
  /*char c[]="abcde";
    //print string;
    cout<<c<<endl; // it is not print address of c[0]
 */
/*
  char z='z';
  char *ptr=&z;
  cout<<ptr<<endl;
*/
 int a = 10;
int *p = &a;
int **q = &p;
int b = 20;
*q = &b;
(*p)++;
cout << a << " " << b << endl;
    return 0;
}

