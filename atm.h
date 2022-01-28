#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <vector>
#include <algorithm>

using namespace std;

void heading();
string hidepassword();

class ATM:Bank{
	public:
		void mainmenu();
		void depositmenu();
		void withdrawmenu();
		bool DecreaseBalance(double amount);
		void IncreaseBalance(double amount);
		double newbalance();
		int newpin();
		void depositsucceed();
		void depositdeclined();
		void withdrawsucceed();
		void withdrawdeclined();
		void checkbalance();
		void changepin();
		ATM(string name, int accountnumber,int password, double balance);
		
		friend void heading();
		friend string hidepassword();
};

ATM::ATM(string name, int accountnumber, int password ,double balance){
	ATM::name = name;
	ATM::accountnumber = accountnumber;
	ATM::balance = balance;
	ATM::password = password;
}

void ATM::depositmenu(){
	double amount;
	double amt=0;
	double temp;
	system("cls");
	heading();
	cout<<"\t\t\t   Deposit Menu\n\n";
	cout<<"\t\t\tEnter Amount: ";
	cin>>amount;
	cout<<"\n\t\t    Number of 10 dollar: ";
	cin>>temp;
	amt += temp*10;
	cout<<"\t\t    Number of 20 dollar: ";
	cin>>temp;
	amt += temp*20;
	cout<<"\t\t    Number of 100 dollar: ";
	cin>>temp;
	amt += temp*100;
	system("cls");
	heading();
	if(amt==amount){
		IncreaseBalance(amount);
		depositsucceed();
	}
	else{
		depositdeclined();
	}
	getch();
}

void ATM::withdrawmenu(){
	system("cls");
	heading();
	cout<<"\t\t\t  Withdraw Menu\n\n";
	cout<<"\t\t\t[1] To Withdraw $10\n";
	cout<<"\t\t\t[2] To Withdraw $20\n";
	cout<<"\t\t\t[3] To Withdraw $100\n";
	cout<<"\t\t\t[4] To Withdraw $200\n";
	cout<<"\t\t\t[5] To Enter Amount\n";
	cout<<"\n\t\t\t[0] Main Menu\n";
	cout<<"\n\n\t\t\tEnter Option: ";
	int n;
	cin>>n;
	system("cls");
	heading();
	switch (n){
		case 1:
			if(DecreaseBalance(10)){
				withdrawsucceed();
			}
			else{
				withdrawdeclined();
			}
			break;
		case 2:
			if(DecreaseBalance(20)){
				withdrawsucceed();
			}
			else{
				withdrawdeclined();
			}
			break;
		case 3:
			if(DecreaseBalance(100)){
				withdrawsucceed();
			}
			else{
				withdrawdeclined();
			}
			break;
		case 4:
			if(DecreaseBalance(200)){
				withdrawsucceed();
			}
			else{
				withdrawdeclined();
			}
			break;
		case 5:
			double amt;
			cout<<"\t\t\tEnter Amount: ";
			cin>>amt;
			system("cls");
			heading();
			if(DecreaseBalance(amt)){
				withdrawsucceed();
			}
			else{
				withdrawdeclined();
			}
			break;
		case 0:
			mainmenu();
			break;
	}
}

void ATM::mainmenu(){
	system("cls");
	heading();
	cout<<"\t\t\t Welcome ";
	cout<<getname()<<"\n\n";
	cout<<"\t\t\t[1] To Withdraw Money\n";
	cout<<"\t\t\t[2] To Deposit money\n";
	cout<<"\t\t\t[3] To Check Balance\n";
	cout<<"\t\t\t[4] To Change Pin\n";
	cout<<"\n\t\t\t[0] Exit\n";
	cout<<"\n\n\t\t\tEnter Option: ";
	int n;
	cin>>n;
	switch (n){
		case 1:
			withdrawmenu();
			break;
		case 2:
			depositmenu();
			break;
		case 3:
			checkbalance();
			break;
		case 4:
			changepin();
			break;
		case 0:
			break;
	}
}

bool ATM::DecreaseBalance(double amount) {
	if(balance<amount){	
		return false;	
	}
	else{	
		balance = balance - amount;	
		return true;	
	}	
}

double ATM::newbalance(){
	return balance;
}

int ATM::newpin(){
	return password;
}

void ATM::withdrawsucceed(){
	cout<<"\t\t\t  Transection Successful\n";
	cout<<"\n\t\t\t  Please Take Your Cash\n\n\n";
	system("pause");
}

void ATM::withdrawdeclined(){
	cout<<"\t\t\t  Transection Declined\n";
	cout<<"\n\t\t     You don't have enough money.\n\n\n";
	system("pause");
}

void ATM::depositsucceed(){
	cout<<"\t\t\t  Transection Successful\n";
	cout<<"\n\t\t      Your account has beed refiiled\n\n\n";
	system("pause");
}

void ATM::depositdeclined(){
	cout<<"\t\t\t  Transection Declined\n";
	cout<<"\n\t\t    Something wrong please try again\n\n\n";
	system("pause");
}

void ATM::IncreaseBalance(double amount) {
	ATM::balance = balance + amount;
}

void ATM::checkbalance(){
	system("cls");
	heading();
	print();
	system("pause");
}

void ATM::changepin(){
	system("cls");
	heading();
	int pin1,pin2;
	string temp;
	cout<<"\t\tEnter your new Pin: ";
	temp = hidepassword();
	pin1 = stoi(temp);
	cout<<"\t\tEnter your new Pin Again: ";
	temp = hidepassword();
	pin2 = stoi(temp);
	if(pin1==pin2){
		password = pin1;
	}
}
