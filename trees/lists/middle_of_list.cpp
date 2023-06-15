#include<iostream>
#include<limits.h>
using namespace std;
// https://leetcode.com/problems/middle-of-the-linked-list/
struct ListNode {
    int key;
    ListNode *next;
    ListNode() : key(0), next(nullptr) {}
    ListNode(int x) : key(x), next(NULL) {}
    ListNode(int x, ListNode *link) : key(x), next(link) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *it = head;
        ListNode *md = head;
        while(it != NULL) {
            ListNode *temp = (it != NULL ? it->next : NULL);

            it = it->next;
            if(it != NULL)
                it = it->next;
            if(temp != NULL)
                md = md->next;
        }
        return md;
    }
};
