#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"addressList.h"

int main()
{
    contactNode* root = NULL;

    while (1) 
    {
        printf("1. 添加联系人\n");
        printf("2. 删除联系人\n");
        printf("3. 修改联系人\n");
        printf("4. 查找联系人\n");
        printf("5. 显示所有联系人\n");
        printf("6. 退出\n");
        printf("请选择操作："); 
        int choice;
        scanf("%d", &choice);

        if (choice == 1) 
        {
            char name[NAME_SIZE], phone[PHONE_SIZE];
            printf("请输入联系人姓名：");
            scanf("%s", name);
            printf("请输入联系人电话：");
            scanf("%s", phone);
            root = addressListAddMember(root, name, phone);
            printf("联系人已添加。\n");
        } 
        else if (choice == 2) 
        {
            char name[NAME_SIZE];
            printf("请输入要删除的联系人姓名：");
            scanf("%s", name);
            root = addressListDeleMember(root, name);
            printf("联系人已删除。\n");
        } 
        else if (choice == 3) 
        {
            char name[NAME_SIZE], phone[PHONE_SIZE];
            printf("请输入要修改的联系人姓名：");
            scanf("%s", name);
            contact * contact = addressListGetMember(root, name);
            if (contact == NULL) 
            {
                printf("联系人不存在。\n");
            } 
            else 
            {
                printf("请输入新的联系人电话：");
                scanf("%s", phone);
                strcpy(contact->phone, phone);
                printf("联系人已修改。\n");
            }
        } 
        else if (choice == 4) 
        {
            char name[NAME_SIZE];
            printf("请输入要查找的联系人姓名：");
            scanf("%s", name);
            TreeNode* contact = addressListGetMember(root, name);
            if (contact == NULL) 
            {
                printf("联系人不存在。\n");
            } 
            else 
            {
                printf("联系人信息：\n");
                printContact(contact);
            }
        } 
        else if (choice == 5)
        {
            if (root == NULL) 
            {
                printf("通讯录为空。\n");
            } 
            else 
            {
                printf("所有联系人信息：\n");
                inorderTraversal(root);
            }
        } 
        else if (choice == 6) 
        {
            printf("程序已退出。\n");
            break;
        } 
        else 
        {
            printf("无效的选择，请重新输入。\n");
        }
    }

    return 0;
   
}