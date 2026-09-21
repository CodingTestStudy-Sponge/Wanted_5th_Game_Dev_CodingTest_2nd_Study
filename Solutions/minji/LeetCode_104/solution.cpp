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
    int depth = 1;
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        // 큐 생성
        //queue<TreeNode*> q;
        queue<pair<TreeNode*, int>> q;
        TreeNode* currentNode = root;
        q.push(make_pair(currentNode, depth));
        while (!q.empty())
        {
            currentNode = q.front().first;
            //q.front().first 
            // 맨 앞의 노드가 루트만 아니면 depth를 올리기??????????????
            int newDepth = q.front().second + 1;
            if (currentNode->left != nullptr)
            {
                q.emplace(make_pair(currentNode->left, newDepth));
                if (newDepth > depth) depth = newDepth;

            }

            if (currentNode->right != nullptr)
            {
                q.emplace(make_pair(currentNode->right, newDepth));
                if (newDepth > depth) depth = newDepth;

            }
            q.pop();

        }

        return depth;
    }
};