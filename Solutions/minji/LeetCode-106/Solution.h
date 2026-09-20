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
    void NodeTraversal(TreeNode* currentNode, vector<int>& inorder, vector<int>& postorder)
    {
        if (postorder.size() == 0) return;
        auto it = find(inorder.begin(), inorder.end(), currentNode->val);
        // 루트 못찾았으면 리턴
        if (it == inorder.end()) return;

        // 왼오 나누기. 루트와같은값은 건너뛴다. 
        int endValue = 0;
        vector<int> left;
        vector<int> right;
        //왼쪽
        while (true)
        {
            if (inorder[endValue] == *it) // 0번째가 it일수도잇으니 맨앞에서 검사
                break;
            left.emplace_back(inorder[endValue]);
            endValue++;
        }
        //오른쪽
        for (int i = endValue + 1; i < inorder.size(); i++)
        {
            right.emplace_back(inorder[i]);
        }


        // 오른쪽 벡터에서 루트값 찾았으면 오른쪽자식에 추가
        auto it3 = find(right.begin(), right.end(), postorder.back());
        if (it3 != right.end())
        {
            // 찾았다면 right에 추가
            currentNode->right = new TreeNode(postorder.back());
            postorder.pop_back();
            NodeTraversal(currentNode->right, right, postorder);
        }
        // 왼쪽 벡터에서 루트값 찾았으면 왼쪽자식에 추가

        auto it2 = find(left.begin(), left.end(), postorder.back());
        if (it2 != left.end())
        {
            // 찾았다면 left에 추가
            currentNode->left = new TreeNode(postorder.back());
            postorder.pop_back();
            NodeTraversal(currentNode->left, left, postorder);
        }
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 중위 순회: 9->3->15->20->7 
        // 후위 순회: 9->15->7->20->3
        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();
        NodeTraversal(root, inorder, postorder);

        return root;
    }
};