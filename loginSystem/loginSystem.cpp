#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int choice;

    cout << "\t\t\t____________________________________________\n\n\n";
    cout << "\t\t\t               Welcome to the login page     \n\n\n";
    cout << "\t\t\t______________       MENU     ________________\n\n";
    cout << "                                                     \n\n";
    cout << "\t| Press 1 to LOGIN                       |" << endl;
    cout << "\t| Press 2 to REGISTER                    |" << endl;
    cout << "\t| Press 3 to if You forgot password      |" << endl;
    cout << "\t| Press 4 to EXIT                        |" << endl;
    cout << "\n\t\t\t Please enter Your choice: ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "\t\t\tThank You and see You again!\n\n";
        break;
    default:
        system("cls");
        cout << "\t\t\t Select from the avilable options \n" << endl;
        main();
    }

}

void login()
{
    int count{};
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Eneter username and password: " << endl;
    cout << "\t\t\t Username: ";
    cin >> userId;
    cout << "\t\t\t Password: ";
    cin >> password;

    // Chcecking if username and password already exists in our records
    ifstream input("records.txt");
    
    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            // If count will be 1 the login will be sucessfull
            count = 1;
            system("cls");
        }
    }

    input.close();

    if (count == 1)
    {
        cout << userId << "\n Login sucessfull \n";
        main();
    }
    else
    {
        cout << "\n LOGIN ERROR \n Wrong username or password \n";
        main();
    }
}

void registration()
{
    string rUserId, rPassword, rId, rPass;
    system("cls");

    cout << "\t\t\t Enter username: ";
    cin >> rUserId;
    cout << "\t\t\t Enter password: ";
    cin >> rPassword;

    ofstream f1("records.txt", ios::app);
    f1 << rUserId << " " << rPassword << endl;
    system("cls");

    cout << "\n\nt\t\t Registration sucessfull \n";
    main();
}

void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password? \n";
    cout << "Press 1 to search Your id by username" << endl;
    cout << "Press 2 to go back to the main menu" << endl;
    cout << "\t\t\t Enter Your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string sUserId, sId, sPass;
        cout << "\t\t\t Enter username You remembered: ";
        cin >> sUserId;

        ifstream f2("records.txt");

        while (f2 >> sId >> sPass)
        {
            if (sId == sUserId)
            {
                count = 1;
            }
        }

        f2.close();

        if (count == 1)
        {
            cout << "\n\n Your account is found \n";
            cout << "\n\n Your password is: " << sPass;
            main();
        }
        else
        {
            cout << "\n\t Your account is not found :( \n";
            main();
        }
        break;
    }

    case 2:
    {
        main();
    }

    default:
        cout << "\t\t\t Choose from avilable options" << endl;
        forgot();
    }
}
