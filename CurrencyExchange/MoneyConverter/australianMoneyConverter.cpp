/*
 * @file australianMoneyConverter.cpp
 * @brief This is a Concrete class to manage Australian Money Converter functionalities.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include "australianMoneyConverter.h"
#include "../exchangerDefs.h"

 /**
   * Constructor.
   *
   * @param [IN]	void
   *
   * @return	void.
   */
cAusMoneyConverter::cAusMoneyConverter() :IMoneyConverter()
{

}

/**
 * Destructor.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
cAusMoneyConverter::~cAusMoneyConverter()
{

}

/**
 * getBaseCurrencyType : Return Currency Type
 *
 * @param [IN]	void
 *
 * @return	std::string.
 */
std::string cAusMoneyConverter::getBaseCurrencyType()
{
	return "Australian Dollar";
}

/**
 * convertMoney : Function to convert balance amount into exchanged currency value.
 *
 * @param [IN]	int type, long balance
 *
 * @return	long
 */
long cAusMoneyConverter::convertMoney(int type, long balance)
{
	long exchangedCurrencyAmount = balance;

	switch (type)
	{
	case exchanger::CURRENCY_CODE::ISD: //Indian Rupee
		exchangedCurrencyAmount = exchangedCurrencyAmount * 53.18;
		break;

	case exchanger::CURRENCY_CODE::USD: //USD
		exchangedCurrencyAmount = exchangedCurrencyAmount * 0.72;
		break;

	case exchanger::CURRENCY_CODE::CAD: //Canadian Dollar
		exchangedCurrencyAmount = exchangedCurrencyAmount * 0.91;
		break;

	case exchanger::CURRENCY_CODE::AUD: //Australian Dollar
		//Do nothing since class is for Indian Currency only
		break;

	case exchanger::CURRENCY_CODE::EUR: //Euro
		exchangedCurrencyAmount = exchangedCurrencyAmount * 0.63;
		break;

	default:
		break;
	}

	return exchangedCurrencyAmount;
}