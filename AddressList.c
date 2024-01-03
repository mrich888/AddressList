#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"AddressList.h"
enum STATUS_CODE
{
    mALLLOC_ERROR,
    NULL_PTR,
    INVALID_POS,
    INVALID_VAL,
    MALLOC_ERROR,
    ON_SUCCESS,
    
};
/*初始化*/
int AddressListInit(Contact *member)
{

}
/*增*/
int AddressListAddMember(Contact *member,  int numContact)
{
}
/*删*/
int AddressListDeleMember(Contact *member, int numContact);
/*改*/
int AddressListModifyMember(Contact *member, int numContact);
/*查*/
int AddressListGetMember(Contact *member, int numContact);