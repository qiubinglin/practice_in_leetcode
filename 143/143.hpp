
方法1
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
    void reorderList(ListNode* head) {
        if(!(head && head->next && head->next->next)) return;
        
        ListNode *slow, *fast;
        slow = fast = head;
        
        //找到中间节点
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *mid = slow->next;
        slow->next = NULL;
        
        //逆转第二个链表
        ListNode *firHead = head->next;
        ListNode *secHead = NULL;
        while(mid){
            ListNode *tmp = mid->next;
            mid->next = secHead;
            secHead = mid;
            mid = tmp;
        }
        
        //合并两个链表
        ListNode *tail = head;
        while(secHead){
            tail = tail->next = secHead;
            secHead = secHead->next;
            tail = tail->next = firHead;
            firHead = firHead->next;
        }
        tail->next = firHead;
    }
};