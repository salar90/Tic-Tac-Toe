// C++ Tic Tac Toe game by Salar Gholizadeh
// https://github.com/salar90/Tic-Tac-Toe

#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
struct player
{
	char *name;
	int wins;
};

void disp(int a[3][3])
{
	clrscr();
	char s[7][7];
	int i,j;
	s[0][0]=201;
	s[0][1]=205;
	s[0][2]=203;
	s[0][3]=205;
	s[0][4]=203;
	s[0][5]=205;
	s[0][6]=187;
	s[1][0]=186;
	s[1][2]=186;
	s[1][4]=186;
	s[1][6]=186;
	s[2][0]=204;
	s[2][1]=205;
	s[2][2]=206;
	s[2][3]=205;
	s[2][4]=206;
	s[2][5]=205;
	s[2][6]=185;
	s[3][0]=186;
	s[3][2]=186;
	s[3][4]=186;
	s[3][6]=186;
	s[4][0]=204;
	s[4][1]=205;
	s[4][2]=206;
	s[4][3]=205;
	s[4][4]=206;
	s[4][5]=205;
	s[4][6]=185;
	s[5][0]=186;
	s[5][2]=186;
	s[5][4]=186;
	s[5][6]=186;
	s[6][0]=200;
	s[6][1]=205;
	s[6][2]=202;
	s[6][3]=205;
	s[6][4]=202;
	s[6][5]=205;
	s[6][6]=188;
	s[1][1]='1';
	s[1][3]='2';
	s[1][5]='3';
	s[3][1]='4';
	s[3][3]='5';
	s[3][5]='6';
	s[5][1]='7';
	s[5][3]='8';
	s[5][5]='9';
	for(i=0;i<=2;i++)
		for (j=0;j<=2;j++)
			if(a[i][j]==1)
				s[i*2+1][j*2+1]='X';
			else if(a[i][j]==2)
				s[i*2+1][j*2+1]='O';

	for(i=0;i<=6;i++)
		{
			for(j=0;j<=6;j++)
				cout << s[i][j];
			cout << "\n";
		}
}
int checkwin(int a[3][3])
{
	int i;
	for (i=0;i<=2;i++)
	{
		if (a[i][0]==a[i][1] && a[i][1]==a[i][2] && a[i][1] !=0)
			return a[i][1];
		if (a[0][i]==a[1][i] && a[1][i]==a[2][i] && a[2][i] !=0)
			return a[2][i];
	}
	if (a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[0][0]!=0)
		return a[0][0];
	if (a[2][0]==a[1][1] && a[1][1]==a[0][2] && a[2][0]!=0)
		return a[2][0];
	return 0;
}
int playgame(int a[3][3],player fp,player sp)
{
	int haswon=0;
	int count=0;
	while (haswon==0)
	{


		int choice;
		int chx,chy;

		disp(a);
		cout << "\nTurn of "<< fp.name;
		cout << "\nEnter number of the cell for X.";
		char ch;
		do
		{
			ch=getch();
			choice=ch-49;//choice range: 0 to 8
			chy=choice/3;
			chx=choice%3;
		}while (!(ch>='0' && ch <= '9' ) || a[chy][chx]!=0);
		a[chy][chx]=1;
		count++;
		haswon=checkwin(a);
		if (haswon==1) break;
		if (count==9) return 3;


		disp(a);
		cout << "\nTurn of "<< sp.name;
		cout << "\nEnter number of the cell for O.";

		do
		{
			ch=getch();
			choice=ch-49;//choice range: 0 to 8
			chy=choice/3;
			chx=choice%3;
		}while (!(ch>='0' && ch <= '9' ) || a[chy][chx]!=0);
		a[chy][chx]=2;
		count++;
		haswon=checkwin(a);
		if (haswon==2) break;
		if (count==9) return 3;

	}
	disp(a);
	return haswon;
}
void main()
{
	char ch;
	int i,j;
	int pvp[3][3];
	player p1;
	player p2;
	clrscr();
	cout << "Welcome.";
	cout << "\nEnter Player1 name:  ";
	cin >> p1.name;
	cout << "\nEnter Player2 name:  ";
	cin >> p2.name;
	p1.wins=0;
	p2.wins=0;

	do
	{
		for (i=0 ;i<=2;i++)
			for (j=0;j<=2;j++)
				pvp[i][j]=0;
		int winner;
		winner=playgame(pvp,p1,p2);
		switch (winner)
		{
		case 1:
			cout <<"\n"<< p1.name <<" Wins.";
			break;
		case 2:
			cout <<"\n" << p2.name <<" Wins.";
			break;
		case 3:
			cout <<"\nNo Winner !";
			break;
		}


		cout << "\nPlay again?(y/n)";
		ch=' ';
		while(ch !='Y' && ch !='y' && ch !='N' && ch !='n')
			ch=getch();
		if (ch=='N' || ch=='n') break;

	}while(1);


}