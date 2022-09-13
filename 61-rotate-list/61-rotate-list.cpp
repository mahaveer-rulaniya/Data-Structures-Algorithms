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
    ListNode* rotateRight(ListNode* head, int k) {
        int n =1;
        ListNode* curr = head;
        ListNode* move = head;
        
        if(head==NULL || head->next==NULL) return head;
        
        while(curr->next !=NULL){
            curr = curr->next;
            n++;
        }
        
        curr->next = head;
        int t = n-(k%n);
        
        for(int i=0;i<t-1;i++){
            move = move->next;
        }
        
        head = move->next;
        move->next = NULL;
        
        return head;
    }
};