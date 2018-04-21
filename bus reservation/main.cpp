#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

#define PASS "198499"
#define altPASS "AlTpAsS198499"

static int COUNT = 0;

void reservation();
void payment(int, int, int);
void ending();
void checkseat(int, int, int);
void checking();
void cancel();
void busstaff();
void altpasser();
int price(int, int);
void passcor();
void ticketlist();
int main()
{
    cout<<"-------------------------------B U S  R E S E R V A T I O N  S Y S T E M-------------------------------";

    getch();
    cout<<endl<<endl<<"Choose your objective:"<<endl;
    cout<<"1. Bus Reservation"<<endl;
    cout<<"2. Reservation Checking"<<endl;
    cout<<"3. Reservation Cancellation"<<endl;
    cout<<"4. Bus Service Processes (RESTRICTED ACCESS)"<<endl;

    cout<<endl<<"Input choice:\n";
    int choice;
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            reservation();
            break;
        }
        case 2:
        {
            checking();
            break;
        }
        case 3:
        {
            cancel();
            break;
        }
        case 4:
        {
            busstaff();
            break;
        }
    }

    ending();

    return 0;
}

void ending()
{
    cout<<endl<<"--------------------------P R O C E S S  E N D E D--------------------------";
    cout<<endl<<endl<<"Choose your option:";
    cout<<endl<<"1. Go to main menu";
    cout<<endl<<"2. Exit"<<endl;

    int finalchoice;
    cin>>finalchoice;

    if(finalchoice==1)
    {
        cout<<"-------------------------------------------M A I N  M E N U-------------------------------------------"<<endl<<endl<<endl;
        main();
    }

    cout<<endl<<"-----------------------E N D  O F  P R O G R A M-----------------------"<<endl<<endl;
}

void reservation()
{
    cout<<"_________________________________________________________\n\n";
    cout<<"City codes:"<<endl<<endl;
    cout<<setw(4)<<"CODE"<<setw(15)<<"CITY"<<endl<<endl;
    cout<<setw(4)<<"01"<<setw(15)<<"Amritsar"<<endl;
    cout<<setw(4)<<"02"<<setw(15)<<"Chandigarh"<<endl;
    cout<<setw(4)<<"03"<<setw(15)<<"Dehradun"<<endl;
    cout<<setw(4)<<"04"<<setw(15)<<"Delhi"<<endl;
    cout<<setw(4)<<"05"<<setw(15)<<"Hoshiarpur"<<endl;
    cout<<setw(4)<<"06"<<setw(15)<<"Kurukshetra"<<endl;
    cout<<setw(4)<<"07"<<setw(15)<<"Ludhiana"<<endl;
    cout<<setw(4)<<"08"<<setw(15)<<"Patiala"<<endl;
    cout<<setw(4)<<"09"<<setw(15)<<"Ropar"<<endl;
    cout<<setw(4)<<"10"<<setw(15)<<"Shimla"<<endl<<endl;

    getch();
    cout<<"CITY SELECTION:"<<endl<<endl;
    getch();
    int citcod, destcod;
    cout<<"Input CODE for city of departure:"<<endl;
    cin>>citcod;
    cout<<endl<<"Input CODE for destination:"<<endl;
    cin>>destcod;

    int prc;
    prc = price(citcod, destcod);

    getch();

    cout<<endl<<endl<<"Price for ticket:\n";
    cout<<prc;

    getch();
    cout<<endl<<endl<<"Proceed to payment? (Y/N)"<<endl;

    char yesno;
    cin>>yesno;

    if(yesno == 'Y' || yesno == 'y')
        payment(citcod, destcod, prc);

}


int price(int a, int b)
{
    int price = sqrt(a)*sqrt(b)*80;

    if(price<90)
        return 2*price;

    if(250<price && price<500)
        return price*3/4;

    if(price>500)
        return price/3.5;

    return price;
}


