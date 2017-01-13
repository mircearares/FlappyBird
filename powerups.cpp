#include"biblioteci.cpp"

int canColide=1;

int collisionPowerUp()
{
   if((a[bird.y][bird.x]=='B' && (a[bird.y][bird.x+1]=='L' || a[bird.y][bird.x+1]=='S' || a[bird.y][bird.x+1]=='C'))
      ||(a[bird.y][bird.x]=='B' && (a[bird.y][bird.x+1]=='W' || a[bird.y][bird.x+1]=='T' || a[bird.y][bird.x+1]=='L'))
      ||(a[bird.y][bird.x]=='B' && (a[bird.y+1][bird.x]=='S' || a[bird.y+1][bird.x]=='F' || a[bird.y+1][bird.x]=='N'))
      ||(a[bird.y][bird.x]=='B' && (a[bird.y-1][bird.x]=='L' || a[bird.y-1][bird.x]=='S' || a[bird.y-1][bird.x+1]=='C')))
        return 1;
   return 0;
}

int whichPowerUp()
{
    if((a[bird.y][bird.x]=='B' && a[bird.y][bird.x+1]=='L')
      ||(a[bird.y][bird.x]=='B' && a[bird.y][bird.x+1]=='W')
      ||(a[bird.y][bird.x]=='B' && a[bird.y+1][bird.x]=='S')
      ||(a[bird.y][bird.x]=='B' && a[bird.y-1][bird.x]=='L'))
        return 1;
    if((a[bird.y][bird.x]=='B' && a[bird.y][bird.x+1]=='S')
      ||(a[bird.y][bird.x]=='B' && a[bird.y][bird.x+1]=='T')
      ||(a[bird.y][bird.x]=='B' && a[bird.y+1][bird.x]=='F')
      ||(a[bird.y][bird.x]=='B' && a[bird.y-1][bird.x]=='S'))
        return 2;
    if((a[bird.y][bird.x]=='B' && a[bird.y][bird.x+1]=='C')
      ||(a[bird.y][bird.x]=='B' && a[bird.y][bird.x+1]=='L')
      ||(a[bird.y][bird.x]=='B' && a[bird.y+1][bird.x]=='N')
      ||(a[bird.y][bird.x]=='B' && a[bird.y-1][bird.x]=='C'))
        return 3;
}

void typePowerUp(int type)
{
    int poz=rand()%8+7;
    switch(type)
    {
        case 1:
        {
            a[poz][45]='S';//94
            a[poz][46]='L';//95
            a[poz+1][45]='L';//94
            a[poz+1][46]='W';//95
            break;
        }
        case 2:
        {
            a[poz][45]='F';//94
            a[poz][46]='S';//95
            a[poz+1][45]='S';//94
            a[poz+1][46]='T';//95
            break;
        }
        case 3:
        {
            a[poz][45]='N';//94
            a[poz][46]='C';//95
            a[poz+1][45]='C';//94
            a[poz+1][46]='L';//95
            break;
        }
    }
}

void genPowerUp()
{
    srand(time(0));
    int type=rand()% 3+1;
    typePowerUp(type);

}

void deletePowerUp()
{
        a[bird.y+1][bird.x+1]=a[bird.y][bird.x+1]=a[bird.y-1][bird.x+1]=
        a[bird.y+1][bird.x]=a[bird.y-1][bird.x]=a[bird.y+1][bird.x-1]=
        a[bird.y][bird.x-1]=a[bird.y-1][bird.x-1]=' ';
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

void powerUp()
{
    int type=whichPowerUp();
    switch(type)
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
