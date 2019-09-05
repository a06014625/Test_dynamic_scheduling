#include "stdlib.h"
#include "stdio.h"
#include <cstring>
#define NUMBER 20 
//#define DISPLAY //開啟顯示

//以結構存取
struct ORDER
{
	char finish;	//完成
	
	char word[3];	//編號
	
	unsigned int star1;		//起始時間
	
	unsigned int end1;		//結束時間
	
	int weight;		//權重
};

//指標變數
int *ia;

int *temp;

int *num;

int **arr;

int **simparr;

int **point;

int **Maximum;

int **weightresult;

int ***math; 


int MAX = NUMBER;

int finished_count = 0;

int remain_count = MAX;

int stop = 0;

int maxnum = 0;

int xx = 0;

int x1 = 0;

int y1 = 0; 	//maxnum 的座標

// function prototype
void Initial(void);

void AddData(void);

void LoadData(void);

void ShowData(void);

void DirectMatrix(void);

void weightcount(int x);

void select(void);

void pickup(int g, int h);

void FinishedCheck(void);

void ReSort(void);

void ShowRemainData(void);


struct ORDER order[NUMBER];

struct ORDER order2[NUMBER];

int main(void)
{
	AddData();
	
	ShowData();
	
	memcpy(order2, order, sizeof(order));
	
	while(remain_count > 2)
	{
		MAX = remain_count;
		
		Initial();
		
		DirectMatrix();
		
		select();
		
		if(stop)
		{
			ShowRemainData();
			
			break;
		}
		FinishedCheck();
		
		ReSort();
		
		//釋出
		free(ia);
		
		free(temp);
		
		free(num);
		
		free(arr);
		
		free(simparr);
		
		free(point);
		
		free(Maximum);
		
		free(weightresult);
		
		free(math);
		
		printf("\n---------------------------------\n");
	}
	
	system("pause");
	
	return 0;	
} 


void Initial(void)
{
	stop = 0;
	
	maxnum = 0;
	
	xx = 0;
	
	x1 = 0;
	
	y1 = 0;
	
	//
	temp = (int*)calloc(MAX, sizeof(int));
	
	num = (int*)calloc(MAX, sizeof(int));
	
	arr = (int**)calloc(MAX, sizeof(int*));
	for(int i = 0; i < MAX; i++)
	{
		arr[i] = (int*)calloc(MAX, sizeof(int));
	}
	
	simparr = (int**)calloc(MAX, sizeof(int*));
	for(int i = 0; i < MAX; i++)
	{
		simparr[i] = (int*)calloc(MAX, sizeof(int));
	}
	
	point = (int**)calloc(MAX, sizeof(int*));
	for(int i = 0; i < MAX; i++)
	{
		point[i] = (int*)calloc(MAX, sizeof(int));
	}
	
	Maximum = (int**)calloc(MAX, sizeof(int*));
	for(int i = 0; i < MAX; i++)
	{
		Maximum[i] = (int*)calloc(MAX, sizeof(int));
	}
	
	weightresult = (int**)calloc(MAX, sizeof(int*));
	for(int i = 0; i < MAX; i++)
	{
		weightresult[i] = (int*)calloc(MAX, sizeof(int));
	}
	
	math = (int***)calloc(MAX, sizeof(int**));
	for(int i = 0; i < MAX; i++)
	{
		math[i] = (int**)calloc(MAX, sizeof(int*));
		for(int j = 0; j < MAX; j++)
		{
			math[i][j] = (int*)calloc(MAX, sizeof(int));
		}
	}
}

