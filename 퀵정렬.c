#include<stdio.h>
#define SIZE 10
void quic(int a[], int n,int b);
void swap(int *l,int *h);
void print_a(int a[]);
int main(void)
{
	int a[SIZE]={10,25,45,35,55,15,95,5,85,75};

 print_a(a);
 quic(a,0,SIZE);
 print_a(a);
 
 return 0;
}


void quic(int a[],int n,int b)
{
 int pivot,low,high;
 int i,j;

	low=n+1;
	high=b-1;
	pivot=a[n];
	if(low<high)
	{
		while(low<high)
		{
			for(;a[low]<pivot&&low<b;low++)
			{}
			for(;a[high]>pivot;high--)
			{}
			if(low<high)
				swap(&a[low],&a[high]);
		}
		if(low>high)
			swap(&a[n],&a[low-1]);
		quic(a,n,high+1);
		quic(a,low,b);
	}

}

void swap(int *l,int *h)
{
 int tmp;

 tmp=*l;
 *l=*h;
 *h=tmp;

}

void print_a(int a[])
{
 int i;
 for(i=0;i<SIZE;i++)
  printf("%3d",a[i]);
 printf("\n");

} 
