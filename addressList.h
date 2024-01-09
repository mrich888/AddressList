#ifndef _ADDRESS_LIST_H_
#define _ADDRESS_LIST_H_

#define MAX_SIZE 100
#define NAME_SIZE 20
#define PHONE_SIZE 20
#define ELEMENTTYPE void *

/* 联系人结构体 */
typedef struct contact
{
    char name[NAME_SIZE]; //姓名 
    char phoneNUmber[PHONE_SIZE];//电话号码
    struct contact* parent;//父结点
    struct contact* left;//左子树
    struct contact* right;//右子树
} contact;

/* 通讯录结构体 */
typedef struct addressList
{
    int size;
    contact * root;
    int(*printFunc)(ELEMENTTYPE val);
}addressList;

/* 通讯录的初始化 */
int addressListInit(addressList ** pList, int (*printFunc)(ELEMENTTYPE val));
/* 新添联系人 */
int addressListAddMember(addressList * pList, char *name, int *phoneNUmber);
/* 删除联系人 */
int addressListDeleMember(addressList * pList, char *name);
/* 查找联系人 */
int addressListGetMember(addressList * pList, char *name);
/* 打印联系人列表 */
int addressListForeachMenber(addressList * pList);


#endif