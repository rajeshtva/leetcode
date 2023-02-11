#include "includes/leetcode.h"

using namespace std;

typedef long long ll;
typedef pair<string, int> psi;

class Compare {
public:
    bool operator()(int a, int b)
    {
        if (a == 0)
            return false;
        if (b == 0)
            return true;

        return true;
    }
};

// class Solution {
// public:
//     int uniquePaths(int m, int n)
//     {
//         vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

//         for (int i = 0; i <= m; i++) {
//             for (int j = 0; j <= n; j++) {
//                 if (i == 0 || j == 0)
//                     memo[i][j] = 1;
//                 else
//                     memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
//             }
//         }

//         return memo[m][n];
//     }
// };
// class Solution {
// public:
//     string s;
//     int l;
//     int maxPalindromes(string s, int k)
//     {
//         this->s = move(s);
//         this->l = k;

//         return solve(0, s.length() - 1);
//     }

//     int solve(int i, int j)
//     {
//         int answer = 0;

//         if (j - i + 1 == l && isPalindrom(i, j)) {
//             answer = 1;
//         }

//     }

//     bool isPalindrom(int i, int j)
//     {
//         int mid = (i + j) / 2;
//         int len = i + j;

//         for (int i = 0; i <= mid; i++) {
//             if (s[i] != s[len - i])
//                 return false;
//         }

//         return true;
//     }
// };

//  */

// Definition for a Node.

// Definition for a Node.

// Definition for a Node.

// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& nums)
//     {
//         typedef long long ll;
//         int n = nums.size();
//         int ans = 0;
//         vector<unordered_map<ll, ll>> memo(n);
//         ll count, diff;

//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 diff = nums[i] * 1ll - nums[j] * 1ll;
//                 count = memo[j].count(diff) ? memo[j][diff] : 0;
//                 memo[i][diff] += count + 1;
//                 ans += count;
//             }
//         }

//         return ans;
//     }
// };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Codec {
// public:
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root)
//     {
//         vector<int> inorderStore, postorderStore;

//         function<void(TreeNode*)> inorder = [&](TreeNode* root) {
//             if (root == nullptr)
//                 return;

//             inorder(root->left);
//             inorderStore.push_back(root->val);
//             inorder(root->right);
//         };
//         function<void(TreeNode*)> postorder = [&](TreeNode* root) {
//             if (root == nullptr)
//                 return;

//             postorder(root->left);
//             postorder(root->right);
//             postorderStore.push_back(root->val);
//         };

//         inorder(root);
//         postorder(root);

//         string ans;

//         for (auto it : inorderStore) {
//             ans.append(to_string(it));
//             ans.push_back(',');
//         }

//         ans.push_back('|');
//         for (auto it : postorderStore) {
//             ans.append(to_string(it));
//             ans.push_back(',');
//         }
//         return ans;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data)
//     {
//         stringstream ss(data);
//         string word;
//         vector<string> nums;

//         while (!ss.eof()) {
//             getline(ss, word, '|');
//             if (word.size())
//                 nums.push_back(word);
//         }

//         string inorderString = nums[0];
//         string postorderString = nums[1];

//         vector<int> inorderStore, postorderStore;

//         stringstream inorderStream(inorderString);
//         stringstream postorderStream(postorderString);

//         while (!inorderStream.eof()) {
//             getline(inorderStream, word, ',');
//             if (word.size())
//                 inorderStore.push_back(stoi(word));
//         }

//         while (!postorderStream.eof()) {
//             getline(postorderStream, word, ',');
//             if (word.size())
//                 postorderStore.push_back(stoi(word));
//         }

//         int n = postorderStore.size();

//         return buildTree(inorderStore, postorderStore);
//     }

//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
//     {
//         map<int, int> table;

//         for (int i = 0; i < inorder.size(); i++) {
//             table[inorder[i]] = i;
//         }

//         TreeNode* root = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, table);

//         return root;
//     }

//     TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd,
//         vector<int>& postorder, int postStart, int postEnd,
//         map<int, int>& table)
//     {
//         if (inStart > inEnd || postStart > postEnd)
//             return nullptr;

//         TreeNode* root = new TreeNode(postorder[postEnd]);

//         int inRoot = table[root->val];

