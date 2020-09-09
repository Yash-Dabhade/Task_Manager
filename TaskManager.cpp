#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include <fstream>
#include <string.h>
using namespace std;
struct Task
{
    int SR_NO;
    char Task_Name[40];
    char Start_Date[20];
    char End_Date[20];
    char Status[20];
};

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
    cout << "\n\t\t\t|______________________________________________________|";
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
void CreateTask(void)
{
    system("CLS");
    struct Task obj;
    ofstream store_SR, store_TASKNAME, store_DATES1, store_DATES2;
    long int i, size;
    char Fname[20], Dname[100], temp1[20], temp2[20], temp3[20], temp4[20];
    string title, srfile, tasknamefile, datesfile1, datesfile2;
    char choice;
    title = "----- C R E A T E I N G     R E C O R D -----";
    cout << "\n\t\t\t ______________________________________________________";
    cout << "\n\n\t\t\t\t"
         << " " << title;
    cout << "\n\t\t\t ______________________________________________________";
    cout << "\n\n\t\tEnter Record Name (Without Space with Extension .dat) :: ";
    cin >> Fname;
    cout << "\n\n\t\tEnter How many Records You Want to Insert:: ";
    cin >> size;
    strcpy(temp1, Fname);
    srfile = strcat(temp1, "_SR.dat");
    strcpy(temp2, Fname);
    tasknamefile = strcat(temp2, "_TASKFILE.dat");
    strcpy(temp3, Fname);
    datesfile1 = strcat(temp3, "_DATESFILE1.dat");
    strcpy(temp4, Fname);
    datesfile2 = strcat(temp4, "_DATESFILE2.dat");

    store_TASKNAME.open(tasknamefile);
    store_DATES1.open(datesfile1);
    store_DATES2.open(datesfile2);
    store_SR.open(srfile);
    for (i = 1; i <= size; i++)
    {
        system("CLS");
        obj.SR_NO = i;
        store_SR << "\n\t"
                 << obj.SR_NO;
        cout << "\n\n\t\tSR-NO -> " << i;
        cout << "\n\n\t\t_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_";
        cout << "\n\n\n\t\tEnter TaskName (Without Space use (_)) :: ";
        scanf("%s", &obj.Task_Name);
        cout << "\n\n\t\tEnter Start Date(DD MM YYYY) ::  ";
        cin >> obj.Start_Date;
        cout << "\n\n\t\tEnter End Date(DD MM YYYY) :: ";
        cin >> obj.End_Date;
        store_TASKNAME << "\n\t" << obj.Task_Name;
        store_DATES1 << "\n"
                     << obj.Start_Date;
        store_DATES2 << "\n"
                     << obj.End_Date;
        //Storing In file
    }
    store_SR.close();
    store_TASKNAME.close();
    store_DATES1.close();
    store_DATES2.close();
    system("CLS");
    cout << "\n\nRecords Inserted Successfully\n";
}
void ViewTaskList(void)
{
    char Fname[20], temp1[20], temp2[20], temp3[20], temp4[20];
    // char tasknamefile[30], datesfile[30], srfile[30];
    ifstream show_SR, show_TASKNAME, show_DATES1, show_DATES2;
    string title, sr, task, dates1, dates2;
    char ch1, ch2, ch3;

    system("CLS");
    title = "----- D I S P L A Y I N G     R E C O R D -----";
    cout << "\n\t\t\t ______________________________________________________";
    cout << "\n\n\t\t\t\t"
         << " " << title;
    cout << "\n\t\t\t ______________________________________________________";
    cout << "\n\n\t\tEnter Record Name (Without Space with Extension .dat) :: ";
    cin >> Fname;
    // srfile = strcat(temp1, "_SR.dat");
    // tasknamefile = strcat(temp2, "_TASKFILE.dat");
    // datesfile = strcat(temp3, "_DATESFILE.dat");
    strcpy(temp2, Fname);
    show_TASKNAME.open((strcat(temp2, "_TASKFILE.dat")));
    strcpy(temp3, Fname);
    show_DATES1.open((strcat(temp3, "_DATESFILE1.dat")));
    strcpy(temp4, Fname);
    show_DATES2.open((strcat(temp4, "_DATESFILE2.dat")));
    strcpy(temp1, Fname);
    show_SR.open((strcat(temp1, "_SR.dat")));
    cout << "\n\t _____________________________________________________________________________________________________";
    cout << "\n\t|                                                                                                    |";
    cout << "\n\t|Sr.NO  ---                Task Name                         -- StartD ----          --- EndD____    |";
    cout << "\n\t|                                                                                                    |";
    cout << "\n\t|****************************************************************************************************|";
    cout << "\n";
    show_SR >> sr;
    show_TASKNAME >> task;
    show_DATES1 >> dates1;
    show_DATES2 >> dates2;
    // while (!show_TASKNAME.eof())
    // {
    //     cout << ch2;
    //     printf("\t\t");
    // }
    // while (!show_DATES.eof())
    // {
    //     cout << ch3;
    // }
    for (int i = 1; i <= 3; i++)
    {
        cout << "\n\t\t" << sr << "\t\t" << task << "\t\t" << dates1 << "\t\t" << dates2;
        show_SR >> sr;
        show_TASKNAME >> task;
        show_DATES1 >> dates1;
        show_DATES2 >> dates2;
    }

    cout << "\n\t|                                                                                                    |";
    cout << "\n\t|                                                                                                    |";
    cout << "\n\t|____________________________________________________________________________________________________|";
    show_DATES1.close();
    show_DATES2.close();

    show_TASKNAME.close();
    show_SR.close();
}

int main()
{
    system("color 02");
    int ch;
    while (1)
    {
        system("CLS");
        ch = welcome();
        switch (ch)
        {
        case 101:
            CreateTask();
            break;

        case 102:
            ViewTaskList();
            break;

        case 103:
            /* code */
            break;

        case 104:
            /* code */
            break;

        case 105:
            exit(0);
            break;

        default:
            cout << "\n\nInvalid Choice :: ";
            break;
        }
        system("PAUSE");
    }
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