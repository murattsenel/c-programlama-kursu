#define _CRT_SECURE_NO_WARNINGS

/*burada virgül operatör mü ayraç mı olarak kullanılmış
çıktı legal mi yoksa tanımsız davranış mı*/

#include <stdio.h>



int main()
{
	int x = 10;

	printf("%d %d %d ", x, ++x, x++);


	printf("%d %d %d ", x, x++,++x);


}