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

 #### 16lık sistemi.
 + Hex sistemi 16lık sistemdir.
 
 **SORULAR**
 
 **0111 1111 değeri kaçtır?**
  
 7F
 
  **2 byte sayının en küçük değeri kaçtır ?**
  
  0111 1111 …  →   8000
  
 **2 byte alanda -1 değeri kaçtır?**
 
 FFFF
 
 #### TERİMLER
  
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

#### Anahtar sözcük (keyword)
 + İnt, if, for, do , float vb
#### Sabitler
+ 41 decimal
+ 0x41 hex
+ 041 octal 8 lik sayı sistemi !!!!!!! **benzeri mükatta çıktı unutma**
+ C kurallarında olmayan bazı şeyler derleyicilerde farklılık gösterebilir.
#### Operatörler
+ Operatör işlem yaptıran tokendir.
#### String literalleri
+ Tek bir tokendir. “merhaba dünya”

#### Object expression

**Valve category**
 + L valve
+ R valve

##### Constant
+ C de bellekte bir yere sahip bazı nitelikleri olan varlıklara nesne nedir.
+ Nesnenin türü nesnelerin ne olduklarını ifade eder.

**Veri bellekte kaç byte yer kaplar?**
**1 ler ve 0 lar nasıl yorumlanacak?**

Bu soruların cevaplarını nesnenin türü verir.

Veri türleri temelde 2 ye ayrılır.

#### Basic types ve user defined types
+ Basic types dil tarafında hazır sunulan tam sayı veya gerçek sayı değerlerini ifade eden türlerdir.
+ User defined types hazır türler dışında yeni oluşturduğumuz türlere verilen addır.

**Expression(ifade)**

**Statement (deyim)**

**Declaration(bildirim)**

Bir ismin ne olduğunu anlatan şeyler declaration'dır.
+ int x ;
+ int foo(int x) ; gibi

Deyimler ise işlem kodu üreten şeylerdir.
 + X=y+5;
 
 Value category işlemleri niteler
 + X+10
+ X*y+5 gibi

**L-value**

**R-value**

ifade bellekte bir yere karşılık geliyorsa l-value dur.

r-value bir hesaplama ifadesidir.

Hangi value kategorisine ait olduğunu anlamak için bir test yapabiliriz.

```c
#include <stdio.h>

// nesnenin value category testi

int main()
{
int x =10;
&(x);
 
}
```
Eğer syntax hatası vermiyorsa bir adresi vardır ve l-value dur.

Syntax hatası veriyorsa r-value dur.

**Constant expression**

+ İfadenin değerinin programın çalışma zamanı dışında derleyicide anlaşılan değerlere constant denir.
