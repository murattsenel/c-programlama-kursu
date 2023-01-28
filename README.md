#         C PRAGRAMLAMA EGİTİM NOTLARI

## DERS 1
### **C DİLİNİ TANIMA**
+ C dilinin kökeni algol dilidir.
 + Procedural programlama dilidir.
+ C non-proprietary dildir.(birine ait olmayan)
+ Program son olarak işlemcinin komutlarında çalıştırılır.
+ Derleyiciler kodu makine diline çevirir.
+ Derleyici daha yüksek seviyeli dilden daha düşük seviyeli dile dönüştüren araçlardır.
+ Statik türde bir dildir.
+ C taşınabilir bir dildir.
+ Çevirici yani derleyici ile istediğimiz sisteme uygun programlama yapılabilir.
+ C ve c++ verim kritik projelerde kullanılır.

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


## DERS 3
### SAYISAL SİSTEMLER
### **2lik sayı sistemi**
 ![image](https://user-images.githubusercontent.com/110337932/215271033-d9cdfdc5-a85a-4a20-ad84-dde13ee21425.png)
+ 4 bit = nibble
+ 8 bit = byte
+ 16 bit = Word
+ 32 bit = Double Word

**SORULAR**

**1100 1001 sayısının decimal değeri kaçtır ?**
 
 213
 
**45 sayısının binary gösterimi nedir?**

00101101

**Binary değerlerin alabileceği maksimum değerler**
- 1 byte =255
- 2byte =65.535
- 4 byte =4.294.967.295
- 8 byte = 18.446.744.073.709.551.615

**Bir sayının 1 e tümleyeni**

Sayının bitlerini terleyerek yapılır

11111111 → 00000000

**Bir sayının 2 ye tümleyeni**

Sayının 1 e tümleyeninin 1 fazlasıdır. Kısa yol olarak sağdan başlayarak ilk 1 bitini görene kadar aynısını yazarız.1 bitini göründe ilk bit aynen yazılır geri kalanı ters çevrilir.

0111 0110 → 1000 1010

**İşaretli 2lik sayı sistemi**
+ 8 bitlik sayının en son sol bitine işaret biti denir.
+ işaret biti 0 ise pozitif
+ 1 ise negatiftir.

**Aynı sayının negatifi pozitif olan sayının 2 ye tümleyenidir.**

+ 0010 0100 = 36
+ 1101 1100= -36

**1111 1111 sayısının değeri kaçtır ?**

Hepsi 1 ise -1 dir.

 ### 16lık sistemi.
 + Hex sistemi 16lık sistemdir.
 
 **SORULAR**
 
 **0111 1111 değeri kaçtır?**
  
 7F
 
  **2 byte sayının en küçük değeri kaçtır ?**
  
  0111 1111 …  →   8000
  
 **2 byte alanda -1 değeri kaçtır?**
 
 FFFF
 
 **TERİMLER**
  
+ Token = atom
+ Tokenazing derleyicinin komutları anlarken kullandığı yöntemdir.kodu token lara ayırır.
+ Translation unit ile source file arasındaki fark nedir?
+ Source file ön işlemci girdisidir.
+ Derleyicinin girdisi ise ön işlemci çıktısı translation unit tir.
+ Anahtar sözcük
+ Sabitler
+ isimler
+ Operatörler
+ String literalleri
+ Ayraçlar

