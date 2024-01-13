#ifndef __ADDRESSLIST_H
#define __ADDRESSLIST_H
#include "common.h"
#include "balanceBinarySearchTree.h"
#define NAME_SIZE 20

enum CHOICE
{
    /* 插入联系人 */
    INSERT = 1,
    /* 查找联系人 */
    SEARCH,
    /* 删除联系人 */
    DELETE,
    /* 查看所有联系人*/
    LIST,
};

/* 联系人的属性 */
typedef struct contactPerson
{
    char name[NAME_SIZE];
    int phoneNumber;
}contactPerson;

/* 通讯录的结构体 */
typedef struct addressList
{
    /* 拿到树的结构体 */
    BalanceBinarySearchTree * tree;
}addressList;

/* 通讯录的初始化 */
int contactInit(addressList *pAddressList, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE val));
/* 菜单选择 */
int menuChoice(addressList *pAddressList);
/* 插入联系人 */
int insertContact(addressList *pAddressList);
/* 查找联系人 */
int searchAppointPerson(addressList *pAddressList, contactPerson person);
/* 删除联系人*/
int deleteAppointPerson(addressList *pAddressList, contactPerson person);
/* 打印联系人菜单 */
int printContactMenu(addressList *pAddressList);
/* 返回菜单 */
int backMenuChoice(addressList *pAddressList);

#endif //__ADDRESSLIST_H