## DERS 7

**Bir mutlak değer hesaplayan fonksiyon yazalım.**

```c
int get_abs(int x)
{
	if(x>0)
	   return x;
	else
	   return -x;   

}
```
Daha kısa bir yöntem ile yazalım.

```c
int get_abs(int x)
{
	return x >= 0 ? x : -x;

}
```
Fonksiyonlar içinde fonksiyonlar tanımlanmaz.

Fonksiyonlar global isim alanında tanımlanmalı.



```c
int main()
{
	int get_abs(int x)
	{
		return x >= 0 ? x : -x;

	}

	int x;
	x=get_abs(-20);
	printf("%d", x);
	
}
```
Main de bir fonksiyon olduğu için prgram syntax hatası verir.

**Old-style function definition**

+ Dikkat kullanmayınız.
+ sadece eski fonksiyon tanımlamalarında vardır.

```c
double get_mean(a,b,c)
double a,b,c
{
	return a+b+c ;
}
```
Eski tip tanımlamadır. Yeni kurallar ile dilden çıkarılmıştır. Ancak derleyiciler eski kodların çalışmasını sağlamak için doğru kabul eder.

**Soru**

**Fonksiyonların geri dönüş değeri niçin vardır?**


1) Bir değer hesaplamaya yönelik fonksiyonların hesaplanan değeri geri dönüş değeri olarak çağırılan koda aktarılır.
2) Bir soruya cevap veren fonksiyonlar evet hayır , doğru yanlış , geçerli geçersiz gibi.
   + predicate funciton
   + test function
   + bool function
  
    Geleneksel olarak int türü kullanılır.

	İsimlendirmede is ön eki kullanılır.(isprime)

	Bool için kullanılan int türüne boolin int denir.

	0 = ise false 

	0 hariç bütün değerler true' dur. non-zero


3) Bazı fonksiyonların geri dönüş değeri başarı bilgisidir.
   
   Bazılarında başarı değeri int türünde gönderilir.

   0 ise success non-zero ise failure

   Microsoftta negetif değer başarısızlıktır.

4) Fonksiyonun geri dönüş değeri tamamlayıcı bir bilgi olabilir.
   
   Kullanıp kullanmak kullanıcının elindedir.

   Örnek **printf** fonksiyonu

   Printf fonsiyonunun geri dönüş değeri ekrana yazdırdığı karakter sayısıdır.

**Fonksiyonların geri dönüş değerlerini kullanmak zorunda değiliz ancak lojik hata olabilir.**

+ 1 , 2 ve 3. tip fonksiyonlarda geri dönüş değerini kullanmamak lojik hatadır.
+ 4 . tip fonksiyonların geri dönüş değerini kullanmamak lojik hata olmayabilir.

### Fonksiyon çağrıları

+ C ve c++ dillerinde fonksiyon çağrıları bir ifade ile olur ve bir opreratör gereklidir.

+ function call oparetor **()**

+ func();
+ Fonksiyonun içindeki parametre kadar arguman gönderilmesi gerekir.
  
**örnek**

```c
int a =234
int b =321
func(a*a + b*b ) ;
```
Fonksiyon çağrı ifadesinde gönderilen argumana matematiksel işlem yazılabilir.

**örnek**

```c
if(ndigit(x)>5)
{

}
```
Void olmayan bir fonksiyonun çağrı ifadesinin değeri fonksiyonun geri dönüş değeri olarak kullanılabilir.

- [x] .
```c
if(sin(x)<cos(y))
```
- [x] .
```c
int ival ndigit(x)+ndigit(y)
```
  - [x] .
```c
if(max2(x,y)>max2(a,b))
```
Yukarıdaki bütün fonksiyon çağrıları syntax kurallarına uygundur.

**Dikkat**

Void fonksiyonlar yalnızca deyim olarak kullanılır.

```c
void clear_screen(void)
//
clear_screen();
```
Fonksiyonun geri dönüş değerinini isteyerek kullanmamaya discard etmek denir.

