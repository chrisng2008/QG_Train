//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H
#include <stdio.h>
#define true 1
#define false 0
#define succeed 1
#define failed


typedef enum Status
{
    ERROR = 0,
    SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct Node{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree{
    NodePtr root;
} BinarySortTree, *BinarySortTreePtr;

typedef struct BNode
{
    Node data;
    int time;
}BNode;


/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr);

void CreateBiTree(NodePtr T);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr T, ElemType data);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status searchBST(NodePtr T,ElemType data);
Status BST_delete(BinarySortTreePtr, ElemType data);
/**
 * delete
 * @param NodePtr p
 * @param 从二叉树中删除结点p，并重接它的左或右子树
 * @return is successful
 */
void DeleteBST(NodePtr T,ElemType data);
Status Delete(NodePtr p);
/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr, ElemType);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
 //无递归前序遍历
Status BST_preorderI(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
 //有递归
Status BST_preorderR(BinarySortTreePtr, void (*visit)(NodePtr));
void PreOrderTraverse(NodePtr T,void (*visit)(NodePtr));
/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(BinarySortTreePtr, void (*visit)(NodePtr));
void InOrderTraverse(NodePtr T, void (*visit)(NodePtr));
/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
 //后序遍历的非递归实现
Status BST_postorderI(BinarySortTreePtr, void (*visit)(NodePtr));
void PostOrderTraverse(NodePtr T, void (*visit)(NodePtr));
/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr T, void (*visit)(NodePtr));

/**
 * get the deepth of the BinarySortTree
 * @param BinarySortTreePtr T
 * @return None
 */
int getTreeDeepth(NodePtr T);

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
