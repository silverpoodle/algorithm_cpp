package leetcode;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {

    int largestDiameter = 0;

    int height(TreeNode root) {
        if(root == null) return 0;

        int right_height = height(root.right);
        int left_height = height(root.left);
        largestDiameter = Math.max(right_height + left_height, largestDiameter);

        return 1 + Math.max(left_height, right_height);
    }

    public int diameterOfBinaryTree(TreeNode root) {
        height(root);
        return largestDiameter;
    }
}