/*
 * @file IBankServer.h
 * @brief This is an interface for Bank Servers.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#ifndef	__I_BANK_SERVER_H__
#define	__I_BANK_SERVER_H__
#include <string>
#include "bankStructs.h"

class IBankServer
{
public:
	IBankServer() {};
	virtual ~IBankServer() {};
	virtual std::string getBankName() = 0;
	virtual bool isValidAccount(long accountNumber, std::string password) = 0;
	virtual bankStructs::AccounteeInfo getAccounteeInfo(long accountNumber) = 0;
};
#endif