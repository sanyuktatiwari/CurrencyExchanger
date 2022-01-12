/*
 * @file indianMoneyConverter.cpp
 * @brief This is a Concrete class to manage Indian Money Converter functionalities.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include "indianMoneyConverter.h"
#include "../exchangerDefs.h"

 /**
 * Constructor.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
cIndianMoneyConverter::cIndianMoneyConverter():IMoneyConverter()
{

}

/**
 * Destructor.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
cIndianMoneyConverter::~cIndianMoneyConverter()
{

}

/**
 * getBaseCurrencyType : Return Currency Type
 *
 * @param [IN]	void
 *
 * @return	std::string.
 */
std::string cIndianMoneyConverter::getBaseCurrencyType()
{
	return "Indian Rupee";
}

/**
 * convertMoney : Function to convert balance amount into exchanged currency value.
 *
 * @param [IN]	int type, long balance
 *
 * @return	long
 */
long cIndianMoneyConverter::convertMoney(int type, long balance)
{
	long exchangedCurrencyAmount = balance;

	switch (type)
	{
	case exchanger::CURRENCY_CODE::ISD: //Indian Rupee
		//Do nothing since class is for Indian Currency only 
		break;

	case exchanger::CURRENCY_CODE::USD: //USD
		exchangedCurrencyAmount = exchangedCurrencyAmount * 0.014;
		break;

	case exchanger::CURRENCY_CODE::CAD: //Canadian Dollar
		exchangedCurrencyAmount = exchangedCurrencyAmount * 0.017;
		break;

	case exchanger::CURRENCY_CODE::AUD: //Australian Dollar
		exchangedCurrencyAmount = exchangedCurrencyAmount * 0.019;
		break;

	case exchanger::CURRENCY_CODE::EUR: //Euro
		exchangedCurrencyAmount = exchangedCurrencyAmount * 0.012;
		break;

	default:
		break;
	}

	return exchangedCurrencyAmount;
}