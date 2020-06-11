/*
 * Discription----------------------
 * big num has 7 functions
 * check( bignum )
 * add(x ,y ,ans)
 * multiply(x , y , ans)
 * compare(x ,y )  x>y:1 x<y:-1 x=y:0
 * creat( num , big_num) creat a big num of num
 * print_b( num )
 *str_to_bignum( bignum )
 *
 * N is the length of the big num
*/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define N 255

void check(int*num)
{
	for( int i=N-1 ; i>0 ; i--)
	{
		while(num[i] >= 10)
		{
			num[i]-=10;
			num[i-1]+=1;
		}
	}
}
void add( int*x , int*y , int*ans)
{
	for( int i=N-1 ; i>=0 ; i--)
	{
		ans[i] = x[i]+y[i];
	}
	check(ans);
}

void multiply( int*x , int*y , int*ans )
{
	for( int y_coun=N-1 ; y_coun>=0 ; y_coun-- )
	{
		for( int x_coun=N-1 ; x_coun>=0 ; x_coun--)
		{/*
 * Discription----------------------
 * big num has 7 functions
 * check( bignum )
 * add(x ,y ,ans)
 * multiply(x , y , ans)
 * compare(x ,y )  x>y:1 x<y:-1 x=y:0
 * creat( num , big_num) creat a big num of num
 * print_b( num )
 *str_to_bignum( bignum )
 *
 * N is the length of the big num
*/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define N 255

void check(int*num)
{
	for( int i=N-1 ; i>0 ; i--)
	{
		while(num[i] >= 10)
		{
			num[i]-=10;
			num[i-1]+=1;
		}
	}
}
void add( int*x , int*y , int*ans)
{
	for( int i=N-1 ; i>=0 ; i--)
	{
		ans[i] = x[i]+y[i];
	}
	check(ans);
}

void multiply( int*x , int*y , int*ans )
{
	for( int y_coun=N-1 ; y_coun>=0 ; y_coun-- )
	{
		for( int x_coun=N-1 ; x_coun>=0 ; x_coun--)
		{
			int ans_coun = x_coun + y_coun - (N-1);
			if(ans_coun >= 0 )
			{
				ans[ans_coun] += x[x_coun]*y[y_coun];
			}
		}
		check(ans);
	}

}

int compare(int*x ,int*y)
{
	for( int coun=0 ; coun<N ; coun++)
	{
		if(x[coun] > y[coun])
			return 1;
		else if(x[coun]<y[coun])
			return -1;
	}
	return 0;
}


void creat( int num , int* big_num )
{
	big_num[N-1] = num;
	check( big_num );
}

void print_b(int* num)
{
	int i=0;
	for(i ; num[i]==0 ; i++);
	for(i ; i<N ; i++)
		printf("%d",num[i]);
}

void str_to_bignum( char*str ,int* bignum)
{
	int str_cou=0;
	for( str_cou ; str[str_cou] != '\0';str_cou++);
	str_cou--;
	for( int i=N-1 ; str_cou>=0 ; str_cou--)
	{
		bignum[i--] = (int)str[str_cou]-48;
	}
}
/*
void half( int* bignum)
{
	for( int i=0 ; i<N-1 ; i++)
	{
		if(bignum%2==0)
			bignum[i]/=2;
		else
		{

		}
	}
	bignum[N-1]/=2;
}
*/
//-------------------------------------------------

int main()
{
	int a[N]={0},b[N]={0},c[N]={0};
	char str1[N] = "123456789";
	char str2[N] = "123456789";
	str_to_bignum(str1,a);
	str_to_bignum(str2,b);
	multiply(a,b,c);
	print_b(c);
	return 0;
}






			int ans_coun = x_coun + y_coun - (N-1);
			if(ans_coun >= 0 )
			{
				ans[ans_coun] += x[x_coun]*y[y_coun];
			}
		}
		check(ans);
	}

}

int compare(int*x ,int*y)
{
	for( int coun=0 ; coun<N ; coun++)
	{
		if(x[coun] > y[coun])
			return 1;
		else if(x[coun]<y[coun])
			return -1;
	}
	return 0;
}


void creat( int num , int* big_num )
{
	big_num[N-1] = num;
	check( big_num );
}

void print_b(int* num)
{
	int i=0;
	for(i ; num[i]==0 ; i++);
	for(i ; i<N ; i++)
		printf("%d",num[i]);
}

void str_to_bignum( int* bignum)
{
	char c;
	int in_tem[255] = {0}, tem_coun=0;
	while(scanf("%c",&c))
	{
		if( c == '\n')
			break;
		in_tem[tem_coun++] = (int)c-48;			
	}
	tem_coun--;
	for(int i=N-1 ; tem_coun>=0;i--)
		bignum[i] = in_tem[tem_coun];
}

void half( int* bignum)
{
	for( int i=0 ; i<N-1 ; i++)
	{
		if(bignum%2==0)
			bignum[i]/=2;
		else
		{

		}
	}
	bignum[N-1]/=2;
}
//-------------------------------------------------

int main()
{
	int target_bignum[N];
	str_to_bignum(target_bignum);
	int big_s[N]={0} , big_e[N]={0};
	creat(1,big_s);
	creat(2,big_e);
	while( compare(big_s,big_e) == -1 )
	{
		if( 
	}
}