void payment(int citcode, int destcode, int price)
{
    cout<<endl<<"--------------------------P A Y M E N T  P R O C E S S--------------------------"<<endl;

    getch();
    cout<<endl<<"Input name of passenger:"<<endl;

    char fname[15], lname[15];
    cin>>fname>>lname;

    cout<<endl<<endl<<"Input 12-number AADHAAR UID number"<<endl;
    char uidno[13];
    cin>>uidno;
    while(strlen(uidno)!=12)
    {
        cout<<endl<<endl<<"ERROR: Invalid UID number.";

        getch();
        cout<<endl<<"Re-input 12-number AADHAAR UID number"<<endl;
        cin>>uidno;
    }

    cout<<endl<<endl<<"Enter phone number (+91)"<<endl;
    char mobno[11];
    cin>>mobno;

    cout<<endl<<endl<<"Enter date (DD/MM/YYYY):"<<endl;
    char date[11];
    cin>>date;

    cout<<endl<<endl<<"Choose time slot (24 hour format):"<<endl;
    cout<<"(Bus leaves every two hours after 0415hours, last bus leaves 2015hours)"<<endl;
    char time[5];
    cin>>time;

    cout<<endl<<endl<<"Enter number of tickets needed:"<<endl;
    int tixno;
    cin>>tixno;

    cout<<endl<<endl<<"Check Details:"<<endl;
    getch();
    cout<<"Name - "<<fname<<" "<<lname<<endl;
    getch();
    cout<<"UID number - "<<uidno<<endl;
    getch();
    cout<<"Input mobile number - (+91)"<<mobno<<endl;
    getch();
    cout<<"Date - "<<date<<endl;
    getch();
    cout<<"Time of departure- "<<time<<endl;
    getch();
    cout<<"Number of tickets needed - "<<tixno<<endl;

    getch();
    cout<<endl<<"Are details correct? (Y/N)"<<endl;
    char choice;
    cin>>choice;

    if(choice=='N' || choice=='n')
    {

        reenter:
        cout<<"\n\nSelect choice:\n";
        cout<<"1. Reenter details"<<endl;
        cout<<"2. Exit to main menu"<<endl;
        int choose;
        cin>>choose;

        if (choose==1)
            payment(citcode, destcode, price);
        if (choose==2)
            main();
        if (choose!=1 && choose!=2)
        {
            cout<<endl<<endl<<"ERROR: Invalid choice. Choose again."<<endl;
            goto reenter;
        }
    }

    checkseat(citcode, destcode, tixno);

    cout<<endl<<endl<<"Total cost of tickets:\t"<<tixno*price<<"inr";
    getch();
    cout<<endl<<endl<<"Make payment? (Y/N)"<<endl;
    cin>>choice;

    if(choice=='N' || choice=='n')
        ending();

    ofstream nameout, UIDout, phoneout, dateout, timeout, numberout, priceout, citcodeout, destcodeout, confirmout;

    char confirmation = 'N';

    nameout.open("Namelist", ios::app);
    nameout<<fname<<" "<<lname<<"\n";
    nameout.close();

    UIDout.open("UIDlist", ios::app);
    UIDout<<uidno<<"\n";
    UIDout.close();

    phoneout.open("Phonelist", ios::app);
    phoneout<<mobno<<"\n";
    phoneout.close();

    citcodeout.open("Citcodelist", ios::app);
    citcodeout<<citcode<<"\n";
    citcodeout.close();

    destcodeout.open("Destcodelist", ios::app);
    destcodeout<<destcode<<"\n";
    destcodeout.close();

    dateout.open("Datelist", ios::app);
    dateout<<date<<"\n";
    dateout.close();

    timeout.open("Timelist", ios::app);
    timeout<<time<<"\n";
    timeout.close();

    numberout.open("Numberlist", ios::app);
    numberout<<tixno<<"\n";
    numberout.close();

    priceout.open("Pricelist", ios::app);
    priceout<<tixno*price<<"\n";
    priceout.close();

    confirmout.open("Confirmlist", ios::app);
    confirmout<<confirmation<<"\n";
    confirmout.close();
    cout<<endl<<endl<<"Your data has been stored";
    cout<<endl<<endl<<"Link to online payment portal:\t http://www.indiabusservices.payment.co.in//";
    getch();
    cout<<endl<<"After payment, you may check if your payment has been made from the checking option in the MAIN MENU\n";
    getch();
}


void checkseat(int citcode, int destcode, int tixno)
{

}


void cancel()
{
    cout<<"--------------------------C A N C E L L A T I O N  P R O C E S S--------------------------"<<endl<<endl;

    cout<<endl<<"Input name of passenger:"<<endl;
    char fnamec[20],lnamec[20];
    cin>>fnamec>>lnamec;

    cout<<endl<<"Input AADHAAR UID number:"<<endl;
    char uidnoc[13];
    cin>>uidnoc;

}


void checking()
{
    cout<<"------------------------------------C H E C K I N G  P R O C E S S------------------------------------"<<endl<<endl;

}


