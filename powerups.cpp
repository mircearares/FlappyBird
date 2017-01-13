#include"biblioteci.cpp"

int canColide=1;

int collisionPowerUp()
{
   if((a[bird.y][bird.x]=='B' && a[bird.y][bird.x+1]=='W')
      ||(a[bird.y][bird.x]=='B' && a[bird.y][bird.x+1]=='R')
      ||(a[bird.y][bird.x]=='B' && a[bird.y+1][bird.x]=='R')
      ||(a[bird.y][bird.x]=='B' && a[bird.y-1][bird.x]=='W'))
        return 1;
   return 0;
}

void genPowerUp()
{
    srand(time(0));
    int poz=rand()% 8+7;

    a[poz][45]='P';//94
    a[poz][46]='W';//95
    a[poz+1][45]='W';//94
    a[poz+1][46]='R';//95
}

void deletePowerUp()
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

int sleep_value=1;//150

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
