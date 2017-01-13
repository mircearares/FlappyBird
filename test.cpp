#include"biblioteci.cpp"
#include"bird.cpp"
#include"results.cpp"
#include"powerups.cpp"
#include"map.cpp"

void loseGame(int score, int time)
{
    system("cls");
    cout<<"         You lost          \n";
    cout<<"    Score         Time \n";
    cout<<"     "<<score<<"             "<<time<<"s";
    Sleep(1500);
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
            else if((nr+1)%60==0 && !powerUpHit)
                genPowerUp();

            drawBird();

            if(GetAsyncKeyState(VK_SPACE))
                movUpBird();
            else
                movDnBird();

            if((collision() || collisionLand()) && canColide)
            {
                system("cls");
                resetMap();

                time_elapsed=(clock()-begin_time)/CLOCKS_PER_SEC;
                writeResults(score, time_elapsed);

                loseGame(score, time_elapsed);
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
            {
                resetValues();
                powerUpHit=0;
            }

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