+ scanf(); fonksiyonunun geri dönüş değerini kullanmamak lojik hatadır.
+ (void)getchar(); özellikle discard edilmiştir.

### Fonksiyonların geri dönüş değerinin kullanılması

1) Bir fonksiyonun çağrısından elde edilen geri dönüş değeri değişkene atanabilir veya değişkenin ilk değeri olabilir.
   
    ```c
	int n= ndigit(x);
	dval = sin(x);
	```
    
**Soru**

**Fonksiyonun geri dönüş değeri neden değişkende saklanır?**

+ Durumdan duruma değişir.
+ Geri dönüş değeri birden fazla yerde kullanılıyor olabilir.

**Örnek**

```c
a = sqrt(x);
b = sqrt(x);
c = dval + sqrt(x);
```
Kötü kodlama örneğidir.Aynı işlemi birden fazla yerde yapmış.

**Örnek**

```c
for(int i=0 ;i<strlen(str);++i)
```
Kötü kodlama örneğidir.

Hem okuyanı yanıltır.Hemde döngüde fonksiyon bir çok kez tekrardan hesaplanacağı için performansı düşürür.

Bazen fonksiyonun değerini bir değişkende tutmak sakıncalı olabilir.

Karmaşık ve uzun bir kod varsa foksiyon kod içinde bir kere kullanılacaksa bile değişkende tutulabilir.Kodun okuması kolay olması amaçlanır.

Farklı farklı durumlar olabilir.

**Değişkende saklamanın iyi olmadığı durumlar**

```c
x = foo();

y = func();

z = x + y ;

//yerine soyle yazılabilir

z = foo(); + func();
```
**Önemli**

Statik ömürlü değişkenlere sabit değer ile ilk değer verilmelidir.İlk değer olarak fonksiyonun değeri verilemez.Ancak otomatik ömürlü değişkenin ilk değeri fonksiyonun geri dönüş değeri olabilir.

2) Fonksiyonun çağrı ifadesi bir fonksiyon arguman olarak kullanılabilir.

**Örnek**

```c
a= func(foo());
```
+ Arguman değeri önce hesaplanır.Sonra arguman olarak diğer fonksiuona gönderilir.

```c
sin(sqrt(x));

max2(ndigit(x),ndigit(y));

ndigit(ndigit(x));
```
**4 sayının en büyüğünü bulan fonksiyonu yazalım**

```c
#include <stdio.h>

int max2(int x, int y)
{
	return x > y ? x : y;
}



int main()
{
	int x, y, z, t;
	printf("4 adet sayi giriniz\n");

	scanf("%d%d%d%d", &x, &y, &z, &t);

	int max =max2(max2(x, y), max2(z, t));

	printf("\n4 sayini en buyugu %d\n",max);
	
	
}
```
3) İfadeli return deyiminin return değiminde fonksiyon çağrı ifadesi kullanılabilir.

```c
int foo(int a,int b,)
////
return max2(a,b)
```
**İki farklı fonksiyon çağrı yapısı vardır.**
 + Call by value 
 + Call by reference 
  
C de default olarak bütün fonksiyonlar çağrı ifadesi olarak call by value'dur.

C de call by reference yapmanın yolu **pointer** kullanmaktır.

**İki değişkenin değerlerini birbirleriyle takas eden fonksiyon yazalım.**

```c
#include <stdio.h>


int main()
{
int x = 34;
int y = 93;

printf("x = %d   y = %d \n",x,y);

int temp = x;

x = y;

y = temp ;

printf("x = %d   y = %d ",x,y);	
	
}
```
Call by value fonksiyon ile takas işlemi yapılamaz.

Örnek swap(x,y) bu fonksiyonda 2 değişkenin değeri değişemez. Çünkü fonksiyon içindeki değişkenler dışarıya etki etmezler.

**Scanf();** adres operantörü ile çağırılır. Call by reference fonksiyondur.

Yerel değişkenin değerini ancak **call by reference fonksiyon** değiştirebilir.
