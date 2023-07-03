#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right && root->val - targetSum == 0) return true;
    bool left = hasPathSum(root->left, targetSum - root->val);
    bool right = hasPathSum(root->right, targetSum - root->val);
    return left || right;
  }

  void printBT(const std::string &prefix, const TreeNode *node, bool isLeft) {
    if (node) {
      cout << prefix << (isLeft ? "├──" : "└──") << node->val << endl;
      printBT(prefix + (isLeft ? "    " : "    "), node->left, true);
      printBT(prefix + (isLeft ? "    " : "    "), node->right, false);
    }
  }

  void output(TreeNode *root, int targetSum) {
    cout << "Tree\n";
    printBT("", root, false);
    cout << "Has ";
    if (!hasPathSum(root, targetSum))
      cout << "no";
    else
      cout << "a";
    cout << " path with nodes' values sum equal to " << targetSum << "\n\n";
  }
};

int main() {
  Solution s;
  TreeNode *t1 = new TreeNode(
      5,
      new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)),
                   nullptr),
      new TreeNode(8, new TreeNode(13),
                   new TreeNode(4, nullptr, new TreeNode(1))));
  s.output(t1, 22);
  TreeNode *t2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  s.output(t2, 7);
  s.output(t2, 4);
  return 0;
}