/**
 * @file currencyExchanger.h
 * @brief This is a concrete class to define fuctionalties of Currency Exchanger Application. 
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include <unordered_map>

class cCurrencyExchanger
{
	std::unordered_map<int, std::string> mBankList;
	std::unordered_map<std::string, int> mExchangerStatus;
	std::string mStatus;
	std::string mBankListSupportedStr;
	long retryAccountNumber;
	int retryBankID;
	std::unordered_map<int, std::string> mCurrencyCode;
	std::unordered_map<std::string, int> mCurrencyType;

	void initializeBankListSupported();
	void initializeStatusMap();
	void initializeBankListString();
	void initializeCurrencyCode();
	void initializeCurrencyEnum();

public:
	cCurrencyExchanger();
	~cCurrencyExchanger();
	void exchange();
	std::unordered_map<int, std::string> getBankListSupported();
	std::string getExchangerStatus();
};