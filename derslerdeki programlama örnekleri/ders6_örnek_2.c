//////// 2 sayinin toplamini veren foksiyon
int sum(int a,int b)
{
	 return a+b;
}


//////// 2 sayinin buyugunu bulan fonksiyon
int max2(int a,int b)
{
	 return a > b ? a : b;
}

//////// 3 sayinin buyugunu bulan fonksiyon
int max3(int a,int b,int c)
{
	int max = a;
	
	if(b>max)
	max=b;
	
	if(c>max)
	max=c;
	
	return max;
}
