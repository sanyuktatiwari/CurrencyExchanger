/*
 * @file IMoneyConverter.h
 * @brief This is an interface for Money Converter.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#ifndef	__I_MONEY_CONVERTER_H__
#define	__I_MONEY_CONVERTER_H__
#include<string>

class IMoneyConverter
{
public:
	IMoneyConverter() {};
	virtual ~IMoneyConverter() {};
	virtual std::string getBaseCurrencyType() = 0;
	virtual long convertMoney(int type, long balance) = 0;
};
#endif