//         int count = inRoot - inStart;

//         root->left = buildTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + count - 1, table);
//         root->right = buildTree(inorder, inRoot + 1, inEnd, postorder, postStart + count, postEnd - 1, table);

//         return root;
//     }
// };

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k)
//     {
//         int i = -1, j = 0;
//         int n = nums.size();
//         int sum = 0;
//         int count = 0;

//         while (i < n) {
//             sum += nums[i];
//             while (sum >= k) {
//                 if (sum == k)
//                     count++;

//                 if(j > i) {
//                     j = i;
//                     break;
//                 }
//                 sum -= nums[j++];
//             }
//             i++;
//         }

//         return count;
//     }
// };

// class Solution {
// public:
//     int scheduleCourse(vector<vector<int>>& courses)
//     {
//         function<bool(vector<int>&, vector<int>&)> compare = [](vector<int>& a, vector<int>& b) -> bool {
//             if (a[1] != b[1])
//                 return a[1] < b[1];
//             return a[0] < b[0];
//         };

//         int n = courses.size();

//         sort(courses.begin(), courses.end(), compare);

//         vector<bool> visited(n, false);

//         function<int(void)> backtrack = [&](void) -> int {
//             int ans = 0;
//             for (int i = 0; i < n; i++) {
//                 if (!visited[i]) {
//                     visited[i] = true;
//                     int value = backtrack();
//                     ans = max(ans, value + courses[i][1]);
//                 }
//             }
//             return ans;
//         };
//     }
// };

// class Solution {
// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums)
//     {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());

//         vector<int> temp, ans;
//         function<void(int)> backtrack = [&](int current) {
//             if (current >= n) {
//                 if (temp.size() > ans.size()) {
//                     ans = temp;
//                 }
//                 return;
//             }

//             // without using this index.
//             if (temp.empty() || nums[current] % temp.back() == 0) {
//                 temp.push_back(nums[current]);
//                 backtrack(current + 1);
//                 temp.pop_back();
//             }

//             backtrack(current + 1);

//             return;
//         };

//         backtrack(0);

//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums)
//     {
//         int n = nums.size();

//         sort(nums.begin(), nums.end());

//         vector<int> memo(n, 1);
//         vector<int> parent(n, -1);
//         int maxSize = 0;
//         int maxPosition = 0;

//         for (int i = 1; i < n; i++) {
//             for (int j = i - 1; j >= 0; j--) {
//                 if (nums[i] % nums[j] == 0 && memo[i] < 1 + memo[j]) {
//                     memo[i] = 1 + memo[j];
//                     parent[i] = j;
//                 }
//             }

//             if (memo[i] > maxSize) {
//                 maxSize = memo[i];
//                 maxPosition = i;
//             }
//         }

//         vector<int> ans;

//         while (maxPosition != -1) {
//             ans.push_back(nums[maxPosition]);
//             maxPosition = parent[maxPosition];
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target)
//     {
//         int n = nums.size();

//         vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));

//         for (int i = 0; i <= n; i++) {
//             for (int j = 0; j <= target; j++) {
//                 if (i == 0 && j == 0) {
//                     memo[i][j] = 0;
//                 } else if (i == 0) {
//                     memo[i][j] = 0;
//                 } else if (j == 0) {
//                     memo[i][j] = 1;
//                 } else {
//                     if (nums[i - 1] <= j) {
//                         memo[i][j] = memo[i][j - nums[i - 1]] + memo[i - 1][j];
//                     } else {
//                         memo[i][j] = memo[i - 1][j];
//                     }
//                 }
//             }
//         }

//         return memo[n][target];
//     }
// };

// class Solution {
// public:
//     string multiply(string s, int n)
//     {
//         string t;

//         while (n--) {
//             t.append(s);
//         };

//         return t;
//     }
//     string decodeString(string s)
//     {
//         stack<string> st;
//         stack<int> indices;

//         int n = s.length();

