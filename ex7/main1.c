#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SETS 5
#define NUMS 7
#define MAX_NUM 69

/* 產生一組不重複的七個數字 (01~69) */
void gen_set(int set[NUMS])
{
int used[MAX_NUM + 1] = {0};
for (int i = 0; i < NUMS; i++) {
int x;
do {
x = rand() % MAX_NUM + 1;
} while (used[x]);
used[x] = 1;
set[i] = x;
}
}

int main(void)
{
int n;
srand((unsigned)time(NULL));

printf("歡迎光臨長庚樂透彩購買機台\n");
printf("請問您要買幾組樂透彩：");
if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SETS) {
printf("輸入錯誤，n 必須介於 1 到 %d\n", MAX_SETS);
return 1;
}

FILE *fp = fopen("lotto.txt", "w");
if (fp == NULL) {
printf("無法開啟 lotto.txt\n");
return 1;
}

time_t now = time(NULL);
char buf[64];
strftime(buf, sizeof(buf), "%a %b %e %H:%M:%S %Y", localtime(&now));

fprintf(fp, "========= lotto649 =========\n");
fprintf(fp, "= %s =\n", buf);

for (int i = 1; i <= MAX_SETS; i++) {
fprintf(fp, "[%d]:", i);
if (i <= n) {
int set[NUMS];
gen_set(set);
for (int j = 0; j < NUMS; j++)
fprintf(fp, " %02d", set[j]);
} else {
for (int j = 0; j < NUMS; j++)
fprintf(fp, " --");
}
fprintf(fp, "\n");
}

fprintf(fp, "========= csie@CGU =========\n");
fclose(fp);

printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);
return 0;
}
