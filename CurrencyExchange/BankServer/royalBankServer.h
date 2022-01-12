/*
 * @file royalBankServer.h
 * @brief This is a Singleton class to manage Bank processings.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#ifndef	__ROYAL_BANK_SERVER_H__
#define	__ROYAL_BANK_SERVER_H__
#include <unordered_map>
#include "IBankServer.h"
#include <string>
class cRoyalBankServer : public IBankServer
{
	cRoyalBankServer();
	~cRoyalBankServer();
	static cRoyalBankServer* mInstance;
	std::unordered_map<long, bankStructs::AccounteeInfo> mAccountDetails;
	void initializeBankAccountDetails();

public:
	static cRoyalBankServer* getInstance();
	bool isValidAccount(long accountNumber, std::string password);
	std::string getBankName();
	bankStructs::AccounteeInfo getAccounteeInfo(long accountNumber);
};
#endif