//         int prevNum = 0;
//         string temp;
//         char ch;
//         for (int i = 0; i < n; i++) {
//             ch = s[i];
//             if (isdigit(ch)) {
//                 if (!temp.empty()) {
//                     st.push(temp);
//                     temp.clear();
//                 }
//                 prevNum = prevNum * 10 + (ch - '0');
//             } else if (isalpha(ch)) {
//                 temp.push_back(ch);
//             } else if (ch == '[') {
//                 st.push(to_string(prevNum));
//                 prevNum = 0;
//             } else if (ch == ']') {
//                 string d = multiply(temp, stoi(st.top()));
//                 st.pop();
//                 temp = st.empty() ? d : st.top() + d;
//                 if (!st.empty())
//                     st.pop();
//             }
//         }

//         return temp;
//     }
// };

// class Solution {
// public:
//     bool isCircularSentence(string sentence)
//     {
//         stringstream ss(sentence);
//         string word;
//         vector<string> words;

//         while (!ss.eof()) {
//             getline(ss, word, ' ');
//             words.push_back(word);
//         }
//         int n = words.size();
//         words.push_back(words[0]);

//         for (int i = 0; i < n; i++) {
//             if (words[i].back() != words[i + 1].front())
//                 return false;
//         }

//         return true;
//     }
// };

// class Solution {
// public:
//     long long dividePlayers(vector<int>& skill)
//     {
//         typedef long long ll;

//         ll sum = accumulate(skill.begin(), skill.end(), 0);
//         ll teamCount = skill.size() / 2;
//         ll groupSum = sum / teamCount;

//         sort(skill.begin(), skill.end());

//         ll b = 0;
//         ll e = skill.size() - 1;
//         ll product = 0;

//         while (b <= e) {
//             if (skill[b] + skill[e] != groupSum)
//                 return -1;

//             product = product + (skill[b] * skill[e]);
//             b++;
//             e--;
//         }

//         return product;
//     }
// };

// class Solution {
// public:
//     bool find132pattern(vector<int>& nums)
//     {
//         bool inc = false;
//         bool dec = false;

//         int n = nums.size();

//         if (n <= 2)
//             return false;

//         for (int i = 1; i < n; i++) {
//             if (!inc) {
//                 if (nums[i - 1] < nums[i]) {
//                     inc = true;
//                 }
//             }

//             if (inc) {
//                 if (nums[i - 1] > nums[i]) {
//                     dec = true;
//                 }
//             }
//         }

//         return inc & dec;
//     }
// };

// class Solution {
// public:
//     int minCameraCover(TreeNode* root)
//     {
//         function<int(TreeNode*, bool)> preorder = [&](TreeNode* r, bool flag) -> int {
//             if (r == nullptr)
//                 return 0;

//             int leftTrue = INT_MAX, rightTrue = INT_MAX, leftFalse = INT_MAX, rightFalse = INT_MAX;

//             return flag + preorder(r->left, !flag) + preorder(r->right, !flag);
//         };

//         int ans = min(preorder(root, false), preorder(root, true));

//         if (root == nullptr)
//             return 0;

//         if (ans == 0 && root != nullptr)
//             return 1;

