/**
 * @file citiBankServer.cpp
 * @brief This is a Singleton class for CitiBank Server. 
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include "citiBankServer.h"

cCitiBankServer* cCitiBankServer::mInstance = 0;

/**
 * Constructor.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
cCitiBankServer::cCitiBankServer():IBankServer()
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
cCitiBankServer::~cCitiBankServer()
{

}

/**
 * getInstance : Function to get Instance of Class.
 *
 * @param [IN]	void
 *
 * @return	cCitiBankServer*
 */
cCitiBankServer* cCitiBankServer::getInstance()
{
	if (0 == mInstance)
	{
		mInstance = new cCitiBankServer();
	}
	return mInstance;
}

/**
 * initializeBankAccountDetails : Function to initialize Account Details of Account Holder of Citi Bank.
 *
 * @param [IN]	void
 *
 * @return	void
 */
void cCitiBankServer::initializeBankAccountDetails()
{
	mAccountDetails[123456782] = { "A" , "Indian Rupee", 100000};
	mAccountDetails[123458782] = { "B", "USD" ,500000};
	mAccountDetails[113456782] = { "C", "Canadian Dollar" ,300000};
	mAccountDetails[156256782] = { "D", "Australian Dollar" ,289999};
	mAccountDetails[196256782] = { "E", "Euro", 567899 };
}

/**
 * isValidAccount : Function to check Account validity.
 *
 * @param [IN]	long accountNumber, std::string password
 *
 * @return	bool
 */
bool cCitiBankServer::isValidAccount(long accountNumber, std::string password)
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
std::string cCitiBankServer::getBankName()
{
	return "Citi Bank";
}

/**
 * getBankName : Function to getAccount Details.
 *
 * @param [IN]	long accountNumber
 *
 * @return	bankStructs::AccounteeInfo
 */
bankStructs::AccounteeInfo cCitiBankServer::getAccounteeInfo(long accountNumber)
{
	return mAccountDetails[accountNumber];
}