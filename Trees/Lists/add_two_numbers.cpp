// https://leetcode.com/problems/add-two-numbers/description/

//  Definition for singly-nexted list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *l3 = head;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr) {
            int v = l1->val + l2->val + carry;
            carry = v / 10;
            l3->next = new ListNode(v%10);
            l3 = l3->next;
            l2 = l2->next;
            l1 = l1->next;
        }
        while(l2 != nullptr) {
            int v = l2->val + carry;
            carry = v / 10;
            l3->next = new ListNode(v%10);
            l3 = l3->next;
            l2 = l2->next;
        }
        while(l1 != nullptr) {
            int v = l1->val + carry;
            carry = v / 10;
            l3->next = new ListNode(v%10);
            l3 = l3->next;
            l1 = l1->next;
        }
        if(carry != 0) {
            l3->next = new ListNode(carry);
        }
        return head->next;
    }
};

// wrong concept
// class Solution {
// public:
//     ListNode* reverse(ListNode *head){
//         ListNode *temp = head;
//         ListNode *nxt = (*head).next;
//         (*temp).next = NULL;

//         while(nxt != NULL){
//             temp = nxt;
//             nxt = (*temp).next;
//             (*temp).next = head;
//             head = temp;
//         }
//         return head;
//     }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         l1 = reverse(l1);
//         l2 = reverse(l2);
//         if(l1 == NULL) return l2;
//         if(l2 == NULL) return l1;

//         ListNode *head = (ListNode*)malloc(sizeof(ListNode*));
//         ListNode *temp = head;
//         int carry = 0;
//         while(l1 != NULL || l2 != NULL) {
//             temp = (ListNode*)malloc(sizeof(ListNode*));
//             head->next = temp;
//             temp->val = l1->val + l2->val + carry;
//             temp->next = NULL;
//             if(temp->val > 9) {
//                 carry = (l1->val)/10;
//                 temp->val = (temp->val)%10;
//             }
//             l1 = l1 -> next;
//             l2 = l2 -> next;
//         }
//         if(carry == 0) {
//             if(l1 == NULL)
//                 temp->next = l2->next;
//             else if(l2 == NULL)
//                 temp->next = l1->next;
//         } else {
            
//         }
//         return head->next;
//     }
// };