//         return ans;
//     }
// };

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> M(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                M[i][j] = M[i - 1][j] + M[i][j - 1] - M[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int count = 0;

        for (int r1 = 0; r1 < n; r1++) {
            for (int r2 = 0; r2 <= r1; r2++) {
                for (int c1 = 0; c1 < m; c1++) {
                    for (int c2 = 0; c2 < c1; c2++) {
                        int sum = M[r2 + 1][c2 + 1] - M[r1][c2 + 1] - M[r2 + 1][c1] + M[r1][c1];

                        if (sum == target)
                            count++;
                    }
                }
            }
        }

        return count;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        vector<int> temp = nums;

        sort(temp.begin(), temp.end());
        int n = nums.size();

        int begin = 0, end = 0;

        for (int i = 0; i < n; i++) {
            if (temp[i] != nums[i]) {
                begin = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (temp[i] != nums[i]) {
                end = i;
                break;
            }
        }

        return end - begin + (end != begin);
    }
};

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
    {
        vector<vector<int>> adjList(n);
        vector<vector<int>> result;

        for (auto it : connections) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        int timer = 1;
        vector<bool> visited(n, false);
        vector<int> low(n, INT_MAX), tIn(n, INT_MAX);

        function<void(int, int)> dfs = [&](int current, int parent) -> void {
            visited[current] = true;

            low[current] = tIn[current] = timer++;

            for (auto it : adjList[current]) {
                if (it == parent)
                    continue;

                if (!visited[it]) {
                    dfs(it, current);
                    low[current] = min(low[current], low[it]);

                    if (low[it] > tIn[current]) {
                        result.push_back({ it, current });
                    }
                } else {
                    low[current] = min(low[current], tIn[it]);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                dfs(i, -1);
        }

        return result;
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> t(n, 1), sum(n, 1);
        int value = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    if (t[j] + 1 > t[i]) {
                        t[i] = 1 + t[j];
                        sum[i] = sum[j];
                    } else if (t[i] == 1 + t[j]) {
                        sum[i] += sum[j];
                    }
                }
            }

            if (maxLen < t[i]) {
                maxLen = t[i];
                value = sum[i];
            } else if (maxLen == t[i]) {
                value += sum[i];
            }
        }

        return value;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        unordered_map<int, int> parent, rank;

        for (auto it : edges) {
            parent[it[0]] = it[0];
            parent[it[1]] = it[1];
            rank[it[1]] = 0;
            rank[it[0]] = 0;
        }

        function<int(int)> findParent = [&](int a) -> int {
            return parent[a] == a
                ? a
                : parent[a] = findParent(parent[a]);
        };

        function<void(int, int)> doUnion = [&](int a, int b) {
            int x = findParent(a);
            int y = findParent(b);

            if (rank[a] > rank[b]) {
                parent[b] = x;
            } else if (rank[a] < rank[b]) {
                parent[a] = y;
            } else {
                parent[a] = b;
                rank[b]++;
            }
        };

        vector<int> ans;

        for (auto it : edges) {
            if (findParent(it[0]) != findParent(it[1])) {
                doUnion(it[0], it[1]);
            } else {
                ans = it;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
    {
    }
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root)
    {
        function<int(TreeNode*, int, int)> preorder = [&](TreeNode* r, int minValue, int maxValue) -> int {
            if (r == nullptr)
                return INT_MIN;

            if (r->left == nullptr && r->right == nullptr) {
                return max({ abs(minValue - r->val), abs(maxValue - r->val), abs(maxValue - minValue) });
            }

            int left = preorder(r->left, min(minValue, r->val), max(maxValue, r->val));
            int right = preorder(r->right, min(minValue, r->val), max(maxValue, r->val));

            return max(abs(left), abs(right));
        };

        return preorder(root, INT_MAX, INT_MIN);
    }
};

class Solution {
public:
    int maximumValue(vector<string>& strs)
    {
        int maxValue = INT_MIN;

        function<bool(string&)> isNumeric = [&](string& s) -> bool {
            int l = s.size();

            for (int i = 0; i < l; i++)
                if (!isdigit(s[i]))
                    return false;

            return true;
        };

        for (auto it : strs) {
            if (isNumeric(it)) {
                maxValue = max(maxValue, stoi(it));
            } else {
                maxValue = max(maxValue, (int)it.size());
            }
        }

        return maxValue;
    }
};

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k)
    {
        int n = vals.size();
        vector<vector<int>> adjList(n);

        for (auto it : edges) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        vector<bool> visited(n, false);
        queue<int> q;

        int ans = INT_MIN;

        function<void(int)> bfs = [&](int start) {
            q.push(start);
            visited[start] = true;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                priority_queue<int> pq;

                for (auto b : adjList[node]) {
                    pq.push(vals[b]);
                }

                int time = min((int)pq.size(), k);
                int value = vals[node];
                while (time--) {
                    if (pq.top() > 0)
                        value += pq.top();
                    pq.pop();
                }

                ans = max(ans, value);

                for (auto it : adjList[node]) {
                    if (!visited[it]) {
                        visited[it] = true;
                        q.push(it);
                    }
                }
            };
        };

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(i);
            }
        }

        return ans;
    };
};

class Solution {
public:
    int maxJump(vector<int>& stones)
    {
        int n = stones.size();
        int ans = INT_MAX;
        function<void(int, int, int, int)> dfs = [&](int i, int j, int maxI, int maxJ) {
            if (i >= n && j >= n) {
                ans = min({ maxI, maxJ, ans });
                return;
            }
        };
    }
};

