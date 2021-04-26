//
// Created by Chris on 2021/4/23.
//
#include "binary_sort_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
#include "LinkStack.h"
#include "LinkList.h"
/*二叉树根节点的初始化*/
//初始化我们需要填入一个排序好的序列
Status BST_init(BinarySortTreePtr T)
{
    T = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    if(T==NULL)
        return false;
    else
    {
        T->root =NULL;
    }
    return succeed;
}

void CreateBiTree(NodePtr T)
{
    int num;
    scanf("%d",&num);
    if(num =='#')
        T = NULL;
    else
    {
        T = (NodePtr)malloc(sizeof(Node));
        T->value = num;//生成根节点
        CreateBiTree(T->left);
        CreateBiTree(T->right);
    }
}

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
 /*二叉树的插入，*/
Status BST_insert(BinarySortTreePtr T, ElemType data)
{
    /*如果该二叉树为空树*/
    NodePtr p=T->root;
    if(T->root == NULL){
        T->root = (NodePtr)malloc(sizeof(Node));
        T->root->right=NULL;
        T->root->left=NULL;
        T->root->value=data;
    }
    else
    {
        //定位
        while(p)
        {
            //找到合适位置
            if(data< p->value && p->left!=NULL)
                p = p->left;
            if(data>p->value && p->right!=NULL)
                p= p->right;
            if(data < p->value && p->left==NULL)
            {
                p->left = (NodePtr)malloc(sizeof(Node));
                p->left->value=data;
                p->left->left=NULL;
                p->left->right=NULL;
                break;
            }
            if(data > p->value && p->right==NULL)
            {
                p->right = (NodePtr)malloc(sizeof(Node));
                p->right->value=data;
                p->right->left=NULL;
                p->right->right=NULL;
                break;
            }
            if(data==p->value)
                break;
        }
    }
    return succeed;
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr T, ElemType data)
{

    NodePtr p = (*T).root;
    NodePtr pre = p;
    NodePtr s;
    if(p==NULL)
        return false;
    if(BST_search(T,data)==false)
        return false;
    if(data==p->value&&p->left!=NULL)
    {
        s = p->left;
        while(s->right)
        {
            s = s->right;
        }
        if(s->left!=NULL)
        {
            pre = s;
            s = s->left;
            ElemType temp;
            temp = p->value;
            p->value=pre->value;
            pre->value=temp;
            free(pre);
        }
        else{
            ElemType temp;
            temp = p->value;
            p->value=s->value;
            s->value=temp;
            free(s);
        }
    }
    else if(data<p->value)
        p=p->left;
    else if(data>p->value)
        p=p->right;
    else if(data==p->value)
    {
        if(p->left!=NULL&&p->right==NULL)
        {
            s = p;
            p=p->left;
            free(s);
        }
        else if(p->left==NULL&&p->right!=NULL)
        {
            s = p;
            p=p->right;
            free(s);
        }
            //末尾
        else if(pre->right->value==data&&p->left==NULL&&p->right==NULL)
        {
            Delete(p);
            pre->right=NULL;
        }
        else if(pre->left->value==data&&p->left==NULL&&p->right==NULL)
        {
            Delete(p);
            pre->left=NULL;
        }
        else if(p->left!=NULL&&p->right!=NULL) {
            s = p->left;
            while (s->right) {
                s = s->right;
            }
            if (s->left != NULL) {
                pre = s;
                s = s->left;
                ElemType temp;
                temp = p->value;
                p->value = pre->value;
                pre->value = temp;
                free(pre);
            } else {
                ElemType temp;
                temp = p->value;
                p->value = s->value;
                s->value = temp;
                free(s);
            }
        }
    }
    while(p->value!=data)
    {
        if(data<p->value)
        {
            pre = p;
            p = p->left;
        }
        else if(data > p->value)
        {
            pre = p;
            p = p->right;
        }
    }
    if(p->left!=NULL&&p->right==NULL)
    {
        s = p;
        p=p->left;
        free(s);
    }
    else if(p->left==NULL&&p->right!=NULL)
    {
        s = p;
        p=p->right;
        free(s);
    }
    //末尾
    else if(pre->right->value==data&&p->left==NULL&&p->right==NULL)
    {
        Delete(p);
        pre->right=NULL;
    }
    else if(pre->left->value==data&&p->left==NULL&&p->right==NULL)
    {
        Delete(p);
        pre->left=NULL;
    }
    else if(p->left!=NULL&&p->right!=NULL) {
        s = p->left;
        while (s->right) {
            s = s->right;
        }
        if (s->left != NULL) {
            pre = s;
            s = s->left;
            ElemType temp;
            temp = p->value;
            p->value = pre->value;
            pre->value = temp;
            free(pre);
        } else {
            ElemType temp;
            temp = p->value;
            p->value = s->value;
            s->value = temp;
            free(s);
        }
    }
    return succeed;
}

Status Delete(NodePtr p)
{
    NodePtr q,s;
    if(p->right==NULL&&p->left==NULL)
        free(p);
    else if(p->right==NULL)
    {
        q=p;
        p=p->left;
        free(q);
    }
    else if(p->left==NULL)
    {
        q=p;
        p=p->right;
        free(q);
    } else{
        q=p;
        s=p->left;
        while(s->right)
        {
            q=s;
            s=s->right;
        }
        p->value=s->value;
        if(q!=p)
            q->right=s->left;
        else
            q->left=s->right;
        free(s);
    }
    return succeed;
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr T, ElemType data)
{
   if(T->root==NULL)
       return false;
   NodePtr p = T->root;
    if(data == T->root->value)
        return succeed;
    else if(data < p->value)
        return searchBST(p->left,data);
    else if(data>p->value)
        return searchBST(p->right,data);
}

