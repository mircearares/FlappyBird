#include "test.cpp"

void helpScreen()
{
    system("cls");
    cout<<"Press SPACE to fly between the obstacles    \n";Sleep(100);
    cout<<"Every successful pass between the pipes is rewarded with 1pt    \n";Sleep(150);
    cout<<"If you collide with the pipes, the game will end and your SCORE and TIME will be saved in the leaderboard   \n";Sleep(200);
    cout<<"There are going to be 3 types of Power Ups \n";Sleep(100);
    cout<<" SL              FS             NC     \n";
    cout<<" LW              ST             CL     \n";
    cout<<"^slow^         ^fast^     ^no collision^";Sleep(300);
    cout<<"\n\n\n GOOD LUCK. HAVE FUN";Sleep(300);
    cout<<"\n\n\n PRESS SPACE TO START";
}

void PrintMenu()
{

	string Meniu[4]={"1. Start", "2. LeaderBoard", "3. Exit"};
	int option=0;

	while(1)
    {
        system("cls");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<" ________  _       ________  ________  _______  __     __    _______  _  ______  ____      \n";Sleep(100);
        cout<<"|  ______|| |     |  ____  ||  ____  ||  ___  ||  |   |  |  |  ___  ||_||  __  ||  _ |      \n";Sleep(100);
        cout<<"| |______ | |     | |____| || |____| || |___| | |  |_|  |   | |   | | _ | |__| || | | |      \n";Sleep(100);
        cout<<"|  ______|| |     |  ____  || _______|| ______|  |     |    | |___| || ||     _|| |  | |     \n";Sleep(100);
        cout<<"| |       | |     | |    | || |       | |         |   |     |  ___  || ||  _ |  | |   | |     \n";Sleep(100);
        cout<<"| |       | |     | |    | || |       | |          | |      | |   | || || | |_| | |  | |     \n";Sleep(100);
        cout<<"| |       | |____ | |    | || |       | |          | |      | |___| || || |  | || |_| |      \n";Sleep(100);
        cout<<"|_|       |______||_|    |_||_|       |_|          |_|      |_______||_||_|  |_||____|        \n\n";Sleep(100);

        for(int i=0; i<3;i++)
        {
            if(i==option)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                cout<<Meniu[i]<<"\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout<<Meniu[i]<<"\n";
            }
        }

            while(1)
            {
                if(GetAsyncKeyState(VK_UP)!=0)
                {
                    option--;
                    if(option== -1)
                        option =2;
                    break;
                }
                else if(GetAsyncKeyState(VK_DOWN)!=0)
                {
                    option++;
                    if(option==3)
                        option = 0;
                    break;
                }
                else if(GetAsyncKeyState(VK_RETURN)!=0)
                {
                    switch(option)
                    {
                        case 0:
                        {
                            system("cls");
                            helpScreen();
                            game();
                            PrintMenu();
                            Sleep(10000);
                        }break;
                        case 1:
                        {
                            cout<<"\n\n\n LeaderBoard ! \n";
                            writeResultsConsole();
                            Sleep(10000);
                        }break;
                        case 2:
                        {
                            return;
                        }break;
                    }
                }
            }
        Sleep(150);
    }
}

int main()
{
    PrintMenu();
    return 0;
}
