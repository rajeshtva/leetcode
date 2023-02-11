# 2. Add Two Numbers.

[link](https://leetcode.com/problems/add-two-numbers)
**Level**: Medium 

**Space complexity**: $O(1)$
**time complexity**: $O(n)$, 

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* head = nullptr;
        int val = 0, carry = 0;
        int sum = (temp1->val + temp2->val);

        val = sum % 10;
        carry = sum / 10;
        head = new ListNode(val);
        ListNode* temp = head;
        temp1 = temp1->next;
        temp2 = temp2->next;

        while (temp1 && temp2) {
            sum = temp1->val + temp2->val + carry;

            val = sum % 10;
            carry = sum / 10;

            temp->next = new ListNode(val);
            temp = temp->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while (temp1) {
            sum = temp1->val + carry;

            val = sum % 10;
            carry = sum / 10;

            temp->next = new ListNode(val);
            temp = temp->next;
            temp1 = temp1->next;
        }

        while (temp2) {
            sum = temp2->val + carry;

            val = sum % 10;
            carry = sum / 10;

            temp->next = new ListNode(val);
            temp = temp->next;
            temp2 = temp2->next;
        }

        if (carry != 0) {
            temp->next = new ListNode(carry);
        }

        return head;
    }
};

```

