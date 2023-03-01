#include <iostream>
#include<queue>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int d)
    {
        size = size + 1;
        int index = size;
        arr[index] = d;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deleteNode()
    {   //step 1: check if tree is empty is not 
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }

        //step 2: swap last element  and first element      
        arr[1] = arr[size];
        //step 3: delete last  element 
        size--;
        //step 4:take root element to its correct position 
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = (2 * i) + 1;
            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
    void heapify(int arr[],int n,int i)
    {
        int largest=i;
        int leftChild=i*2;
        int rightChild=(2*i)+1;

        if (leftChild <= n && arr[leftChild] >arr[largest])
        {
           largest=leftChild;
        }
        if (rightChild <= n && arr[rightChild] > arr[largest])
        {
            largest=rightChild;
        }
        
        if(largest!=i)
        {
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }
    void heapsort(int arr[],int n)
    {
        int size=n;

        while (size > 1)
        {
        //step 1:
        swap(arr[1],arr[size]);
        size--;
        //step 2 
          heapify(arr,size,1);  
        }
        
    }
};
int main()
{
    heap h;
    h.insert(51);
    h.insert(52);
    h.insert(53);
    h.insert(54);
    h.insert(55);
    h.print();
    h.deleteNode();
    h.print();

    int arr[6]={-1,54,53,55,52,50};
  int n=5;
    for (int i = n/2; i>0;--i)
    {
        h.heapify(arr,n,i);
    }
    cout<<"print array"<<endl;
   for(int i=1;i<6;i++)
   {
    cout<<arr[i]<<" ";
   }
   cout<<endl;
   h.heapsort(arr,n);
   cout<<"print array"<<endl;
   for(int i=1;i<=5;i++)
   {
    cout<<arr[i]<<" ";
   }
   cout<<endl;

   cout<<"Using priority queue"<<endl;
   //max heap
   priority_queue<int> pq;
   pq.push(20);
   pq.push(25);
   pq.push(22);
   pq.push(21);
   pq.push(24);

   cout<<"element at top:"<<pq.top()<<endl;
   pq.pop();
   cout<<"element at top:"<<pq.top()<<endl;

   //min heap
   priority_queue<int,vector<int>,greater<int>> minheap;
   minheap.push(20);
   minheap.push(25);
   minheap.push(22);
   minheap.push(21);
   minheap.push(24);

   cout<<"element at top:"<<minheap.top()<<endl;
   minheap.pop();
   cout<<"element at top:"<<minheap.top()<<endl;

    return 0;
}