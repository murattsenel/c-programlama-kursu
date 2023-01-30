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

+ Fonksiyonların geri dönüş değeri olmak zorunda  değildir.
+ Geri dönüş değeri olmayan fonksiyonlar void ön  adıyla yazılır.
+ Eğer fonksiyonu tanımlarken void yazmak yerine boş bırakırsanız int olarak algılanır.

**Örnek**

```c
func(int x)
return 1;
```
+ derleyici int yazdığımızı düşünür.
  
**Normalde dilin kurallarında böyle bişey yoktur.**
```c
Void clear_screen(void)
```

Parametrenin içindeki void değişkenin başlangıç parametresinin olmadığını gösterir.

Boş bırakırsak paremetre olabilir veya olmaya bilir diye düşünür.
```c
Void func (int x,int y)
```

X ye y argümandır.
```c
Void func (int x …..) //→ variyadik fonsiyondur.
```

İstediğimiz kadar argüman yazabiliriz.

Fonksiyonun parametre değişkeni ile içindeki değişken farklıdır.

Variyadik fonksiyon yazmak için en az bir tane paremetre yazmalıyız.

Parametreyi çağıran kod gönderir.

#### Statement
+  Expression statement
+  compound statement
+  null statement
+  control statement

**expression statement**

+ x=5;
+ ++x;
+ Func();
  
 **Compound statement**
 ```c
 {
+ x=5;
+ ++x;
+ Func();
 }
 ```

+ Blokların içine yazılmış.
  
 **Null statement**

+ ; tek şekilde noktalı virgül kullanılır.
  
  **Control statement**
  
+ Önceden bilirlenmiş bir syntax a sahip ve bu syntax gereği en az bir keyword kullanılan yapılar.
+ Prgramın akısını değiştirebilir.
+  İf statement
+  Loop statement
+  While statement
+  Do while statement
+  For statement
+  Switch statement
+  Goto statement
+  Return statement
+  Break statement
+  Contiune statement

+ void ve return anahtar kelimeler
  bir fonksiyonun geri dönüş değeri olacaksa bunu return deyimi ile yapar.
+ eturn ; yalın return deyimi
+ eturn expr ; ifadeli return deyimi

**Soru**

**Neden 2 tene return deyimi var?**

+ Return deyiminin 2 işlevi vardır.
+ Çalışmakta olan fonksiyonun çalışmasını durdurması
+ Geri dönüş değeri üretmesi

```c

void func(void)
//statement
//statement
if()
return;
//statement
//statement
```
+ Normalde return deyimine ihtiyaç yoktu. Ancak programın istediğimiz bir yerde durması için return deyimini kullandık.
+ Void bir fonsiyonun sonuna return deyimi koyarsak syntax hatası olmaz. Ancak okuyanın yanlış anlamasını sağlayabilir. Gereksizdir.

**İfadeli return deyimi**

+ Geri dönüş değeri olan fonksiyonda ifadesiz return kullanmayın.
+ İfadeli return deyiminde return ifadenin değeri hesaplanır.
+ Geri dönüş değeri çağıran koda iletilir.
Fonksiyonun kodunun çalışması sona erer.

**Soru**

**Fonksiyonda bir adet mi geri dönüş değeri vardır?**

+ Fonksiyonda bir adet geri dönüş değeri vardır.
+ fonksiyonun içerisinde birden fazla return deyimi bulunabilir. Yalnızca bir tanesi geri dönüş değeri olarak iletilir.

**Soru**

**İki tam sayıyı toplayan fonksiyon yazınız**

```c
int sum(int a,int b)
{
	 return a+b;
}
```
**Soru**

**İki sayının en büyüğünü bulan fonksiyon yazınız.**

```c
int max2(int a,int b)
{
	 return a > b ? a : b;
}
```

**Soru**

**üç sayının en büyüğünü bulan fonksiyon yazınız.**

```c
int max3(int a,int b,int c)
{
	int max = a;
	
	if(b>max)
	max=b;
	
	if(c>max)
	max=c;
	
	return max;
}
```
