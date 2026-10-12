#include <iostream>
#include <thread>
#include <random>
using namespace std;

int main() {

    double distance;
    double total;
    int payment;
    string number;
    int verification;
    int amount;
    string userPIN = "1500";
    string pin;
    int attempt = 4;
    string appName = "DriveIt";

    cout << "--- DriveIt ---" << endl;
    cout << "Input distance (km): ";
    cin >> distance;

    if (distance <= 2) {
        total = 50;
        cout << endl << "Total: " << total << endl;
    }
    else if (distance > 2 && distance <= 7) {
        total = (distance - 2) * 10 + 50;
        cout << "Total: "<< total << endl;
    }
    else if (distance > 7) {
        total = (distance - 7) * 15 + 100;
        cout << "Total: " << total << endl;
    }
    else {
        cout << "Please input a valid character!";
    }

    cout << "[1] Cash" << endl;
    cout << "[2] Gcash" << endl;
    cout << "[3] Credit" << endl;
    cout << "Enter Payment Method: ";
    cin >> payment;

    switch(payment) {
        case 1:

            do {
                cout << "Enter amount: ";
                cin >> amount;

                if (amount == total) {
                    cout << "Payment successful!" << endl;
                    cout << "Thank you for using " << appName << "!";
                    total = 0;
                }
                else if (amount >= total) {
                    cout << "Here is your change: " << amount - total << endl;
                    cout << "Thank you for using " << appName << "!";
                    total = 0;
                }
                else if (amount < total) {
                    cout << "You gave " << amount << ". You still need " << (total -= amount) << endl; 
                }
                else {
                    cout << "Please input a valid character!" << endl;
                }
            } while (total > 0);
            break;


        case 2:

            do {

                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> dist(1000, 9999);

                int random = dist(gen);
                cout << "Enter this Gcash Number. (09123456789)" << endl;
                cout << "Enter Number: ";
                cin >> number;

                if (number == "09123456789") {
                    cout << "Wait for the verification code!" << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                    cout << ".";
                    this_thread::sleep_for(chrono::seconds(1));
                    cout << ".";
                    this_thread::sleep_for(chrono::seconds(1));
                    cout << ".";
                    this_thread::sleep_for(chrono::seconds(1));
                    cout << endl << random;
                    cout << endl <<"Enter Verification Code: ";
                    cin >> verification;
                    if (verification == random) {
                        cout << "Enter Amount: ";
                        cin >> amount;

                        if (amount == total) {
                            cout << "Payment successful!" << endl;
                            cout << "Thank you for using " << appName << "!";
                            total = 0;
                        }
                        else if (amount > total) {
                            cout << "You've enter too much, here is your change: " << (amount -= total) << endl;
                            cout << "Thank you for using " << appName << "!";
                            total = 0;
                        }
                        else if (amount < total) {
                            cout << "You gave " << amount << ". You still need " << (total -= amount) << endl;
                        }
                        else {
                            cout << "Please input a valid character!" << endl;
                        }
                    }
                }

            } while (total > 0);
            break;

            case 3:
                do {
                    for (int i = 0; i <= attempt; i++) {
                        attempt --;
                        cout << "Attempt left: " << attempt << endl;
                        cout << "Enter PIN: ";
                        cin >> pin;
                        
                        if (pin == userPIN) {
                            break;
                        }
                        else if (i == attempt) {
                            cout << "To many wrong PINs." << endl;
                            cout << "Please contact your bank." << endl;
                            return 0;
                        }
                    }

                    cout << "Enter amount: ";
                    cin >> amount;

                    if (amount == total) {
                        cout << "Payment successful!" << endl;
                        cout << "Thank you for using " << appName << "!";
                        total = 0;
                    }
                    else if (amount >= total) {
                        cout << "You've enter too much, here is your change: " << (amount -= total) << endl;
                        cout << "Thank you for using " << appName << "!";
                        total = 0;
                    }
                    else if (amount < total) {
                        cout << "You gave " << amount << ". You still need " << (total -= amount) << endl;
                    }
                    else {
                        cout << "Please input a valid character!" << endl;
                    }
                } while (total > 0);
    }


}
