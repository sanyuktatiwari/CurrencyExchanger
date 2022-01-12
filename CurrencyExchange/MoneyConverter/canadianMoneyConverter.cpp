/*
 * @file canadianMoneyConverter.cpp
 * @brief This is a Concrete class to manage Canadian Money Converter functionalities.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include "canadianMoneyConverter.h"
#include "../exchangerDefs.h"

 /**
	* Constructor.
	*
	* @param [IN]	void
	*
	* @return	void.
	*/
cCanadianMoneyConverter::cCanadianMoneyConverter() :IMoneyConverter()
{

}

/**
 * Destructor.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
cCanadianMoneyConverter::~cCanadianMoneyConverter()
{

}

/**
 * getBaseCurrencyType : Return Currency Type
 *
 * @param [IN]	void
 *
 * @return	std::string.
 */
std::string cCanadianMoneyConverter::getBaseCurrencyType()
{
	return "Canadian Dollar";
}

/**
 * convertMoney : Function to convert balance amount into exchanged currency value.
 *
 * @param [IN]	int type, long balance
 *
 * @return	long
 */
long cCanadianMoneyConverter::convertMoney(int type, long balance)
{
	long exchangedCurrencyAmount = balance;

	switch (type)
	{
	case exchanger::CURRENCY_CODE::ISD: //Indian Rupee
		exchangedCurrencyAmount = exchangedCurrencyAmount * 58.66;
		break;

	case exchanger::CURRENCY_CODE::USD: //USD
		exchangedCurrencyAmount = exchangedCurrencyAmount * 0.80;
		break;

	case exchanger::CURRENCY_CODE::CAD: //Canadian Dollar
		//Do nothing since class is for Indian Currency only
		break;

	case exchanger::CURRENCY_CODE::AUD: //Australian Dollar
		exchangedCurrencyAmount = exchangedCurrencyAmount * 1.10;
		break;

	case exchanger::CURRENCY_CODE::EUR: //Euro
		exchangedCurrencyAmount = exchangedCurrencyAmount * 0.70;
		break;

	default:
		break;
	}

	return exchangedCurrencyAmount;
}