class Solution {
public:
    void recursivePath(TreeNode* root, int targetSum, vector<int>& singlePath, vector<vector<int>>& path)
    {
        if(!root)
        {
            return;
        }

        targetSum -= root->val;
        singlePath.push_back(root->val);
        if(targetSum == 0 && !root->left && !root->right)
        {
            path.push_back(singlePath);
        }
        
        recursivePath(root->left, targetSum, singlePath, path);
        recursivePath(root->right, targetSum, singlePath, path);
        singlePath.pop_back();
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> array;
        vector<vector<int>> answer;

        recursivePath(root, targetSum, array, answer);

        return answer;
    }
};