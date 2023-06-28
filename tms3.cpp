#include<iostream>
#include<fstream>
#include<string>
/*This header file is used for handling files in C++. 
It provides classes for working with files, including reading from and writing to files. 
*/
#include<iomanip>
/* This header file is used for input/output manipulations in C++.
It provides functions that allow you to format the output of your program,
*/
#include<windows.h>
/*This header file is specific to the Windows operating system and provides access to the Windows API (Application Programming Interface).
It is used for creating graphical user interfaces (GUIs), working with system resources, and accessing low-level system functions in Windows.
It is not portable across different operating systems.*/
using namespace std;


void menu();//main menu function prototype
//main menu
class ManageMenu
{
	protected:
    	string userName; //hide admin name
        int password; // hide password

	public:

    ManageMenu()
    {
        system("color 0B"); //change terminal color
        cout << "\n\n\n\n\n\n  Enter Your Name to Continue as an Admin: ";
        cin >> userName;
        cin>>password;
        if((userName=="Hassam" || userName=="Bilal" || userName == "Anas" || userName=="CR" || userName=="Abdulahad") && to_string(password) == "1234")
            system("CLS");
        menu(); //call to main function to load after executing the constructr
    }

    ~ManageMenu(){} 
};

class Customer{
    protected:
    string f_name,l_name,gender,address;
    int mobile_no,age;
	static int cusID;
    char all[999];
    public:
    void getDetails(){
        ofstream out("old-customer.txt",ios::app);
        /*The line ofstream out("old-customer.txt",ios::app); 
        creates an object out of the ofstream class and opens the file "old-customer.txt" in append mode. 
        ios is a base class in C++ that provides the basic functionality for input/output operations */
        {
        cout<<"Enter customer ID :"<<endl;
        cin>>cusID;
        cout<<"Enter First name :"<<endl;
        cin>>f_name;
        cout<<"Enter Last name :"<<endl;
        cin>>l_name;
        cout<<"Enter Gender :"<<endl;
        cin>>gender;
        cout<<"Enter Age :"<<endl;
        cin>>age;
        cout<<"Enter Mobile Number :"<<endl;
        cin>>mobile_no;
        cout<<"Enter Address :"<<endl;
        cin>>address;
        }

        out<<"\nCustomer ID: "<<cusID<<"\nFirst Name: "<<f_name<<"\nLast Name: "<<"\nAge :"<<age<<"\nMobile No: "<<mobile_no<<"\nGender: "<<gender<<"\nAddress: "<<address<<"\n";
        out.close();
        cout<<"\nsaved\n Note we save your details record for future purposes\n "<<endl;
    }

    void show_Details(){
        ifstream in("old-customers.txt");
        {
            if(!in){
                cout << "File not found" << endl;
            }

            while(!(in.eof())){
                in.getline(all,999);
                cout<<all<<endl;
            }
            in.close();
        }
    }
};

int Customer::cusID;

class Cabs{
    protected:
    int cab_Choice;
    int kilometers;
    float cost;
    static float last_cab_cost;

    public:
    void Cab_details(){
        cout<<"We colaborated with fastest, safest, and smaetest cab services around the country"<<endl;
        cout<<"1.  Rent a Standard Cab - Rs. 15 for 1KM"<<endl;
        cout<<"2.  Rent a Luxury Cab - Rs. 25 for 1KM"<<endl;

        cout<<"\n To calculate the cost for your new journey"<<endl;
        cout<<"Enter which kind of cab you want for your journey"<<endl;
        cin>>cab_Choice;

        cout<<"Enter the distance that you want to cover"<<endl;
        cin>>kilometers;
        int hire_cab;

        if(cab_Choice==1){
            cost=kilometers*15;
            cout<<"\nYour tour cost "<<cost<<" rupees for a standard Cab"<<endl;
            cout<<"Press 1 to hire this cab or \n Press 2 to hire the Luxury Cab"<<endl;
            cin>>hire_cab;
            
            system("CLS");
               //  This will clear the console
            if(hire_cab==1){
                last_cab_cost=cost;
                cout<<"\nYou have successfully booked a standard cab"<<endl;
                cout<<"take the receipt";
            }

            else if(hire_cab=2){
                Cab_details();
            }

            else{
                cout<<"INVALID INPUT! REDIRECTING THE PREVIOUS MENU \nPlease wait";
                Sleep(990);
                system("CLS");
                Cab_details();
            }
        }
            
        else if(cab_Choice == 2){
            cost = kilometers * 25;
            cout << "\nYour tour will cost " << cost << " rupees for a luxury cab" << endl;
            cout << "Press 1 to hire this cab: or ";
            cout << "Press 2 to select another cab: ";
            cin >> hire_cab;
            system("CLS");
            if (hire_cab == 1){
                last_cab_cost = cost;
                cout << "\nYou have successfully hired luxury cab" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if(hire_cab == 2){
                Cab_details();
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                Cab_details();
            }
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }

        cout << "\nPress 1 to Redirect Main Menu: ";
        cin >> hire_cab;
        system("CLS");
        if(hire_cab == 1){
            menu();
        }
        else{
            menu();
        }
    }

};

float Cabs::last_cab_cost;

class Booking{
public:
    int choiceHotel;
    int packChoice1;
    int gotoMenu;
    static float hotelCost;

