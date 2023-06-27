#include<iostream>
#include<windows.h>
using namespace std;


class Cabs{
    protected:
    int cab_Choice;
    int kilometers;
    float cost;
    float last_cab_cost;

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
            //menu();
        }

        cout << "\nPress 1 to Redirect Main Menu: ";
        cin >> hire_cab;
        system("CLS");
        if(hire_cab == 1){
            //menu();
        }
        else{
            //menu();
        }
    }

};

int main()
{
    Cabs c;
    c.Cab_details();
    return 0;
}