/*
 * @file indianMoneyConverter.h
 * @brief This is a Concrete class to manage Indian Money Converter functionalities.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include"IMoneyConverter.h"

class cIndianMoneyConverter: public IMoneyConverter
{
public:
	cIndianMoneyConverter();
	~cIndianMoneyConverter();
	std::string getBaseCurrencyType();
	long convertMoney(int type, long balance);
};