    void hotels()
    {
        string hotelNo[] = {"Avendra", "ChoiceYou", "ElephantBay"};
        for(int a = 0; a < 3; a++)
        {
            cout << (a+1) <<". Hotel " << hotelNo[a] << endl;
        }

        cout << "\nCurrently we collaborated with above hotels!" << endl;

        cout << "Press any key to back or\nEnter Number of the hotel you want to book or see details: ";
        cin >> choiceHotel;

        system("CLS");

        if(choiceHotel == 1){
            cout << "-------WELCOME TO HOTEL AVENDRA-------\n" << endl;

            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;

            cout << "Packages offered by Avendra:\n" << endl;

            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.10000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tLive a Luxury at Avendra: Rs.15000.00" << endl;


            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1){
                hotelCost = 5000.00;
                cout << "\nYou have successfully booked Standard Pack at Avendra" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 10000.00;
                cout << "\nYou have successfully booked Premium Pack at Avendra" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 15000.00;
                cout << "\nYou have successfully booked Luxury Pack at Avendra" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();

            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 2){
            cout << "-------WELCOME TO HOTEL CHOICEYOU-------\n" << endl;

            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;

            cout << "Packages Offered by ChoiceYou:\n" << endl;

            cout << "1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "3. Single Pack" << endl;
            cout << "\t 5000.00 for a day" << endl;

            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1){
                hotelCost = 15000.00;
                cout << "You have successfully booked Family Pack at ChoiceYou" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 10000.00;
                cout << "You have successfully booked Couple Pack at ChoiceYou" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 5000.00;
                cout << "You have successfully booked Single Pack at ChoiceYou" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                //menu();
            }
            else{
                //menu();
            }
        }
        else if(choiceHotel == 3){
            cout << "-------WELCOME TO HOTEL ELEPHANTBAY-------\n" << endl;
            cout << "Set in tropical gardens on the banks of the Maha Oya river While Seeing Elephants" << endl;
            cout << "Amazing offer in this summer: Rs.5000.00 for a one day!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;

            if (packChoice1 == 1){
                hotelCost = 5000.00;
                cout << "You have successfully booked ElephantBay Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                //menu();
            }
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            //menu();
        }
    }
};





float Booking::hotelCost;

class Chargers : public Booking, public Cabs, public Customer //Multiple Inheritance of some other classes to Chargers
{

public:

    void printBill()
    {
        ofstream outf("receipt.txt"); //receipt for bought items
        {
            outf << "--------ABC Travel Agency--------" << endl;
            outf << "-------------Receipt-------------" << endl;
            outf << "_________________________________" << endl;

            outf << "Customer ID: " << Customer::cusID << endl << endl;
            outf << "Description\t\t Total" << endl;
            outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::last_cab_cost << endl;

            outf << "_________________________________" << endl;
            outf << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost+Cabs::last_cab_cost << endl;
            outf << "_________________________________" << endl;
            outf << "------------THANK YOU------------" << endl;
        }
        outf.close();
        //cout << "Your receipt printed, please get it from the file saved path:D" << endl;
    }

    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if(!inf)
            {
                cout << "File Error!" << endl;
            }
            while(!(inf.eof()))
            {
                inf.getline(all, 999);
                cout << all << endl;
            }
        }
        inf.close();
    }
};

void menu() //menu function contain main menu
{

    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout << "\t\t      * ABC Travels *\n" << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tBookings Management -> 3\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 4\t|" << endl;
    cout << "\t|\tExit                -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Choice: ";
    cin >> mainChoice;

    system("CLS");

    Customer a2; //creating objects
    Cabs a3;
    Booking a4;
    Chargers a5;

    /*if(mainChoice == 0){

    }*/
    if(mainChoice == 1){
        cout << "------Customers------\n" << endl;
        cout << "1. Enter New Customer"<< endl;
        cout << "2. See Old Customers"<< endl;

        cout << "\nEnter choice: ";
        cin >> inChoice;

        system("CLS");
        if(inChoice == 1){
            a2.getDetails();
        }
        else if(inChoice == 2){
            a2.show_Details();
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if(gotoMenu == 1){
            menu();
        }
        else{
            menu();
        }
    }
    else if(mainChoice == 2){
        a3.Cab_details();
    }
    else if(mainChoice == 3){
        cout << "--> Book a Luxury Hotel using the System <--\n" << endl;
        a4.hotels();
    }
    else if(mainChoice == 4){
        cout << "-->Get your receipt<--\n" << endl;
        a5.printBill();
        cout << "Your receipt is already printed you can get it from file path\n" << endl;
        cout << "to display the your receipt in the screen, Enter 1: or Enter another key to back main menu: ";
        cin >> gotoMenu;
        if(gotoMenu == 1){
            system("CLS");
            a5.showBill();
            cout << "Press 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            system("CLS");
            menu();
        }
    }
    else if(mainChoice == 5){
        cout << "\n\n\t--GOOD-BYE!--" << endl;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
    else{
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}


int main()
{
    ManageMenu startObj; 
    return 0;
}

