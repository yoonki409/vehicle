#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct student {
	int id;
	char name[5];
	int jumsu[3];
	float avr;
	int rank;
}ST;

ST data_create(ST);
void data_print(ST*, int);
void avr_rank(ST*, int);
void err_fun(int);
void end_fun();

int main()
{
	int no,i;
	srand((unsigned)time(NULL));

	ST std[10];

	printf("\n학생수<=1 : 종료, 2<= 학생수 <=10 : 적합, 학생수>10 : 다시 입력\n");
	do
	{
		printf("\n학생의 수를 입력하시요 : ");
		scanf_s("%d", &no);
		printf("\n");
		if (no >= 2 && no <= 10)
		{
			for (i = 0; i < no; i++)
			{
				std[i]=data_create(std[i]);
			}
			avr_rank(std, no);
			data_print(std, no);			
		}
		else if (no > 10)
			err_fun(no);
		else
			end_fun();
	} while (1);

}

void err_fun(int no)
{
	printf("\n %d는(은) 틀린 입력이니 다시 입력하시요 :\n", no);
}

void end_fun()
{
	printf("\n 프로그램 종료\n");
	exit(1);
}

ST data_create(ST std_one)
{
	int i, sum = 0;	

	printf("학생의 이름을 입력하시요(5글자 이내의 영문자) :");
	scanf_s(" %s", std_one.name, 5);
	std_one.id = rand() % 1000 + 2000;
			
	for(i = 0; i < 3; i++)
	{
		std_one.jumsu[i] = rand() % 51 + 50;
		sum += std_one.jumsu[i];
	}
	std_one.avr = sum / 3.0;

	return std_one;
}

void data_print(ST *pstd, int no)
{
	int i, j;
	double avr[10];

	printf("\n\n\t학번\t\b이름\t\b국어\t\b수학\t\b영어\t평균\t등수\n");

	for (i = 0; i <= no-1; i++)
	{
		printf("\t%d", pstd[i].id);
		printf("\t%s", pstd[i].name);
		for (j = 0; j <= 2; j++)
		{
			printf("\t%d", pstd[i].jumsu[j]);
		}
		printf("\t\b%5.2f", pstd[i].avr);
		printf("\t%2d\n", pstd[i].rank);
	}
	
}

void avr_rank(ST *pstd, int no)
{
	int i, j, max = 0, tmp_index;
	double tmp_avr;
	double avr[10] = { 0.0 };
	int index[10] = { 0 };
	no = no - 1; //학생수-1은 인덱스 가장 큰번호

	for (i = 0; i <= no; i++)
	{
		avr[i] = pstd[i].avr;
		index[i] = i;
	}	

	for (i = 0; i <= no - 1; i++)
	{
		max = i;

		for (j = i + 1; j <= no; j++)
		{
			if (avr[j] > avr[max])
				max = j;
		}

		tmp_avr = avr[i];
		avr[i] = avr[max];
		avr[max] = tmp_avr;
		
		tmp_index = index[i];
		index[i] = index[max];
		index[max] = tmp_index;
	}
	
	for (i = 0; i <= no; i++)
	{
		pstd[index[i]].rank=i+1;
	}

}




