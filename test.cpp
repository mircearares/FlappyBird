#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<windows.h>
#include<fstream>
#include<algorithm>
using namespace std;

fstream file("rez.txt", ios::in | ios::out | ios::app);

int results[100], nrRes=0;

void addResult(int rez)
{
    results[++nrRes]=rez;
}

void readResults()
{
    int x;
    while(file>>x)
        addResult(x);
}

void writeResults(int rez)
{
    file.clear();
    file<<rez<<"\n";
    file.close();
}


void writeResultsConsole()
{
    readResults();
    sort(results, results+nrRes);
    for(int i=nrRes-1;i>=0;i--)
        cout<<results[i]<<"\n";
}

char a[23][98];
int canColide=1;

typedef struct
{
    int x, y;
}PASARE;

int collision(PASARE bird)
{
   if(a[bird.y-1][bird.x]=='#' && a[bird.y-1][bird.x-1]=='#' && a[bird.y-1][bird.x+1]=='#')
        return 0;
   if((a[bird.y][bird.x]=='B' && a[bird.y-1][bird.x]=='#' && a[bird.y+1][bird.x]=='#')
       ||(a[bird.y][bird.x]=='B' && a[bird.y][bird.x+1]=='#' && a[bird.y][bird.x+2]=='#')
       ||(a[bird.y][bird.x]=='B' && a[bird.y-1][bird.x]=='#' && a[bird.y-2][bird.x]=='#')
       ||(a[bird.y][bird.x]=='B' && a[bird.y][bird.x-1]=='#' && a[bird.y][bird.x-2]=='#')) //merge oarecum, capetele de la tevi tre facute cu 3 stelute
        return 1;
    return 0;
}

int collisionPowerUp(PASARE bird)
{
   if((a[bird.y][bird.x]=='B' && a[bird.y][bird.x+1]=='W')
      ||(a[bird.y][bird.x]=='B' && a[bird.y][bird.x+1]=='R')
      ||(a[bird.y][bird.x]=='B' && a[bird.y+1][bird.x]=='R')
      ||(a[bird.y][bird.x]=='B' && a[bird.y-1][bird.x]=='W'))
        return 1;
   return 0;

}
void drawBird(PASARE bird)
{
    a[bird.y][bird.x]='B';
    a[bird.y][bird.x-1]=0;
}

void drawLand()
{
    for(int i=0;i<=97;i++)
        a[21][i]='#';
}

int collisionLand(PASARE bird)
{
    if(bird.y==21)
        return 1;
    return 0;
}

// astea 2 pot sa le unesc intr-un singur subprogram mai incolo
void movUpBird(PASARE &bird)
{
    a[bird.y][bird.x]=0;
    bird.y--;
    a[bird.y][bird.x]='B';
    Beep(200,50);
}

void movDnBird(PASARE &bird)
{
    a[bird.y][bird.x]=0;
    bird.y++;
    a[bird.y][bird.x]='B';
}


void genObst()
{
    int y1=rand() % 11;
    for(int i=0;i<=y1;i++)
        a[i][95]='#';
    a[y1][94]=a[y1][96]='#';

    for(int i=y1+6;i<21;i++)
        a[i][95]='#';
    a[y1+6][94]=a[y1+6][96]='#';

}

void movObst(PASARE bird)
{
    for(int i=0;i<22;i++)
        for(int j=0;j<97;j++)
            a[i][j]=a[i][j+1];

}

void afis()
{
    //cout.sync_with_stdio(0);//afisare mai rapida
    system("cls");
    for(int i=0;i<=21;i++)
    {
        for(int j=0;j<96;j++)
            cout<<a[i][j];
        cout<<"\n";
    }
    Sleep(50);
}

void genPowerUp()
{
    int poz=rand()% 16+10;
    a[poz][94]='P';
    a[poz][95]='W';
    a[poz+1][94]='W';
    a[poz+1][95]='R';
}

bool addScore(PASARE bird)
{
    if(a[0][bird.x]=='#' && a[20][bird.x] && !collision(bird))
        return true;
    return false;
}

void deletePowerUp(PASARE bird)
{
    if((a[bird.y][bird.x]=='B' && a[bird.y][bird.x+1]=='W')
      ||(a[bird.y][bird.x]=='B' && a[bird.y][bird.x+1]=='R')
      ||(a[bird.y][bird.x]=='B' && a[bird.y+1][bird.x]=='R')
      ||(a[bird.y][bird.x]=='B' && a[bird.y-1][bird.x]=='W'))
    {
        a[bird.y+1][bird.x+1]=a[bird.y][bird.x+1]=a[bird.y-1][bird.x+1]=
        a[bird.y+1][bird.x]=a[bird.y-1][bird.x]=a[bird.y+1][bird.x-1]=
        a[bird.y][bird.x-1]=a[bird.y-1][bird.x-1]=' ';
    }
}

int sleep_value=15;//150

void resetValues()
{
    sleep_value=15;//lasa 150
    canColide=1;
}

void sleepValueIncrease()
{
    sleep_value=300;
}

void sleepValueDecrease()
{
    sleep_value=7;//10
}

void powerUp()//trebuie testate fiecare in parte
{
    int powerUp=rand()% 2;
    switch(powerUp)
    {
        case 0:
        {
           sleepValueIncrease();
           break;
        }
        case 1:
        {
           sleepValueDecrease();
           break;
        }
        case 2:
        {
            canColide=0;
            break;
        }
    }
}

void game()
{
    int nr=0, score=0, powerUpHit=0, timer=0;
    PASARE bird;
    bird.x=5;
    bird.y=10;
    drawBird(bird);
    drawLand();

    while(1)
    {
        system("cls");
        while(1)
        {
            if(GetAsyncKeyState(VK_RETURN))
                return;
            if(nr%15==0)
                genObst();
            else if((nr+1)%105==0 && !powerUpHit)
                genPowerUp();

            drawBird(bird);

            if(GetAsyncKeyState(VK_SPACE))
                movUpBird(bird);
            else
                movDnBird(bird);

            if((collision(bird) || collisionLand(bird)) && canColide)
            {
                system("cls");
                cout<<"Scorul dvs. este: "<<score;
                writeResults(score);
                Sleep(1500);
                return;
            }
            if(collisionPowerUp(bird))
            {
                powerUp();
                powerUpHit=1;
                timer=0;
                deletePowerUp(bird);
            }

            if(powerUpHit)
                timer++;
            if(powerUpHit && timer==20)
                resetValues();

            if(addScore(bird))
            {
                Beep(400,50);
                score++;
            }

            nr++;
            movObst(bird);
            afis();
            Sleep(sleep_value);
        }
    }
}

/*
int main()
{
    game();
    return 0;
}
*/

