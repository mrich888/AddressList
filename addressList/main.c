#include "addressList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 比较器 */
int compareFunc(void * arg1, void *arg2)
{
    contactPerson * person1 = ( contactPerson *)arg1;
    contactPerson * person2 = ( contactPerson *)arg2;
    /* 姓名和手机号都符合才符合 */
    return strcmp(person1->name, person2->name) && (person1->phoneNumber - person2->phoneNumber);
    /* && strcmp(person1->phoneNumber, person2->phoneNumber) */
}
/* 输出格式 */
int printFunc(void * arg)
{
    contactPerson * person = (contactPerson *)arg;
    printf("name:%s\t phoneNumber:%d\n", person->name, person->phoneNumber);
}

int main()
{
    /* 定义一个通讯录 */
    addressList  contacts;
    /* 初始化通讯录 */
    contactInit(&contacts, compareFunc, printFunc);
    /* */
    contactPerson person;
    /* 菜单目录 */
    int choice = 0;
    menuChoice(&contacts);
    while (1)
    {
        printf("请输入你要选择的功能：\n");
        scanf("%d\n", &choice);

        switch (choice)
        {
        case INSERT:
            insertContact(&contacts);
            menuChoice(&contacts);
            break;
        
        case SEARCH:
            searchAppointPerson(&contacts, person);
            menuChoice(&contacts);
            break;

        case DELETE:
            deleteAppointPerson(&contacts, person);
            menuChoice(&contacts);
        break;

        case LIST:
            printContactMenu(&contacts);
            menuChoice(&contacts);
        break;

        default:
            printf("请输出正确的选项！\n");
            break;
        }
    }
    return 0;
}