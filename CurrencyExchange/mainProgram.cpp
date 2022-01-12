/**
 * @file mainProgram.cpp
 * @brief This file contains the 'main' function. Program execution begins and ends here.
 * This is a Console Application where Authorized Users can login to their Bank via Account details and can know
 * the exchange value of their balance present, in other currencies.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include <iostream>
#include "currencyExchanger.h"

int main()
{
	cCurrencyExchanger *exchanger = new cCurrencyExchanger();
	std::unordered_map<int, std::string> mBankSupported;

	if (exchanger != NULL)
	{
		mBankSupported = exchanger->getBankListSupported();

		while (exchanger != NULL && mBankSupported.size() != 0)
		{
			exchanger->exchange();
		}
	}

	if (exchanger == NULL)
	{
		std::cout << "The Application Failed to open";
	}
	else if (mBankSupported.size() == 0)
	{
		std::cout << "No Bank yet added with this exchanger";
	}
	delete exchanger;
}