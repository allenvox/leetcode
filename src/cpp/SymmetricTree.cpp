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
 private:
  bool testSymmetric(TreeNode *p, TreeNode *q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return (p->val == q->val && testSymmetric(p->left, q->right) &&
            testSymmetric(p->right, q->left));
  }

 public:
  bool isSymmetric(TreeNode *root) {
    if (!root) return true;
    return testSymmetric(root->left, root->right);
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
    cout << "is ";
    if (!isSymmetric(root)) cout << "not ";
    cout << "symmetric" << endl << endl;
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
  return 0;
}