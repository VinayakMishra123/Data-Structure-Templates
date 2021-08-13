#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define fastio() ios::sync_with_stdio(0); cin.tie(0);
class mx_heap
{
    int *heap;
    int c;
    int si;

public:

    mx_heap(int capacity){
        c = capacity;
        heap = new int[c];
        si = 0;
    }
    
    /* MEMBER/HIEGHT METHODS */
    int left(int i){return (2*i + 1);}
    int right(int i){return (2*i + 2);}
    int parent(int i){return (i-1)/2;}
    int hieght(){return ceil(log2(si+1))-1;}

    /* MODIFICATION || DISPLAY METHODS */
    void disp_heap();
    void insert_heap(int val);
    void mx_heapify(int i);
    int extract_mx();
    void inc_key(int i,int new_val);
    void dec_key(int i,int new_val);
    void delete_top();
    void delete_rand(int i);

    /*HEAP SORT*/
    vector<int> $sort();
    void render(int A[],int n);    
};

void mx_heap :: insert_heap(int val)
{
    if (si == c)
        return;
    si++;
    heap[si-1] = val;
    // bool terminate = false;
    int i = si-1;
    while(i != 0 and heap[parent(i)]<heap[i]){
        swap(heap[parent(i)],heap[i]);
        i = parent(i);
    } 
}

void mx_heap :: disp_heap()
{
    for(int key = 0; key < si; key++)
        cout<< heap[key] <<" ";
    cout<<"\n";
}

void mx_heap :: mx_heapify(int i)
{
    int lt = left(i);
    int rt = right(i);
    int largest = i;
    if(lt<si and heap[lt]>heap[largest])
       largest = lt;
    if(rt<si and heap[rt]>heap[largest])
       largest = rt;
    if(largest != i){ 
        swap(heap[i],heap[largest]);
        mx_heapify(largest);
    }      
}

int mx_heap :: extract_mx()
{
    if(si == 0)
      return INT_MIN;
    if(si == 1)
      return heap[0];
    else{
    swap(heap[0],heap[si-1]);
    si--;
    mx_heapify(0);
    return heap[si];
    }
}

void mx_heap :: inc_key(int i,int new_val)
{
    heap[i] = new_val;
    while(i>=0 and heap[i]>heap[parent(i)]){
        swap(heap[i],heap[parent(i)]);
        i = parent(i);
    }
}

void mx_heap :: dec_key(int i,int new_val)
{
    //NOT SURE
    heap[i] = new_val;
    mx_heapify(i);
}

void mx_heap :: delete_top()
{
    if(si == 0)
      return;
    else{
    swap(heap[0],heap[si-1]);
    si--;
    mx_heapify(0);
    }
}

void mx_heap :: delete_rand(int i)
{
    inc_key(i,1e7);
    delete_top();
}

void mx_heap :: render(int A[],int n)
{
    si = n;
    for(int i = 0;i < n; i++)
       heap[i] = A[i];
    int leaf_starts = floor(si/2);
    for(int i = leaf_starts; i >= 0; i--)
    {
        mx_heapify(i);
    }
}

vector<int> mx_heap :: $sort()
{
    vector<int> sorted_vec;
    int sz = si;
    for(int i = 0;i < sz;i++)
    {
        sorted_vec.push_back(heap[0]);
        delete_top();
        
    }
    render(heap,sz);//renders heap back into original form....
    return sorted_vec;
}
int main()
{
    fastio();   

    mx_heap h(10);
    int A[6] = {10,30,50,20,35,15};
    h.render(A,6);


}