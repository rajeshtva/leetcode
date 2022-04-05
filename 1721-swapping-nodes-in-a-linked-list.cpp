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
