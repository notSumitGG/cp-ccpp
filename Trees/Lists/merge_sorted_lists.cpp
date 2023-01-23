#include<iostream>
#include<limits.h>
using namespace std;
// https://leetcode.com/problems/merge-two-sorted-lists/
struct ListNode {
    int key;
    ListNode *next;
    ListNode() : key(0), next(nullptr) {}
    ListNode(int x) : key(x), next(NULL) {}
    ListNode(int x, ListNode *link) : key(x), next(link) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // ListNode *start, *last;
        // if(l1 == NULL) return l2;
        // if(l2 == NULL) return l1;
        // if(l1->key < l2->key) {
        //     start = l1;
        //     l1 = l1->next;
        // } else {
        //     start = l2;
        //     l2 = l2->next;
        // }
        // last = start;
        ListNode fake(INT_MIN);
        ListNode *last = &fake;
        while(l1 != NULL && l2 != NULL) {
            if(l1->key < l2->key) {
                last->next = l1;
                last = l1;
                l1 = l1->next;
            }
            else {
                last->next = l2;
                last = l2;
                l2 = l2->next;
            }
        }
        if(l1 != NULL)
            last->next = l1;
        if(l2 != NULL)
            last->next = l2;
        
        return fake.next;
    }
};