void AddData(void)
{
	// 編號 起始時間 結束時間 權重
	
	strcpy(order[0].word, "A1"); order[0].star1 = 20180301; order[0].end1 = 20180401; order[0].weight = 2;
	strcpy(order[1].word, "B1"); order[1].star1 = 20180315; order[1].end1 =	20180415; order[1].weight = 4;
	strcpy(order[2].word, "C1"); order[2].star1 = 20180401; order[2].end1 = 20180420; order[2].weight = 1;
	strcpy(order[3].word, "D1"); order[3].star1 = 20180415; order[3].end1 = 20180601; order[3].weight = 5;
	strcpy(order[4].word, "E1"); order[4].star1 = 20180420; order[4].end1 = 20180601; order[4].weight = 6;
	strcpy(order[5].word, "F1"); order[5].star1 = 20180501; order[5].end1 = 20180715; order[5].weight = 5;
	strcpy(order[6].word, "G1"); order[6].star1 = 20180610; order[6].end1 = 20180710; order[6].weight = 3;
	strcpy(order[7].word, "H1"); order[7].star1 = 20180615; order[7].end1 = 20180801; order[7].weight = 7;
	strcpy(order[8].word, "I1"); order[8].star1 = 20180701; order[8].end1 =	20180810; order[8].weight = 5;
	strcpy(order[9].word, "J1"); order[9].star1 = 20180720; order[9].end1 =	20180815; order[9].weight = 2;
	
	strcpy(order[10].word, "K1"); order[10].star1 = 20180816; order[10].end1 = 20180820; order[10].weight = 7;
	strcpy(order[11].word, "L1"); order[11].star1 = 20180819; order[11].end1 = 20180823; order[11].weight = 9;
	strcpy(order[12].word, "M1"); order[12].star1 = 20180820; order[12].end1 = 20180823; order[12].weight = 5;
	strcpy(order[13].word, "N1"); order[13].star1 = 20180901; order[13].end1 = 20180909; order[13].weight = 5;
	strcpy(order[14].word, "O1"); order[14].star1 = 20180902; order[14].end1 = 20180909; order[14].weight = 2;
	strcpy(order[15].word, "P1"); order[15].star1 = 20180902; order[15].end1 = 20180910; order[15].weight = 4;
	strcpy(order[16].word, "Q1"); order[16].star1 = 20180911; order[16].end1 = 20180920; order[16].weight = 2;
	strcpy(order[17].word, "R1"); order[17].star1 = 20180912; order[17].end1 = 20180916; order[17].weight = 6;
	strcpy(order[18].word, "S1"); order[18].star1 = 20180917; order[18].end1 = 20180920; order[18].weight = 7;
	strcpy(order[19].word, "T1"); order[19].star1 = 20181001; order[19].end1 = 20181010; order[19].weight = 2;
	
//	strcpy(order[20].word, "U1"); order[20].star1 = 20181010; order[20].end1 = 20181103; order[20].weight = 8;
//	strcpy(order[21].word, "V1"); order[21].star1 = 20181011; order[21].end1 = 20181203; order[21].weight = 2;
//	strcpy(order[22].word, "W1"); order[22].star1 = 20181110; order[22].end1 = 20181202; order[22].weight = 9;
//	strcpy(order[23].word, "X1"); order[23].star1 = 20181120; order[23].end1 = 20181125; order[23].weight = 2;
//	strcpy(order[24].word, "Y1"); order[24].star1 = 20181204; order[24].end1 = 20181225; order[24].weight = 4;
//	strcpy(order[25].word, "Z1"); order[25].star1 = 20181224; order[25].end1 = 20181229; order[25].weight = 5;
//	strcpy(order[26].word, "A2"); order[26].star1 = 20190304; order[26].end1 = 20200101; order[26].weight = 2;
//	strcpy(order[27].word, "B2"); order[27].star1 = 20190315; order[27].end1 = 20200215; order[27].weight = 4;
//	strcpy(order[28].word, "C2"); order[28].star1 = 20190401; order[28].end1 = 20200320; order[28].weight = 3;
//	strcpy(order[29].word, "D2"); order[29].star1 = 20190415; order[29].end1 = 20200801; order[29].weight = 5;
//	
//	strcpy(order[30].word, "E2"); order[30].star1 = 20190420; order[30].end1 = 20200301; order[30].weight = 6;
//	strcpy(order[31].word, "F2"); order[31].star1 = 20190501; order[31].end1 = 20200415; order[31].weight = 5;
//	strcpy(order[32].word, "G2"); order[32].star1 = 20190610; order[32].end1 = 20200510; order[32].weight = 3;
//	strcpy(order[33].word, "H2"); order[33].star1 = 20190615; order[33].end1 = 20200601; order[33].weight = 7;
//	strcpy(order[34].word, "I2"); order[34].star1 = 20190701; order[34].end1 = 20200710; order[34].weight = 5;
//	strcpy(order[35].word, "J2"); order[35].star1 = 20190720; order[35].end1 = 20200815; order[35].weight = 4;
//	strcpy(order[36].word, "K2"); order[36].star1 = 20190816; order[36].end1 = 20200720; order[36].weight = 8;
//	strcpy(order[37].word, "L2"); order[37].star1 = 20190819; order[37].end1 = 20200623; order[37].weight = 6;
//	strcpy(order[38].word, "M2"); order[38].star1 = 20190820; order[38].end1 = 20200623; order[38].weight = 7;
//	strcpy(order[39].word, "N2"); order[39].star1 = 20190901; order[39].end1 = 20200809; order[39].weight = 5;
//	
//	strcpy(order[40].word, "O2"); order[40].star1 = 20190902; order[40].end1 = 20200809; order[40].weight = 3;
//	strcpy(order[41].word, "P2"); order[41].star1 = 20190902; order[41].end1 = 20200810; order[41].weight = 2;
//	strcpy(order[42].word, "Q2"); order[42].star1 = 20190911; order[42].end1 = 20200820; order[42].weight = 3;
//	strcpy(order[43].word, "R2"); order[43].star1 = 20190912; order[43].end1 = 20200816; order[43].weight = 3;
//	strcpy(order[44].word, "S2"); order[44].star1 = 20190917; order[44].end1 = 20200820; order[44].weight = 5;
//	strcpy(order[45].word, "T2"); order[45].star1 = 20191001; order[45].end1 = 20200910; order[45].weight = 4;
//	strcpy(order[46].word, "U2"); order[46].star1 = 20191010; order[46].end1 = 20201003; order[46].weight = 7;
//	strcpy(order[47].word, "V2"); order[47].star1 = 20191011; order[47].end1 = 20201103; order[47].weight = 4;
//	strcpy(order[48].word, "W2"); order[48].star1 = 20191110; order[48].end1 = 20201102; order[48].weight = 3;
//	strcpy(order[49].word, "X2"); order[49].star1 = 20191120; order[49].end1 = 20201025; order[49].weight = 6;
//	
//	strcpy(order[50].word, "Y2"); order[50].star1 = 20191204; order[50].end1 = 20201125; order[50].weight = 5;
//	strcpy(order[51].word, "Z2"); order[51].star1 = 20191224; order[51].end1 = 20201129; order[51].weight = 4;
//	strcpy(order[52].word, "A3"); order[52].star1 = 20200301; order[52].end1 = 20200401; order[52].weight = 2;
//	strcpy(order[53].word, "B3"); order[53].star1 = 20200315; order[53].end1 = 20210415; order[53].weight = 4;
//	strcpy(order[54].word, "C3"); order[54].star1 = 20200401; order[54].end1 = 20210420; order[54].weight = 3;
//	strcpy(order[55].word, "D3"); order[55].star1 = 20200415; order[55].end1 = 20210601; order[55].weight = 5;
//	strcpy(order[56].word, "E3"); order[56].star1 = 20200420; order[56].end1 = 20210601; order[56].weight = 6;
//	strcpy(order[57].word, "F3"); order[57].star1 = 20200501; order[57].end1 = 20210715; order[57].weight = 5;
//	strcpy(order[58].word, "G3"); order[58].star1 = 20200610; order[58].end1 = 20210710; order[58].weight = 3;
//	strcpy(order[59].word, "H3"); order[59].star1 = 20200615; order[59].end1 = 20210801; order[59].weight = 7;
//	
//	strcpy(order[60].word, "I3"); order[60].star1 = 20200701; order[60].end1 = 20210810; order[60].weight = 5;
//	strcpy(order[61].word, "J3"); order[61].star1 = 20200816; order[61].end1 = 20210820; order[61].weight = 4;
//	strcpy(order[62].word, "K3"); order[62].star1 = 20200819; order[62].end1 = 20210823; order[62].weight = 1;
//	strcpy(order[63].word, "L3"); order[63].star1 = 20200820; order[63].end1 = 20210823; order[63].weight = 2;
//	strcpy(order[64].word, "M3"); order[64].star1 = 20200901; order[64].end1 = 20210909; order[64].weight = 3;
//	strcpy(order[65].word, "N3"); order[65].star1 = 20200902; order[65].end1 = 20210909; order[65].weight = 6;
//	strcpy(order[66].word, "O3"); order[66].star1 = 20200902; order[66].end1 = 20210910; order[66].weight = 5;
//	strcpy(order[67].word, "P3"); order[67].star1 = 20200911; order[67].end1 = 20210920; order[67].weight = 7;
//	strcpy(order[68].word, "Q3"); order[68].star1 = 20200912; order[68].end1 = 20210918; order[68].weight = 3;
//	strcpy(order[69].word, "R3"); order[69].star1 = 20200917; order[69].end1 = 20210920; order[69].weight = 5;
//	
//	strcpy(order[70].word, "S3"); order[70].star1 = 20201001; order[70].end1 = 20211010; order[70].weight = 6;
//	strcpy(order[71].word, "T3"); order[71].star1 = 20201010; order[71].end1 = 20211103; order[71].weight = 5;
//	strcpy(order[72].word, "U3"); order[72].star1 = 20201110; order[72].end1 = 20211202; order[72].weight = 7;
//	strcpy(order[73].word, "V3"); order[73].star1 = 20201120; order[73].end1 = 20211125; order[73].weight = 3;
//	strcpy(order[74].word, "W3"); order[74].star1 = 20201204; order[74].end1 = 20211225; order[74].weight = 4;
//	strcpy(order[75].word, "X3"); order[75].star1 = 20210301; order[75].end1 = 20220710; order[75].weight = 3;
//	strcpy(order[76].word, "Y3"); order[76].star1 = 20210315; order[76].end1 = 20220215; order[76].weight = 4;
//	strcpy(order[77].word, "Z3"); order[77].star1 = 20210503; order[77].end1 = 20220320; order[77].weight = 3;
//	strcpy(order[78].word, "A4"); order[78].star1 = 20210415; order[78].end1 = 20220801; order[78].weight = 5;
//	strcpy(order[79].word, "B4"); order[79].star1 = 20210420; order[79].end1 = 20220301; order[79].weight = 6;
//	
//	strcpy(order[80].word, "C4"); order[80].star1 = 20210501; order[80].end1 = 20220415; order[80].weight = 5;
//	strcpy(order[81].word, "D4"); order[81].star1 = 20210610; order[81].end1 = 20220510; order[81].weight = 3;
//	strcpy(order[82].word, "E4"); order[82].star1 = 20210615; order[82].end1 = 20220601; order[82].weight = 7;
//	strcpy(order[83].word, "F4"); order[83].star1 = 20210701; order[83].end1 = 20220710; order[83].weight = 5;
//	strcpy(order[84].word, "G4"); order[84].star1 = 20210816; order[84].end1 = 20220720; order[84].weight = 5;
//	strcpy(order[85].word, "H4"); order[85].star1 = 20210819; order[85].end1 = 20220623; order[85].weight = 4;
//	strcpy(order[86].word, "I4"); order[86].star1 = 20210820; order[86].end1 = 20220623; order[86].weight = 6;
//	strcpy(order[87].word, "J4"); order[87].star1 = 20210901; order[87].end1 = 20220809; order[87].weight = 2;
//	strcpy(order[88].word, "K4"); order[88].star1 = 20210902; order[88].end1 = 20220809; order[88].weight = 7;
//	strcpy(order[89].word, "L4"); order[89].star1 = 20210902; order[89].end1 = 20220810; order[89].weight = 3;
//	
//	strcpy(order[90].word, "M4"); order[90].star1 = 20210911; order[90].end1 = 20220820; order[90].weight = 4;
//	strcpy(order[91].word, "N4"); order[91].star1 = 20210912; order[91].end1 = 20220816, order[91].weight = 5;
//	strcpy(order[92].word, "O4"); order[92].star1 = 20210917; order[92].end1 = 20220820; order[92].weight = 7;
//	strcpy(order[93].word, "P4"); order[93].star1 = 20211001; order[93].end1 = 20220910; order[93].weight = 4;
//	strcpy(order[94].word, "Q4"); order[94].star1 = 20211010; order[94].end1 = 20221003; order[94].weight = 6;
//	strcpy(order[95].word, "R4"); order[95].star1 = 20211011; order[95].end1 = 20221103; order[95].weight = 3;
//	strcpy(order[96].word, "S4"); order[96].star1 = 20221004; order[96].end1 = 20221105; order[96].weight = 2;
//	strcpy(order[97].word, "T4"); order[97].star1 = 20230101; order[97].end1 = 20230102; order[97].weight = 1;
//	strcpy(order[98].word, "U4"); order[98].star1 = 20230202; order[98].end1 = 20230205; order[98].weight = 2;
//	strcpy(order[99].word, "V4"); order[99].star1 = 20230301; order[99].end1 = 20230304; order[99].weight = 2;
	
	for(int i = 0; i < NUMBER; i++)
	{
		order[i].finish = 0;
	}
}

