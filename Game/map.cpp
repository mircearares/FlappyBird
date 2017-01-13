void drawLand()
{
    for(int i=0;i<=48;i++)//97
        a[21][i]='#';
}

void resetMap()
{
    for(int i=0;i<23;i++)
        for(int j=0;j<49;j++)
            a[i][j]=' ';
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