class Solution {
public:
    int kthGrammar(int n, int k)
    {
        function<int(vector<int>&, int)> dfs = [&](vector<int>& t, int u) -> int {
            if (u == 1)
                return t[k - 1];

            int n = t.size();

            for (int i = 0; i < n; i++) {
                t.push_back(t[i] == 0 ? 1 : 0);
            }

            return dfs(t, n - 1);
        };

        vector<int> t { 0 };

        return dfs(t, n);
    }
};

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        typedef long long ll;

        for (int i = 0; i < n; i++) {
            sort(grid[i].begin(), grid[i].end());
        }

        ll sum = 0;

        for (int j = m - 1; j >= 0; j--) {
            int temp = INT_MIN;
            for (int i = 0; i < n; i++) {
                temp = max(temp, grid[i][j]);
            }

            sum += temp;
        }

        return (int)sum;
    }
};

class Solution {
public:
    bool isPossible(vector<int>& target)
    {
        int n = target.size();

        vector<int> temp(n, 1);

        function<int(int)> tryCombinations = [&](int current) -> int {

        };
    }
};

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n)
    {
        unordered_map<int, vector<TreeNode*>> mp;
        mp[1] = { new TreeNode(0) };

        function<TreeNode*(TreeNode*)> createTree = [&](TreeNode* r) -> TreeNode* {
            if (r == nullptr)
                return r;

            TreeNode* a = new TreeNode(0);
            a->left = createTree(r->left);
            a->right = createTree(r->right);

            return a;
        };

        function<vector<TreeNode*>(int)> recurse = [&](int m) -> vector<TreeNode*> {
            if ((n & 1) == 0)
                return {};

            if (n == 1) {
                return { new TreeNode(0) };
            }

            if (mp.count(n)) {
                return mp[n];
            }

            vector<TreeNode*> ans;

            for (int i = 1; i < n; i += 2) {
                auto leftPossibleTrees = allPossibleFBT(i);
                auto rightPossibleTrees = allPossibleFBT(n - i - 1);

                for (auto x : leftPossibleTrees) {
                    for (auto y : rightPossibleTrees) {
                        TreeNode* root = new TreeNode(0);
                        root->left = createTree(x);
                        root->right = createTree(y);

                        ans.push_back(root);
                    }
                }
            }

            return mp[n] = ans;
        };

        return recurse(n);
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        struct cell {
            int i, j, cost = INT_MAX;
        };

        vector<vector<int>> memo(n, vector<int>(m, INT_MAX));

        priority_queue<cell> pq;
        vector<pair<int, int>> nebors = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

        pq.push({ 0, 0, 0 });

        while (!pq.empty()) {
            cell c = pq.top();
            pq.pop();

            for (int i = 0; i < 4; i++) {
                auto it = nebors[i];
                int x = it.first + c.i;
                int y = it.second + c.j;

                if (0 <= x && x < n && 0 <= y && y < n) {
                }
            }
        }
    }
};

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue)
    {
        int n = stoneValue.size();
        vector<int> memo(n + 10, 1e8);

        function<int(int)> f = [&](int i) -> int {
            if (i >= n)
                return 0;

            if (memo[i] != 1e8)
                return memo[i];

            int value = 0;

            value = stoneValue[i] + min({ f(i + 2), f(i + 3), f(i + 4) });

            if (i + 1 < n) {
                value = max(value, stoneValue[i] + stoneValue[i + 1] + min({ f(i + 3), f(i + 4), f(i + 5) }));
            }

            if (i + 2 < n) {
                value = max(value, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] + min({ f(i + 4), f(i + 5), f(i + 6) }));
            }

            return memo[i] = value;
        };

        int alice = f(0);
        int totalSum = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        int bob = totalSum - alice;

        if (alice > bob)
            return "Alice";
        else if (alice < bob)
            return "Bob";

        return "Tie";
    }
};

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k)
    {
        int M = 1e9 + 7;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(k, -1)));

        function<int(int, int, int)> f = [&](int i, int j, int rem) -> int {
            int y, x;
            y = grid[i][j] % k;
            x = rem - y;

            if (x < 0)
                x += k;

            if (i == 0 && j == 0) {
                return x == 0;
            }

            if (memo[i][j][rem] != -1)
                return memo[i][j][rem];

            int value = 0;

            if (i - 1 >= 0) {
                value = (value + f(i - 1, j, x)) % M;
            }

            if (j - 1 >= 0) {
                value = (value + f(i, j - 1, x)) % M;
            }

            return memo[i][j][rem] = value;
        };

        return f(n - 1, m - 1, 0);
    }
};