void ShowData(void)
{
	printf("編號\t起始時間\t結束時間\t權重\t完成\n");
	
	for (int i = 0; i < NUMBER; i++)
	{
		printf("%2s\t%4d 年 %2d 月 %2d 日 \t%4d 年 %2d 月 %2d 日 \t%2d\t%2d\n",
		order[i].word,
		order[i].star1 / 10000, order[i].star1 / 100 % 100, order[i].star1 % 100,
		order[i].end1 / 10000, order[i].end1 / 100 % 100, order[i].end1 % 100,
		order[i].weight,
		order[i].finish);
	}
}

void DirectMatrix(void)
{
	#ifdef DISPLAY
	printf("\n\n 有向矩陣 \n");
	for(int i = 0; i < MAX; i++)
	{
		if(i != 0)
		{
			printf("%-3s", order[i].word);
		}
		for(int j = 0; j < MAX; j++)
		{
			if(i == 0 && j == 0)
			{
				printf(" ");
				for(int k = 0; k <= MAX-1; k++)
				{
					printf("%3s", order[k].word);
				}
				printf("\n");
				if(i == 0)
				{
					printf("%-3s", order[0].word);
				}
			}
			if((order[i].end1 > order[j].star1) || (order[i].end1 < order[i].star1) || i == j)
			{
				arr[i][j] = 0;
				printf("%3d", arr[i][j]);
			}
			else if(order[i].end1 <= order[j].star1 && order[i].end1 >= order[i].star1 && i !=j)
			{
				arr[i][j] = 1;
				printf("%3d", arr[i][j]);
			}
		}
		printf("\n");
	#else
	for(int i = 0; i <= MAX-1; i++)
	{
		for(int j = 0; j <= MAX-1; j++)
		{
			if((order[i].end1 > order[j].star1) || (order[i].end1 < order[i].star1) || i == j)
			{
				arr[i][j] = 0;
			}
			else if(order[i].end1 <= order[j].star1 && order[i].end1 >= order[i].star1 && i != j)
			{
				arr[i][j] = 1;
			}
		}
	}
	#endif
	for(int i = 0; i < MAX; i++)
	{
		num[i] = i + 1;
	}
				
}

void weightcount(int x)
{
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			for(int q = 0; q <= x; q++)
			{
				math[x][q][q] = 1;
			}
			if(simparr[x][j] == 1)
			{
				math[x][j][j] = 1;
				math[x][j][x] = 1;
			}
			weightresult[x][i] = math[x][i][j] * order[j].weight + weightresult[x][i];
		}
	}
	//判斷每一個做完之後的數值 如果比較大就會作取代 但是如果還有沒有做完 便還原這個點的數值
	
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			if(weightresult[j][i] > order[i].weight && simparr[j][i] == 1 && weightresult[j][i] != 0)
			{
				order[i].weight = weightresult[j][i];
				x1 = j;
				y1 = i;
			}
			else if(simparr[j][i] == 1 && weightresult[j][i] == 0)
			{
				order[i].weight = temp[i];
			}
		}
	}
	
	#ifdef DISPLAY
	
	printf("使用 reduced 矩陣:%d\n", num[x]);
	
	for(int j = 0; j < MAX; j++)
	{
		if (j != 0 && j <= (MAX - 2))
		{
			printf(" %d", num[j]);
		}
		else if (j >= (MAX - 1))
		{
			printf(" %d", num[j]);	
		}
		for(int k = 0; k < MAX; k++)
		{
			if (j == 0 && k == 0)
			{
				printf(" ");
				for(int q = 0; q < MAX; q++)
				{
					if(q <= (MAX - 2))
					{
						printf(" %d ", num[q]);
					}
					else if (q >= (MAX - 1))
					{
						printf(" %d ", num[q]);
					}
				}
				printf("\n");
				
				if(j == 0)
				{
					printf("1");	
				}
			}
			printf(" %d ", math[x][j][k]);
		}
		printf("\n");
	}
	
	printf("\n 點 %d, 運算過後的點權重:", num[x]);
	
	for(int q = 0; q < MAX; q++)
	{
		printf("%d.%d ", num[q], weightresult[x][q]);
	}
	
	printf("\n 權重:");
	
	for(int q = 0 ;q < MAX; q++)
	{
		printf("%d", order[q].weight);
	}
	
	printf("\n\n\n");
	#endif
	
	x++;
	
	if(x != MAX)
	{
		weightcount(x);
	}
}


