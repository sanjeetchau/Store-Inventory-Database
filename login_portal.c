#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (void)
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
	
	printf("Hello");
	fp = fopen("./staff_credentials.csv", "r");
	
	//fp = fp + 21*(sizeof(char)); //the length of ' "user_id","password", ' is 21 characters
				     //cheating again
	
	for( i = 0; i <= 20; i++) //this loop works instead of directly trying to increase the fp pointer with arithmetic
				  //i hate pointers
	{
		getc(fp);
	}
	
	ch = getc(fp);
	putchar(ch);											//test print
	//works till here so far
	
	puts("\nbefore loop");
	while(ch != EOF)
	{
		puts("\nouter while start");								//test print
		count1 = 0;
		while((count1 != 2) && (ch != EOF))
		{
			puts("\ninner while start");							//test print
			putchar(ch);									//test print
			if (ch == ',')
			{
				count1++;
				ch = getc(fp);
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
			ch = getc(fp);
			puts("\ninner while end");							//test print; not working
		}
		puts("\nouter while end");								//test print; not working
		puts(txt_stream1);
		puts(txt_stream2);
	}
	puts("\nend hello\n");										//test print; not working 

	fclose(fp);


	return 0;
}
