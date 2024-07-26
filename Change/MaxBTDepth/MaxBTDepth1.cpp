int MaxBTDepth(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    std::queue<std::pair<TreeNode*, int>> q;
    q.push({root,1});
    int result{};
    while (!q.empty())
    {
        auto node = q.front().first;
        int depth = q.front().second;
        q.pop();

        result = std::max(result, depth);

        if (node->left) { q.push({node->left,depth+1}); }
        if (node->right) { q.push({ node->right,depth + 1 } ); }
    }

    return result;
}
