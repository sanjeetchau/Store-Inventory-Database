#include<stdio.h>
#include<string.h>
//extern  login_portal();
//extern  staff_page();
//extern  customer_page();
int main()
{
    //char    login_accessvar[]; // logout_var;
    bool login_accessvar; // maybe I don't need to be fancy and use strings here
			  // I could just have login_portal() return bool i.e. 2 values
			  // though the 'true'/'false' implications is making me icky, let's see what happens
    login_accessvar    =   login_portal(); //returns tbd
    switch (login_accessvar)
    {
    	case "Staff"/* constant-expression */:
        	staff_page();
        	break;
    	case "Customer":
        	customer_page();
        	break;
    
    	default:
        	printf("\n Error.\n") //Or maybe the default should be to show the available items list (info only)
        	break;
    }
}
