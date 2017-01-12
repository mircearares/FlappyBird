#include"biblioteci.cpp"

fstream file("rez.txt", ios::in | ios::out | ios::app);

int nrRes=0;

typedef struct
{
    int score, time;
}RESULTS;

RESULTS result[100];

void addResult(int rez, int tim)
{
    result[nrRes].score=rez;
    result[nrRes].time=tim;
    nrRes++;
}

void readResults()
{
    int rez, tim;
    while(file>>rez>>tim)
        addResult(rez, tim);
}

void writeResults(int rez, int tim)
{
    file.clear();
    file<<rez<<" "<<tim<<"\n";
    file.close();
}

bool comp(RESULTS a, RESULTS b)
{
    if(a.score<b.score)
        return 1;
    return 0;
}

void writeResultsConsole()
{
    readResults();
    sort(result, result+nrRes, comp);
    for(int i=nrRes-1;i>=0;i--)
        cout<<result[i].score<<" "<<result[i].time<<"s\n";
}
