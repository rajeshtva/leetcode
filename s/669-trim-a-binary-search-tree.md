# Trim a binary search tree 

[link](https://leetcode.com/problems/trim-a-binary-search-tree/)
**Level**: Easy 

**Memory Use**:  24.1mb

**Time**: 22 ms

**Explanation**:
    - first of all, if root is smaller than `low`, then entire left tree will be smaller than `low`. so no point of keeping it. 
    - similarly, if `root` is greater than `high`, then entire right tree will be greater than `high`. 
    - rest of the code only is to fullfill the logic of bianry search tree. 

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr){
            return root;
        } 
        if(root->val > high) return trimBST(root->left, low, high);
        if(root->val < low) return trimBST(root->right, low, high);
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        return root;
    }
};
```

##### 2.nd approach.
**This code has issues. just keeping here for record and debug later.**
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> T;
typedef unsigned long long ull;

class TreeNode {
public:
    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int x) { val = x; }

    TreeNode(int x, TreeNode* l, TreeNode* r)
    {
        val = x;
        left = l;
        right = r;
    }
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if (root == nullptr) {
            return root;
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        if (root->val < low || root->val > high) {

            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
            } else if (root->left == nullptr) {
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            } else {
                TreeNode* temp = findMin(root->right);
                root->val = temp->val;
                root->right = trimBST(root->right, low, high);
            }
        }

        return root;
    }

    TreeNode* findMin(TreeNode* root)
    {
        while (root->left != nullptr)
            root = root->left;
        return root;
    }

    TreeNode* cTree(TreeNode* root, int val)
    {
        if (root == nullptr) {
            return new TreeNode(val);
        } else if (val < root->val) {
            root->left = cTree(root->left, val);
        } else {
            root->right = cTree(root->right, val);
        }

        return root;
    }

    void printTree(TreeNode* root)
    {

        if (root == nullptr)
            return;

        printTree(root->left);
        cout << root->val;
        printTree(root->right);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Solution s;
    ull t;

    cin >> t;

    while (t--) {
        ull m = 0, n = 0, low = 0, high = 0;
        cin >> n;
        TreeNode* root = nullptr;
        int temp;

        for (int i = 0; i < n; i++) {
            cin >> temp;

            s.cTree(root, temp);
        }
        cin >> low >> high;

        s.trimBST(root, low, high);

        s.printTree(root);

        cout << endl;
    }
}


```
