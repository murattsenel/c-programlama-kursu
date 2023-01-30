## DERS 4

Derleyicinin isim arama sürecine name lookup denir.

İlk programı yazdıralım.
```C
#include <stdio.h>

int main(void)
{
 printf("hello world");
 
}
```

###Veri türleri (data types)

+ Her değişken verinin türü derleme aşamasında bilinmesi gerekir.

 **Basic types**

**User defined types**

Basic types 2 kategoriye ayrılır.

+ İnteger types
+ Floating types
#### İnteger types
+ _Bool
+ Char
+ Signed char
+ Unsigned char
+ Short int
+ Unsigned short int
+ Long int
+ Unsigned long int
+ Long long int
+ Unsigned long long int
+ İnt
+ Unsigned int
#### Floating types
+ Float
+ Double
+ Long double
#### Değişken bildirimi
+ Global namespace
+ Local namespace
+ Global isim alanında statement yazılamaz sadece  bildirim yapılabilir.
+ Yerel isim alanında ikiside yapılabilir.
  
#### İlk değer verme (initialization) 

 Değişkenin yaşam süresi
 - Lifespan
   - Storage duration

+ Global isim alanına yazılan ve yerel isim alanında static ön eki alan değişkenler statik değişken  olurlar.
+ Değişken global ise ilk değer vermesekte 0 + değerini alır.
+ Statik değişken olur ve bellekte kalır.
+ Değişkenin ömürüyle programın ömürü aynıdır.
+ Otomatik ömürlü değişkenler ise bulunduları scope kadar programda hayatta kalırlar.

**Örnek**
```C
#include <stdio.h>


void func(void)
{
	int x = 10;
	printf("x = %d \n",x);
	x+=10;
}

int main(void)
{
 func();
 func();
 func();
 func();
}
```
Bu örnekte değişkenimiz otomatik ömürlü olduğu için her zaman 10 değerini verir.
```c
#include <stdio.h>


void func(void)
{
	static int x = 10;
	printf("x = %d \n",x);
	x+=10;
}

int main(void)
{
 func();
 func();
 func();
 func();
}
```
Ancak burada statik ömürlü olduğu için her fonsiyonu çağırdığımızda 10 artarak gelir

**ilk tanımsız değer örneği**

Otomatik ömürlü değişkene ilk değer vermezsek değişken çöp değer ile hayata başlar.

Program ve çalışması için hiç istemeyen bir durumdur.
