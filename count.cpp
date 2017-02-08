#include <iostream>

int main(void)
{	int i=0, count=0;
	int A[]={5,5,5,7,12,12,14,14,14,14,14,6,3};
	while (i<15)
	{
	if (A[i]==A[i+1])
		{if (A[i+1]==A[i+2])
			{if(A[i+2]==A[i+3])
				{if(A[i+3]==A[i+4])
					{count=count+1;
					 i=i+5;
					 continue;}
					else
					{count=count+1;
					 i=i+4;
					 continue;}
				}
			 else
			{count=count+1;
			i=i+3;
			continue;}
			}
		}
	else
	{i++;}
	}
	std:: cout<<count;
return 0;
}
