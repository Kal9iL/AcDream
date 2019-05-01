#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;


// void adjust_down(vector<int> & heap, int start,int end)
// { 
//     //大根堆  
//     int max_child = (start << 1) + 1;
//     if( max_child > end)
//         return ;
//     if(max_child < end && heap[max_child] < heap[max_child + 1])
//         max_child ++;
//     if(heap[start] < heap[max_child]){
//         swap(heap[start],heap[max_child]);
//         adjust_down(heap, max_child,end);
//     }
// }

void adjust_down(vector<int> & heap, int start, int end)
{
    int fa = start;
    for(int max_child = (fa << 1) + 1; max_child <= end; fa = max_child,max_child = (max_child << 1)  + 1){
        if(max_child < end && heap[max_child] < heap[max_child + 1])
            max_child ++;
        if(heap[fa] >= heap[max_child])
            break;
        else
            swap(heap[max_child],heap[fa]);
    }
}

void build_heap(vector<int>  & heap)
{   
    int length = heap.size();
    for(int i = (length - 1) / 2; i >= 0; i --){
        adjust_down(heap, i,length - 1);
    }
}


//升序
void heap_sort(vector<int> & heap)
{

    build_heap(heap);//建立大根堆
    int length = heap.size();
    for(int i = length - 1;i > 0;i --){
        swap(heap[0],heap[i]);
        adjust_down(heap,0,i - 1);
    }
    
}


int main()
{
    vector<int> heap;
    int n;
    int length;
    cin >> length;
    for(int i = 0; i < length ; i ++)
    {
        cin >> n;
        heap.push_back(n); 
    }
    heap_sort(heap);
    cout << "Sorted array:\n";
    for(int i = 0;i < length;i ++){
        cout << heap[i] << " ";
    }
    cout << endl;
}