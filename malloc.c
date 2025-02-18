#include<stdio.h>
void main()
{
int nm,np,i,j;
struct mem{
	int size;
	int alloc;
}m[10];
struct pro{
	int size;
	int flag;
}p[10];
//Input of Memory blocks
printf("Enter the total number of memory blocks ");
scanf("%d" ,&nm);
for(i=0;i<nm;i++)
{
printf("Enter the size of M%d block ",i);
scanf("%d",&m[i].size);
m[i].alloc=0;
}
//Input of Processes
printf("Enter the number of proccess ");
scanf("%d" ,&np);
for(i=0;i<np;i++)
{
printf("Enter the size of P%d process ",i);
scanf("%d",&p[i].size);
}
//First Fit algorithm
for(i=0;i<np;i++)
{
	for(j=0;j<nm;j++)
	{
		if(p[i].flag!=1)
		{
			if(p[i].size<m[j].size)
			{
				if(m[j].alloc==0)
				{
					printf("\n P%d is allocated to M %d\n",i,j);
					m[j].alloc=1;
					p[i].flag=1;
				}
			}
		}
	}
}
for(i=0;i<np;i++)
{
if(p[i].flag!=1)
{
printf("\nP%d is not allocated as memory space was not found",i);
}
}
}
