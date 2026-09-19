class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool isTrue = false;

        if(!root)
        {
            return false;
        }


        if(root)
        {
            targetSum -= root->val;
            if(targetSum == 0 && !root->left && !root->right)
            {
                isTrue = true;
                return isTrue;
            }
            else
            {
                isTrue = hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
            }
            
        }
        return isTrue;
    }
};