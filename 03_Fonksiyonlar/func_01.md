* _3_ sayıdan en büyüğünü hesaplayan _max3_ isimli bir fonksiyon tanımlayınız.

* _main_ fonksiyonu içinde standart giriş akımından _3_ tamsayı alınız.

* _max3_ isimli fonksiyona çağrı yaparak alınan _3_ tam sayıdan en büyüğünü standart çıkış akımına _(ekrana)_ yazdırınız:

* Aynı programı bu kez gerçek sayılar için yazınız.

### Örnek ekran çıktısı (1)

```
uc tamsayi girin:
12 56 8

12, 56 ve 8 sayilarinin en buyugu 56
```

### Örnek ekran çıktısı (2)

```
uc gercek sayi girin:
2.87 1.35 0.12

2.870000, 1.350000 ve 0.120000 sayilarinin en buyugu 2.870000
```

### cevaplar

```c
int max3(int x, int y, int z) {

	int max = x;

	if (y > max)
		max = y;

	if (z > max)
		max = z;
	return max;
}


int main() {

	int x, y, z;
	
	printf("uc tam sayi giriniz \n ");
	scanf("%d%d%d",&x,&y,&z);

	printf("%d %d %d sayilarinin en buyugu %d", x, y, z, max3(x, y, z));

 ```

bu kodu yazarken printf içinde double için %f kullan  scanf için %lf 

```c
    #define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

double max3(double x, double y, double z) {

	double max = x;

	if (y > max)
		max = y;

	if (z > max)
		max = z;
	return max;
}


int main() {

	double x, y, z;
	
	printf("uc tam sayi giriniz \n ");
	scanf("%lf%lf%lf",&x,&y,&z);

	printf("%f %f %f sayilarinin en buyugu %f", x, y, z, max3(x, y, z));
```