void pickup(int g, int h)
{
	ia[maxnum - Maximum[g][h]] = h;

	ia[maxnum - Maximum[g][h] + 1] = g;

	xx--;

	if(xx != 0)
	{
		pickup(point[g][h], g);
	}
}

void select(void)
{
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			simparr[i][j] = arr[i][j];
			
			if(point[i][j] == 0)
			{
				point[i][j] = MAX;
			}
			
			if(arr[i][j] == 1)
			{
				point[i][j] = i;	// 假設只有點對點
				
				Maximum[i][j] = 1;
			}
		}
	}
	
	// 搜尋點對點之前有無連線
	for(int j = 0; j < MAX; j++)
	{
		for(int i = 0; i < MAX; i++)
		{
			for(int k = i + 1; k < MAX; k++)
			{
				if(arr[j][i] + arr[i][k] == 2)
				{
					Maximum[i][k] = Maximum[j][i] + 1;
					point[i][k] = j;
					if(maxnum < Maximum[i][k])
					{
						maxnum = Maximum[i][k];
						xx = maxnum;
						x1 = i;
						y1 = k;
					}
				}
			}
		}
	}
	
	//----------------------------------------------------------------
	//重要 ...xx 找不到
	//----------------------------------------------------------------
	if(xx == 0)
	{
		printf("\n****************************************************\n");
		
		printf("ERROR: select( )搜尋點對點之前有無連線。\n");
		
		printf("找不到，使得 xx = 0");
		
		printf("\n****************************************************\n");
		
		stop = 1;
		
		return;
	}
	
	//動態配置
	ia = (int*)calloc(maxnum, sizeof(int));
	
	pickup(x1, y1);
	
	#ifdef DISPLAY
	
	printf("\n 最大路線為:\n");
	
	for(int i = maxnum; i >= 0; i--)
	{
		printf("%s", order[ia[i]].word);
		
		if(i !=0)
		{
			printf(" →");
		}
	}
	
	printf("\n\n\n	reduced 過後的矩陣 \n");
	
	#endif
	
	for(int j = 0; j < MAX; j++)
	{
		for(int i = 0; i < MAX; i++)
		{
			for(int k = i + 1; k < MAX; k++)
			{
				if(arr[i][j] + arr[j][k] == 2)
				{
					simparr[i][k] = 0;
				}
			}
		}
	}
	
	#ifdef DISPLAY
	
	for(int i = 0; i < MAX; i++)
	{
		if(i != 0 && i <= 8)
		{
			printf("%d ", num[i]);
		}	
		else if(i >= 9)
		{
			printf("%d ",num[i]);
		}
		
		for(int j = 0; j < MAX; j++)
		{
			if(i == 0 && j == 0)
			{
				printf(" ");
				
				for(int q = 0; q < MAX; q++)
				{
					if(q <= 8)
					{
						printf("%d ", num[q]);
					}
					else if(q >= 9)
					{
						printf("%d ", num[q]);
					}
				}
				
				printf("\n");
				
				if( j== 0)
				{
					printf(" 1 ");
				}
			}
			printf("%d ",simparr[i][j]);
		}
		printf("\n");
	}
	
	#endif
	
	for(int i = 0; i < MAX; i++)
	{
		temp[i] = order[i].weight;
	}
	
	weightcount(0);
	
	for(int i = 0; i < MAX; i++)
	{
		if(maxnum < order[i].weight)
		{
			maxnum = order[i].weight;
			
			x1 = i;
		}
	}
	
	printf("權重最大是%d, 路線為: \n", maxnum);
	
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			if(maxnum == temp[x1] + order[j].weight && simparr[j][x1] == 1)
			{
				y1 = j;
				
				ia[i] = x1;
				
				ia[i+1] = y1;
				
				x1 = j;
				
				maxnum = order[j].weight;
				
				xx++;
			}
		}
	}
	
	for(int i = xx; i >= 0; i--)
	{
		printf("%s", order[ia[i]].word);
		
		if(i != 0)
		{
			printf(" →");
		}
	}
	
	printf("\n\n");
}

