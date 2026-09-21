class Solution {
public:

    void order(TreeNode* root, vector<int>& path)
    {
        if(!root) return;

        //배열의 주소를 알려주고 순회돌면서 하나씩 넣어주기.
        order(root->left, path);
        path.push_back(root->val);
        order(root->right, path);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;

        order(root, answer);

        return answer;
    }
};