#include"biblioteci.cpp"
#include"bird.cpp"
#include"results.cpp"
#include"powerups.cpp"

void drawLand()
{
    for(int i=0;i<=48;i++)//97
        a[21][i]='#';
}

int collisionLand()
{
    if(bird.y==21)
        return 1;
    return 0;
}

void genObst()
{
    int y1=rand() % 11;
    for(int i=0;i<=y1;i++)
        a[i][46]='#';//95
    a[y1][45]=a[y1][47]='#';//94 si 96

    for(int i=y1+6;i<21;i++)
        a[i][46]='#';//95
    a[y1+6][45]=a[y1+6][47]='#';

}

void movObst()
{
    for(int i=0;i<22;i++)
        for(int j=0;j<48;j++)//97
            a[i][j]=a[i][j+1];

}

void afis()
{
    //cout.sync_with_stdio(0);//afisare mai rapida
    system("cls");
    for(int i=0;i<=21;i++)
    {
        for(int j=0;j<47;j++)//96
            cout<<a[i][j];
        cout<<"\n";
    }
    Sleep(50);
}

bool addScore()
{
    if(a[0][bird.x]=='#' && a[20][bird.x] && !collision())
        return true;
    return false;
}

void game()
{
    int nr=0, score=0, powerUpHit=0, timer=0;
    float time_elapsed=0;
    const clock_t begin_time = clock();

    bird.x=5;
    bird.y=10;
    drawBird();
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
            else if((nr+1)%60  ==0 && !powerUpHit)
                genPowerUp();

            drawBird();

            if(GetAsyncKeyState(VK_SPACE))
                movUpBird();
            else
                movDnBird();

            if((collision() || collisionLand()) && canColide)
            {
                system("cls");
                cout<<"Scorul dvs. este: "<<score;
                time_elapsed=(clock()-begin_time)/CLOCKS_PER_SEC;
                writeResults(score, time_elapsed);
                Sleep(1500);
                return;
            }
            if(collisionPowerUp())
            {
                powerUp();
                powerUpHit=1;
                timer=0;
                deletePowerUp();
            }

            if(powerUpHit)
                timer++;
            if(powerUpHit && timer==20)
                resetValues();

            if(addScore())
            {
                Beep(400,50);
                score++;
            }

            nr++;
            movObst();
            afis();
            Sleep(sleep_value);
        }
    }
}
/*
int main()
{
    game();
    return 100;
}
*/
