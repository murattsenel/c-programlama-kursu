## DERS 2
![image](https://user-images.githubusercontent.com/110337932/215270434-4f6e98b1-b328-4d50-b9fc-208950bdbd24.png)
* Kodların yazıldığı yer txt editörüdür.
* Bilgisayarda hafızada dosyalar bit bayt şeklinde tutulur.
* Derleyiciden çıkan assemby kodları assember ile makine kodlarına dönüştürülür.
* Derleyici çıktısına object code denir.
* Derleyicinin oluşturduğu hedef kodu linker yani bağlayıcılar özel bir yapıyla birleştirip çalıştırılabilir bir kod üretir.
* Derleyici kaynak dosyaları tek tek derler.
* Linker farklı kaynak dosyalarındaki kodları birbirleriyle ilişkilendirip uyumlu çalışmasını sağlar.
* Compile time(derleme zamanı)
* Link time (bağlama zamanı)
* Run time (çalışma zamanı)
* C standartında kaynak dosya ön işlemcinin girişidir.
* Kaynak kodun ön işlemciden çıktığı koda translation unit denir.
* Derleyicinin girişi translation unit tir.
* Kodun yazıldığı yer derleyici değil editördür.
* Derleyici çeviricidir.
* Program çalıştırıp hataları görmemizi sağlayan bu yaparken yardımcı araçlar kullanan programlara debugger denir.
* Her dilin kuralları vardır. Bunlara syntax adı verilir.
* Derleyici syntax kurallarına bakar. Dilin kurallarını çiğnediğimiz yerlerde derleyici ileti verir.
* Bunlar error veya warning dir.
* Warning 2 anlamda kullanılır.
```c
#include <stdio.h>

int ival;

int ival=10;
int ival==10; // burada derleyici lojic hata uyarisi verir.

int main()
{
}
```
Burada dil kurallarına uygundur. Ancak dil uyarı mesajı verir.
```c
#include <stdio.h>

int ival;

int main()
{
int ival += 10;
int ival + 10; 
}
```
Burada da bir kurallarına uygundur ama ival değeri 10 artmayacaktır.
Derleyici burada uyarı mesajı verir.

Static code analyzer logic hataları gösterir.

Compiler optimization da derleyici kodun anlamını bozmadan daha kısa sürede çalışacak şekilde ayarlar.

**TANIMSIZ DAVRANIŞ**

Tanımsız davranışlar tehlikeli durumlardır.
```c
#include <stdio.h>

int main()
{
 x= f1() + f2()	;// tanimsiz durum hangi fonksiyonun once cagirilicagi belli degil
}
```
Burada f1 veya f2 fonksiyonları sırası karışık olarak çağırılabilir.
Hangisinin önce çağırılacağının bir garantisi yoktur. Bu belirsiz bir davranıştır.
