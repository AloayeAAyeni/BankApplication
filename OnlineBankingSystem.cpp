// OnlineBankingSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "OnlineBankingApp.h"
#include "OnlineBankingApp.cpp"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

int main()
{
    Account mainAccount("Mark", "Smith"); // constructs account.
    Current_Account currentA("Mark", "Smith"); //constructs a current account.
    Savings_Account savingsA("Mark", "Smith"); //consturcts a savings account.
    Payee Payees[100];  // constructs payee array that holds 100 places.     
    cout << "welcome to the online banking system!\n";   
    mainAccount.accessName(); // gets name of user. 
    mainAccount.loginDeets();  // validates the login to the software. 
    int choice;
    int opt ; 
    bool x = false;
    int i = 1;
    double dAmount = 0;
  
     
    /*Encase the whole user facing program in a loop that displayes
    the menu and allows a choice */
    do 
    {       
        // Menu
       cout << "Which service do you want?" << endl;
       cout << endl;
       cout << "0.Quit" << endl;
       cout << "1.View Balance" << endl;
       cout << "2.Print Account details" << endl;
       cout << "3.Withdraw" << endl;
       cout << "4.Deposit" << endl;
       cout << "5.Transfer" << endl;
       cout << "6.Add a new Payee" << endl;
       cin >> choice;
       cout << "\n" ; 

       switch (choice)
       {
       case 0:
           //Closes Application
           cout << "App closed\n";
           exit;
       case 1:
           //Prints name and Balance. 
           cout << mainAccount.accessName()<< endl;
           cout << "Your current account balance is " << char(156) << currentA.accessBal() << endl;
           cout << "Your savings account balance is " << char(156) << savingsA.accessBal() << endl;
           cout << '\n';
           break;

       case 2:
           //Prints the accounts information
           // ADD MORE NONSENSE HERE
           cout << "Printing your details...\n " << endl;
           cout << endl; 
           cout << mainAccount.accessName() << endl;
           cout << "Your current account balance is: " << char(156) << currentA.accessBal() << endl;
           cout << "Your savings account balance is:" << char(156) << savingsA.accessBal() << endl;
           cout <<"Your Overdraft limit is: " <<mainAccount.overdraftlim() << endl;
           cout << "\n";
           break;

       case 3:
           //withdraws money from the current account.         
          do
          {
           currentA.getWAmount();
           currentA.getFinalAmount();
           currentA.CheckOverdraft();
            
          } while (currentA.Verified() == false);
          currentA.withdrawl();
          break;
      
       case 4:
           //Deposits money to the correct account.    
           
          do
          {
               cout << "which account would you like to transact with" << endl;
               cout << "1) Saving_Account " << endl;
               cout << "2) Current_Account " << endl;
               cin >> opt;               
               cout << endl;

               switch (opt)
               {// Options that allow to chose saving or current accout and perform the transaction. 
                 case 1:
                  {
                      savingsA.getDAmount();                   
                      savingsA.deposit();
                      x = true;
                      break;
                  }
                 case 2:
                  {
                      currentA.getDAmount();                      
                      currentA.deposit();
                      x = true;
                      break;
                  }
               }
          } while ( x == false);           
           break;

       case 5:

           // Transfers money to one of the payee accounts created.
          
           // loop that cycles through all the payees that the user has entered and prints them to terminal. 
           if (Payees->primaryusage() == true)
           {
               cout << "There are no payees to send money to. " << endl;
               cout << endl;
               break;
             
           }
           else
           {
               cout << "who would you like to transfer to" << endl;
               // loop that cycles through all the payees that the user has entered and prints them to terminal. 
               for (int x = 1; x < i; x++)
               {
                   cout << x << ".";
                   Payees[x].printPnames();

               }
               cin >> choice;
               //  Withdraws money from the 
               do
               {
                   currentA.getTAmount(dAmount);
                   currentA.getFinalAmount();
                   currentA.CheckOverdraft();

               } while (currentA.Verified() == false);

               cout << "You have sent money to, " << Payees[choice].accessName() << endl;
               cout << mainAccount.accessName() << " your balance is " << char(156) << currentA.accessBal() << endl;
               break;
           }
   
       case 6:
           // Takes user input to add payees details. 
           do
           {
               Payees[i].getNames();
               Payees[i].getSortcode();
               Payees[i].getAccountNum();             
               Payees->correctDetails();
           } while (Payees->CorrectInfo() == false); 
               cout << endl;
               cout << Payees[i].accessName() << "'s information has been saved" << endl;
               cout << endl;
               Payees->primaryusage();
               Payees[i++];   
               break;
       }      
    } while (choice!=0);
}
    