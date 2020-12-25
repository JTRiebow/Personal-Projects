#include <iostream>
#include "Transaction.h"

using namespace std;

Transaction::Transaction(int transactionID, std::string date, std::string description, double amount)
{
	idNumber = transactionID;
	this->date = date;
	this->description = description;
	this->amount = amount;
	cleared = false;
}
