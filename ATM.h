#pragma once

class ATM
{
public:
	ATM();
	~ATM();
public:
	int Account_Create(int myaccout, char *myusername, int mybalance);
	int Save_Money(int myaccout, char *myusername,int mysavemoney,int mydate);
	int Draw_Money(int myaccout, char *myusername, int mydrawmoney, int mydate);
	int Search_Account();
	void PrintAtm();
private:
	int account;
	char *username;
	int balance;
	int data;
};
