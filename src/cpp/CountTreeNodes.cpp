#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
  ~TreeNode() {
    delete left;
    delete right;
  }
};

class Solution {
 public:
  int countNodes(TreeNode *root) {
    return root == NULL ? 0
                        : 1 + countNodes(root->left) + countNodes(root->right);
  }

  void printBT(const std::string &prefix, const TreeNode *node, bool isLeft) {
    if (node) {
      cout << prefix << (isLeft ? "├──" : "└──") << node->val << endl;
      printBT(prefix + (isLeft ? "    " : "    "), node->left, true);
      printBT(prefix + (isLeft ? "    " : "    "), node->right, false);
    }
  }

  void output(TreeNode *root) {
    cout << "Binary tree" << endl;
    printBT("", root, false);
    int ans = countNodes(root);
    cout << "has " << countNodes(root) << " node";
    if (ans != 1) cout << 's';
    cout << endl << endl;
  }
};

int main() {
  Solution s;
  TreeNode *t1 = new TreeNode(1, new TreeNode(), new TreeNode());
  s.output(t1);
  delete t1;
  TreeNode *t2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  s.output(t2);
  delete t2;
  TreeNode *t3 = new TreeNode();
  s.output(t3);
  delete t3;
  TreeNode *t4 = new TreeNode(
      5,
      new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)),
                   nullptr),
      new TreeNode(8, new TreeNode(13),
                   new TreeNode(4, nullptr, new TreeNode(1))));
  s.output(t4);
  delete t4;
  return 0;
}