/*
 * @file canadianMoneyConverter.h
 * @brief This is a Concrete class to manage Canadian Money Converter functionalities.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include"IMoneyConverter.h"

class cCanadianMoneyConverter : public IMoneyConverter
{
public:
	cCanadianMoneyConverter();
	~cCanadianMoneyConverter();
	std::string getBaseCurrencyType();
	long convertMoney(int type, long balance);
};