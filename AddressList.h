#ifndef _ADDRESS_LIST_H_
#define _ADDRESS_LIST_H_
#define MAX_SIZE 100
#define NAME_SIZE 20
#define PHONE_SIZE 20
typedef struct TreeNode {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

/*初始化*/
int addressListInit(char *name, char *phone);
/*增*/
int addressListAddMember(TreeNode* root, char *name, char *phone);
/*删*/
int addressListDeleMember(TreeNode* root, char *name);
/*查*/
int addressListGetMember(TreeNode* root, char* name);
#endif