#pragma ONCE;

#include <bits/stdc++.h>
/** ListNode implementation for ListNode.
 **/

// All Typedef's are here.
typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::set<int> si;
typedef std::set<ll> sll;
typedef vi::iterator viI;
typedef sll::iterator sllI;
typedef std::vector<std::string> vs;
typedef std::pair<int, int> pii;
typedef std::map<int, int> mii;
typedef unsigned long long ull;

struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

/**
 * TreeNode implementation for binary tree
 **/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

/**
 *  Tree build binary tree from input similar from leetcode.
 */

TreeNode* buildBinaryTree(std::string serialized)
{
    serialized = serialized.substr(1, serialized.size() - 2);
    std::istringstream iss(serialized);
    std::string s;
    std::vector<int> nums;

    while (getline(iss, s, ','))
        nums.push_back(s == "null" ? -1 : stoi(s));

    if (nums.empty())
        return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    std::queue<TreeNode*> q;

    q.push(root);
    int i = 0;
    int n = nums.size();

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (++i < n && nums[i] != -1) {
            cur->left = new TreeNode(nums[i]);
            q.push(cur->left);
        }
        if (++i < n && nums[i] != -1) {
            cur->right = new TreeNode(nums[i]);
            q.push(cur->right);
        }
    }
    return root;
}

// std::vector<std::vector<char>> deserialise2dMatrix(std::string serialised);
bool isRedundant(char ch)
{
    if (ch == '"' || ch == '[' || ch == ']' || ch == ',')
        return true;

    return false;
}

std::vector<std::vector<char>> deserialise2dMatrix(std::string serialised)
{
    replace_if(serialised.begin(), serialised.end(), isRedundant, ' ');

    std::istringstream iss(serialised);
    std::vector<std::vector<char>> input(9, std::vector<char>(9));

    while (iss) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                iss >> input[i][j];
            }
        }
    }

    return input;
}

