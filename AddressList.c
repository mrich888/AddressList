#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"AddressList.h"
enum STATUS_CODE
{
    MALLLOC_ERROR,
    NULL_PTR,
    INVALID_POS,
    INVALID_VAL,
    MALLOC_ERROR,
    ON_SUCCESS,
};
/*************************静态函数声明*********************************/
static TreeNode* createNode(char* name, char* phone);
static TreeNode* findMin(TreeNode* node);
static int printContact(TreeNode* contact); 
static int printContact(TreeNode* contact);
/*************************静态函数实现*********************************/
static TreeNode* createNode(char* name, char* phone) 
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
static TreeNode* findMin(TreeNode* node) 
{
    while (node->left != NULL) 
    {
        node = node->left;
    }
    return node;
}
static int printContact(TreeNode* contact) 
{
    printf("姓名：%s  电话：%s  \n", contact->name, contact->phone);
}

static int inorderTraversal(TreeNode* root) 
{
    if (root != NULL) 
    {
        inorderTraversal(root->left);
        printContact(root);
        inorderTraversal(root->right);
    }
}
/*************************以上为静态函数*******************************/
/****************************API函数实现*******************************/
int addressListAddMember(TreeNode* root, char *name, char *phone)
{
    if (root == NULL)
    {
        return createNode(name, phone);
    }
    int cmp = strcmp(name, root->name);
    if (cmp < 0) 
    {
        root->left = insert(root->left, name, phone);
    } 
    else if (cmp > 0) 
    {
        root->right = insert(root->right, name, phone);
    } 
    else 
    {
        printf("联系人已存在。\n");
    }

    return root;
}

int addressListDeleMember(TreeNode* root, char *name)
{
    if (root == NULL)
    {
        return root;
    }
    int cmp = strcmp(name, root->name);
    if (cmp < 0) 
    {
        root->left = deleteNode(root->left, name);
    } 
    else if (cmp > 0) 
    {
        root->right = deleteNode(root->right, name);
    } 
    else 
    {
        // 当前节点是要删除的节点
        if (root->left == NULL && root->right == NULL) 
        {
            free(root);
            return NULL;
        } 
        else if (root->left == NULL) 
        {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        } 
        else 
        {
            TreeNode* minNode = findMin(root->right);
            strcpy(root->name, minNode->name);
            strcpy(root->phone, minNode->phone);
            root->right = deleteNode(root->right, minNode->name);
        }
    }
    return root;
}

int addressListGetMember(TreeNode* root, char* name)
{
    if (root == NULL) 
    {
        return NULL;
    }

    int cmp = strcmp(name, root->name);
    if (cmp < 0) 
    {
        return find(root->left, name);
    }
    else if (cmp > 0) 
    {
        return find(root->right, name);
    } 
    else 
    {
        return root;
    }
}
