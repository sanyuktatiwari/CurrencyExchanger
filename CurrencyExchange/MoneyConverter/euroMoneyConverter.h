/*
 * @file europeMoneyConverter.h
 * @brief This is a Concrete class to manage Europe Money Converter functionalities.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include"IMoneyConverter.h"

class cEuroMoneyConverter : public IMoneyConverter
{
public:
	cEuroMoneyConverter();
	~cEuroMoneyConverter();
	std::string getBaseCurrencyType();
	long convertMoney(int type, long balance);
};