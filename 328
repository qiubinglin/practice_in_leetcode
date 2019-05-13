
方法1：
c++
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || head->next == NULL) return head;
        ListNode *oddtail = head, *node = head->next;
        
        while(node && node->next){
            ListNode *tmp = node->next->next;
            node->next->next = oddtail->next;
            oddtail->next = node->next;
            oddtail = oddtail->next;
            node->next = tmp;
            node = node->next;
        }
        
        return head;
    }
};