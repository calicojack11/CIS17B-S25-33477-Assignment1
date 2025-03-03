#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Bank Account class includes fucntions to depoist, withdraw and check balance for a object in the Banck Account class
class BankAccount
{
//private memebers include the name of account holder, the account number, and the balance of the account
private:
	string accountHolderName;
	int accountNumber;
	double balance;

public:
	//2 constructs: the basic constuctor and a construct that takes parameters to create the object
	BankAccount()
	{
		accountHolderName = "Your name";
		accountNumber = 1234567;
		balance = 0.00;
	}

	BankAccount(string name, int accountNum, double startingBalance)
	{
		accountHolderName = name;
		accountNumber = accountNum;
		balance = startingBalance;
	}

	void setAccountHolderName(string name)
	{
		accountHolderName = name;
	}

	void setAccountNumber(int accountNum)
	{
		accountNumber = accountNum;
	}
	//2 functions that return a pointer to the balance variable. Both take a parameter of an amount regarding what the user is either deposits or withdraws from their bank account
	double* deposit(double amount)
	{
		double* balancePtr = &balance;
		balance += amount;
		return balancePtr;
	}

	double* withdraw(double amount)
	{
		double* balancePtr = &balance;
		balance -= amount;
		return balancePtr;
	}

	//void funciton to display the balance of the bank account object. 
	void getBalance()
	{
		cout << balance << endl;
	}

};

//function that displays the menu options for the user. 
void menu();
int accountNumberGenarator();

int main()
{
	int menuChoice; 
	double amount;
	string name;
	int accountNum;
	double balance;
	double* balancePtr = &balance;
	BankAccount userAccount;

	//do while loop to display the menu options and lets the user go between the options until they decide to exit the program.
	do
	{
		menu();
		cout << "Choose option (use number): ";
		cin >> menuChoice;
		cout << endl;

		//switch statement use to go through the various menu options and to display the option chosen by the user.
		switch (menuChoice)
		{
		
		//case 1 creates an user account by asking for user input of a name and their starting balance.
		case 1:
			cin.ignore(255, '\n');
			cin.sync();
			cin.clear();

			cout << "Please enter your name: ";
			getline(cin, name);
			userAccount.setAccountHolderName(name);
			cout << "Please enter your starting balance: ";
			accountNum = accountNumberGenarator();
			userAccount.setAccountNumber(accountNum);
			cin >> amount;
			balancePtr = userAccount.deposit(amount);
			//while loop is used to make sure that negative amounts are not use when creating the starting balance of an account
			while (amount <= 0)
			{
				cout << "Please enter a number higher than 0." << endl;
				cin >> amount;
				balancePtr = userAccount.deposit(amount);
			}
			cout << endl;
			cout << "Account Holder Name: " << name << endl;
			cout << "Account Number: " << accountNum << endl;
			cout << "Balance: $";
			userAccount.getBalance();
			break;

		//case 2 asks for user input for the deposit they like to make into their bank account.
		case 2:
			cout << "Please enter the amount to deposit: ";
			cin >> amount;
			balancePtr = userAccount.deposit(amount);
			//while loop to ensure no negative numbers are used when make a deposit
			while (amount <= 0)
			{
				cout << "Please enter a number higher than 0." << endl;
				cin >> amount;
				balancePtr = userAccount.deposit(amount);
			}
			break;

		//case 3 asks for user input for a withdrawal from their bank account.
		case 3:
			cout << "Please enter the amount to withdraw: ";
			cin >> amount;
			balancePtr = userAccount.withdraw(amount);
			//while loop to ensure no negative numbers are used when making a withdrawal
			while (amount <= 0)
			{
				cout << "Please enter a number higher than 0." << endl;
				cin >> amount;
				balancePtr = userAccount.deposit(amount);
			}
			if (balance < 0)
			{
				cout << "Account is in the negative.";
			}
			break;

		//case 4 displays the current balance of the bank account
		case 4:
			cout << "Current balance: $";
			userAccount.getBalance();
			break;

		//case 5 exits the program and displays a message to indicate that happening
		case 5:
			cout << "Thank you for using this Banking Account app." << endl;
			break;
		}

		cout << endl;
	}while(menuChoice != 5);
	
	return 0;
}

void menu()
{
	cout << "Bank Account options: " << endl;
	cout << "1. Create an account" << endl;
	cout << "2. Deposit money" << endl;
	cout << "3. Withdraw money" << endl;
	cout << "4. Check balance" << endl;
	cout << "5. Exit program" << endl;
}

int accountNumberGenarator()
{
	int num;
	int min = 0;
	int max = 1000000;
	int seed = time(0);
	srand(seed);
	
	num = min + (rand() % max);

	return num;
}

