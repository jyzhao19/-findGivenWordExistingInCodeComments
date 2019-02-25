/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      helper(root, p, q);
      return ans;
    }
private:
  bool helper(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root==NULL)
      return false;
      
    bool c1=false, c2=false, c3=false;
    if(root==p||root==q)
      c1=true;
    c2=helper(root->left, p, q);
    c3=helper(root->right, p, q);
    if(c1+c2+c3==2)
      ans=root;
    if(c1+c2+c3==1)
      return true;
    else
      return false;
  }
  TreeNode* ans;
};
