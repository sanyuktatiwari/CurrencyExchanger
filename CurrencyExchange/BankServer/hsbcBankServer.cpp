/*
 * @file hsbcBankServer.cpp
 * @brief This is a Singleton class to manage Bank processings.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include "hsbcBankServer.h"

cHSBCBankServer* cHSBCBankServer::mInstance = 0;

/**
 * Constructor.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
cHSBCBankServer::cHSBCBankServer() :IBankServer()
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
cHSBCBankServer::~cHSBCBankServer()
{

}

/**
 * getInstance : Function to get Instance of Class.
 *
 * @param [IN]	void
 *
 * @return	cHSBCBankServer*
 */
cHSBCBankServer* cHSBCBankServer::getInstance()
{
	if (0 == mInstance)
	{
		mInstance = new cHSBCBankServer();
	}
	return mInstance;
}

/**
 * initializeBankAccountDetails : Function to initialize Account Details of Account Holder of HSBC Bank.
 *
 * @param [IN]	void
 *
 * @return	void
 */
void cHSBCBankServer::initializeBankAccountDetails()
{
	mAccountDetails[111111111] = { "F" , "Indian Rupee", 100000 };
	mAccountDetails[222222222] = { "G", "USD" ,500000 };
	mAccountDetails[333333333] = { "H", "Canadian Dollar" ,300000 };
	mAccountDetails[444444444] = { "I", "Australian Dollar" ,289999 };
	mAccountDetails[555555555] = { "J", "Euro", 567899 };
}

/**
 * isValidAccount : Function to check Account validity.
 *
 * @param [IN]	long accountNumber, std::string password
 *
 * @return	bool
 */
bool cHSBCBankServer::isValidAccount(long accountNumber, std::string password)
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
std::string cHSBCBankServer::getBankName()
{
	return "HSBC";
}

/**
 * getBankName : Function to getAccount Details.
 *
 * @param [IN]	long accountNumber
 *
 * @return	bankStructs::AccounteeInfo
 */
bankStructs::AccounteeInfo cHSBCBankServer::getAccounteeInfo(long accountNumber)
{
	return mAccountDetails[accountNumber];
}