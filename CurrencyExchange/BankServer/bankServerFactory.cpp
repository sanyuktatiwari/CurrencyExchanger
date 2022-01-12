/**
 * @file bankServerFactory.cpp
 * @brief This is a Factory Class for bank servers
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include "../exchangerDefs.h"
#include "bankServerFactory.h"
#include "citiBankServer.h"
#include "hsbcBankServer.h"
#include "royalBankServer.h"

 /**
  * Constructor : cBankServerFactory
  *
  * @param [IN]	void
  *
  * @return	void.
  */
cBankServerFactory::cBankServerFactory()
{

}

/**
  * Destructor : cBankServerFactory
  *
  * @param [IN]	void
  *
  * @return	void.
  */
cBankServerFactory::~cBankServerFactory()
{

}

/**
  * createBankInstance
  *
  * @param [IN]	int bankID
  *
  * @return	IBankServer*
  */
IBankServer* cBankServerFactory::createBankInstance(int bankID)
{
	IBankServer* bank = NULL;
	switch (bankID)
	{
	case exchanger::BANK_ID::CITIBANK_1: //CitiBank
		bank = cCitiBankServer::getInstance();
		break;
	case exchanger::BANK_ID::HSBC_2: //HSBC
		bank = cHSBCBankServer::getInstance();
		break;
	case exchanger::BANK_ID::ROYALBANK_3: //Royal Bank
		bank = cRoyalBankServer::getInstance();
		break;
	default:
		bank = NULL;
		break;
	}
	return bank;
}