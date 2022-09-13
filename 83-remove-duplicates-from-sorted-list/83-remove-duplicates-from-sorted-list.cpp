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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        
        if(curr==NULL || curr->next==NULL) return head;
        
        while(curr->next != NULL){
            int data = curr->val;
            
            ListNode * move = curr->next;
            while(move!=NULL && move->val==data){
                move = move->next;
            }
            
            curr->next = move;
            if(move==NULL) break;
            curr = move;
        }
        
        return head;
    }
};