#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

void load();
void gotoxy();
static int count1;
static int counter;

class Home
{
private:
    string uName, pass, logname, logpass;
    int option;
    string name, car;

    int cost, dob, yrs, premium, acc, choice, choice2, month1, damount, choice3;
    string coverage, paytype;
    long int acc1;
    int damage;
    int fault;

public:
    void signup();//Kushagra
    void home();//Kushagra
    void login();//Kushagra
    void menu();//Siddharth
    void Register();//Siddharth
    void Payment();//Akhil & Siddharth
    void claim();//Akhil
    void display();//Akhil
};
void Home::home()
{

    cout << "1.)Sign Up (New User)\n2.)Login (Already a User)" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
        signup();
        break;

    case 2:
        login();
        break;

    default:
        cout << "Enter Valid Option";
    }
}

void Home ::signup()
{
    ofstream output;
    output.open("record.txt");
    cout << "Enter username: " << endl;
    cin >> uName;
    cout << "Enter password: " << endl;
    cin >> pass;

    output << uName << " " << pass << endl;
    output.close();

    cout << "Sign up Complete" << endl
         << endl;
    home();
}

void Home ::login()
{

    ifstream input("record.txt");

    cout << "Enter username for Login :" << endl;
    cin >> logname;
    cout << "Enter password for Login:" << endl;
    cin >> logpass;

    if (input >> uName && input >> pass && uName == logname && pass == logpass)
    {
        cout << "Login successful" << endl
             << endl;
        menu();
    }
    else
    {
        cout << "Login failed!" << endl;
    }

    input.close();
}

void Home::menu()
{
    cout << "-------------------Main Menu-------------------" << endl;

    int choice2;
    cout << "1)Register For an Insurance\n2)Pay for insurance\n3)Claim Insurance\n4)Display All User Data\n5)Exit" << endl;
    cin >> choice2;

    switch (choice2)
    {
    case 1:
        Register();
        break;

    case 2:
        Payment();
        break;
    case 3:
        claim();
        count1++;
        break;

    case 4:
        display();
        break;

    default:
        break;
    }
}

void Home::Register()
{

    cout << "Enter Your First Name- " << endl;
    cin >> name;
    cout << "What is the name of your car (Only model)- " << endl;
    cin >> car;
    cout << "How old is the car" << endl;
    cin >> yrs;
    cout << "What is the cost of your Car? " << endl;
    cin >> cost;
    cout << "How many accidents have previously had? " << endl;
    cin >> acc;

    if (acc == 0)
    {
        acc1 = 0;
    }
    else if (acc >= 1 && acc < 3)
    {
        acc1 = 10, 000;
    }
    else if (acc >= 3)
    {
        acc1 = 20, 000;
    }

    cout << "What types of Insurance do you want? -" << endl
         << endl;
    cout << "1)Liability Coverage - When you are involved in the accident and when it is concluded that, that accident took place before your fault/negligence, the liability coverage will come to your rescue.(Upto 10L insured)" << endl
         << endl;
    cout << "2)Collision Coverage- If you subscribe for collision coverage, our company will bear your car repair expenses after the accident(Upto 15L insured)" << endl
         << endl;
    cout << "3)Comprhension Coverage- Comprehension insurance coverage will include all kinds of risk factors that are associated with your vehicle, driver, passenger, third party vehicle, third party driver, third party vehicle passenger and property. No copayment clause (Upto 25L insured) " << endl
         << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        coverage = "Liabilty";
        premium = (cost / 20) + acc1 + 1000 * yrs;
        cout << "Your premium for car insurance is " << premium << endl;
        break;
    case 2:
        coverage = "Collision";
        premium = (cost / 10) + acc1 + 1000 * yrs;
        cout << "Your premium for car insurance is " << premium << endl;
        break;

    case 3:
        coverage = "Comprehensive";
        premium = (cost / 5) + acc1 + 1000 * yrs;
        cout << "Your premium for car insurance is " << premium << endl;
        break;
    default:
        break;
    }
    cout << "How would you like to pay your Premium " << endl;
    cout << "1)Lump sum\n2)Monthly Installments" << endl;
    cin >> choice3;
    if (choice3 == 1)
    {
        paytype = "LumpSum";
        cout << "Your due amount is " << premium << " Rs" << endl;
        menu();
    }
    else if (choice3 == 2)
    {
        paytype = "Installments";
        cout << "How many months would like to Pay your Premium " << endl;
        cin >> month1;

        cout << "Your premium to be paid in " << month1 << " months is " << premium / month1 << " per month" << endl;
        menu();
    }
}

void Home ::Payment()
{

    if (paytype == "LumpSum")
    {
        cout << "Pay " << premium << endl;
        cin >> damount;
        if (damount == premium)
        {
            cout << "Payment Successfull!!!" << endl;
            menu();
        }

        else
        {
            cout << "Wrong Amount" << endl;
            Payment();
        }
    }
    else if (paytype == "Installments")
    {
        cout << "Pay your Monthly installment of " << premium / month1 << endl;
        cin >> damount;

        if (damount == premium / month1)
        {
            counter++;
            cout << "Payment Successfull!!!" << endl;
            cout << "Remaining Numer of Installments - " << month1 - counter << endl;
            menu();
        }
        else
        {
            cout << "Wrong Amount" << endl;
            Payment();
        }
    }
}

void Home::claim()
{
    count1++;
    cout << "What is the total amount of damage?" << endl;
    cin >> damage;
    cout << "Were you at fault?\n1)yes\n2)no" << endl;
    cin >> fault;
    if (fault == 1)
    {
        if (choice == 1)
        {
            cout << "Since You chose Liability Coverage and you were at fault, they will be copayment of 30 perecent i.e " << 0.3 * damage << " Rs" << endl;
            menu();
        }
        else if (choice == 2)
        {
            cout << "Since You chose Collision Coverage and you were at fault, they will be copayment of 20 perecent i.e " << 0.2 * damage << " Rs" << endl;
            menu();
        }
        else if (choice == 3)
        {
            cout << "Since You choice Comprehensive Coverage, All your damages will be covered" << endl;
            menu();
        }
    }
    else if (fault == 2)
    {
        cout << "All Your damages will be covered by us";
        menu();
    }
}

void Home::display()
{
    cout << "-----------------All Details-----------------" << endl;
    cout << "Your Name - " << name << endl;
    cout << "Model of car you have insured - " << car << endl;
    cout << "Age of car - " << yrs << endl;
    cout << "Your type of coverage - " << coverage << endl;
    cout << "Your premium is " << premium << endl;
    cout << "Type of payment - " << paytype << endl;
    if (paytype == "Installments")
    {
        cout << "Number of installments remaining are " << month1 - counter << endl;
    }
    cout << "How many times Insurance has been claimed " << count1 << endl;
menu();

}

int main()
{

    int timer = 5 + rand() % 20;
    int row, col, r, q;
    COORD c;
    c.X = 35;
    c.Y = 10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    cout << "WELCOME TO CAR INSURANCE SYSTEM" << endl;
    system("color 5F");
    load();
    cout << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl;
    cout << "-----------------WELCOME TO CAR INSURANCE SYSTEM-----------------" << endl;
    cout << endl;
    Home obj;

    obj.home();

    return 0;
}

void gotoxy(int x, int y)
{
    COORD d;
    d.X = x;
    d.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
}
void load()
{
    char a = 219;
	gotoxy(36, 14);
	cout << "\t\tLoading...";
	gotoxy(60,14);
	for(int r =1; r<=20; r++)
	{
		for(int q=0; q<=100000000; q++);
		cout <<a;
	}
}