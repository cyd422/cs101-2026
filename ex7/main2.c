#include <stdio.h>
#include <string.h>

#define N 6
#define TITLE_LEN 64

typedef struct Books {
int id;
int price;
char title[TITLE_LEN];
} book_t;

/* 計算並輸出所有書籍的總價錢 */
void total_price(const book_t books[], int n)
{
int sum = 0;
for (int i = 0; i < n; i++)
sum += books[i].price;
printf("Total price: %d\n", sum);
}

/* 輸出書籍資料 */
void list_books(const book_t books[], int n)
{
printf("%-4s %-6s %s\n", "Id", "Price", "Title");
for (int i = 0; i < n; i++)
printf("%-4d %-6d %s\n", books[i].id, books[i].price, books[i].title);
}

int main(void)
{
book_t books[N] = {
{1, 1000, "All the Light We Cannot See"},
{2, 300, "The 38 Letters from J.D. Rockefeller to his son"},
{3, 1000, "The Ballad of Songbirds and Snakes"},
{4, 550, "Killers of the Flower Moon"},
{5, 870, "Elon Musk"},
{6, 1344, "Milk and Honey 12-Month 2024"}
};

/* 存成二進位檔 Book.bin */
FILE *fp = fopen("Book.bin", "wb");
if (fp == NULL) {
printf("無法開啟 Book.bin\n");
return 1;
}
fwrite(books, sizeof(book_t), N, fp);
fclose(fp);

/* 讀回來確認檔案內容正確 */
book_t loaded[N];
fp = fopen("Book.bin", "rb");
if (fp == NULL) {
printf("無法讀取 Book.bin\n");
return 1;
}
size_t cnt = fread(loaded, sizeof(book_t), N, fp);
fclose(fp);

list_books(loaded, (int)cnt);
total_price(loaded, (int)cnt);
return 0;
}
