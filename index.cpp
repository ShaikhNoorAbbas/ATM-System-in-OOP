#include <iostream>
#include <math.h>
using namespace std;
int pin();
class Balance
{
public:
    long balance;
    void balanceInput()
    {
        cout << endl
             << "Enter Balance in your Account: ";
        cin >> balance;
    }
    void displaybalance()
    {
        cout << endl
             << "Amount in Your Account: " << balance;
    }
};
class Deposite
{
public:
    long deposite_amount;
    void depositeInput()
    {
        cout << endl
             << "Enter Amount You Want To Deposite:  ";
        cin >> deposite_amount;
    }
};
class Withdraw
{
public:
    long number;
    void withdrawInput()
    {
        cout << endl
             << "Enter Amount You Want to Withdraw: ";
        cin >> number;
    }
};
class User : public Balance, public Withdraw, public Deposite
{
public:
    string name;
    void nameInput()
    {
        cout << endl
             << "Enter User Name: ";
        cin >> name;
    }
    void withdrawcheck()
    {
    start:
        if (number > balance)
        {
            cout << endl
                 << "You Have Only: {" << balance << "} in Your Account ";
            withdrawInput();
            goto start;
        }
        else
        {
            if (number == balance)
            {
                cout << endl
                     << "Your Left With Nothing " << (char)(2);
            }
            else
            {
                balance = balance - number;
                cout << endl
                     << "Amount Available in Your Account is: " << abs(balance);
            }
        }
    }
    void depositeCheck()
    {
        balance += deposite_amount;
        cout << endl
             << "Amount Available in your Account is: " << balance;
    }
};
int main()
{
    system("color 3");
    User obj[100];
    char confirm;
    int flag = 0;
    int i, size;
    do
    {
        cout << endl
             << "\t\t\t WELCOME TO ATM SYSTEM " << (char)(2);
        cout << endl
             << "Ente Number of Users you Want: ";
        cin >> size;
        for (i = 0; i < size; i++)
        {
            cout << endl
                 << endl
                 << "\t\t\t" << (i + 1) << " USER " << endl
                 << endl;
            flag = pin();
            if (flag != 0)
            {
                cout << endl
                     << "\t\t\t Welcome into ATM System ";
                obj[i].nameInput();
                obj[i].balanceInput();
                int choice;
                cout << endl
                     << "\t\t\t SELECT YOUR CHOICE " << (char)(2);
                cout << endl
                     << "1 Press (1) to Deposite ";
                cout << endl
                     << "2 Press (2) to Withdraw ";
                cout << endl
                     << "3 Press (3) to Check Amount Available in Your Account";
                cout << endl
                     << "Enter Your choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    obj[i].depositeInput();
                    obj[i].depositeCheck();
                    break;
                case 2:
                    obj[i].withdrawInput();
                    obj[i].withdrawcheck();
                    break;
                case 3:
                    obj[i].displaybalance();
                    break;
                default:
                    cout << endl
                         << "Please Enter Valid Choice " << (char)(2);
                }
            }
            else
            {
                cout << endl
                     << "\t\t\t Please Enter Valid Pin Next Time Now Do Whole Processes Again ";
            }
        }
        cout << endl
             << "Do You Want To Countinue ?:  ";
        cin >> confirm;
    } while (confirm == 'y' || confirm == 'Y');
    cout << endl
         << "\t\t\t STAY LEARNING....... TO STAY EARNING.......";
    return 0;
}
int pin()
{
    int mob[10];
    int pin[4];
    int i;
    cout << endl
         << "\t\t\t\t FIRST YOU NEED TO VERIFY YOURSELF " << (char)(2);
    cout << endl
         << endl
         << "REMEMBER -> Your Pin is Your Last Four Digits of Your Mobile Number " << endl;
    cout << endl
         << "Enter Your Mobile Number ";
    cout << "+91 ";
    for (i = 0; i < 10; i++)
    {
        cout << endl
             << "Enter " << (i + 1) << " Digit of your Mobile Number: ";
        cin >> mob[i];
    }
    cout << endl
         << endl
         << "\t\t\t\t Your Mobile Number is: +91 ";
    for (i = 0; i < 10; i++)
    {
        cout << " " << mob[i];
    }
    cout << endl
         << "\t\t\t Okay Now Let's See if Your Pin is valid or Not  ";
    for (i = 0; i < 4; i++)
    {
        cout << endl
             << "Enter " << (i + 1) << " Digit of Your Pin: ";
        cin >> pin[i];
    }
    if (mob[6] == pin[0] && mob[7] == pin[1] && mob[8] == pin[2] && mob[9] == pin[3])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}