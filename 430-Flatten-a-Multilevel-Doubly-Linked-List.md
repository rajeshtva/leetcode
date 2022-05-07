# 430. Flatten a Multilevel Doubly Linked List

[link](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)
**Level**: Medium

**Memory Use**: 7.5 MB

**Time**: 6 ms

**Explanation**:
- used recursion to store all nodes in a vector.
- iterate over that vector and join them as a single doubly linked list.

**Space complexity**: $O(n)$
**time complexity**: $O(n^2)$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    vector<Node*> st;

    Node* someFlatten(Node* head)
    {
        Node* temp = head;

        while (temp) {
            st.push_back(temp);

            if (temp->child != nullptr) {
                someFlatten(temp->child);
            }

            temp = temp->next;
        }

        return head;
    }

    Node* flatten(Node* head)
    {
        someFlatten(head);

        if (st.empty())
            return nullptr;

        Node* prev = st[0];
        prev->prev = nullptr;
        prev->child = nullptr;

        for (Node* i : st) {
            prev->next = i;
            i->prev = prev;
            prev = i;
        }

        return head;
    }
};

```
