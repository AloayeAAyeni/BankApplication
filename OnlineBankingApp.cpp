#include "OnlineBankingApp.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


Account::Account()
{	 

}

// Account constructor. 
Account::Account(string Fn, string Ln, float Bal)
{	
	// save the parameters of the account to useable variables.
	First_name = name = Fn;
	Last_name = Ln;
	iBal = Bal;	
}

// Asks for login details , compares, validates and handles the expetion of a constant incorrect details
void Account::loginDeets()
{
	// Nesserasry Local variables
	string username;
	string password;
	int x = 0 ; 
 	
	// Loops while they input the incorrect details 5 times. 
	do
	{
		cout << "Enter your username. \n";
		getline(cin, username); 
		// removes the blank spaces from the string 'username' , incase of accidental input. 
		username.erase(remove_if(username.begin(), username.end(), [](unsigned char x) {return isspace(x); }), username.end());
		cout << "Enter your password. \n";
		getline(cin, password);		

		if ((username == First_name) && (password == "1234")) // Both parameters need to be fufilled to gain access. 
		{
			cout <<"\n" << "Hello, " << name << "\n" <<  endl;
			break; 
		}
		else if (x >= 4)
		{
			cout << "too many attempts. contact your bank to log in." << endl;
			exit(0);

		}else 
		{
			// Error message , increments and sow how many attemps are left. 
			cout << "invalid username or password" << endl;
			x++;
			cout << "\n you have " << 5 - x << " attempt(s) left \n" << endl;
		}
	} while (x <= 4);
		
}
 
// Asks for the new payees first/sirname and saves the input in name 
void Payee::getNames()
{
	cout << "Please enter the Payee details " << endl;
	cout << "First name: ";	
	cin >> First_name; 
	First_name.erase(remove_if(First_name.begin(), First_name.end(), [](unsigned char x) {return isspace(x); }), First_name.end());
	cout << "Surname: "; 
	cin >> Last_name; 
	Last_name.erase(remove_if(Last_name.begin(), Last_name.end(), [](unsigned char x) {return isspace(x); }), Last_name.end());
	name = First_name + " " + Last_name;	
}

//Gets the Payee sort code from user. 
void Payee::getSortcode()
{	
	// Loops forever until the program gets the correct input type (Integer)
	for (;;) //loops forever
	{
		cout << "Sortcode: ";
		if (!(cin >> SortCode)) // if not the correct data type in the input.
		{
			cout << "Please enter a valid integer" << endl;
			cin.clear(); // clears the input stream
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // remove the bad input until the '\n'	
		}
		else
		{	
			break;
		}
	}
}

