#include <iostream>
#include <string.h>
using namespace std;

// class
class Bank
{
private:
    int acno;
    char name[30];
    long balance;

public:
    void OpenAccount(int i)
    {
        cout << i + 1 << " "
             << "User Number -->" << endl;
        cout << "Enter Account Number: ";
        cin >> acno;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Please Enter the first Deposit: ";
        cin >> balance;
    }
    void ShowAccount()
    {
        cout << "Account Number: " << acno << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "\n<------------------ XXXXX ------------------>\n";
    }
    void Deposit()
    {
        long amt;
        cout << "Enter Amount U want to deposit? ";
        cin >> amt;
        balance = balance + amt;
        cout<<"Balance:"<<balance<<endl;
        cout << "\n<------------------ XXXXX ------------------>\n";
    }
    void Withdrawal()
    {
        long amt;
        cout << "Enter Amount U want to withdraw? ";
        cin >> amt;
        if (amt <= balance)
        {

            balance = balance - amt;
            cout<<"Balance:"<<balance<<endl;
            cout << "\n<------------------ XXXXX ------------------>\n";
        }
        else
        {
            cout << "Less Balance..." << endl;
            cout << "\n<------------------ XXXXX ------------------>\n";
        }
    }
    int Search(int);
};

int Bank::Search(int a)
{
    if (acno == a)
    {
        ShowAccount();
        return (1);
    }
    return (0);
}

// main code
int main()
{
    int num = 0;
    cout << "\n\n\t\t\t\t\t############################ START ############################"
         << "\n\n";
    cout << "Please select the number of account :";
    cin >> num;
    int store = num-1;
    Bank C[store];

    int found = 0, a, ch, i;

    if (num != 0)
    {

        for (i = 0; i <= num-1; i++)
        {
            C[i].OpenAccount(i);
            cout << "\n<------------------ XXXXX ------------------>\n\n";
        }

        do
        {
            // display options
            cout << "\n\n1:Display All\n2:By Account No\n3:Deposit\n4:Withdraw\n5:Exit" << endl;

            // user input
            cout << "Please input your choice: ";
            cin >> ch;
            cout << "\n<------------------ XXXXX ------------------>\n";

            switch (ch)
            {
            case 1: // displating account info
                for (i = 0; i <= num - 1; i++)
                {
                    C[i].ShowAccount();
                }
                break;
            case 2: // searching the record
                cout << "Account Number? ";
                cin >> a;
                cout << "\n<------------------ XXXXX ------------------>\n";
                for (i = 0; i <= num - 1; i++)
                {
                    found = C[i].Search(a);
                    if (found)
                        break;
                }
                if (!found)
                {

                    cout << "Record Not Found" << endl;
                    cout << "\n<------------------ XXXXX ------------------>\n";
                }
                break;
            case 3: // deposit operation
                cout << "Account Number To Deposit Amount? ";
                cin >> a;
                cout << "\n<------------------ XXXXX ------------------>\n";
                for (i = 0; i <= num - 1; i++)
                {
                    found = C[i].Search(a);
                    if (found)
                    {
                        C[i].Deposit();
                        break;
                    }
                }
                if (!found)
                    cout << "Record Not Found" << endl;
                cout << "\n<------------------ XXXXX ------------------>\n";
                break;
            case 4: // withdraw operation
                cout << "Account Number To Withdraw Amount? ";
                cin >> a;
                cout << "\n<------------------ XXXXX ------------------>\n";
                for (i = 0; i <= num - 1; i++)
                {
                    found = C[i].Search(a);
                    if (found)
                    {
                        C[i].Withdrawal();
                        break;
                    }
                }
                if (!found)
                    cout << "Record Not Found" << endl;
                cout << "\n<------------------ XXXXX ------------------>\n";
                break;
            case 5: // exit
                cout << "Have a nice day" << endl;
                cout << "\t\t\t\t\t############################ END ############################";
                break;
            default:
                cout << "Invalide Credentials !" << endl;
                cout << "\n<------------------ XXXXX ------------------>\n";
            }
        } while (ch != 5);
    }

    else
    {
        cout << "\n\n THANKS FOR VISITING US" << endl;
        cout << "\n\n\t\t\t\t\t############################ END ############################";
    }

    return 0;
}
