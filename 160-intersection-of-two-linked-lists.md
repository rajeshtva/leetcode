# 160. Intersection of two linked lists.

[link](https://leetcode.com/problems/intersection-of-two-linked-lists/)
**Level**: Easy 

**Memory Use**:  19.8 MB

**Time**: 36 ms

**Explanation**:

- use stack to keep tracks.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*>listA,listB;
        
        ListNode* temp = headA;
        
        while(temp){
            listA.push(temp);
            temp = temp->next;
        }
        
        temp = headB;
        while(temp){
            listB.push(temp);
            temp = temp->next;
        }
        
        while(listA.top() == listB.top()){
            listA.pop();
            listB.pop();
            
            if(listA.empty() || listB.empty()) break;
        }
        
        if(listA.empty()) return headA;
        else if(listB.empty()) return headB;
        else return listA.top()->next;
        
        
    }
};
```

