/*
 * @file royalBankServer.h
 * @brief This is a Singleton class to manage Bank processings.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include "royalBankServer.h"

cRoyalBankServer* cRoyalBankServer::mInstance = 0;

/**
 * Constructor.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
cRoyalBankServer::cRoyalBankServer() :IBankServer()
{
	mAccountDetails.clear();
	initializeBankAccountDetails();
}

/**
 * Destructor.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
cRoyalBankServer::~cRoyalBankServer()
{

}

/**
 * getInstance : Function to get Instance of Class.
 *
 * @param [IN]	void
 *
 * @return	cRoyalBankServer*
 */
cRoyalBankServer* cRoyalBankServer::getInstance()
{
	if (0 == mInstance)
	{
		mInstance = new cRoyalBankServer();
	}
	return mInstance;
}

/**
 * initializeBankAccountDetails : Function to initialize Account Details of Account Holder of Royal Bank.
 *
 * @param [IN]	void
 *
 * @return	void
 */
void cRoyalBankServer::initializeBankAccountDetails()
{
	mAccountDetails[111111116] = { "K" , "Indian Rupee", 100000 };
	mAccountDetails[222222227] = { "L", "USD" ,500000 };
	mAccountDetails[333333338] = { "M", "Canadian Dollar" ,300000 };
	mAccountDetails[444444449] = { "N", "Australian Dollar" ,289999 };
	mAccountDetails[555555553] = { "O", "Euro", 567899 };
}

/**
 * isValidAccount : Function to check Account validity.
 *
 * @param [IN]	long accountNumber, std::string password
 *
 * @return	bool
 */
bool cRoyalBankServer::isValidAccount(long accountNumber, std::string password)
{
	bool isAccountValid = false;
	if (mAccountDetails.find(accountNumber) != mAccountDetails.end() && mAccountDetails[accountNumber].password == password)
		isAccountValid = true;
	return isAccountValid;
}

/**
 * getBankName : Function to get Bank name.
 *
 * @param [IN]	void
 *
 * @return	std::string
 */
std::string cRoyalBankServer::getBankName()
{
	return "Royal Bank";
}

/**
 * getBankName : Function to getAccount Details.
 *
 * @param [IN]	long accountNumber
 *
 * @return	bankStructs::AccounteeInfo
 */
bankStructs::AccounteeInfo cRoyalBankServer::getAccounteeInfo(long accountNumber)
{
	return mAccountDetails[accountNumber];
}