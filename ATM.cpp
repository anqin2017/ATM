// ATM.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"ATM.h"
#include<iostream>
using namespace std;
ATM::ATM() {};
ATM::~ATM() {};
int ATM::Account_Create(int myaccout,char *myusername,int mybalance)
{
	account = myaccout;
	username = myusername;
	balance = mybalance;
	return 0;
}
int ATM::Save_Money(int myaccout, char *myusername, int mysavemoney, int mydate)
{
	balance = balance + mysavemoney;

	return 0;
}
int ATM::Draw_Money(int myaccout, char *myusername, int mydrawmoney, int mydate)
{
	return 0;
}
int ATM::Search_Account()
{
	return 0;
}
void ATM::PrintAtm()
{
	cout << "my accout is: " <<account<< endl;
	cout << "my username is: " << username << endl;
	cout << "my balance is: " << balance << endl;
}
