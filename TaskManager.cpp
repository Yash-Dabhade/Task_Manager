#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include <fstream>
#include <string.h>
using namespace std;
int welcome(void)
{
    string title;
    char choice;
    title = "-----T A S K    M A N A G E R-----";
    cout << "\n\t\t\t ______________________________________________________";
    cout << "\n\n\t\t\t\t"
         << " " << title;
    cout << "\n\t\t\t ______________________________________________________";
    cout << "\n\t\t\t|                                                      |";
    cout << "\n\t\t\t|          Hello  Friends, Welcome !!                  |";
    cout << "\n\t\t\t|                                                      |";
    cout << "\n\t\t\t|******************************************************|";
    cout << "\n\t\t\t|                                                      |";
    cout << "\n\t\t\t|   A-) CREATE NEW TASK RECORD                         |";
    cout << "\n\t\t\t|                                                      |";
    cout << "\n\t\t\t|   B-) VIEW TASK LIST                                 |";
    cout << "\n\t\t\t|                                                      |";
    cout << "\n\t\t\t|   C-) ADD TASK                                       |";
    cout << "\n\t\t\t|                                                      |";
    cout << "\n\t\t\t|   D-) DELETE TASK RECORD                             |";
    cout << "\n\t\t\t|                                                      |";
    cout << "\n\t\t\t|   E-) EXIT                                           |";
    cout << "\n\t\t\t_______________________________________________________";
    cout << "\n\n\t\t\t   ENTER OPTION NUMBER :: ";
    cin >> choice;
    if (choice == 'A' || choice == 'a')
        return (101);
    else if (choice == 'B' || choice == 'b')
        return (102);
    else if (choice == 'C' || choice == 'c')
        return (103);
    else if (choice == 'D' || choice == 'd')
        return (104);
    else if (choice == 'E' || choice == 'e')
        return (105);
    else
        return (999);
}
int main()
{
    system("CLS");
    system("color 02");
    welcome();
    // char ch;
    // store.open("Data.dat");
    // store << "Hello World\n";
    // store.close();
    // show.open("Data.dat");
    // ch = show.get();
    // while (!show.eof())
    // {
    //     cout << ch;
    //     ch = show.get();
    // }
    // show.close();
    // cout << "\nAfter append !\n";
    // store.open("Data.dat", ios::app);
}