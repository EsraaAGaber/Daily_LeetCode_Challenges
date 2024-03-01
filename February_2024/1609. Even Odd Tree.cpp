/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
 #define sz(s) (int)s.size()
vector <vector <int >>vec;
class Solution {
public:
int mx=0;

    void dfs(TreeNode* root, int d) {
        if (root == NULL)
            return;
vec[d].push_back(root->val);
        mx=max(mx,d);
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }
    bool isEvenOddTree(TreeNode* root) {
        mx=0;
        vec=vector <vector <int >>(100001);
        dfs(root,0);
        if (vec[0][0]%2==0)return 0;
        for (int i=1;i<=mx;i++)
        {
            
            if (i%2)
            {
                if (sz(vec[i])==1)
                if (vec[i][0]%2)return 0;
                
                for (int j=1;j<sz(vec[i]);j++)
                {
                                            if (vec[i][j]>=vec[i][j-1]||vec[i][j]%2==1||vec[i][j-1]%2==1)return 0;

                }
                cout <<"\n";

            }
            else 
           { if (sz(vec[i])==1)
                if (vec[i][0]%2==0)return 0; for (int j=1;j<sz(vec[i]);j++)
                {
                    cout <<vec[i][j]<<" ";
                    if (vec[i][j]<=vec[i][j-1]||vec[i][j]%2==0||vec[i][j-1]%2==0)return 0;
                }cout <<"\n";}
        }
        return 1;
    }
};
