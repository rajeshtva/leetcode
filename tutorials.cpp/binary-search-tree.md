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
    int sum = 0;

public:
    TreeNode* convertBST(TreeNode* root)
    {
        if (root == nullptr) {
            return root;
        }

        root->right = convertBST(root->right);

        int s = sum;
        sum += root->val;
        root->val += s;

        root->left = convertBST(root->left);

        return root;
    }

    TreeNode* createBST(TreeNode* root, int val)
    {
        TreeNode* temp;
        if (root == nullptr) {
            root = new TreeNode(val);
            root->left = root->right = nullptr;
        } else if (val < root->val) {
            root->left = createBST(root->left, val);
        } else {
            root->right = createBST(root->right, val);
        }

        return root;
    }

    void printInorder(TreeNode* root)
    {
        if (root == nullptr)
            return;

        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }

    void printBreadthFirst(TreeNode* root)
    {
        queue<TreeNode*> row;
        row.push(root);
        TreeNode* temp = root;

        while (!row.empty()) {
            temp = row.front();
            row.pop();

            if (temp->left != nullptr)
                row.push(temp->left);

            if (temp->right != nullptr)
                row.push(temp->right);

            cout << temp->val << " ";
        }
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
        ull m = 0, n = 0;
        cin >> n;
        TreeNode* root = nullptr;
        int temp;

        for (int i = 0; i < n; i++) {
            cin >> temp;
            root = s.createBST(root, temp);
        }

        s.convertBST(root);

        // s.printInorder(root);
        cout << endl;

        s.printBreadthFirst(root);

        cout << endl;
    }
}



```
