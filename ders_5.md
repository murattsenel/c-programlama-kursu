## DERS 5

**İnitialization is not a assignment**

**İlk değer verme bir atama değildir.**

C dilinde statik ömürlü değişkenlerinin ilk değerleri constat olmadır.

**Örnek**
```c
int x= 10 ;// kurallara uygun
int y=x ; //syntax hatası
```

Otomatik ömürlü değişkenlerde böyle bir zorunluluk yoktur.

#### Scope / namespace

**Scope nedir**

**Soru bildirdiğimiz bir ismi hangi kaynak kod alanında kullanabilirim ?**

+ Sorunun cevabı scope dur.

isim ara işlemi cok önemlidir

isim arama billi bir sırayla yapılır.

Aranan isim bulununca isim arama işlemi biter.

**Basit bir mülakat sorusu**
```c
#include <stdio.h>


/// syntax hatasi verir.printf nesne olarak algılanır.
int main(void)
{
	int printf =10;
 printf("hello world");
 
}
```

Burada isim arama sırasında printf i değişken olarak gösterdiğimiz için syntax hatası alıyoruz.

İsim aramayı kullanıldığı ve üstende kalan alanda yapar.

**Soru Aynı ismi birden fazla varlığa verirsek ne olur?**

+ Eğer 2 isimin kapsamı aynı ise birde fazla varlığa verilemez ancak kapsamları farklı ise syntax hatası olmaz.

 + Buna karşın iyi bir kullanım yöntemi değildir.

## Scope türleri

+ File scope
+ Block scope

**File scope**

+ Global isim alanında bildirildikleri noktadan dosyanın sonuna kadardır.

**Block scope**
+ Bildirildiği yerden bulunduğu bloğun sonuna kadardır.

**Örnek**
```c
#include <stdio.h>

///// syntax hatasi olur. Scope lari ayný  maskemeleme yapar.


int main()
{
	
int x =10;
double x[];	

}
```
Geçersiz kod
```c

#include <stdio.h>

///// syntax hatasi olmaz. Scope lari farkli 


int main()
{
	
int x =10;
if()
double x[];	

}
```

Scope ları farklı olduğu için geçerlidir.

#### İsmin maskelenmesi
+ Yerel isim global ismi maskelerse global değer yazırılamaz.

**Örnek**
```c
#include <stdio.h>

///// syntax hatasi olmaz. Scope lari farkli ancak maskeleme yapar.

int x = 70;
int main()
{
	
int x = 10;

printf("%d",x);
}
```

Yerel int x global x i maskelediği için çıktı 10 değerini alır.

**!!!Kursta Necati Ergin global x değişkeni yazdıramayız dedi ve bu dikkatimi çekti x değişkeninin nasıl yazdırabileceğimi düşünerek deneme yaptım ve buldum.**

```c
#include <stdio.h>

int x = 70;
void func(void)
{
    printf("x=%d",x);

}
int main()
{
	
int x = 10;

func();
}
```
Bu kodun çıktısı 70 olur.

Burada func fonksiyonunu çağırdığımız zaman x ismini aramaya func fonksiyonunun içinden ve üstünden başlar.

**Önemli bir mülakat sorusu**

**Ekran çıktısı ne olur.**
```c

#include <stdio.h>

/////// onemli tanimsiz davranis vardir.
////// x cop degeriyle hayata gelir.

int x =10;

int main()
{
	int x=x;
}
```
**Burada tanımsız davranış örneği vardır.**

x değerininin çöp değeri ile tekrar kendisine değer atanmıştır.

Global ve yerel statik değişkenlerin ilk değerleri constant (sabit) olmalı.

Static ön adı gelen kod satırındaki bütün değişkenler statik değişken olur.

#### Costant
```c
int main()
Const int x=10;
```

Cons değişkeninin değeri hiçbir zaman değiştirilemeyeceğini gösterir.

**Değişmeyen değişkenin yararları nelerdir ?**

+ Lojik hataların önüne geçer.
+ Kodun niyetini daha iyi anlatır.
+ Optimizasyonun daha iyi olmasını sağlar.
+ Static ve const ön adları birlikte kullanılabilir.
+ Sabitler kodun bir parçasıdır ve bellekte yer kaplamazlar.
