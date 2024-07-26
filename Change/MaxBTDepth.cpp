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

int MaxBTDepth(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    else
        return 1 + std::max(MaxBTDepth(root->left), MaxBTDepth(root->right));
}

int main()
{
    std::cout << "Hello World!\n";
}
