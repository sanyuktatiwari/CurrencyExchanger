/**
 * @file CurrencyExchange.cpp
 * @brief This is a Console Application where Authorized Users can login to their Bank via Account details and can know
 * the exchange value of their balance present, in other currencies.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include "currencyExchanger.h"
#include <iostream>
#include <string>
#include "MoneyConverter/moneyConverterFactory.h"
#include "BankServer/bankServerFactory.h"
#include "exchangerDefs.h"

using namespace exchanger;

/**
 * Constructor.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
cCurrencyExchanger::cCurrencyExchanger()
{
	//Initialize Member Variables
	mBankList.clear();
	mExchangerStatus.clear();
	mCurrencyCode.clear();
	mCurrencyType.clear();
	mStatus = "New User";
	mBankListSupportedStr = "";

	//Initialize Maps
	initializeBankListSupported();
	initializeStatusMap();
	initializeBankListString();
	initializeCurrencyCode();
	initializeCurrencyEnum();
}

/**
 * Destructor.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
cCurrencyExchanger::~cCurrencyExchanger()
{

}

/**
 * Function to initialize Map of Banks Supported by the exchanger.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
void cCurrencyExchanger::initializeBankListSupported()
{
	//Banks supported : Citibank, HSBC, Royal Bank.
	mBankList[CITIBANK_1] = "Citibank";
	mBankList[HSBC_2] = "HSBC";
	mBankList[ROYALBANK_3] = "Royal Bank";
}

/**
 * Function to initialize Status Map of exchanger.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
void cCurrencyExchanger::initializeStatusMap()
{
	mExchangerStatus["New User"] = NEW_USER;
	mExchangerStatus["Retry"] = RETRY;
	mExchangerStatus["Log Off"] = LOG_OFF;
}

/**
 * Function to initialize Currency Code map.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
void cCurrencyExchanger::initializeCurrencyCode()
{
	mCurrencyCode[ISD_1] = "ISD"; //Indian Rupee Code
	mCurrencyCode[USD_2] = "USD"; //United States Dollar Code
	mCurrencyCode[CAD_3] = "CAD"; //Canadian Dollar Code
	mCurrencyCode[AUD_4] = "AUD"; //Australian Dollar Code
	mCurrencyCode[EUR_5] = "EUR"; //Euro Code
}

/**
 * Function to initialize Currency types supported by the exchanger.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
void cCurrencyExchanger::initializeCurrencyEnum()
{
	mCurrencyType["Indian Rupee"] = ISD;
	mCurrencyType["USD"] = USD;
	mCurrencyType["Canadian Dollar"] = CAD;
	mCurrencyType["Australian Dollar"] = AUD;
	mCurrencyType["Euro"] = EUR;
}

/**
 * Function of Exchanger, to show account balance in different currencies.
 *
 * @param [IN]	void
 *
 * @return	void.
 */
