#include"biblioteci.cpp"

int canColide=1, powerUpValue=0;

typedef struct
{
    int x, y;
}POWERUP;

POWERUP pwr;

int collisionPowerUp()
{
   if(bird.y==pwr.y && bird.x==pwr.x)
        return 1;
   return 0;
}

void typePowerUp(int type)
{
    switch(type)
    {
        case 1:
        {
            a[pwr.y][pwr.x]='S';
            powerUpValue=1;
            break;
        }
        case 2:
        {
            a[pwr.y][pwr.x]='F';
            powerUpValue=2;
            break;
        }
        case 3:
        {
            a[pwr.y][pwr.x]='N';
            powerUpValue=3;
            break;
        }
    }

}

void genPowerUp()
{
    srand(time(0));
    int type=rand()% 3+1;
    pwr.x=46;
    pwr.y=rand()% 16;
    typePowerUp(type);

}

int sleep_value=100;

void resetValues()
{
    sleep_value=100;
    canColide=1;
}

void sleepValueIncrease()
{
    sleep_value=200;
}

void sleepValueDecrease()
{
    sleep_value=10;
}

void powerUp()
{
    switch(powerUpValue)
    {
        case 1:
        {
           sleepValueIncrease();
           break;
        }
        case 2:
        {
           sleepValueDecrease();
           break;
        }
        case 3:
        {
            canColide=0;
            break;
        }
    }
}

void movPowerUp()
{
    pwr.x--;
}