Status searchBST(NodePtr T,ElemType data)
{
    if(!T)
        return false;
    else if(data == T->value)
        return succeed;
    else if(data<T->value)
        return searchBST(T->left,data);
    else
        return searchBST(T->right,data);
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
/*非递归实现前序遍历*/
Status BST_preorderI(BinarySortTreePtr T, void (*visit)(NodePtr))
{
    if(T->root==NULL)
        return false;
    NodePtr p = T->root;
    NodePtr temp;
    temp = (NodePtr)malloc(sizeof(Node));
    LinkStack s;
    initLStack(&s);
    //首元素入栈
    pushLStack(&s,p);
    while(!isEmptyLStack(&s))
    {
        //先出栈，再将该结点的左右孩子入栈
        //根据栈的特殊性，应该先将栈的右孩子先入栈
        popLStack(&s,temp);
        visit(temp);
        //栈的右左孩子入栈
        if(temp->right!=NULL)
            pushLStack(&s,temp->right);
        if(temp->left!=NULL)
            pushLStack(&s,temp->left);
    }
    return succeed;
}

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */

Status BST_preorderR(BinarySortTreePtr T, void (*visit)(NodePtr))
{
    NodePtr p = T->root;
    if(p==NULL)
        return false;
    visit(p);
    PreOrderTraverse(p->left,visit);
    PreOrderTraverse(p->right,visit);

    return succeed;
}

void PreOrderTraverse(NodePtr T,void (*visit)(NodePtr))
{
    if(T == NULL)
        return;
    visit(T);
    PreOrderTraverse(T->left,visit);
    PreOrderTraverse(T->right,visit);
}

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
 //将所有的左孩子入栈，输出栈顶，压栈顶的右孩子入栈
 Status BST_inorderI(BinarySortTreePtr T, void (*visit)(NodePtr))
 {

     if (T->root == NULL)
     {
         return false;
     }
     NodePtr p= T->root;
     NodePtr temp;
     temp = (NodePtr)malloc(sizeof(Node));
     LinkStack s;
     initLStack(&s);
     while (p != NULL || !isEmptyLStack(&s))
     {
         while (p)
         {
             pushLStack(&s,p);
             p=p->left;
         }
         popLStack(&s,temp);
         visit(temp);
         p = temp->right;
         //都要移动，如果为NULL是判断下次是否移动的关键
     }
     return succeed;
 }


/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
/*中序遍历递归实现*/
Status BST_inorderR(BinarySortTreePtr T, void (*visit)(NodePtr))
{
    NodePtr p = T->root;
    if(p==NULL)
        return false;
    InOrderTraverse(p->left,visit);
    visit(p);
    InOrderTraverse(p->right,visit);
    return succeed;
}
void InOrderTraverse(NodePtr T, void (*visit)(NodePtr))
{
    if(T == NULL)
        return;
    InOrderTraverse(T->left,visit);
    visit(T);
    InOrderTraverse(T->right,visit);
}
/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
//无递归的后序遍历 需要用栈
//为了方便，我们将栈修改为泛型栈
//实际上观察后序遍历来说，后序遍历其实就是前序遍历先遍历右子树再左子树，最后再逆序。结果其实时一样的。
//考虑到最后要逆序，我们需要另外一个栈，用来逆序
Status BST_postorderI(BinarySortTreePtr T, void (*visit)(NodePtr))
{
    if(T->root==NULL)
        return false;
    NodePtr p = T->root;
    NodePtr temp;
    temp = (NodePtr)malloc(sizeof(Node));
    LinkStack s1,s2;
    initLStack(&s1);
    initLStack(&s2);
    pushLStack(&s1,p);//首结点入栈

    while(!isEmptyLStack(&s1))
    {
        //先出栈，再将该结点的左右孩子入栈
        //根据栈的特殊性，应该先将栈的右孩子先入栈
        popLStack(&s1,temp);
        //visit(temp);
        pushLStack(&s2,temp);
        //栈的右左孩子入栈
        if(temp->left!=NULL)
            pushLStack(&s1,temp->left);
        if(temp->right!=NULL)
            pushLStack(&s1,temp->right);
    }

    while(!isEmptyLStack(&s2))
    {
        popLStack(&s2,temp);
        visit(temp);
    }
    destroyLStack(&s1);
    destroyLStack(&s2);
    return succeed;
}

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
 //后序遍历的递归实现
Status BST_postorderR(BinarySortTreePtr T, void (*visit)(NodePtr))
{
    NodePtr p = T->root;
    if(p==NULL)
        return false;
    PostOrderTraverse(p->left,visit);
    PostOrderTraverse(p->right,visit);
    visit(p);
    return  succeed;
}
void PostOrderTraverse(NodePtr T, void (*visit)(NodePtr))
{
    if(T==NULL)
        return;
    PostOrderTraverse(T->left,visit);
    PostOrderTraverse(T->right,visit);
    visit(T);
}
/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */

Status BST_levelOrder(BinarySortTreePtr T, void (*visit)(NodePtr))
{
    if(T->root==NULL)
        return false;
    NodePtr p=T->root;
    LQueue Q;
    InitLQueue(&Q);//队列初始化
    //首结点入队
    EnLQueue(&Q,p);//首结点入栈
    while(!IsEmptyLQueue(&Q))
    {
        NodePtr node;
        node = (NodePtr)malloc(sizeof(Node));
        GetHeadLQueue(&Q,node);
        if(node == NULL)
            continue;
        visit(node);
        DeLQueue(&Q);
        if(node->left!=NULL)
        {
            EnLQueue(&Q,node->left);
        }
        if(node->right!=NULL)
            EnLQueue(&Q,node->right);
    }
    DestoryLQueue(&Q);
    return succeed;
}