void cCurrencyExchanger::exchange()
{
	switch (mExchangerStatus[mStatus])
	{
	case NEW_USER:
		if (mBankList.size() > 0)
		{
			bool validIDEntered = false;
			int bankIDSelected;
			long accountNumber;
			std::string password="";
			IBankServer* bank = NULL;

			//Select Bank
			std::cout << "----------Select Your Bank-----------\n";
			std::cout << "To choose your Bank please enter it's ID\n";
			std::cout << "\n" + mBankListSupportedStr + "\n";
			
			while (!validIDEntered)
			{
				std::cin >> bankIDSelected;
				if (mBankList.find(bankIDSelected) != mBankList.end())
				{
					validIDEntered = true;
					cBankServerFactory bankServerFactory;
					bank = bankServerFactory.createBankInstance(bankIDSelected);
					break;
				}
				std::cout << "\n Invalid ID entered, Re-enter";
			}

			//Enter Account Details and do authorization
			std::cout << "----------Enter Account Number-----------\n";
			std::cin >> accountNumber;
			std::cout << "----------Enter Password-----------\n";
			std::cin >> password;

			bool authorizedLogin = false;
			int currencyConversionTypeSelected;
			if (bank != NULL)
			{
				std::cout << "\n Welcome to " + bank->getBankName() + "\n";
				authorizedLogin = bank->isValidAccount(accountNumber, password);
				if (authorizedLogin)
				{
					std::cout << "Authorized User";
					bankStructs::AccounteeInfo info = bank->getAccounteeInfo(accountNumber);
					std::cout << "\n Available Balance : " + std::to_string(info.balance) + info.currencyType;
					std::cout << "\n Select Currency ID to convert your Balance into \n";
					std::cout << "1: Indian Rupee	2: USD	3: Canadian Dollar	 4: Australian Dollar	5:Euro\n";
					std::cin >> currencyConversionTypeSelected;
					IMoneyConverter *converter = NULL;
					cMoneyConverterFactory converterFactory;
					converter = converterFactory.createMoneyConverterInstance(mCurrencyType[info.currencyType]);

					std::cout << "\n Converted Balance:" + std::to_string(converter->convertMoney(currencyConversionTypeSelected, info.balance)) + mCurrencyCode[currencyConversionTypeSelected];
					std::cout << "\n";
				}
				else
				{
					std::cout << "Either the Account number or password entered is wrong. Or you dont have valid account with us...\n\n\n";
					break;
				}
			}

			int nextStep = 0;
			bool validInput = false;
			while (!validInput)
			{
				std::cout << "Please enter ID: Do you want to Retry[1] or LogOff[2]\n";
				std::cin >> nextStep;
				if (nextStep >= 1 && nextStep <= 2)
				{
					validInput = true;
					if (nextStep == 1)
					{
						mStatus = "Retry";
						retryAccountNumber = accountNumber;
						retryBankID = bankIDSelected;
					}
					else if (nextStep == 2)
						mStatus = "Log Off";
					break;
				}
				std::cout << "Invalid ID Entered\n";
			}
		}
		break;

	case RETRY:
	{
		IBankServer* bank = NULL;
		cBankServerFactory bankServerFactory;
		bank = bankServerFactory.createBankInstance(retryBankID);

		int currencyConversionTypeSelected;
		bankStructs::AccounteeInfo info = bank->getAccounteeInfo(retryAccountNumber);

		std::cout << "\n Available Balance : " + std::to_string(info.balance) + info.currencyType;
		std::cout << "\n Select Currency ID to convert your Balance into \n";
		std::cout << "1: Indian Rupee	2: USD	3: Canadian Dollar	 4: Australian Dollar	5:Euro\n";
		std::cin >> currencyConversionTypeSelected;

		IMoneyConverter *converter = NULL;
		cMoneyConverterFactory converterFactory;
		converter = converterFactory.createMoneyConverterInstance(mCurrencyType[info.currencyType]);

		std::cout << "\n Converted Balance:" + std::to_string(converter->convertMoney(currencyConversionTypeSelected, info.balance)) + mCurrencyCode[currencyConversionTypeSelected];
		std::cout << "\n";

		int nextStep = 0;
		bool validInput = false;
		while (!validInput)
		{
			std::cout << "Please enter ID: Do you want to Retry[1] or LogOff[2]\n";
			std::cin >> nextStep;
			if (nextStep >= 1 && nextStep <= 2)
			{
				validInput = true;
				if (nextStep == 1)
				{
					mStatus = "Retry";
				}
				else if (nextStep == 2)
					mStatus = "Log Off";
				break;
			}
			std::cout << "Invalid ID Entered\n";
		}
	}
	break;

	case LOG_OFF:
		mStatus = "New User";
		retryBankID = 0;
		retryAccountNumber = 0;
		std::cout << "\nThe User successfully Logged Off\n\n\n";
		break;

	default:
		break;
	}
}

/**
 * getBankListSupported
 *
 * @param [IN]	void
 *
 * @return	std::unordered_map<int, std::string>
 */
std::unordered_map<int, std::string> cCurrencyExchanger::getBankListSupported()
{
	return mBankList;
}

/**
 * getExchangerStatus
 *
 * @param [IN]	void
 *
 * @return	std::string
 */
std::string cCurrencyExchanger::getExchangerStatus()
{
	return mStatus;
}

/**
 * initializeBankListString
 *
 * @param [IN]	void
 *
 * @return	void
 */
void cCurrencyExchanger::initializeBankListString()
{
	std::unordered_map<int, std::string>::iterator iter = mBankList.begin();
	for (; iter != mBankList.end(); ++iter)
	{
		mBankListSupportedStr += (std::to_string(iter->first) + ": " + iter->second + "		");
	}
}