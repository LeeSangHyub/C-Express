#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void scan_number(int a[]);		//7���� ������ �Է¹޴� �Լ�
void generate_number(int s[],int null1[]);	//7���� ������ �����ϴ� �Լ�
void compare_number(int a[],int b[]);	//���ؼ� count �����༭ ++ �ؼ� ������������˻�

int count; //��� ������ �˱����� ��������

int main(void)
{
	int scan_num[7]={0};
	int null1[45]={0},null[7];

	scan_number(scan_num);
	generate_number(null,null1);
	compare_number(scan_num,null);

	printf("���� ��ȣ�� ������ %d���Դϴ�.",count);


	return 0;
}

void scan_number(int a[])
{
	int i,j;

	for(i=0;i<7;i++)
	{
		if(i==6)
		{
			printf("���ʽ� ���ڸ� �Է��Ͻÿ�:");
			scanf("%d",&a[i]);

			if(a[i]<=0||a[i]>45)
			{
				printf("1~45������ ���ڸ� �Է��Ͻÿ�.\n");
				printf("���ʽ� ���ڸ� �Է��Ͻÿ�:");
				scanf("%d",&a[i]);
			}
		}
		else
		{
			printf("%d��° ���ڸ� �Է��Ͻÿ�:",i+1);
			scanf("%d",&a[i]);
		}

		if(a[i]<=0||a[i]>45)
		{
			printf("1~45������ ���ڸ� �Է��Ͻÿ�.\n");
			printf("%d��° ���ڸ� �Է��Ͻÿ�:",i+1);
			scanf("%d",&a[i]);
		}
		for(j=0;j<7;j++)
		{
			if(a[i]==a[j]&&i!=j)
			{
				printf("�ߺ��Ǿ����ϴ�.\n");
				printf("%d��° ���ڸ� �Է��Ͻÿ�:",i+1);
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