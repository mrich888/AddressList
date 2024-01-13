#include <stdio.h>
#include <string.h>
#include "balanceBinarySearchTree.h"
#include "addressList.h"

/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS = 1,
    NOT_FIND ,
    NULL_PTR,
    INSERT_ERROR,
    INVALID_ACCESS,
};

/* 通讯录的初始化 */
int contactInit(addressList *pAddress, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE val))
{
    /* 调用树的初始化，传入树的结构体 */
    return balanceBinarySearchTreeInit(&(pAddress->tree), compareFunc, printFunc);
   
}

/* 菜单选择 */
int menuChoice(addressList *pAddressList)
{
    int ret = 0;
    printf("1.插入联系人\n");
    printf("2.查找联系人\n");
    printf("3.删除联系人\n");
    printf("4.打印联系人\n");
    return ret;
}


/* 插入联系人 */
int insertContact(addressList *pAddressList)
{
    int ret = 0;
    /* 先判空 */
    if (pAddressList == NULL)
    {
        return NULL_PTR;
    }
    
    char name[NAME_SIZE];
    memset(name, 0, sizeof(name));

    printf("name:\n");
    scanf("%s", name);
    printf("%s\n", name);
    int phone = 0;
    printf("phoneNumber:\n");
    scanf("%d", &phone);
    
    /* 定义联系人结构体，将信息插入到结构体中 */
    contactPerson tempPerson;
    memset(&tempPerson, 0, sizeof(tempPerson));

    strncpy(tempPerson.name, name, sizeof(name) - 1);
    tempPerson.phoneNumber = phone;

    /* 判断联系人是否存在 */
    if (searchAppointPerson(pAddressList, tempPerson) != NULL_PTR)
    {
        printf("联系人已存在\n");
        return INSERT_ERROR;
    }
    else
    {
        /* 若没有则将联系人的信息插入到树的结构中去 */
        balanceBinarySearchTreeInsert(pAddressList->tree, &tempPerson);
        printf("插入成功\n");
    }

    return ret;
}

/* 查找联系人 */
int searchAppointPerson(addressList *pAddressList, contactPerson person)
{
    /* 如果通讯录为空直接范围没有该联系人 */
    if (pAddressList == NULL)
    {
        printf("没有该联系人\n");
        return NULL_PTR;
    }
    /* 不为空则查找有没有对应的结点 */
    AVLTreeNode * node =  baseAppointValGetAVLTreeNode(pAddressList->tree, &person);
    if (node == NULL)
    {
        printf("没有该联系人");
    }
    else
    {
        pAddressList->tree->printFunc;
    }
    return NULL_PTR;
}
/* 删除联系人*/
int deleteAppointPerson(addressList *pAddressList, contactPerson person)
{
    if (pAddressList == NULL)
    {
        printf("没有该联系人\n");
        return NULL_PTR;
    }
    
    int ret = balanceBinarySearchTreeIsContainAppointVal(pAddressList->tree, &person);
    if (ret == 1)
    {
        int res = balanceBinarySearchTreeDelete(pAddressList->tree, &person);
        if (res != 0)
        {
            printf("删除成功！\n");
        }
    }
    else
    {
        printf("没有该联系人\n");
    }
    return ON_SUCCESS;
}
/* 打印联系人菜单 */
int printContactMenu(addressList *pAddressList)
{
    return balanceBinarySearchTreeInOrderTravel(pAddressList->tree);

}

