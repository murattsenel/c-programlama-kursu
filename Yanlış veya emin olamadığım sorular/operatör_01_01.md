#### Aşağıdaki programın ekran çıktısı ne olur? 

__1. program__

```
#include <stdio.h>
 
int main()
{
	int x = 1;
	int y = -1;
	int z = !--x - !++y;
 
	z += x += y;
 
	printf("%d%d%d", x, y, z);
 
	return 0;
}
```

[ödevin cevabı](https://vimeo.com/363313251)

### Benim cevabım

+ Bana göre bu ifadede 
 
+ int "z = !--x - !++y;" satırı legal ! operatörünün operantı r-value olabilir.
 
+ Ancak  **"z += x += y;"** satırı sıkıntılı çünkü += operatörü sağdan sola öncelikli 2 . += kullanılırken ilk operantı (z += x) bu işlemin sonucu ve r-value olur.
 
+ tanımsız davranıştır.

### YANLIŞ YAPTIM
### Ödevin cevabı

+ !--x 1 azaltıp değilini aldık 1 oldu
  
+ !++y; 1 arttırıp değilini aldık 1 oldu.
 
+ z = 1-1 =0
  
+ z += x += y; burada yanlış düşünmüşüm sağdan başladığımız için ilk işlem yapıldı. ve 0 oldu 
  
+ z += 0 deyimi geldi sol operant z ve l-value olduğu için legal ve değeri 0
  
+  x=0 y=0 z=0 oldu
  

