#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;

class Bank{
	public:
		string name;
		int accountnumber;
		int password;
		double balance;
		Bank();
		Bank(string name,int accountnumber, int password, double balance);
		void print();
		string getname();
		int getaccountnumber() const;
		int getpassword();
		double getbalance();
		void setbalance(double balance);
		void setpin(int pin);
};


Bank::Bank(){
	Bank::name = "";
	Bank::accountnumber = 0;
	Bank::password = 0;
	Bank::balance = 0.00;
}

Bank::Bank(string name,int accountnumber, int password, double balance){
	Bank::name = name;
	Bank::accountnumber = accountnumber;
	Bank::password = password;
	Bank::balance = balance;
}

void Bank::print(){
	cout<<"\t\t\t   Name: "<<name<<endl;
	cout<<"\t\t\t   Acc No: "<<accountnumber<<endl;
	cout<<setprecision(2)<<fixed<<"\t\t\t   Balance: "<<balance<<endl<<endl<<endl;
}

string Bank::getname(){
	return name;
}

int Bank::getaccountnumber() const{
	return accountnumber;	
}

int Bank::getpassword(){
	return password;
}

double Bank::getbalance(){
	return balance;
}

void Bank::setbalance(double balance){
	Bank::balance = balance;
}

void Bank::setpin(int pin){
	Bank::password = pin;
}
