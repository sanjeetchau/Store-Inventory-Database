

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void login_portal(void)
{
	//trying file handling staff_credentials.csv first
	
	FILE *fp;
	int i, j, k, count1, count2;
	bool a;
	a = (2 < 3);
	count1 = 0;
	count2 = 0;
	char *p1, *p2, *p3;
	char ch, txt_stream1[12], txt_stream2[12]; //don't know if this needs to be an array
					       //gonna cheat and do 11 char long string arrays (coz samples are that long)
					       //will worry about dynamic memory allocations
					       //--for varying length of uid and passwords later
	

	//printf("%d",a);
	p1 = txt_stream1;
	p2 = txt_stream2;
	//p3 = ch;
	//p1 = "text2";				//test string-input

	

	//printf("Hello");
	//ch[1] = '\0';

	fp = fopen("./staff_credentials.csv", "r");
	
	//fp = fp + 21*(sizeof(char)); //the length of ' "user_id","password", ' is 21 characters
				     //cheating again
	
	for( i = 0; i <= 20; i++) //this loop works instead of directly trying to increase the fp pointer with arithmetic
				  //i hate pointers
	{
		getc(fp);
	}
	
	ch = getc(fp);
	//putchar(ch);											//test print
	
	//puts("\nbefore loop");
	while(ch != EOF)
	{
		//puts("\nouter while start");								//test print
		count1 = 0;
		txt_stream1[0] = '\0';
		txt_stream2[0] = '\0';
		while( (count1 != 2) && (ch != EOF) ) //'a' is the bool var that checks when both txts are full
                                //--> doesn't work even when the conditional is negated
                                //--> i.e. while( !((count1 == 2) || !a) ) gives exact same logical error
		{
			//puts("\ninner while start");							//test print
			//putchar(ch);									//test print
			j = 0;
      if (ch == ',')
			{
				count1++;
				ch = getc(fp);
        //putchar(ch);
        //printf("count %d\n", count1);
				//puts("\ninner while first conditional");				//test print
				//a = a && (ch != EOF);
        //a = !a;
        continue;
			}
			if (!(strlen(txt_stream1) == 11))
			{
				//puts("\ninner while second conditional");				//test print
				strncat(txt_stream1, &ch, 1);
        j++;                                              //flag to check whether this condition branch has been executed
				//txt_stream1 = txt_stream1.c_str();
			}
			if ( !(j == 1) && !(strlen(txt_stream2) == 11) )		//try "==11" instead of >=
			{
				//puts("\ninner while third conditional");				//test print
				strncat(txt_stream2, &ch, 1);
			}
			ch = getc(fp);
			//a = (strlen(txt_stream1) == 11) && (strlen(txt_stream2) == 11);
			//a = a && (ch != EOF);
			//a = !a;
			//puts("\ninner while end");							//test print
		}
		printf("\nuser id : %s and password : %s ", txt_stream1, txt_stream2);

		//puts("\nouter while end");								//test print; not working
		//puts(txt_stream1);
		//puts(txt_stream2);
	}
	//puts("\nend hello\n");										//test print; not working 
	

	fclose(fp);


	//return 0;
}
