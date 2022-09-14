/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt;
        
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* temp = slow->next;
        slow->next = NULL;
        
        ListNode* conn = reverse(temp);
        ListNode* curr = head;
        
        while(conn!=NULL){
            ListNode* temp1 = curr->next;
            ListNode* temp2 = conn->next;
            
            curr->next = conn;
            conn->next = temp1;
            
            conn = temp2;
            curr = temp1;
        }
    }
};