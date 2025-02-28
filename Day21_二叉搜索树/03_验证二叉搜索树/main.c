
httpsleetcode.cnproblemsvalidate-binary-search-tree
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。


示例 1：


输入：root = [2,1,3]
输出：true
示例 2：


输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。


提示：

树中节点数目范围在[1, 104] 内
-231 = Node.val = 231 - 1



  Definition for a binary tree node.
  struct TreeNode {
      int val;
      struct TreeNode left;
      struct TreeNode right;
  };
 


bool checkVaild(struct TreeNode root, long long min, long long max) {
    if (root == NULL) {
        return true;
    }
    if (root-val = max) {
        return false;
    }
    if (root-val = min) {
        return false;
    }

    return checkVaild(root-left, min, root-val) && checkVaild(root-right, root-val, max);

}

bool isValidBST(struct TreeNode root) {
    return checkVaild(root, LONG_MIN, LONG_MAX);
}


bool vaildBST(struct TreeNode root) {
    if (root == NULL) {
        return true;
    }

    if (root-left) {
        struct TreeNode tempLeft = root-left;
        while (tempLeft-right) {
            tempLeft = tempLeft-right;
        }
        if (root-val = tempLeft-val) {
            return false;
        }
        if (!vaildBST(root-left)) {
            return false;
        }
    }
    
    if (root-right) {
        struct TreeNode tempRight = root-right;
        while (tempRight-left) {
            tempRight = tempRight-left;
        }
        if (root-val = tempRight-val) {
            return false;
        }
        if (!vaildBST(root-right)) {
            return false;
        }
    }
    
    return true;

}

bool isValidBST(struct TreeNode root) {
    return vaildBST(root);
}


int num1[10001];
int numsize = 0;
void inorderTraversal(struct TreeNode node) {
    if (node) {
        inorderTraversal(node-left);
        num1[numsize++] = node-val;
        inorderTraversal(node-right);
    }
}
bool isValidBST(struct TreeNode root) {
    numsize = 0;
    inorderTraversal(root);
    for (int i = 1; i  numsize; ++i) {
        if (num1[i] = num1[i - 1]) {
            return false;
        }
    }
    return true;
}