
方法1
相等元素不保持原来的相对顺序
c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        return insertionSort(head, NULL);
    }
    
    ListNode* insertionSort(ListNode* head, ListNode *tail){
        if(head == tail) return head;
        
        ListNode *node = head->next;
        ListNode *pre = head, *last = tail;
        while(node != tail){
            ListNode *tmp = node;
            node = node->next;
            if(tmp->val <= head->val){
                tmp->next = pre;
                pre = tmp;
            }
            else if(tmp->val > head->val){
                tmp->next = last;
                last = tmp;
            }
        }
        
        head->next = insertionSort(last, tail);
        return insertionSort(pre, head);
    }
};