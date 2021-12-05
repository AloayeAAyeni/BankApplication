#pragma once
#include <iostream>
#include <string>
#include "OnlineBankingApp.h"
#include "stdio.h"

#ifndef OnlineBankingApp_H
#define OnlineBankingApp_H

using std::string;

// Parent class : Account
class Account {
public: 
	Account();
	Account(string Fn, string Ln, float Bal = 0 );
	
	string name;
	string First_name, Last_name;
	double wAmount;
	double tAmount;	
	double dAmount = 0;
	double uDAmount;

	void loginDeets();
	//string getname();	

	double accessBal(); 
	string accessName(); 

	void withdrawl();
	void getWAmount(); 
	double getTAmount(double dAmount);
	double accessWAmount();
	void CheckOverdraft();
	double overdraftlim();
	double getFinalAmount(); 
	bool Verified(); 	
	void deposit();
	void getDAmount();
	//void moveMinusToFront(char str[]);
protected:
	double iBal;
	double Balance = 0;

private:
	double finalAmount = 0;
	

	//withdrawlTrans
	
	const double limitOverDraft = -1000;
	bool verified; 
	
	//DepositTrans
	double dBal;
	

	// all transactions
	
	bool IntialTrans = true;

};

class Current_Account : public Account
{
public:
	Current_Account(string Fn, string Ln, float Bal = 0);
private:
};

class Savings_Account : public Account
{
public:
	Savings_Account(string Fn, string Ln, float Bal = 0);
private:
};

class Payee : public Account {
	// all seperate account other than main go here
public:

	void correctDetails();
	void getNames();
	void getSortcode();
	void getAccountNum();
	void printDeets(); 
	bool CorrectInfo();
	void printPnames();
	void printBalance();
	bool primaryusage(); 

private:

	string Pname;
	int	SortCode;
	int AccountNum;
	bool correctInfo;
	bool PrimaryUsage; 

};
#endif
