/*
 * @file australianMoneyConverter.h
 * @brief This is a Concrete class to manage Australian Money Converter functionalities.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include"IMoneyConverter.h"

class cAusMoneyConverter : public IMoneyConverter
{
public:
	cAusMoneyConverter();
	~cAusMoneyConverter();
	std::string getBaseCurrencyType();
	long convertMoney(int type, long balance);
};