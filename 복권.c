#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void scan_number(int a[]);		//7개의 정수를 입력받는 함수
void generate_number(int s[],int null1[]);	//7개의 정수를 생성하는 함수
void compare_number(int a[],int b[]);	//비교해서 count 정수줘서 ++ 해서 몇번나오는지검사

int count; //몇개가 같은지 알기위한 전역변수

int main(void)
{
	int scan_num[7]={0};
	int null1[45]={0},null[7];

	scan_number(scan_num);
	generate_number(null,null1);
	compare_number(scan_num,null);

	printf("같은 번호의 갯수는 %d개입니다.",count);


	return 0;
}

void scan_number(int a[])
{
	int i,j;

	for(i=0;i<7;i++)
	{
		if(i==6)
		{
			printf("보너스 숫자를 입력하시오:");
			scanf("%d",&a[i]);

			if(a[i]<=0||a[i]>45)
			{
				printf("1~45사이의 숫자를 입력하시오.\n");
				printf("보너스 숫자를 입력하시오:");
				scanf("%d",&a[i]);
			}
		}
		else
		{
			printf("%d번째 숫자를 입력하시오:",i+1);
			scanf("%d",&a[i]);
		}

		if(a[i]<=0||a[i]>45)
		{
			printf("1~45사이의 숫자를 입력하시오.\n");
			printf("%d번째 숫자를 입력하시오:",i+1);
			scanf("%d",&a[i]);
		}
		for(j=0;j<7;j++)
		{
			if(a[i]==a[j]&&i!=j)
			{
				printf("중복되었습니다.\n");
				printf("%d번째 숫자를 입력하시오:",i+1);
				scanf("%d",&a[i]);
			}
		}
	}
}

void generate_number(int s[],int null1[])
{
	int i,a,j;

	srand((unsigned)time(NULL));

	for(i=0;i<7;i++)
	{
		a=rand()%45;
		if(null1[a]==0)
			null1[a]++;
		else if(null1[a]==1)
			i--;
	}
	for(j=0;j<7;j++)
	{
		for(i=0;i<45;i++)
			if(null1[i]!=0)
			{
				s[j]=i+1;
				null1[i]--;
				break;
			}	
	}	
}
void compare_number(int a[],int b[])
{
	int i,j;

	for(j=0;j<7;j++)
	{
		for(i=0;i<7;i++)
		{
			if(a[j]==b[i])
				count++;
		}
	}
}