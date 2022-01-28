#include <iostream>
#include <fstream> 	//for file operation
#include <sstream>	//for stringstream
#include <time.h>	//for current date and time
#include <stdlib.h>	
#include <string.h>
#include <conio.h>
#include <vector>	//data structure
#include <algorithm>
#include <iomanip>
#include "bank.h"
#include "atm.h"

using namespace std;

void heading();
string hidepassword();
bool askingaccountnubmer(vector<Bank> accounts,Bank& account);
bool askingpassword(Bank& account);
bool checkingaccountnumberpassword(vector<Bank> accounts, Bank& account);
void fileoperationreading(vector<Bank>& accounts);
void fileoperationwriting(vector<Bank>& accounts,Bank account);

void heading(){
	cout<<"\n\t\t\t     BANK OF AMERICA\n\n";
	time_t now;
	time(&now);
	printf("\t\t\t%s\n\n", ctime(&now));
}

bool askingaccountnubmer(vector<Bank> accounts,Bank& account){
	cout<<"\t Please Enter Your Six Digit Account Number:  ";
	int acc;
	cin>>acc;
	vector<Bank>::iterator it;
	it = find_if(accounts.begin(),accounts.end(),[&acc](const Bank& a){ return acc==a.getaccountnumber();} );
	if(it!=accounts.end()){
		account=*it;
		return true;	
	}
	else{
		system("cls");
		heading();
		cout<<"\t\t\t Wrong Account Number!!!\n"<<endl;
		return false;
	}	
}

string hidepassword(){
	string password="";
	char ch;
	for(int i=0;i<4;i++){
		ch= getch();
		password.push_back(ch);
		cout<<"*";
	}
	cout<<"\n";
	return password;
}

bool askingpassword(Bank& account){
	cout<<"\t Please Enter Your Four Digit pin:  ";
	string password = hidepassword();
	int pass=stoi(password);
	
	if(pass==account.getpassword()){
		return true;	
	}
	else{
		system("cls");
		heading();
		cout<<"\t\t\t   Wrong Pin Number!!!\n"<<endl;
		return false;
	}
}

bool checkingaccountnumberpassword(vector<Bank> accounts, Bank& account){
	while(!askingaccountnubmer(accounts,account)){}
	for(int i=0;!askingpassword(account);i++){
		if(i==2){
			cout<<"\tYour account has been locked please contact customer care. \n";
			getch();
			return false;
		}
		cout<<"\t\t\tYou have "<<2-i<<"attempts left\n\n";
	}
	return true;
}

void fileoperationreading(vector<Bank>& accounts){
	ifstream fin;
	fin.open("accounts.txt");
	string name;
	string temp;
	int account;
	int password;
	double balance;
	int numberofaccount;
	getline(fin,temp);
	stringstream snumberofaccount(temp);
	snumberofaccount>>numberofaccount;
	
	for(int i=0;i<numberofaccount;i++){
		
		getline(fin,name);
		getline(fin,temp);
		stringstream saccount(temp);
		saccount>>account;
		getline(fin,temp);
		stringstream spassword(temp);
		spassword>>password;
		getline(fin,temp);
		stringstream sbalance(temp);
		sbalance>>balance;
		
		Bank btemp = Bank(name, account, password, balance);
		accounts.push_back(btemp);
	}
	fin.close();
}

void fileoperationwriting(vector<Bank>& accounts,Bank account){
	ofstream fout;
	fout.open("accounts.txt");
	fout<<accounts.size()<<endl;
	for(int i=0;i<accounts.size();i++){
		if(accounts[i].getaccountnumber()==account.getaccountnumber()){
			accounts[i].setbalance(account.getbalance());
			accounts[i].setpin(account.getpassword());
		}
		fout<<accounts[i].getname()<<endl;
		fout<<accounts[i].getaccountnumber()<<endl;
		fout<<setprecision(2)<<fixed<<accounts[i].getpassword()<<endl;
		fout<<accounts[i].getbalance()<<endl;
	}
	fout.close();	
}

int main(){	
	vector<Bank> accounts;
	fileoperationreading(accounts);
	while(1){
		Bank account = Bank();
		system("cls");
		heading();
		if(checkingaccountnumberpassword(accounts,account)){
			ATM atm = ATM(account.getname(),account.getaccountnumber(),account.getpassword(),account.getbalance());
			atm.mainmenu();
			double newbalance=atm.newbalance();
			int pin=atm.newpin();
			account.setbalance(newbalance);
			account.setpin(pin);
			fileoperationwriting(accounts,account);
		}
	}
	return 0;
}
