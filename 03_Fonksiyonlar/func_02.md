* _4_ sayıdan en büyüğünü hesaplayan _max4_ isimli bir fonksiyon tanımlayınız.

* _main_ fonksiyonu içinde standart giriş akımından _4_ tamsayı alınız.

* _max4_ isimli fonksiyona çağrı yaparak alınan _4_ tam sayıdan en büyüğünü standart çıkış akımına _(ekrana)_ yazdırınız:

### Örnek ekran çıktısı (1)

```
dört tamsayi girin:
12 56 91 8

12, 56, 91 ve 8 sayilarinin en buyugu 96
```
```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int max4(int x, int y, int z,int t) {

	int max = x;

	if (y > max)
		max = y;

	if (z > max)
		max = z;
	if (t > max)
		max = t;

	
	return max;
}


int main() {

	int x, y, z,t;
	
	printf("dort tam sayi giriniz \n ");
	scanf("%d%d%d%d",&x,&y,&z,&t);

	printf("%d %d %d %d sayilarinin en buyugu %d", x, y, z, t, max4(x, y, z,t));
	

}
```
