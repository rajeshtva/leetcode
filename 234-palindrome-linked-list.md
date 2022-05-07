# 234. Palindrome Linked List

[link](https://leetcode.com/problems/palindrome-linked-list/)
**Level**: Easy

**Memory Use**: 114.1ms

**Time**: 371 ms

**Explanation**:

- reverse other half of linked list
- then loop and compare vals

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        int count = 0;
        ListNode* temp = head;

        while (temp) {
            count++;
            temp = temp->next;
        }

        int half = count / 2;

        ListNode* pHead;
        temp = head;

        while (half--)
            temp = temp->next;

        if (count & 1) {
            temp = temp->next;
        }

        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (temp) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        ListNode* temp1 = prev;
        ListNode* temp2 = head;

        while (temp1 && temp2) {
            if (temp1->val == temp2->val) {
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else
                return false;
        }

        return true;
    }
};



```

