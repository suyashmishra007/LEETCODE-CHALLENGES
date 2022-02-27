class Pair {
public:
    TreeNode* node;
    long long index ;
    Pair(TreeNode *_node ,   long long _index) {
        node = _node ;
        index = _index;
    }
};
class Solution {
public:
  int widthOfBinaryTree(TreeNode* root) {
        if (!root) return  0 ;

        int maxWidth = 0 ;
        queue<pair<TreeNode*,   long long>> que ;
        que.push({root, 0});
        // 0 based indexing

        while (!que.empty()) {
            int size = que.size() ;
              long long last , first ;
              long long minIndex = que.front().second;

            for (int i = 0 ; i < size ; i++) {
                TreeNode *node = que.front().first;
                  long long currIndex = que.front().second-minIndex;
                que.pop();

                if (i == 0)
                    first = currIndex;
                if (i == size - 1)
                    last = currIndex;

                if (node->left) {
                    que.push({node->left, 1LL * (2 * currIndex + 1) });
                }
                if (node->right) {
                    que.push({node->right, (2 * currIndex + 2) * 1LL});
                }
            }
            maxWidth = max(maxWidth * 1LL, last - first + 1);
        }

        return  maxWidth;
    