#define _CRT_SECURE_NO_WARNINGS

/* ben call by value da değişken değerlerini değiştiremeyiz sanıyordum.
ancak arguman olarak gönderdiğimiz dışındaki global değişkenleri fonksiyonlar
 hem kullanıp hemde değiştirebiliyormuş.*/

#include <stdio.h>

int g = 3;
int y = 5;

int f1(int x)
{
	y = 3;
	return x * g++;
}

int f2(int x)
{
	return x * ++g;
}


int main()
{
	f1(3);
	printf("%d", y);
}


