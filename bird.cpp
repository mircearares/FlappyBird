char a[23][49];

typedef struct
{
    int x, y;
}PASARE;

PASARE bird;

int collision()
{
   if(a[bird.y-1][bird.x]=='#' && a[bird.y-1][bird.x-1]=='#' && a[bird.y-1][bird.x+1]=='#')
        return 0;
   if((a[bird.y][bird.x]=='B' && a[bird.y-1][bird.x]=='#' && a[bird.y+1][bird.x]=='#')
       ||(a[bird.y][bird.x]=='B' && a[bird.y][bird.x+1]=='#' && a[bird.y][bird.x+2]=='#')
       ||(a[bird.y][bird.x]=='B' && a[bird.y-1][bird.x]=='#' && a[bird.y-2][bird.x]=='#')
       ||(a[bird.y][bird.x]=='B' && a[bird.y][bird.x-1]=='#' && a[bird.y][bird.x-2]=='#'))
        return 1;
    return 0;
}

void drawBird()
{
    a[bird.y][bird.x]='B';
    a[bird.y][bird.x-1]=0;
}

void movUpBird()
{
    if(bird.y==0)
        return;
    a[bird.y][bird.x]=0;
    bird.y--;
    a[bird.y][bird.x]='B';
    Beep(200,50);
}

void movDnBird()
{
    a[bird.y][bird.x]=0;
    bird.y++;
    a[bird.y][bird.x]='B';
}
