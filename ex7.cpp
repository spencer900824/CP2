#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct State
{
    int x;
    int y;
}S;
int* BFS( int sx , int sy ,int** t)
{
	int* re = (int*)malloc(sizeof(int)*10000);
	for( int i =0 ; i<10000 ; i++)
		*(re+i)=-1;
	int re_cou = 0;
	
    // up =1 , down =2 , left =3 , right =4
    int mx[4] = {0,0,-1,1};
    int my[4] = {1,-1,0,0};
    S que[100000];
    
    int rear=0 ,front=0;
    que[front].x = sx;
    que[front].y = sy;
    rear++;
    t[sx][sy] =0;
    for(front ; front<rear ; ++front)
    {
        sx=que[front].x;
        sy=que[front].y;
        
        for(int i = 0; i<4 ; i++)
        {
            if( mx[i]+sx>=0 && mx[i]+sx<101 && my[i]+sy>=0 && my[i]+sy<101 &&
				t[mx[i]+sx][my[i]+sy] < 0)
            {
				if(t[mx[i]+sx][my[i]+sy] == -1)
				{
					t[mx[i]+sx][my[i]+sy] = t[sx][sy]+1;
                	que[rear].x = sx+mx[i];
                	que[rear].y = sy+my[i];
                	rear++;
                	re[re_cou++] = t[mx[i]+sx][my[i]+sy];
				}
				else
				{
                	t[mx[i]+sx][my[i]+sy] = t[sx][sy]+1;
                	que[rear].x = sx+mx[i];
                	que[rear].y = sy+my[i];
                	rear++;
				}
            }
        }
    }
    return re;
}
int main()
{
	int N;
	char dis;
    //creat table
    while(scanf("%d\n", &N)&& N!= 0)
    {
    	int Kx,Ky;
        S mice[10000];
        int m_counter=0;
		int** t = (int**)malloc(sizeof(int*)*101);
        for( int i=0 ; i<101 ; i++ )
            *(t+i) = (int*)malloc(sizeof(int)*101);
		for( int i=0 ; i<101 ; i++)
			for( int j=0 ; j<101 ; j++)
				t[i][j] = 0;
        
        //get input ----------------------------------------------------------------
		char* str = (char*)calloc(103,sizeof(char));
		for( int i = 0; i<N ; i++)
        {
			char cross;
			gets(str);
			for( int j=0 ; str[j]!= NULL && str[j]!= '\n'; j++)
			{
				char tem = str[j];
				
				if(i==0 && j==0)
					cross = tem;
				if(tem == 'K')
				{ Kx=i;Ky=j;t[i][j]=1; }
				else if(tem =='@')
				{
					mice[m_counter].x=i;
                    mice[m_counter].y=j;
                    m_counter++;
					t[i][j] = -1;
				}
				else if(tem ==cross)
					t[i][j] = 0;
                else
					t[i][j]=-2;
			}
		}
		free(str);
        /*----------------------------------------------------------------
        for( int i = 0; i<N ; i++)
        {
           	for( int j = 0; j<20; j++ )
				printf("%d",t[i][j]);
			printf("\n");
		}
		/*/
        int* ans;
        ans = BFS(Kx,Ky,t);
        /*/----------------------------------
        for( int i = 0; i<N ; i++)
        {
           	for( int j = 0; j<20; j++ )
				printf("%d",t[i][j]);
			printf("\n");
		}
		/*/
		int min = 10000;
	  	for( int i=0 ; ans[i]!=-1 ; i++)
			if(ans[i]<min)
				min = ans[i];
		if( min == 10000)
			puts("= =");
		else
			printf("%d\n",min);
    }
    return 0;
}
