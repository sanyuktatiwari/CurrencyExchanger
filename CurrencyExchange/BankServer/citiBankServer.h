/*
 * @file citiBankServer.h
 * @brief This is a Singleton class to manage Bank processings.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#ifndef	__CITI_BANK_SERVER_H__
#define	__CITI_BANK_SERVER_H__
#include <unordered_map>
#include "IBankServer.h"
#include <string>
class cCitiBankServer : public IBankServer
{
	cCitiBankServer();
	~cCitiBankServer();
	static cCitiBankServer* mInstance;
	std::unordered_map<long, bankStructs::AccounteeInfo> mAccountDetails;
	void initializeBankAccountDetails();

public:
	static cCitiBankServer* getInstance();
	bool isValidAccount(long accountNumber, std::string password);
	std::string getBankName();
	bankStructs::AccounteeInfo getAccounteeInfo(long accountNumber);
};
#endif