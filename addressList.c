#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"addressList.h"

enum STATUS_CODE
{
    ON_SUCCESS,
    MALLLOC_ERROR,
    NULL_PTR,
    INVALID_POS,
    INVALID_VAL,
};

/*************************静态函数声明*********************************/
static contact* createNode(char* name, char* phone);
static contact* findMin(contact* node);
static int printContact(contact* contact); 
static int inorderTraversal(contact* root) ;
/*************************静态函数实现*********************************/
/* 创建新结点 */
static contactNode * createContactsNewNode(char * name, char * phone, contactNode *parent) 
{
    contactNode * newNode = (contactNode *)malloc(sizeof(contactNode) * 1);
    if (newNode == NULL)
    {
        return NULL;
    }
    /* 清除脏数据 */
    memset(newNode, 0, sizeof(contactNode) * 1);

    /* 初始化根节点 */
    newNode->name[NAME_SIZE] = 0;
    newNode->phone[PHONE_SIZE] = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    /* 赋值 */
    newNode->name[NAME_SIZE] = name;
    newNode->phone[PHONE_SIZE] = phone;
    
    return newNode;
}
// /* */
// static contact* findMin(contact* node) 
// {
//     while (node->left != NULL) 
//     {
//         node = node->left;
//     }
//     return node;
// }
// /* 打印联系人 */
// static int printContact(contact* contact) 
// {
//     printf("姓名：%s  电话：%s  \n", contact->name, contact->phone);
// }
// /* 遍历 */
// static int inorderTraversal(contact* root) 
// {
//     if (root != NULL) 
//     {
//         inorderTraversal(root->left);
//         printContact(root);
//         inorderTraversal(root->right);
//     }
// }
/*************************以上为静态函数*******************************/
/****************************API函数实现*******************************/
/* 通讯录的初始化 */
int addressListInit(ContactsTree **pContacts, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
{
    int ret = 0;

    ContactsTree * contactsT = (ContactsTree *)malloc(sizeof(ContactsTree) * 1);
    if (pContacts == NULL)
    {
        return MALLLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(pContacts, 0, sizeof(ContactsTree) * 1);

    /* 初始化通讯录的树 */
    contactsT->root = NULL;
    contactsT->size = 0;

    /* 钩子函数在这里初始化 */
    contactsT->compareFunc = compareFunc;

}

/* 新添联系人 */ 
int addressListAddMember(contact* root, char *name, char *phone)
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
/* 删除联系人 */
int addressListDeleMember(contact* root, char *name)
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
            contact* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            contact* temp = root->left;
            free(root);
            return temp;
        } 
        else 
        {
            contact* minNode = findMin(root->right);
            strcpy(root->name, minNode->name);
            strcpy(root->phone, minNode->phone);
            root->right = deleteNode(root->right, minNode->name);
        }
    }
    return root;
}
/* 查找联系人 */
int addressListGetMember(contact* root, char* name)
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
/* 打印联系人列表 */
int addressListForeachMenber(contact* root)
{

}