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
        // using a dict to store parent node of any node, then u can easily trace them back
      unordered_map<TreeNode*, TreeNode*> m;                
      stack<TreeNode* > s;
      s.push(root);
      m[root] = NULL;
        
      while (!m.count(p) || !m.count(q)) {
        auto n = s.top(); s.pop();
        if (n->left) {
          s.push(n->left);
          m[n->left] = n;
        }
        if (n->right) {
          s.push(n->right);
          m[n->right] = n;
        }
      }
      
      unordered_set<TreeNode*> pPath;
      TreeNode* pp = p;
      while (pp) {
        pPath.insert(pp);
        pp = m[pp];
      }
        
      TreeNode* qq = q;
      while (qq) {
        if (pPath.count(qq))
            break;
        qq = m[qq];
      }
      return qq;
    }
};
