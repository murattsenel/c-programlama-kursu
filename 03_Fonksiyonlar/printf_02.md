Aşağıdaki program derlenip çalıştırıldığında ekran çıktısı ne olur?
  
```
#include <stdio.h>

int main()
{
	int x = 333;

	printf("%d", printf("%d", printf("%d", x)));
}

```
### Cevabım

çıktısı 33331 olur.

printf() fonksiyonun geri dönüş değeri kullanılır.

ilk ifade 333 yazar. Sonra 3 yazılır. Son olarak 1 yazar.