/*
 * @file americanMoneyConverter.h
 * @brief This is a Concrete class to manage American Money Converter functionalities.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include"IMoneyConverter.h"

class cAmericanMoneyConverter : public IMoneyConverter
{
public:
	cAmericanMoneyConverter();
	~cAmericanMoneyConverter();
	std::string getBaseCurrencyType();
	long convertMoney(int type, long balance);
};