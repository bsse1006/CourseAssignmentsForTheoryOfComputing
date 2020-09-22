#include <stdio.h>

int strlength (char* a)
{
	int i=0;
	
	for(i=0;a[i]!='\0';i++);
	
	return i;
}

int strcomp (char* a, char* b)
{
	int temp;
	
	for(int i=0; a[i]!='\0'; i++)
	{
		if(a[i]==b[i]) temp=0;
		else if(a[i]>b[i]) temp=1;
		else if(a[i]<b[i]) temp=-1;
	}	
	
	return temp;
}

char* strreverse (char* a)
{
	char temp [100];
	
	int i = strlength(a);
	int j;
	
	for(i=i-1,j=0;i>=0;i--,j++)
	{
		temp[j]=a[i];
	}
	
	temp[j]='\0';
	a=temp;
	return a;
}

char* strconcat (char* a, char*b)
{
	int temp = strlength(a);
	int temp2 = strlength(b);
	int i,j;
	for(i =temp, j=0;b[j]!='\0';j++,i++)
	{
		a[i]=b[j];
	}
	a[i]='\0';
	
	
	return a;
}

int pal (char* a)
{
	if(strcomp(a,strreverse(a))==0) printf("Palindrom!\n");
	else printf("Not palindrom!\n");
}

int main (void)
{
	int a;
	
	char string1 [100];
	char string2 [100];
	
	printf("Enter your 1st string: ");
	scanf("%s", string1);
	
	printf("Enter your 2nd string: ");
	scanf("%s", string2);

	printf("What do you want to do?\n1.string compare\n2. 1st string length\n3.1st string reverse\n4.string concatenation\n5.1st string palindrom\n6.Exit\n");
	
	scanf("%d",&a);
	
	while(1)
	{
	
		if(a==1)
		{
			if(strcomp(string1,string2)==0) printf("Strings are equal!\n");
			else printf("Strings are not equal!\n");
		} 
		else if(a==2) 
		{
			int temp = strlength(string1);
			printf("%d\n", temp);
		}
		else if(a==3) printf("%s\n", strreverse(string1));
		else if(a==4) printf("%s\n", strconcat(string1,string2));
		else if(a==5) pal(string1);
		else break;
		
		printf("What do you want to do?\n1.string compare\n2.1st string length\n3.1st string reverse\n4.string concatenation\n5.1st string palindrom\n6.Exit\n");
	
		scanf("%d",&a);
	}
	
	return 0;
}
