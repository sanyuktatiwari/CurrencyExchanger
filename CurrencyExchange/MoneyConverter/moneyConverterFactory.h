/*
 * @file moneyConverterFactory.h
 * @brief This is a Factory class to return Instances of appropriate money converters.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include <unordered_map>
#include "IMoneyConverter.h"
#include <string>
class cMoneyConverterFactory
{
public:
	cMoneyConverterFactory();
	~cMoneyConverterFactory();
	IMoneyConverter* createMoneyConverterInstance(int converterID);
};