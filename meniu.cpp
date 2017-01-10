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
        cout<<" _____ _                           ____  _         _ \n";
        cout<<"|  ___| | __ _ _ __  _ __  _   _  | __ )(_)_ __ __| |\n";
        cout<<"| |_  | |/ _` | '_ || '_ || | | | |  _ || | '__/ _` |\n";
        cout<<"|  _| | | (_| | |_)|| |_)|| |_| | | |_)|| | |  | (_)|\n";
        cout<<"|_|   |_||__._| .__/| .__/|___  | |____||_|_|  |____|\n";
        cout<<"              |_|   |_|    |___/                     \n\n";

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
                            cout<<"\n\n\n Commencing game...";
                            game();
                            Sleep(10);
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
