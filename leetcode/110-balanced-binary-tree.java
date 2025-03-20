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
    boolean balanced = true;
    
    int height(TreeNode root) {
        if(root == null) return 0;

        int left_height = height(root.left);
        int right_height = height(root.right);

        if(Math.abs(left_height - right_height) > 1) {
            balanced = false;
            return 0;
        }
        
        return 1 + Math.max(left_height, right_height);
    }

    public boolean isBalanced(TreeNode root) {
        height(root);
        return balanced;
    }
}