void busstaff()
{
    cout<<endl<<endl<<"Enter password to continue:"<<endl;
    char passcheck[7];
    cin>>passcheck;

    if(COUNT==3)
    {
        cout<<endl<<endl<<"TOO MANY WRONG ATTEMPTS!!!!"<<endl;
        getch();
        cout<<"Input alternate corrective password to continue:"<<endl;

        altpasser();
    }

    if(strcmp(passcheck,PASS)!=0)
    {
        COUNT++;
        cout<<endl<<"INCORRECT PASSWORD"<<endl;
        getch();
        cout<<endl<<"Select choice:";
        cout<<endl<<"1. Try again";
        cout<<endl<<"2. Go to main menu"<<endl;

        int choice;
        cin>>choice;

        while(choice<1 || choice>2)
        {
            cout<<endl<<"Input a valid response"<<endl;
            cin>>choice;
        }

        if(choice==2)
            main();

        if(choice==1)
            busstaff();

    }

    passcor();
}

void altpasser()
{
        char altin[14];
        cin>>altin;

        if(strcmp(altin,altPASS)!=0)
        {
            cout<<"INCORRECT ALTERNATE PASSWORD"<<endl;
            getch();
            cout<<endl<<endl<<"Select choice:";
            cout<<endl<<"1. Try again";
            cout<<endl<<"2. Go to main menu"<<endl;

            int choice;
            cin>>choice;

            while(choice>2 && choice<1)
            {
                cout<<endl<<"Input a valid response"<<endl;
                cin>>choice;
            }

            if(choice==2)
            main();
            if(choice==1)
            altpasser();

        }

        COUNT=0;
        passcor();

}

void passcor()
{
    cout<<endl<<"---------------------------------PASSWORRD CORRECT---------------------------------"<<endl;
    cout<<endl<<endl<<"Administrator processes:"<<endl;
    cout<<"1. Confirm ticket(s)"<<endl;
    //cout<<"2. ";
    int choice;
    cin>>choice;

    switch(choice)
    {
        case(1):
        {
            cout<<"--------------------------------D I S P L A Y I N G  T I C K E T  L I S T--------------------------------";
            getch();
            cout<<endl<<".";
            getch();
            ticketlist();
            break;
        }
        //case(2)
        {

        }
    }

}

const int N = 30;

void ticketlist()
{
    ifstream namein("Namelist", ios::in), UIDin("UIDlist", ios::in), phonein("Phonelist", ios::in), timein("Timelist", ios::in),
             citcodein("Citcodelist", ios::in), destcodein("Destcodelist", ios::in), datein("Datelist", ios::in),
             numberin("Numberlist", ios::in), pricein("Pricelist", ios::in), confirmin("Confirmationlist", ios::in);

    char name[30], uidno[13], phone[11], date[17], confirmation = 'N';
    int tixno, price, city, destination, time;

    cout<<"______________________________________________________________________________________";

    cout<<endl<<endl<<setw(10)<<"SERIAL"<<setw(20)<<"NAME"<<setw(15)<<"UID NUMBER"<<setw(15)<<"MOBILE"<<setw(10)<<"CITY"
        <<setw(15)<<"DESTINATION"<<setw(15)<<"DATE"<<setw(10)<<"TIME"<<setw(25)<<"NUMBER OF TICKETS"<<setw(10)<<"PRICE"
        <<setw(20)<<"CONFIRMATION"<<endl;

    int count=1;

    while(namein && UIDin && phonein && citcodein && destcodein && datein && timein)
    {
        cout<<endl;

        cout<<setw(10)<<count;
        count++;

        namein.getline(name, N);
        cout<<setw(20)<<name;

        UIDin.getline(uidno, N);
        cout<<setw(15)<<uidno;

        phonein.getline(phone, N);
        cout<<setw(15)<<phone;

        citcodein>>city;
        cout<<setw(10)<<city;

        destcodein>>destination;
        cout<<setw(15)<<destination;

        datein.getline(date, N);
        cout<<setw(15)<<date;

        timein>>time;
        cout<<setw(10)<<time;

        numberin>>tixno;
        cout<<setw(25)<<tixno;

        pricein>>price;
        cout<<setw(10)<<price;

        confirmin>>confirmation;
        cout<<setw(20)<<confirmation;

    }

    cout<<endl<<"____________________________________________________________________________";
    cout<<endl<<endl<<"Choose Option:"<<endl;
    cout<<"1. Confirm ticket(s)"<<endl;
    cout<<"2. Main Menu"<<endl;
    cout<<"3. Authorised Menu"<<endl;
    int choose;
    cin>>choose;

    switch(choose)
    {
        case(1):
        {
            break;
        }
        case(2):
        {
            main();
            break;
        }
        case(3):
        {
            passcor();
            break;
        }
    }
    namein.close();
    UIDin.close();
    phonein.close();
    datein.close();
    timein.close();
    numberin.close();
    pricein.close();
    citcodein.close();
    destcodein.close();

    cout<<"List process ends";
    main();
}