void FinishedCheck(void)
{
	for(int i = xx; i >= 0; i--)
	{
		for(int j = 0; j < NUMBER; j++)
		{
			if(!strcmp(order[ia[i]].word, order2[j].word))
			{
				order2[j].finish = 1;
				printf("%2s\t%4d 年 %2d 月 %2d 日 \t%4d 年 %2d 月 %2d 日\t%2d\t%2d\n",
				order2[j].word,
				order2[j].star1 / 10000, order2[j].star1 / 100 % 100, order2[j].star1 % 100,
				order2[j].end1 / 10000, order2[j].end1 / 100 % 100, order2[j].end1 % 100,
				order2[j].weight,
				order2[j].finish);
				finished_count++;
			}
		}
	}
	printf("完成數 : %d\n", finished_count);
	
	remain_count = NUMBER - finished_count;
	
	printf("剩餘數 : %d\n", remain_count);
}

void ReSort(void)
{
	int index = 0;
	
	for(int i = 0; i < NUMBER; i++)
	{
		if(order2[i].finish == 0)
		{
			strcpy(order[index].word, order2[i].word);
			order[index].star1 = order2[i].star1;
			order[index].end1 = order2[i].end1;
			order[index].weight = order2[i].weight;
			order[index].finish = order2[i].finish;
			index++;
		}
	}
	
	/*printf("編號 \t 起始時間 \t 結束時間 \t 權重 \t 完成 \n");
	for(int i = 0; i < NUMBER; i++)
	{
		if(order2[i].finish == 0)
		{
			printf("%2s\t%4d 年 %2d 月 %2d 日 \t%4d 年 %2d 月 %2d 日 t%2d \t%2d \n",
			order2[i].word,
			order2[i].star1 / 10000, order2[i].star1 / 100 % 100, order2[i].star1 % 100,
			order2[i].end1 / 10000, order2[i].end1 / 100 % 100, order2[i].end1 % 100,
			order2[i].weight,
			order2[i].finish);
			}
	}*/

//system("pause");
}

void ShowRemainData(void)
{
	printf("編號 \t 起始時間 \t 結束時間 \t 權重 \t 完成 \n");
	
	for(int i = 0; i < NUMBER; i++)
	{
		if(order2[i].finish == 0)
		{
			printf("%2s\t%4d 年 %2d 月 %2d 日 \t%4d 年 %2d 月 %2d 日 \t%2d \t%2d \n",
			order2[i].word,
			order2[i].star1 / 10000, order2[i].star1 / 100 % 100, order2[i].star1 % 100,
			order2[i].end1 / 10000, order2[i].end1 / 100 % 100, order2[i].end1 % 100,
			order2[i].weight,
			order2[i].finish);
			
		}
	}
}
