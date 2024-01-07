#ifndef _ADDRESS_LIST_H_
#define _ADDRESS_LIST_H_

#define MAX_SIZE 100
#define NAME_SIZE 20
#define PHONE_SIZE 20

/* 联系人结构体 */
typedef struct contact
{
    char name[NAME_SIZE]; //姓名 
    char phone[PHONE_SIZE];//电话号码
    struct contact* parent;//父结点
    struct contact* left;//左子树
    struct contact* right;//右子树
} contact;

/* 通讯录的初始化 */
int addressListInit(char *name, char *phone);
/* 新添联系人 */
int addressListAddMember(contact* root, char *name, char *phone);
/* 删除联系人 */
int addressListDeleMember(contact* root, char *name);
/* 查找联系人 */
int addressListGetMember(contact* root, char* name);
/* 打印联系人列表 */
int addressListForeachMenber(contact* root);


#endif