class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> memo(n + 1, -1);

        function<int(int)> f = [&](int currentI) -> int {
            if (currentI >= n)
                return 0;

            if (memo[currentI] != -1)
                return memo[currentI];

            return memo[currentI] = max(f(currentI + 1), f(currentI + 2) + nums[currentI]);
        };

        return f(0);
    }
};

class Solution {
public:
    int numOfWays(int n)
    {
        typedef long long ll;
        int l = n - 1;
        ll count121 = 6, count123 = 6;
        ll t121, t123;
        int M = 1E9 + 7;

        while (l--) {
            t121 = (count121 * 3 * 1ll + count123 * 2 * 1ll) % M;
            t123 = (count121 * 2 * 1ll + count123 * 2 * 1ll) % M;
            count121 = t121;
            count123 = t123;
        }

        return (int)(count121 + count123) % M;
    }
};

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        int n = arr.size();

        vector<int> memo(n, -1);

        function<int(int)> f = [&](int currentI) -> int {
            if (currentI >= n)
                return 0;

            if (memo[currentI] != -1)
                return memo[currentI];

            int sum = 0;

            int maxValue = arr[currentI];

            for (int i = 1; i <= k && currentI + i - 1 < n; i++) {
                maxValue = max(maxValue, arr[currentI + i - 1]);
                sum = max(sum, maxValue * (i) + f(currentI + i));
            }

            return memo[currentI] = sum;
        };

        return f(0);
    }
};

class Solution {
public:
    int ways(vector<string>& pizza, int k)
    {
        int M = 1e9 + 7;

        int n = pizza.size();
        int m = pizza[0].size();

        vector<vector<int>> pfSum(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pfSum[i][j] = pfSum[i - 1][j] + pfSum[i][j - 1]
                        - pfSum[i - 1][j - 1] + pizza[i - 1][j - 1]
                    == 'A';
            }
        }

        function<int(int, int, int)> f = [&](int a, int b, int k) -> int {

        };
    }
};

class Solution {
public:
    string removeDuplicates(string s, int k)
    {
        set<char> st(s.begin(), s.end());
        set<string> toFind;

        for (auto it : st) {
            toFind.insert(string(k, it));
        }

        string temp;

        while (true) {
            bool flag = false;
            int n = s.length();
            temp.clear();

            int i = 0;
            while (i <= n - k) {
                string t = s.substr(i, k);

                if (toFind.find(t) != toFind.end()) {
                    i = i + k;
                    flag = true;
                    continue;
                } else {
                    temp.push_back(s[i]);
                }

                i++;
            }

            while (i < n) {
                temp.push_back(s[i++]);
            }

            if (flag == true)
                s = temp;
            else
                break;
        }

        return s;
    }
};

class Solution {
public:
    string removeDuplicates(string s, int k)
    {
        struct letter {
            char ch;
            int count = 0;
        };

        stack<letter> st;
        st.push({ 'A', 0 });

        for (auto it : s) {
            if (st.top().ch == it) {
                if (st.top().count + 1 == k)
                    st.pop();
                else
                    st.top().count++;
            } else {
                st.push({ it, 1 });
            }
        }

        string ans;

        while (!st.empty()) {
            ans.append(string(st.top().count, st.top().ch));
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k)
    {
        typedef long long ll;
        int kadaneSum = kadane(arr);

        int M = 1e9 + 7;

        if (k == 1)
            return kadaneSum;

        int n = arr.size();

        int sum = accumulate(arr.begin(), arr.end(), 0);

        for (int i = 0; i < n; i++)
            arr.push_back(arr[i]);

        int twoKadaneSum = kadane(arr);

        if (sum < 0)
            return twoKadaneSum % M;

        ll sumRest = (k - 2) * 1ll * sum;

        return (sumRest + twoKadaneSum) % M;
    }

    int kadane(vector<int>& arr)
    {
        int n = arr.size();
        int sum = 0;
        int value = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum < 0)
                sum = 0;
            value = max(value, sum);
        }

