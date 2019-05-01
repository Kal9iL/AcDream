/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


 //Definition for singly-linked list.

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int num_of_lists = lists.size();
        vector<pair<ListNode *, int> > heap;
        int tot = 0;
        int heaplength = 0;
        for(int i = 0; i < num_of_lists; i ++){
            int l = getlength(lists[i]);
            if(l > 0)
            {    
                tot += l;
                heap.push_back(make_pair(lists[i], i));            
                heaplength ++;
            }
                
        }
        if(tot == 0)
            return NULL;
        build_heap(heap);

        ListNode * head = NULL;
        ListNode * tail = NULL;
        
        while(tot --)
        {
            if(tail == NULL)
            {    
                tail = heap[0].first;
            }
            else
            {
                tail -> next = heap[0].first;
                tail = tail -> next;
            }
            if(heap[0].first ->next == NULL){
                swap(heap[0],heap[heaplength - 1]);
                heaplength --;
                adjust_down(heap,0,heaplength - 1);
            }
            else
            {
                heap[0] = make_pair(heap[0].first -> next, heap[0].second);
                adjust_down(heap,0,heaplength - 1);
            }        
            
            if(head == NULL)
            {
                head = tail;   
            }
            
        }
        tail -> next = NULL;
        return head;
    }

    int getlength(ListNode * p){
        int length = 0;
        while(p){
            length ++;
            p = p-> next;
        }
        return length;
    }

    void adjust_down(vector< pair<ListNode *, int> > & heap, int start,int end){
        int fa = start;
        for(int max_child = (start << 1) + 1; max_child <= end; fa = max_child, max_child = (max_child << 1) + 1){
            if(max_child < end && heap[max_child].first ->val > heap[max_child + 1].first -> val)
                max_child ++;
            
            if(heap[fa].first -> val > heap[max_child].first -> val)
                swap(heap[fa],heap[max_child]);
            else
                break;
        }
    }
    void build_heap(vector< pair<ListNode * ,int> >& heap){
        int length = heap.size();
        for(int i = (length - 1) / 2; i >= 0 ; i --){
            adjust_down(heap,i,length - 1);
        }
    }
};

