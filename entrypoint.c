#include<stdio.h>
#include<string.h>
int main()
{
    char    login_access;
    login_access    =   login_portal(); //returns tbd
    switch (login_access)
    {
    case "Staff"/* constant-expression */:
        
        break;
    case "Customer":
        
        break;
    
    default:
        printf("\nError.\n")
        break;
    }
}