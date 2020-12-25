#include <iostream>
#include <iomanip>
#include <ios>
#include "DebitCard.h"


using namespace std;

DebitCard::DebitCard()
{
	totalTransactions = 0;
	accountBalance = 0.0;
	totalDeposits = 0.0;
}

DebitCard::~DebitCard()
{
}

double DebitCard::Deposit(double deposit)
{
	accountBalance += deposit;
	totalDeposits = totalDeposits + deposit;
	return accountBalance;
}

double DebitCard::PostTransaction(int idNumber, std::string date, std::string description, double amount)
{
	Transaction *tmp = new Transaction(idNumber, date, description, amount);
	transactions.push_back(*tmp);

	totalTransactions++;

	accountBalance -= amount;

	return accountBalance;
}

bool DebitCard::ClearTransaction(int idNumber)
{
	for (int i = 0; i < totalTransactions; i++)
	{
		if (transactions.at(i).idNumber == idNumber)
		{
			transactions.at(i).cleared = true;
			return true;
		}

	}
	return false;
}

void DebitCard::DisplayActivity()
{
	cout << "total transactions: " << totalTransactions << endl;
	cout << "total deposits: $" << fixed << setprecision(2) << totalDeposits << endl;
	cout << "account balance: $" << fixed << setprecision(2) << accountBalance << endl;
	cout << "\n";
	cout << "List of cleared transactions:\n";
	for (int i = 0; i < totalTransactions; i++)
	{
		if (transactions.at(i).cleared == true)
		{
			cout << transactions.at(i).date << "\t$" << fixed << setprecision(2) << transactions.at(i).amount << "\t" << transactions.at(i).description << endl;
		}
	}
	cout << "\n";
	cout << "List of Pending transactions: " << endl;
	for (int i = 0; i < totalTransactions; i++)
	{
		if (transactions.at(i).cleared == false)
		{
			cout << transactions.at(i).date << "\t$" << fixed << setprecision(2) << transactions.at(i).amount << "\t" << transactions.at(i).description << endl;
		}
	}
}
