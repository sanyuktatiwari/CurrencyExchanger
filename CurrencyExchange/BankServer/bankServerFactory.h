/*
 * @file bankServerFactory.h
 * @brief This is a Factory class to return Instances of appropriate bank servers.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include <unordered_map>
#include "IBankServer.h"
#include <string>
class cBankServerFactory
{
public:
	cBankServerFactory();
	~cBankServerFactory();
	IBankServer* createBankInstance(int bankID);
};