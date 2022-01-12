/**
 * @file bankStructs.h
 * @brief This is a file to bank related structures, enums, constants.
 *
 * @date	2022-01-09
 *
 * @authors Sanyukta Tiwari
 */

#include <string>

namespace bankStructs
{
	struct AccounteeInfo
	{
		std::string password;
		std::string currencyType;
		long balance;
	};
}