        return value;
    }
};

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(m, -1)));

        function<int(int, int, int)> f = [&](int r, int c1, int c2) -> int {
            if (r >= n)
                return 0;

            if (memo[r][c1][c2] != -1)
                return memo[r][c1][c2];

            vector<int> cols = { -1, 0, 1 };
            int maxCherry = 0;
            int posGain = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
            int temp = 0;

            for (int j1 = 0; j1 < 3; j1++) {
                for (int j2 = 0; j2 < 3; j2++) {
                    int col1 = c1 + cols[j1];
                    int col2 = c2 + cols[j2];

                    if (0 <= col1 && col1 < m && 0 <= col2 && col2 < m) {
                        temp = f(r + 1, col1, col2);
                        maxCherry = max(maxCherry, temp);
                    }
                }
            }

            return memo[r][c1][c2] = maxCherry + posGain;
        };

        return f(0, 0, m - 1);
    }
};

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& queries)
    {
        vector<vector<int>> adjList(n);

        for (auto it : prereq) {
            adjList[it[0]].push_back(it[1]);
        }
    }
};

class Solution {
public:
    bool winnerSquareGame(int n)
    {
    }
};

class Solution {
public:
    int minNumberOperations(vector<int>& target)
    {
        int x = 0;
        int sum = 0;

        for (auto it : target) {
            if (it > x) {
                sum += it - x;
                x = it;
            }

            return sum;
        }
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
    {
        double ans = -DBL_MAX;
        typedef pair<int, double> pd;
        vector<vector<pd>> adjList(n);
        vector<double> distance(n, 0);

        for (int i = 0; i < edges.size(); i++) {
            auto it = edges[i];
            double cost = succProb[i];

            adjList[it[0]].push_back({ it[1], cost });
            adjList[it[1]].push_back({ it[0], cost });
        }

        function<bool(pd&, pd&)> compare = [&](pd& a, pd& b) -> bool {
            return a.second > b.second;
        };

        priority_queue<pd, vector<pd>, decltype(compare)> q(compare);

        q.push({ start, 1 });
        distance[start] = 1;

        while (!q.empty()) {
            auto node = q.top();
            q.pop();

            if (node.first == end) {
                return node.second;
            }

            for (auto it : adjList[node.first]) {
                if (node.second * it.second > distance[it.first]) {
                    distance[it.first] = node.second * it.second;
                    q.push({ it.first, distance[it.first] });
                }
            }
        }

        return 0;
    }
};

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        vector<int> temp;

        function<int(string, int)> dfs = [&](string current, int) -> int {
            if (k == 0) {
                stack<pair<char, int>> st;

                for (auto it : current) {
                    if (st.size() && st.top().first == it) {
                        st.top().second++;
                    } else {
                        st.push({ it, 1 });
                    }
                }

                int count = 0;
                while (!st.empty()) {
                    count++;
                    st.top().second >= 10 ? count += 2 : count++;
                    st.pop();
                }

                return count;
            }
        };
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int end)
    {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);

        for (auto it : edges) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        queue<int> q;

        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == end)
                return true;

            for (auto it : adjList[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }

        return false;
    }
};

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        priority_queue<int> pq;
        int n = heights.size();
        pq.push(0);
        int ans = 0;

        for (int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i - 1];

            if (diff <= 0)
                continue;

            if (pq.top() >= diff) {
            }

            ans = i;
        }
    }
};

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> adjList(n);
        unordered_map<int, unordered_map<int, int>> memo;

        for (auto it : edges) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        vector<int> answer(n);

        function<int(int)> f = [&](int current) -> int {
            vector<int> visited(n, false);
            queue<int> q;
            visited[current] = true;
            q.push(current);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto it : adjList[node]) {
                    if (!visited[it]) {
                        visited[it] = true;
                        q.push(it);
                    }
                }
            }
        };

        for (int i = 0; i < n; i++) {
        }
    }
};

class Solution {
public:
    vector<long long> lcmAndGcd(long long A, long long B)
    {
    }
};

