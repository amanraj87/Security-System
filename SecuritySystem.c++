#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
int main()
{
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];
    cout << "      Security System       \n";
    cout << "_______________________"
         << "\n\n";
    cout << "|      1.Register      |"
         << "\n";
    cout << "|      2.Login         |"
         << "\n";
    cout << "|   3.Change Password  |"
         << "\n";
    cout << "|_____4.End Program____|"
         << "\n\n";
    do
    {
        cout << "\n"
             << "\n";
        cout << "Enter Your Choice:- ";
        cin >> a;
        switch (a)
        {
        case 1:
        {
            cout << "_____________________________"
                 << "\n"
                 << "\n";
            cout << "|---------Register----------|"
                 << "\n";
            cout << "|___________________________|"
                 << "\n"
                 << "\n";
            cout << "Please enter username:- ";
            cin >> name;
            cout << "Please enter the Password:- ";
            cin >> password0;
            cout << "Please enter your age:- ";
            cin >> age;

            ofstream of1;
            of1.open("file.text");
            if (of1.is_open())
            {
                of1 << name << "\n";
                of1 << password0;
                cout << "Registration Successfull\n";
            }
            break;
        }
        case 2:
        {
            i = 0;
            cout << "_____________________________"
                 << "\n"
                 << "\n";
            cout << "|-----------Login------------|"
                 << "\n";
            cout << "|____________________________|"
                 << "\n"
                 << "\n";
            ifstream of2;
            of2.open("file.txt");
            cout << "Please enter the username:- ";
            cin >> user;
            cout << "Please enter the Password:- ";
            cin >> pass;
            if (of2.is_open())
            {
                while (!of2.eof())
                {
                    while (getline(of2, text))
                    {
                        istringstream iss(text);
                        iss >> word;
                        creds[i] = word;
                        i++;
                    }
                    if (user == creds[0] and pass == creds[1])
                    {
                        cout << "----Login successful----"
                             << "\n"
                             << "\n";
                        cout << "Details: "
                             << "\n";
                        cout << "Username: " + name << "\n";
                        cout << "Password: " + pass << "\n";
                        cout << "Age: " + age << "\n";
                    }
                    else
                    {
                        cout << "\n"
                             << "\n";
                        cout << "Incorrect Credential\n";
                        cout << "|       1.press 2 to login       |\n";
                        cout << "|  2.Press 3 to change password  |\n";
                        break;
                    }
                }
            }
            break;
        }

        case 3:
        {
            i = 0;
            cout << "------Change Password------\n";
            ifstream of0;
            of0.open("file.txt");
            cout << "Enter the old password:- ";
            cin >> old;
            if (of0.is_open())
            {
                while (getline(of0, text))
                {
                    istringstream iss(text);
                    iss >> word1;
                    cp[i] = word1;
                    i++;
                }
                if (old == cp[1])
                {
                    of0.close();
                    ofstream of1;
                    if (of1.is_open())
                    {
                        cout << "Enter your new password:- ";
                        cin >> password1;
                        cout << "Enter your password again:- ";
                        cin >> password2;
                        if (password1 == password2)
                        {
                            of1 << cp[0] << "\n";
                            of1 << password1;
                            cout << "Password changed successfully\n";
                        }
                        else
                        {
                            of1 << cp[0] << "\n";
                            of1 << old;
                            cout << "Password do not match\n";
                        }
                    }
                }
                else
                {
                    cout << "Please enter a valid password\n";
                    break;
                }
            }
            break;
        }
        case 4:
        {
            cout << "________THank You!________";
            break;
        }
        default:
            cout << "Enter a valid choice";
        }
    } while (a != 4);
    {
        return 0;
    }
}