//Gets the Account number ...see void Payee. 
void Payee::getAccountNum()
{
	for (;;)
	{
		cout << "Account Number: ";
		if (!(cin >> AccountNum))
		{
			cout << "Please enter a valid integer" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else 
		{
			break;
		}
	}
}

//Prints the Payee details. 
void Payee::printDeets()
{
	cout << "Are these details correct?" << endl; 
	cout << "Name: "<< name << endl;
	cout << "Sortcode: " << SortCode << endl;
	cout << "Account number: " << AccountNum << endl;
}

//Returns a boolean. 
bool Payee::CorrectInfo()
{
	return correctInfo;
}

//Prints all the payee names. 
void Payee::printPnames()
{
	cout << name;
	cout << endl;
}

//Adjusts and prints payee balance. 
void Payee::printBalance()
{	
	Balance = dAmount + Balance;
	cout << dAmount;
	cout << Balance << endl; 
}

//Bool that validates the transfer function , (if any payee has been added or not).
bool Payee::primaryusage()
{	
	PrimaryUsage = false;
	return PrimaryUsage; 
}

//Access the balance for all classes and derived classes.
double Account::accessBal()
{
	if (IntialTrans == true)
	{
		return iBal;
	}
	else
	{
		return Balance;
	}
}

//Access name. 
string Account::accessName()
{
	name = First_name + " " + Last_name;
	return name;
}

//Prints the final balance. 
void Account::withdrawl()
	{	
		cout << "Your current balance is " << char(156) << finalAmount << endl;
		cout << endl;
	}

//Requests the withdrawl amount , throws exception and prints error messages. 
void Account::getWAmount()
{
	double x;
	
	for (;;) // loops forever
	{
		cout << "how much would you like to withdraw?" << endl;
		if (cin >> x) // checks if its formattable with a double
		{
			cout << endl;
			if (x > 0)
			{
				wAmount = x;				
				break;
			}
			else
			{
				cout << endl;
				cout << "You cannot deposit a negative number" << endl;
			}
		}
		else { //  if not a number will ask to re input the number and clears the cin.
			cout << endl;
			cout << "Please enter a valid integer" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Dumps the bad input.
			cout << endl;
		}
	}
	
	finalAmount = 0; 
	
}

//Requests the transaction amount , throws exception and prints error messages. 
double Account::getTAmount(double dAmount)
{// see get wAmount
	double x;

	for (;;)
	{
		cout << "how much would you like to transfer?" << endl;
		if (cin >> x)
		{
			if (x > 0)
			{
				dAmount = wAmount = x;
				return dAmount;
				break;
			}
			else
			{
				cout << "You cannot deposit a negative number" << endl;
			}
		}
		else {
			cout << "Please enter a valid integer" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	//wAmount = x;
	finalAmount = 0;
}

// access withdrawl amount. 
double Account::accessWAmount()
{
	return wAmount;
}

// checks if the your account balance will be smaller than your overdraft limit. 
void Account::CheckOverdraft()
{ 
	
	if (finalAmount > limitOverDraft)
	
	{
		verified = true; // booleean that allows the transaction to take place. 
		Balance = finalAmount;		
	}
	else
	{
		cout << endl;
		cout << "This transaction exceeds your overdraft limit. Your overdraft limit is : " << limitOverDraft << endl;
		cout << "This transaction will leave your balance as : " << finalAmount << endl;			
		verified = false; // If boolean is false , flow control will send user back to requesting the amount. 
	} 
}

// returns the overdraft limit. 
double Account::overdraftlim()
{	
	return limitOverDraft;
}

//Calculate the final amount. 
double Account::getFinalAmount()
{	
	finalAmount = 0;
	if (IntialTrans == true)
	{
		finalAmount = 0 - wAmount; 		
		IntialTrans = false;
	}
	else
	{
		finalAmount = Balance - wAmount; 
	} 	
	return finalAmount;
} 

// returns the boolean verified.
bool Account::Verified()
{
	return verified;
}

// Does the deposit transaction , and prints the result. 
void Account::deposit()
{// depending on the state of the boolean, will use different variables to do calculation.
	if (IntialTrans == true)
	{		
		finalAmount = 0 + dAmount;
		cout << endl;
		cout << "Your balance is " << char(156) << finalAmount << endl;
		IntialTrans = false;
		Balance = finalAmount;		
		
	}
	else
	{	
		
		finalAmount = Balance +	dAmount;
		cout << endl;
		cout << "Your balance is " << char(156) << finalAmount << endl;
		Balance = finalAmount;
		
	}	
}

// Requests the transaction amount, throws exceptionand prints error messages.
void Account::getDAmount()
{ // see get wAmount. 
	double x;

	for (;;)
	{
		cout << "how much would you like to deposit?" << endl;
		if (cin >> x)
		{
			cout << endl;
			if (x > 0)
			{   
				cout << endl;
				dAmount = wAmount = x;
				break;
			}
			else
			{	
				cout << endl;
				cout << "You cannot deposit a negative number" << endl;
			}
		}
		else 
		{
			cout << endl;
			cout << "Please enter a valid integer" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	
	finalAmount = 0;
}

//Asks user if the Payee details are correct and chooses state of boolean depending on choice. 
void Payee::correctDetails()
{
	int choice;
	cout << "Are these details correct?" << endl; 
	cout << "1.Yes " << " 2.No" << endl;
	cout << endl;
	cin >> choice;

	if (choice == 1)
	{	
		correctInfo = true;
	}
	else
	{
		correctInfo = false; 
	}
}

//current account contructor
Current_Account::Current_Account(string Fn, string Ln, float Bal)
{
	First_name = name = Fn;
	Last_name = Ln;
	iBal = Bal;
}

//saving account constructor 
Savings_Account::Savings_Account(string Fn, string Ln, float Bal)
{
	First_name = name = Fn;
	Last_name = Ln;
	iBal = Bal;
}
