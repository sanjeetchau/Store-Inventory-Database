#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool login_portal()
{
	//trying file handling staff_credentials.csv first
	
	FILE *fp;
	int i, j, k, count1, count2;
	count1 = 0;
	count2 = 0;
	char ch, txt_stream1[12], txt_stream2[12]; //don't know if this needs to be an array
					       //gonna cheat and do 11 char long string arrays (coz samples are that long)
					       //will worry about dynamic memory allocations
					       //--for varying length of uid and passwords later
	
	fp = fopen("./staff_credentials.csv", "r");
	fp = fp + 21*(sizeof(char)); //the length of ' "user_id","password", ' is 21 characters
				     //cheating again
	
	ch = getc(fp);
	while(ch != EOF)
	{
		count1 = 0;
		while((count1 != 2) && (ch != EOF))
		{
			if (ch == ",")
			{
				count1++;
				continue;
			}
			if (strlen(txt_stream1) < 11)
			{
				strcat(txt_stream1, ch);
			}
			if ((strlen(txt_stream1) >= 11) && (strlen(txt_stream2) < 11))
			{
				strcat(txt_stream2, ch);
			}
		}
		printf("\n user_id : %s , password : %s", txt_stream1, txt_stream2);
	}

	fclose(fp);


	return 0;
}
