/**
 * @file moneyConverterFactory.cpp
 * @brief This is a Factory Class for Money Converter
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include "moneyConverterFactory.h"
#include "americanMoneyConverter.h"
#include "indianMoneyConverter.h"
#include "australianMoneyConverter.h"
#include "euroMoneyConverter.h"
#include "canadianMoneyConverter.h"
#include "../exchangerDefs.h"

 /**
  * Constructor.
  *
  * @param [IN]	void
  *
  * @return	void.
  */
cMoneyConverterFactory::cMoneyConverterFactory()
{

}

/**
 * Destructor.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
cMoneyConverterFactory::~cMoneyConverterFactory()
{

}

/**
 * createMoneyConverterInstance: Factory Method to create instances of Money Converters
 *
 * @param [IN]	int converterID
 *
 * @return	IMoneyConverter*
 */
IMoneyConverter* cMoneyConverterFactory::createMoneyConverterInstance(int converterID)
{
	IMoneyConverter *converter = NULL;
	switch (converterID)
	{
	case exchanger::CURRENCY_CODE::ISD:
		converter = new cIndianMoneyConverter();
		break;
	case exchanger::CURRENCY_CODE::USD:
		converter = new cAmericanMoneyConverter();
		break;
	case exchanger::CURRENCY_CODE::CAD:
		converter = new cCanadianMoneyConverter();
		break;
	case exchanger::CURRENCY_CODE::AUD:
		converter = new cAusMoneyConverter();
		break;
	case exchanger::CURRENCY_CODE::EUR:
		converter = new cEuroMoneyConverter();
		break;
	default:
		break;
	}
	return converter;
}