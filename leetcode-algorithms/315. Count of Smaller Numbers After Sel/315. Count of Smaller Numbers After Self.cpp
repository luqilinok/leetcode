/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */
class Solution
{
    struct Node
    {
        shared_ptr<Node> left;
        shared_ptr<Node> right;
        int val;
        int count = 0;
        Node(int val) : val(val) {}
    };

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        shared_ptr<Node> root;
        vector<int> res(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            root = insert(root, nums[i], &res, i);
        }
        return res;
    }

    shared_ptr<Node> insert(shared_ptr<Node> root, int val, vector<int> *res, int index)
    {
        if (!root)
        {
            return make_shared<Node>(val);
        }
        auto &r = *res;
        if (val <= root->val)
        {
            root->count++;
            root->left = insert(root->left, val, res, index);
        }
        else
        {
            r[index] += root->count + 1;
            root->right = insert(root->right, val, res, index);
        }
        return root;
    }
};
