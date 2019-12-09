#pragma once

#include <string>
#include <iostream>

using namespace std;

namespace VTKContour
{
	class LogHelper
	{
		public:
			static void log(const string &errorType, const string &errorMsg);
	};

	void LogHelper::log(const string &errorType, const string &errorMsg)
	{
		cout << "[ " << errorType << " ]: " << errorMsg << endl;
	}
}