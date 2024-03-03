// Given the head of a linked list, remove the nth node from the end of the list and return its head.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* ptr = new ListNode();
        ptr = head;
        while(ptr)
        {
            ptr = ptr->next;
            length++;
        }
        int x = length-n;
        if(x==0)    return head->next;
        ptr = head;
        cout<<length<<" "<<x;
        int i=1;
        while(i<x)
        {
            ptr = ptr->next;
            i++;
        }
        if(ptr->next)
        ptr->next = ptr->next->next;
        return head;
    }
};
