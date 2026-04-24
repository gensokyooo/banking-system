#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct transaction {
    string type;
    double amount;
};

struct account {
    int id = 0;
    string name;
    double balance = 0;
};


account a;
vector <account> accounts;

void createAccount () {

    cout << "Enter account name:" << " ";
    cin.ignore();
    getline(cin,a.name);

    cout << "Enter your balance:" << " ";
    cin >> a.balance;
    cin.ignore (numeric_limits <streamsize> ::max(), '\n');
    a.id = static_cast <int> (accounts.size());

    accounts.push_back(a);

}

void showAccounts () {
    int i = 0;
    cout << "Showing accounts ... " << endl;
    for (auto entry: accounts) {
        cout << "============================" << endl;
        cout << "Name: " << entry.name << endl;
        cout << "Balance: " << entry.balance << endl;
        cout << "Id: " << entry.id << endl;
        cout << "============================" << endl;
        i++;
    }
}

// Account ID validation + Account selection
int accSelect () {
    int x;
    cout << "Select the ID of the Account you'd like to use" << endl;
    showAccounts();
    cout << "Select: "; cin >> x;

    while (x < 0 || x > accounts.size()) {
        cout << "Invalid ID" << endl;
        cout << "Select again between this range: " << "0" << " " << "TO" << accounts.size() << endl;
        cin >> x;
    }

    return x;
}

void depositMoney () {


    int result_ID = accSelect();

    double x;
    cout << "Enter the sum you'd like to deposit:"  << endl;
    cin >> x;

    accounts[result_ID].balance += x;

    cout << "Added to account ID:" << accounts[result_ID].id << endl;
    cout << "Added:" << " " << accounts[result_ID].balance << endl;

    cout << "[DEPOSIT SUCCESSFUL]" << endl;
}

void withdrawMoney() {
    int result_ID = accSelect();

    double x;
    cout << "How much would you like to Withdraw?" << endl;
    cin >> x;
    accounts[result_ID].balance -= x;
    cout << "Your new balance: " << accounts[result_ID].balance - x << endl;
    cout << "[WITHDRAW SUCCESSFUL]" << endl;

}

void transferMoney () {

    showAccounts();
    int x;
    int y;
    cout << "Transfer from ID: "; cin >> x;
    cout << "To ID: "; cin >> y;

    double z;
    cout << "How much would you like to transfer?" << endl;
    cin >> z;

    accounts[x].balance -= z;
    accounts[y].balance += z;

    cout << accounts[x].name << "'s new balance is: " << accounts[x].balance << endl;
    cout << accounts[y].name << "'s new balance is: " << accounts[y].balance << endl;


}

int main () {
    int x;
    cout << "\n 1. Create account \n 2. Show accounts \n 3. Deposit \n 4. Withdraw \n 5. Transfer \n 0. Exit" << endl;
        cout << "Enter your choice: "; cin >> x;

    while (x != 0) {
        switch (x) {
            case 1: createAccount();
                break;
            case 2: showAccounts ();
                break;
            case 3: depositMoney();
                break;
            case 4: withdrawMoney();
                break;
            case 5: transferMoney();
                break;
            default: cout << "invalid choice" << endl;
                break;

        }

        cout << "Enter your choice: ";
        cin >> x;
    }
}