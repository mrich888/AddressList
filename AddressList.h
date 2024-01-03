#ifndef _ADDRESS_LIST_H_
#define _ADDRESS_LIST_H_
#define MAX_SIZE 100
typedef struct Contact
{
    char name[20];
    char phonenum[11];
}Contact;
/*初始化*/
int AddressListInit(Contact *member);
/*增*/
int AddressListAddMember(Contact *member, int numContact);
/*删*/
int AddressListDeleMember(Contact *member,int numContact);
/*改*/
int AddressListModifyMember(Contact *member, int numContact);
/*查*/
int AddressListGetMember(Contact *member, int numContact);
#endif