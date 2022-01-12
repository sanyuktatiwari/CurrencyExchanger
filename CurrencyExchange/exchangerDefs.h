/**
 * @file exchangerDefs.h
 * @brief This is a file to maintain different definitions, namespace, structs, constants, enums for Exchanger code.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

namespace exchanger
{
	enum EXCHANGER_STATUS
	{
		NEW_USER = 1,
		RETRY,
		LOG_OFF
	};

	enum BANK_ID
	{
		CITIBANK_1 = 1,
		HSBC_2,
		ROYALBANK_3
	};

	enum CURRENCY_CODE_ID
	{
		ISD_1 = 1,
		USD_2,
		CAD_3,
		AUD_4,
		EUR_5
	};

	enum CURRENCY_CODE
	{
		ISD = 1,
		USD,
		CAD,
		AUD,
		EUR
	};
}