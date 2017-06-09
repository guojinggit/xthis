//
// Created by Administrator on 2017/6/8.
//


#include <iostream>

struct BinaryTreeNode{
    int value;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
};



void prePrint(BinaryTreeNode* root){
    if (root == NULL)
        return;

    std::cout << root->value << std::endl;
    prePrint(root->pLeft);
    prePrint(root->pRight);
}

//统计二叉树的节点
int countBinaryTree(BinaryTreeNode* root){
    if (root == NULL)
        return 0;

    return countBinaryTree(root->pLeft) + countBinaryTree(root->pRight) + 1;

}

//统计二叉树的高度

int hightBinaryTree(BinaryTreeNode* root) {
    int h,letf,right;
    if (root == NULL)
        return 0;
    letf = hightBinaryTree(root->pLeft);
    right = hightBinaryTree(root->pRight);
    h = (letf > right?letf:right) +1;
    return h;
}

int main(){


    return 0;
}