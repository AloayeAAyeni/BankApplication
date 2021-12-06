#pragma once
#include <iostream>
#include <string>
#include "OnlineBankingApp.h"
#include "stdio.h"

#ifndef OnlineBankingApp_H
#define OnlineBankingApp_H

using std::string;

// Parent class
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
	
protected:

	double iBal;
	double Balance = 0;

private:

	double finalAmount = 0;
	const double limitOverDraft = -1000;
	bool verified; 
	double dBal;
	bool IntialTrans = true;
};

//Derived class
class Current_Account : public Account
{
public:
	Current_Account(string Fn, string Ln, float Bal = 0);
private:
};

//Derived class
class Savings_Account : public Account
{
public:
	Savings_Account(string Fn, string Ln, float Bal = 0);
private:
};

//Derived class
class Payee : public Account {
	
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
