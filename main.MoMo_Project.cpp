#include <iostream>
using namespace std;

int main() {
	int numb1,numb2,reference,pin,new_pin;
    int attempts = 0;
    int defaultpin= 0000;
    int option;
    char choice;
    int balance=1000;

    // Authentication
    cout << "Enter your PIN:\n";
    cin >> pin;
    while (pin!=defaultpin && attempts < 3) {
        attempts++;
        cout << "Invalid PIN. Please try again:\n";
        cin >> defaultpin;
    }
    if (attempts == 3) {
        cout << "You have exceeded the maximum number of attempts. Exiting program." << endl;
        return 0;
    }

    // Menu
    while (true) {
        cout << "\nWelcome to MobileMoney Transfer Service" << endl;
        cout<<"Select an option\n\n";
        cout << "1. Check balance" << endl;
        cout << "2. Send money" << endl;
        cout << "3. Reset/change PIN" << endl;
        cout << "4. Exit\n" << endl;
        cin >> option;

        switch(option) {
            case 1: // Checking balance
                cout << "Your balance is Ghc: "<<balance << endl;
                break;
            case 2: // Sending money
                int numb1;
                cout<<"Enter number\n";
                cin>>numb1;
                int numb2;
                cout<<"Confirem number\n";
                cin>>numb2;
                int amount;
                
                if(numb1==numb2){
                cout << "Enter the amount to send:\n";
                // check
                cin>>amount;
                 if(amount>balance) {
                    cout << "Not enough funds to perform transaction\n." << endl;
                } 
                else{
                 cout<<"Enter reference\n";
                cin>>reference;
                cout<<"Enter your 4-digits PIN\n";
                cin>>pin;
                 if(pin==defaultpin){
						balance-=amount;
                    cout << "Payment made for GHc:"<<amount << "to"<<numb2<<" Current Balance:"<<balance-amount<<" Available Balance:"<<balance-amount<<"Reference:"<<reference;
                }
                else{
                	cout<<"Wrong PIN\n";
				}
                break;
            }
        }
               
            else{
            	cout<<"Number Mismatched!\n";
			}
                break;
            case 3: // Resetting/changing PIN
                cout << "Are You Sure You Want To Change PIN\n";
                cout<<" 1.YES \n 2.NO\n";
                char choice;
                cin >>choice;
                if(choice=='1'){
                cout << "Enter old 4-digits PIN.\n";
                cin>>pin;
            }
            else if(choice=='2'){
            	cout<<"PIN change cancelled\n";
			} 
			if(pin!=defaultpin){
				cout<<"Incorrect PIN\n";
			}
			break;
                if(pin!=defaultpin&&attempts<3){
                	cout<<"Incorrect PIN input!\n";
				} else{
					cout<<"Enter new 4-digits PIN\n";
					cin>>new_pin;
					cout<<"PIN change sucessful!\n";
					cout<<" Your new 4-digits PIN is:"<<new_pin;
				}
				break;
            case 4: // Exit
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }

    return 0;
}