class Solution {
public:
    long long primeProduct(long long L, long long R)
    {
        int M = 1e9 + 7;
        typedef long long ll;

        ll sq = sqrt(R);
        vector<ll> basePrimes;

        function<void(ll)> findBasePrimes = [&](ll sq) {
            vector<bool> temp(sq + 1, true);
            temp[0] = temp[1] = false;

            for (int i = 2; i <= sq; i++) {
                if (temp[i] == true) {
                    for (int j = i * 2; j <= sq; j += i) {
                        temp[j] = false;
                    }
                }
            }

            for (int i = 2; i <= sq; i++) {
                if (temp[i] == true) {
                    basePrimes.push_back(i);
                }
            }
        };

        findBasePrimes(sq);

        // finding useful primes.
        ll maxLength = R - L + 1;
        vector<bool> primesFlag(maxLength, true);

        for (auto p : basePrimes) {
            int lowestMultiple = (L / p) * p;
            if (lowestMultiple < p)
                lowestMultiple += p;

            for (ll j = lowestMultiple; j <= R; j += p) {
                primesFlag[j - L] = false;
            }
        }

        ll ans = 1;

        for (ll i = 0; i < maxLength; i++) {
            if (primesFlag[i] == true) {
                ans = (ans * (i + L)) % M;
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries)
    {
        int n = nums.size();
        vector<int> prefixSum(nums.size() + 1, 0);
        unordered_map<int, int> mp;

        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        int sum;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                sum = prefixSum[i + 1] - prefixSum[j];

                if (mp.count(sum))
                    mp[sum] = max(mp[sum], abs(i - j + 1));
                else
                    mp[sum] = i - j + 1;
            }
        }

        vector<int> ans;

        for (auto it : queries) {
            ans.push_back(mp[it]);
        }

        return ans;
    }
};

class Solution {
    vector<int> primes;

    void sieve(int sq)
    {
        vector<bool> p(sq + 1, true); // including that number also.

        p[0] = false;
        p[1] = false;

        for (int i = 2; i <= sq; i++) {
            if (p[i] == true) {
                this->primes.push_back(i);
                for (int j = i * 2; j <= sq; j += i) {
                    p[j] = false;
                }
            }
        }
    }

    void segmentedSieve(int l, int h)
    {
        int sq = sqrt(h);

        vector<int> p(h - l + 1, true);

        sieve(sq);

        for (auto it : primes) {
            int e = (l / it) * it;

            if (e < l) {
                e += it;
            }

            if (e == it) {
                e += it;
            }

            for (int j = e; j <= h; j += it) {
                p[j - l] = false;
            }
        }

        vector<int> answer;

        for (int i = l; i <= h; i++) {
            if (p[i - l]) {
                answer.push_back(i);
            }
        }
    }
};

int main()
{
    int t;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> t;
    while (t--) {
        Solution solution;

        string a, b, c, d, e;
        cin >> a;
        cin >> b;
        // cin >> c;

        // cin >> d;
        // cin >> e;
        // cin >> c;
        // cin >> d;
        auto input1 = deserialize2d<int>(a);
        auto input2 = sanitize<int>(b);
        // auto input3 = deserialize<int>(c);
        // auto input4 = sanitize<int>(d);
        // auto input5 = sanitize<int>(e);
        // auto input3 = deserialise<int>(c);
        // auto input4 = deserialise<int>(d);

        auto output = solution.numSubmatrixSumTarget(input1, input2);

        print(output);
    }
}
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k)
//     {
//         int n = 0;

//         ListNode* temp = head;

//         if (head == nullptr || head->next == nullptr)
//             return head;

//         while (temp) {
//             n++;
//             temp = temp->next;
//         }

//         k = k % n;

//         int rotationCount = n - k;

//         if (rotationCount == 0)
//             return head;

//         temp = head;
//         ListNode* previous;

//         while (rotationCount--) {
//             previous = temp;
//             temp = temp->next;
//         }

//         auto newNode = temp;
//         previous->next = nullptr;

//         /** when temp has at least one next element */
//         while (temp->next) {
//             temp = temp->next;
//         }

//         temp->next = head;

//         return newNode;
//     }
// };
// nancy kumari
