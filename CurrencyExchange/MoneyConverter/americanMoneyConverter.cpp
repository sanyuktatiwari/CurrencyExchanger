/*
 * @file americanMoneyConverter.cpp
 * @brief This is a Concrete class to manage American Money Converter functionalities.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include "americanMoneyConverter.h"
#include "../exchangerDefs.h"

 /**
  * Constructor.
  *
  * @param [IN]	void
  *
  * @return	void.
  */
cAmericanMoneyConverter::cAmericanMoneyConverter() :IMoneyConverter()
{

}

/**
 * Destructor.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
cAmericanMoneyConverter::~cAmericanMoneyConverter()
{

}

/**
 * getBaseCurrencyType : Return Currency Type
 *
 * @param [IN]	void
 *
 * @return	std::string.
 */
std::string cAmericanMoneyConverter::getBaseCurrencyType()
{
	return "USD";
}

/**
 * convertMoney : Function to convert balance amount into exchanged currency value. 
 *
 * @param [IN]	int type, long balance
 *
 * @return	long
 */
long cAmericanMoneyConverter::convertMoney(int type, long balance)
{
	long exchangedCurrencyAmount = balance;

	switch (type)
	{
	case exchanger::CURRENCY_CODE::ISD: //Indian Rupee
		exchangedCurrencyAmount = exchangedCurrencyAmount * 73.78;
		break;

	case exchanger::CURRENCY_CODE::USD: //USD
		//Do nothing since class is for Indian Currency only
		break;

	case exchanger::CURRENCY_CODE::CAD: //Canadian Dollar
		exchangedCurrencyAmount = exchangedCurrencyAmount * 1.26;
		break;

	case exchanger::CURRENCY_CODE::AUD: //Australian Dollar
		exchangedCurrencyAmount = exchangedCurrencyAmount * 1.39;
		break;

	case exchanger::CURRENCY_CODE::EUR: //Euro
		exchangedCurrencyAmount = exchangedCurrencyAmount * 0.88;
		break;

	default:
		break;
	}

	return exchangedCurrencyAmount;
}