#include<iostream>
#include<iomanip>
using namespace std;
// STRUCTS
// struct 1
struct Transaction{
    string withdrawal;
    string deposit;
    double transactionAmount;
};
// struct 2
struct Account{
    int accountNumber;
    int pin;
    double accountBalance;
    Transaction transactions[20];
};
// MAIN APPLICATION
int main(){

// PREMADE ACCOUNTS
    Account account1, account2, account3, account4, account5;
    // accounts array
    Account accountsArray[5];
    // account 1
    account1.accountNumber = 111000;
    account1.accountBalance = 65938.91;
    account1.pin = 12345;
    accountsArray[0] = account1;
    // account 2
    account2.accountNumber = 111001;
    account2.accountBalance = 100.53;
    account2.pin = 12345;
    accountsArray[1] = account2;
    // account 3
    account3.accountNumber = 111002;
    account3.accountBalance = 25.13;
    account3.pin = 12345;
    accountsArray[2] = account3;
    // account 4
    account4.accountNumber = 111003;
    account4.accountBalance = 100983.11;
    account4.pin = 12345;
    accountsArray[3] = account4;
    // account 5
    account5.accountNumber = 111004;
    account5.accountBalance = 83764.17;
    account5.pin = 12345;
    accountsArray[4] = account5;
// START OF APPLICATION
    cout << "\n-------- Welcome to the Banking Application --------\n";
    cout << endl;
    // variables
    int userAccount= 0;
    bool errorCheck = false;
// -------------------------------------------------
    char transactionChoice = ' ';
    do{
// USER ACCOUNT INPUT
    do{
    cout << "Enter account number or -1 to exit:\n";
    cin >> userAccount;
    // account is valid
if(userAccount == 111000 || userAccount == 111001 || userAccount==111002
|| userAccount == 111003 || userAccount == 111004 || userAccount == -1){
        errorCheck = true;
        continue;
    }
    // input failure / length check
    if(to_string(userAccount).length() != 6 || cin.fail()){
            errorCheck = false;
            cout << "Account number must consist of 6 digits\n";
            cout << "Enter account number:\n";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> userAccount;
    } 
    // invalid account number
    else if(userAccount != 111000 || userAccount != 1110001 
|| userAccount!=111002 || userAccount != 111003 || userAccount!=111004){
            errorCheck = false;
            cout << "Incorrect account number!\n";
            cout << "Try again or enter -1 to exit\n";
            cin.clear();
            cin.ignore(256,'\n');
    } 
    // terminate program 
    if(userAccount == -1){
        cout << "Thank you!\n";
        return 0;
    }
    }while(errorCheck == false);
    // user exits program
    if(userAccount == -1){
        cout << "Thank you!\n";
        return 0;
    }
// -------------------------------------------
// USER PIN INPUT
// variables
    int attempts = 3;
    int userPin = 0;
    bool pinError = false;
    // PIN APPLICATION
    do{
        cout << "Enter pin:\n";
        cin >> userPin;
        // valid pin
        if(userPin == 12345){
            pinError = true;
            continue;
        }
        // input failure
        if(cin.fail()){
            pinError = false;
            cout << "Pin should contain numbers only\n";
            cin.clear();
            cin.ignore(256,'\n');
        }
        // invalid pin
        else if(userPin != 12345) {
            pinError = false;
            cout << "Incorrect pin\n";
            attempts--;
            cin.clear();
            cin.ignore(256,'\n');
        }
        // ran out of attempts
        if(attempts == 0){
    cout << "You have exceeded the number of allowed pin attempts\n";
    cout << "See a banker to complete your transaction\nThank you!\n";
            return 0;
        }
    } while (pinError == false);
    // overused allowed attempts 
    if(attempts == 0){
        cout << "You have exceeded the number of allowed attempts\n";
    cout << "See a banker to complete your transaction\nThank you!\n";
        return 0;
    }
// -------------------------------------------
// PRINT MENU
    cout << "Select from menu:\n";
    cout << "1. Withdraw.\n2. Deposit.\n3. Show balance.\n" 
    << "4. Show transactions.\n5. Cancel." << endl;
    char menuSelect = ' ';
    cin >> menuSelect;
    // variables
    double withdraw = 0;
    double deposit = 0;
// ----------------------------------------------
// SELECTION FROM MENU 
    switch (menuSelect){
    // WITHDRAW
    case '1':
        cout << "Enter amount to withdraw:\n";
        cout << "$ ";
        cin >> withdraw;
        do{
        // ACCOUNT 1
        if(userAccount == 111000){
            if(withdraw > account1.accountBalance){
            cout << "Insufficient Balance!\nTransaction Cancelled.\n";
            } else {
            account1.accountBalance = account1.accountBalance - withdraw;
            cout << "New Balance: $" << fixed << setprecision(2) 
            << account1.accountBalance << endl;
            }
            // post transaction question
            cout << "Would you like another transaction? (y/n)\n";
            cin >> transactionChoice;
            if(transactionChoice == 'n'){
                cout << "Thank you!\n";
                return 0;
            }
        } else if(userAccount == 111001){ 
        // ACCOUNT 2
            if(withdraw > account2.accountBalance){
            cout << "Insufficient Balance!\nTransaction Cancelled.\n";
            } else {
            account2.accountBalance = account2.accountBalance - withdraw;
                cout << "New Balance: $" << fixed << setprecision(2) 
                << account2.accountBalance << endl;
            }
            // post transaction question
            cout << "Would you like another transaction? (y/n)\n";
            cin >> transactionChoice;
            if(transactionChoice == 'n'){
                cout << "Thank you!\n";
                return 0;
            }
        } else if(userAccount == 111002){
        // ACCOUNT 3
            if(withdraw > account3.accountBalance){
            cout << "Insufficient Balance!\nTransaction Cancelled.\n";
            } else {
            account3.accountBalance = account3.accountBalance - withdraw;
                cout << "New Balance: $" << fixed << setprecision(2) 
                << account3.accountBalance << endl;
            }
            // post transaction question
            cout << "Would you like another transaction? (y/n)\n";
            cin >> transactionChoice;
            if(transactionChoice == 'n'){
                cout << "Thank you!\n";
                return 0;
            }
        } else if(userAccount == 111003){
        // ACCOUNT 4
            if(withdraw > account4.accountBalance){
            cout << "Insufficient Balance!\nTransaction Cancelled.\n";
            } else {
            account4.accountBalance = account4.accountBalance - withdraw;
                cout << "New Balance: $" << fixed << setprecision(2) 
                << account4.accountBalance << endl;
            }
            // post transaction question
            cout << "Would you like another transaction? (y/n)\n";
            cin >> transactionChoice;
            if(transactionChoice == 'n'){
                cout << "Thank you!\n";
                return 0;
            }
        } else if(userAccount == 111004){
        // ACCOUNT 5
            if(withdraw > account5.accountBalance){
            cout << "Insufficient Balance!\nTransaction Cancelled.\n";
            } else {
            account5.accountBalance = account5.accountBalance - withdraw;
                cout << "New Balance: $" << fixed << setprecision(2) 
                << account5.accountBalance << endl;
            }
            // post transaction question
            cout << "Would you like another transaction? (y/n)\n";
            cin >> transactionChoice;
            if(transactionChoice == 'n'){
                cout << "Thank you!\n";
                return 0;
            }
        }
        }while(transactionChoice != 'y');
        // ---------------------
        break;
    // DEPOSIT --------------------------------
    case '2':
        cout << "Enter amount to deposit:\n$ ";
        cin >> deposit;
        if(userAccount == 111000){
        // ACCOUNT 1
            account1.accountBalance = account1.accountBalance + deposit;
            cout << "New Balance: $" << account1.accountBalance << endl;
            // post transaction question
            cout << "Would you like another transaction? (y/n)\n";
            cin >> transactionChoice;
            if(transactionChoice == 'n'){
                cout << "Thank you!\n";
                return 0;
            }
        } else if(userAccount == 111001){
        // ACCOUNT 2
            account2.accountBalance = account2.accountBalance + deposit;
            cout << "New Balance: $" << account2.accountBalance << endl;
            // post transaction question
            cout << "Would you like another transaction? (y/n)\n";
            cin >> transactionChoice;
            if(transactionChoice == 'n'){
                cout << "Thank you!\n";
                return 0;
            }
        } else if(userAccount == 111002){
        // ACCOUNT 3
            account3.accountBalance = account3.accountBalance + deposit;
            cout << "New Balance: $" << account3.accountBalance << endl;
            // post transaction question
            cout << "Would you like another transaction? (y/n)\n";
            cin >> transactionChoice;
            if(transactionChoice == 'n'){
                cout << "Thank you!\n";
                return 0;
            }
        } else if(userAccount == 111003){
        // ACCOUNT 4
            account4.accountBalance = account4.accountBalance + deposit;
            cout << "New Balance: $" << account4.accountBalance << endl;
            // post transaction question
            cout << "Would you like another transaction? (y/n)\n";
            cin >> transactionChoice;
            if(transactionChoice == 'n'){
                cout << "Thank you!\n";
                return 0;
            }
        } else if(userAccount == 111004){
        // ACCOUNT 5
            account5.accountBalance = account5.accountBalance + deposit;
            cout << "New Balance: $" << account5.accountBalance << endl;
            // post transaction question
            cout << "Would you like another transaction? (y/n)\n";
            cin >> transactionChoice;
            if(transactionChoice == 'n'){
                cout << "Thank you!\n";
                return 0;
            }
        }
        // ----------------
        break;
// SHOW BALANCE --------------------------------
    case '3':
    if(userAccount == 111000){
        // ACCOUNT 1
        cout << "Current Balance: $" << fixed << setprecision(2) 
        << account1.accountBalance << endl;
    } else if(userAccount == 111001){
        // ACCOUNT 2
    cout << "Current Balance: $" <<  account2.accountBalance << endl;
    } else if(userAccount == 111002){
        // ACCOUNT 3
        cout << "Current Balance: $" << account3.accountBalance << endl;
    } else if(userAccount == 111003){
        // ACCOUNT 4
        cout << "Current Balance: $" << fixed << setprecision(2)
        << account4.accountBalance << endl;
    } else if(userAccount == 111004){
        // ACCOUNT 5
        cout << "Current Balance: $" << fixed << setprecision(2) 
        << account5.accountBalance << endl;
    }
    // post transaction question
    cout << "Would you like another transaction? (y/n)\n";
    cin >> transactionChoice;
        if(transactionChoice == 'n'){
            cout << "Thank you!\n";
            return 0;
        }
        break;
   // SHOW TRANSACTION --------------------------
   /* case '4':
    
        break; */
    //CANCEL ----------------------------------------
    case '5':
        cout << "Would you like another transaction? (y/n)\n";
        cin >> transactionChoice;
        if(transactionChoice == 'n'){
            cout << "Thank you!\n";
            return 0;
        }
        // ------------------------
        break; 
    default:
    cout << "Invalid Choice!\n";
        break;
    }
    } while(transactionChoice == 'y');
    // end of program
    cout << "Thank you!\n";
    return 0;
}
