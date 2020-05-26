#include<stdio.h>
#include<stdlib.h>
#define deck(x,y) deck[x][y]

int search( int* ans , int **deck , int m , int n ,int x , int y , int step)
{
	if( deck(x,y) != 0)//accessed
		return 0;

	int max = m*n;//total step
	if( max == step)//final
	{
		(*ans)++;
		return 1;
	}
	else
	{
  	//check if not availiable
  		if( (deck(x+1 , y) == 2 && deck(x-1,y) ==2) && (deck(x,y+1) == 0 && deck(x,y-1) == 0) )
   			return 0;
  		if( (deck(x,y+1) == 2 && deck(x,y-1) == 2) && (deck(x+1,y) == 0 && deck(x-1,y) == 0) )
   			return 0;
   			
			deck(x,y)=2;//accessed
		//up
			if( (x+1) <= m )
				search( ans , deck , m , n , x+1 , y , step+1);
		//down
			if( (x-1) >= 1 )
				search( ans , deck , m , n , x-1 , y , step+1);
		//left
			if( (y-1) >= 1 )
				search( ans , deck , m , n , x , y-1 , step+1);
		//right
			if( (y+1) <= n)
				search( ans , deck , m , n , x , y+1 , step+1);

			deck(x,y)=0;
	}
}
int main()
{
	// creat the deck
	int m,n;//m,n = x,y
	while(scanf("%d %d",&m,&n) != EOF)
	{
	//int** deck = (int**)malloc(sizeof(int*)*(m+2) );
	int* deck[m+2];
	for( int i=0 ; i<m+2 ; i++)
	{
		deck[i] = (int*)malloc(sizeof(int)*(n+2));
		for( int j=0 ; j<n+2 ; j++)
		{
			deck[i][j]=0;
		}
	}
	// set the bound , bound = 1 , not used = 0
	for( int i=0; i<m+2 ; i++)
	{
		deck[i][0]=1;
		deck[i][n+1]=1;
	}
	for( int i=0 ; i<n+2 ; i++)
	{
		deck[0][i]=1;
		deck[m+1][i]=1;
	}
	/* test
	for( int i=1 ; i<=m ; i++)
	{
		for( int j=1 ; j<=n ; j++)
		{
			printf("%d ",deck[i][j]);
		}
		printf("\n");
	}
	*/
	int ans =0;
	for( int x=1 ; x<=m ; x++)
		for( int y=1 ; y<=n ; y++)
			search( &ans , deck , m , n , x , y , 1);
	printf("%d\n",ans/2);
	}
	return 0;
}
