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

## ders 5

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

## DERS 6

+ C büyük harf küçük harf duyarlı bir dildir.
+ Tamamen büyük harf ile isimlendirme yapmak iyi bişey değildir.
+ C de genelde makrolar büyük harflidir. Bu yüzden  koda bakan birisi kafası karışık yanlış  anlayabilir.
+ Global değişkenler dezavantajlıdır.
+ Programın taşınabilirliğini azaltır.
+ Hata bulmayı zorlaştırır.
+ Değişkenin scope nu mümkün olduğunca daraltılması gerekir.
+ 
**Önemli**

+ Statik ömürlü değişken ile otomatik ömürlü değişkenin bulunduğu bellek farklıdır.
+ Otomatik ömürlü değişken ana bellek (stack) da tutulur.
+ Statik ömürlü değişken ana bellek (data segmenti) inde tutulur

**Örnek**

```c
#include <stdio.h>

/////////otomatik omurlu degisken oldugu icin her zaman 5 degerini verir.

int main()
{

	for(int i=0;i<10;i++)
	{
		int x=5;
		printf("%d\n");
		++x;
	}
	
}
```
Bu örnekte ekranda x değerini her zaman 5 olarak gösterir.

Çünkü her seferinde döngüye tekrar giriyor ve x değeri bellekten siliniyor.

### FONKSİYONLAR

**Client code**

**To define a function**

**To call a function**

+ Client code bir fonsiyonu çalıştıracak verileri  gönderen kod
+ To define a funcion bir fonksiyonu tanımlamak
+ To call a function fonksiyonu çağırmak

**Soru**

**Fonksiyon kendini çağıran koda nasıl veri iletir?**
1) Geri dönüş değeri (return value)
2) Call by reference (değişken adresini gönder fonksiyon değişkenine hesapladığı değeri yazsın

+ Double get_area(double Radius) fonksiyon syntax ında içeride noktalı virgül olmaz.

- [ ] void func(int x, y , z) syntax hatası
- [x] Void func(int x . int y , int z) doğru syntax
