# 142. Linked List Cycle II

[link](https://leetcode.com/problems/linked-list-cycle-ii/)
**Level**: Medium 

**Memory Use**:  7.5 MB

**Time**: 14 ms

**Explanation**:

- floydd cycle detection algorithm
- also, the [explanation](https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/) method 3.
- point is from head, and current positon of meet are at equal distance from where cycle begins.

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr)
            return nullptr;

        ListNode *turtle = head, *hare = head;
        ListNode* temp = nullptr;
        while (hare->next && hare->next->next) {
            turtle = turtle->next;
            hare = hare->next->next;

            if (turtle == hare) {
                temp = head;

                while (temp != hare) {
                    hare = hare->next;
                    temp = temp->next;
                }
                return temp;
            }
        }

        return nullptr;
    }
};


```

