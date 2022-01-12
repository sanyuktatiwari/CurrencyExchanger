/*
 * @file europeMoneyConverter.cpp
 * @brief This is a Concrete class to manage Europe Money Converter functionalities.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include "euroMoneyConverter.h"
#include "../exchangerDefs.h"

 /**
	 * Constructor.
	 *
	 * @param [IN]	void
	 *
	 * @return	void.
	 */
cEuroMoneyConverter::cEuroMoneyConverter() :IMoneyConverter()
{

}

/**
 * Destructor.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
cEuroMoneyConverter::~cEuroMoneyConverter()
{

}

/**
 * getBaseCurrencyType : Return Currency Type
 *
 * @param [IN]	void
 *
 * @return	std::string.
 */
std::string cEuroMoneyConverter::getBaseCurrencyType()
{
	return "Euro";
}

/**
 * convertMoney : Function to convert balance amount into exchanged currency value.
 *
 * @param [IN]	int type, long balance
 *
 * @return	long
 */
long cEuroMoneyConverter::convertMoney(int type, long balance)
{
	long exchangedCurrencyAmount = balance;

	switch (type)
	{
	case exchanger::CURRENCY_CODE::ISD: //Indian Rupee
		exchangedCurrencyAmount = exchangedCurrencyAmount * 83.89;
		break;

	case exchanger::CURRENCY_CODE::USD: //USD
		exchangedCurrencyAmount = exchangedCurrencyAmount * 1.14;
		break;

	case exchanger::CURRENCY_CODE::CAD: //Canadian Dollar
		exchangedCurrencyAmount = exchangedCurrencyAmount * 1.43;
		break;

	case exchanger::CURRENCY_CODE::AUD: //Australian Dollar
		exchangedCurrencyAmount = exchangedCurrencyAmount * 1.58;
		break;

	case exchanger::CURRENCY_CODE::EUR: //Euro
		//Do nothing since class is for Indian Currency only
		break;

	default:
		break;
	}

	return exchangedCurrencyAmount;
}