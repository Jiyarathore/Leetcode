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
    
    ListNode* reverseList(ListNode* head){
        ListNode *prev=nullptr;
        ListNode* temp;
        
        while(head!=NULL){
            temp=head->next;
            head->next=prev;
            
            prev=head;
            head=temp;
            
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1=reverseList(l1);
        ListNode* r2=reverseList(l2);
        
        
        int sum=0,carry=0;
        ListNode* ans=new ListNode();
        
        while(r1|| r2){
            if(r1){
                sum+=r1->val;
                r1=r1->next;
            }
            if(r2){
                sum+=r2->val;
                r2=r2->next;
            }
            
            ans->val=sum%10;
            carry=sum/10;
            ListNode* head=new ListNode(carry);
            head->next=ans;
            ans=head;
            sum=carry;
        }
        return carry==0?ans->next:ans;
    }
};