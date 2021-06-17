#include<stdio.h>
#include<time.h>
#include<windows.h>

void create_target();
void clean();
void ekran();
void menu();

char ch;
int i,puan=0,x=30,y=11,targetx,targety;

main()
{
	SetConsoleTitle("MINI OYUN  (github.com/bayover)");
	srand(time(NULL));
	create_target();
	menu();
	while(1)
	{
		ch=getch();
		if(ch==13) break;
	}
	while(1)
	{
		ekran();
		ch=getch();
		if(ch==72)      y--;
		else if(ch==80) y++;
		else if(ch==75) x--;
		else if(ch==77) x++;
		else if(ch=='q'||ch=='Q') exit(0);
		if(y<=0)        y++;
		if(y>28)		y--;
   		if(x<=-1)       x++;
   		if(x>57)        x--;
		if(x==targetx&&y==targety)
		{
			puan++; create_target();
			ekran(); printf("\a");
		} 
	}
}

void menu()
{
	for(i=0;i<y;i++) printf("\n");
	for(i=0;i<x-5;i++) printf("  ");
	printf("YON TUSLARI ILE OYNANIR\n");
	for(i=0;i<x-4;i++) printf("  ");
	printf("BASLAMAK ICIN ENTER");
}

void ekran()
{
	clean();
	printf("[%d] %d,%d konumuna gidin. (Cikmak icin q)\n",puan,targetx,targety);
	for(i=0;i<y;i++) printf("\n");
	for(i=0;i<x;i++) printf("  ");
	printf("*%d,%d",x,y);
}

void create_target()
{
	while(1)
	{
		targetx=rand()%57;
		if(targetx!=x) break; 
	}
	while(1)
	{
		targety=rand()%28+1;
		if(targety!=y) break;
	}
}

void clean()
{
	system("cls");
}
