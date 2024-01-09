#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"addressList.h"
enum STATUS_CODE
{
    NOT_FIND,
    ON_SUCCESS,
    MALLOC_ERROR,
    NULL_PTR,
    INVALID_POS,
    INVALID_VAL,
};
/*************************静态函数声明*********************************/
static contact * createNewContactNode(char name, int phoneNUmber, contact * pParent);
static contact* findMin(contact* node);
static int printFunc(contact * contact);  
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);
/*************************静态函数实现*********************************/

/* 创建新结点 */
static contact * createNewContactNode(char name, int phoneNUmber, contact * pParent)
{
    /* 静态函数不需要判空 */
    /* 给新结点分配空间 */
    contact * newNode = (contact *)malloc(sizeof(contact) * 1);
    if (newNode == NULL)
    {
        return NULL_PTR;
    }
    /* 清楚脏数据 */
    memset(newNode, 0, sizeof(contact) * 1);
    /* 初始化结点 */
    newNode->name[NAME_SIZE] = 0;
    newNode->phoneNUmber[PHONE_SIZE] = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    /* 赋值 */
    strncpy(newNode->name, name, sizeof(name) - 1);
    strncpy(newNode->phoneNUmber, phoneNUmber, sizeof(phoneNUmber) - 1);
    newNode->parent = pParent;

    return newNode;
}
/* 打印 */
static int printFunc(contact * contact) 
{
    printf("姓名：%s  电话：%s  \n", contact->name, contact->phoneNUmber);
}
/* 比较 */
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    return (val1 - val2);
}

/* 通讯录的初始化 */
int addressListInit(addressList ** pList, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE val))
{
    /* 判空，树不能为空 */
    addressList * list = (addressList *)malloc(sizeof(addressList) * 1);
    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清楚脏数据 */
    memset(list, 0, sizeof(addressList) * 1);
    /* 初始化树 */
    list->size = 0;
    list->root = NULL;
    list->compareFunc = compareFunc;
    list->printFunc = printFunc;
    /* 初始化根结点 */
    list->root = createNewBstNode(0, 0, NULL);
    /* 根结点不能为空 */
    if (list->root == NULL)  
    {
        return MALLOC_ERROR;
    }
    
    *pList = list;
    return ON_SUCCESS;
}
/* 新添联系人 */
int addressListAddMember(addressList * pList, char *name, int *phoneNUmber)
{
    if (pList->size == 0)
    {
        /* 直接插入到根结点 */
        strncpy(pList->root->name, name, sizeof(name) - 1);
        strncpy(pList->root->phoneNUmber, phoneNUmber, sizeof(phoneNUmber) - 1);
        /* 树的结点树++ */
        (pList->size)++;
        return ON_SUCCESS;
    }
    /* 如果不为空，封装结点 */
    contact * newNode = createNewContactNode(name, phoneNUmber, newNode->parent);
    contact * travleNode = pList->root;
    /* 找位置：需要一个一个对比 */
    /* todo....compareFunc */
    while (travleNode != NULL)
    {
        /* 对比两个结点的值，左小右大 */
        if (newNode->name[0] <= travleNode->name[0])
        {
            travleNode = travleNode->left;
        }
        else if (newNode->name[0] > travleNode->name[0])
        {
            travleNode = travleNode->right;
        }
    }
       /* 找到位置开始插入 */
    if (newNode->name[0] <= travleNode->name[0])
    { 
        newNode->parent = travleNode;
        travleNode->left = newNode;
    }
    else if (newNode->name[0] > travleNode->name[0])
    {
        newNode->parent = travleNode;
        travleNode->right = newNode;
    }
    /* 结点数增加 */
    (pList->size)++;
}
/* 删除联系人 */
int addressListDeleMember(addressList * pList, ELEMENTTYPE * val);
/* 查找联系人 */
int addressListGetMember(addressList * pList, ELEMENTTYPE * val);
/* 打印联系人列表 */
int addressListForeachMenber(addressList * pList);

#if 0
/* 创建新结点 */
static contact* createNode(char* name, char* phone) 
{
    contact* newNode = (contact*)malloc(sizeof(contact));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
/* */
static contact* findMin(contact* node) 
{
    while (node->left != NULL) 
    {
        node = node->left;
    }
    return node;
}
/* 打印联系人 */
static int printContact(contact* contact) 
{
    printf("姓名：%s  电话：%s  \n", contact->name, contact->phone);
}
/* 遍历 */
static int inorderTraversal(contact* root) 
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
/* 通讯录的初始化 */
int addressListInit(char *name, char *phone)
{
    
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
#endif