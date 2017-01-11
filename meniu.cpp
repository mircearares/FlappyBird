/*
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#include<stdio.h>
using namespace std;
*/
#include "test.cpp"

void screen()
{
    system("cls");


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

        char a=219;
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
                            cout<<"\n\n\n Commencing game...\n\n";
                            system("cls");
                            cout<<"Press SPACE to play";
                            Sleep(1000);
                            game();
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
