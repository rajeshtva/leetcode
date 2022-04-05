two-pointer problem. 

solution: 

maintain two pointers, one for left end and another for right end. 
approach: 
    - Travese till temp->next not become null,
    - in that 
        - for k - 1 time, change left's value to its next pointer,
        - for rest, change right's value to its next.

```cpp
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

struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {

        ListNode *temp = head;
        ListNode *rightEnd = head;
        ListNode *leftEnd = head;

        int counter = 1;

        while (temp->next != nullptr)
        {
            //         left node increemtn till k
            if (counter < k)
            {
                leftEnd = leftEnd->next;
            }

            else
            {
                rightEnd = rightEnd->next;
            }

            counter++;
            temp = temp->next;
        }

        int n = leftEnd->val;
        leftEnd->val = rightEnd->val;
        rightEnd->val = n;

        return head;
    }
};
```
