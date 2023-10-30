#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * 
 * */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

// LeetCode 206 反转链表

// 双指针
class LC206 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while(cur != nullptr){
            ListNode* nxt = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = nxt;
        }

        return prev;
    }
};

// 递归
class LC206 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return head;
        }

        ListNode* newhead = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;

        return newhead;
    }
};


// 


