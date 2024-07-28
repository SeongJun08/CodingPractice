#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool IsSameBT(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;

    return (p->val == q->val) && IsSameBT(p->left, q->left) && IsSameBT(p->right, q->right);

}


int main()
{
    TreeNode *tree1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode *tree2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    if (IsSameBT(tree1, tree2))
    {
        std::cout << "True" << std::endl;
    }
    else { std::cout << "False" << std::endl; }

    TreeNode *tree3 = new TreeNode(1, new TreeNode(2), nullptr);
    TreeNode *tree4 = new TreeNode(1, nullptr, new TreeNode(3));
    if (IsSameBT(tree3, tree4))
    {
        std::cout << "True" << std::endl;
    }
    else { std::cout << "False" << std::endl; }

    TreeNode *tree5 = new TreeNode(1, new TreeNode(2), new TreeNode(1));
    TreeNode *tree6 = new TreeNode(1, new TreeNode(1), new TreeNode(1));
    if (IsSameBT(tree5, tree6))
    {
        std::cout << "True" << std::endl;
    }
    else { std::cout << "False" << std::endl; }
}
