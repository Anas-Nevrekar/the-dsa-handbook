// Linked List - Middle of the Linked List
// Leetcode Problem: 876
//Difficulty: Easy
// Problem Link: https://leetcode.com/problems/middle-of-the-linked-list/description/
// Problem Statement: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

// Approach: We can use the two-pointer technique where one pointer moves one step at a time (slow pointer) and the other moves two steps at a time (fast pointer). When the fast pointer reaches the end of the list, the slow pointer will be at the middle node.

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while( fast != NULL && fast->next != NULL  ){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
//Time Complexity: O(n) - We traverse the list once.
// Space Complexity: O(1) - We use a constant amount of space for the pointers.