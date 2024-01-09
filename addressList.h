#ifndef _ADDRESS_LIST_H_
#define _ADDRESS_LIST_H_

#define MAX_SIZE 100
#define NAME_SIZE 20
#define PHONE_SIZE 20

typedef void * ELEMENTTYPE;

/* 联系人结构体 */
typedef struct contactNode
{
    char name[NAME_SIZE]; //姓名 
    char phone[PHONE_SIZE];//电话号码
    struct contact* parent;//父结点
    struct contact* left;//左子树
    struct contact* right;//右子树

} contactNode;

/* 通讯录树的结构体 */
typedef struct ContactsTree
{
    /* 根结点 */
    contactNode * root;

    int size;
    /* 比较器 */
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);
} ContactsTree;

/* 通讯录的初始化 */
int addressListInit(ContactsTree **pContacts, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

/* 新添联系人 */
int addressListAddMember(contactNode* root, char *name, char *phone);
/* 删除联系人 */
int addressListDeleMember(contactNode* root, char *name);
/* 查找联系人 */
int addressListGetMember(contactNode* root, char* name);
/* 打印联系人列表 */
int addressListForeachMenber(contactNode* root);


#endif