#### Kendisine gün, ay ve yıl olarak gönderilen tarihin yılın kaçıncı günü olduğunu hesaplayan _day_of_year_ isimli işlevi tanımlayın:

```
int day_of_year(int day, int mon, int year);
```

+ İşlevin geri dönüş değeri _day/month/year_ tarihinin year yılının kaçıncı günü olduğu bilgisi.
+ Artık yılları _(leap years)_ göz önüne almayı unutmayınız.


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int day_of_year(int day, int mon, int year) {


	int day_year = 0;

	for (int i = 1; i <= mon - 1 && i < 12; i++) {
		if (i <= 7) {


			if (i % 2)
				day_year += 31;
			else
				day_year += 30;
		}
		else {
			if (i % 2)
				day_year += 30;
			else
				day_year += 31;
		}

	}
	if (mon > 2) {
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			day_year += day - 1;
		else
		  day_year += day - 2;
	}	
	else 
		day_year += day ;

	return day_year;
}    




int main() {

	int day = 0;
	int mon = 0;
	int year = 0;

	while (1) {
		printf(" gun ay yıl olarak bir tarih giriniz\n");
		scanf("%d%d%d", &day, &mon, &year);

		printf("%d/%d/%d tarihi yilin %d inci gunudur \n", day, mon, year, day_of_year(day, mon, year));


	}

	

}

```
