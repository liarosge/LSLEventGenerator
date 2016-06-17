// LSLEventGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lsl_cpp.h"
#include <stdio.h>
#include <string>
#include <tchar.h>
#include <iostream>
#include <functional>

using namespace std;

lsl::stream_info info("EventStream", "Markers", 1, lsl::IRREGULAR_RATE, lsl::cf_int32, "myuniquesourceid23443");
lsl::stream_outlet outlet(info);
int main()
{
	for (std::string line; getline(cin, line);) {
		if (line.length() > 0)
		{
			if (line == "exit")
			{
				break;
			}
			else if (line[0] == '#')
			{
				string code = line.substr(1, line.length() - 1);
				string::const_iterator it = code.begin();
				while (it != code.end() && isdigit(*it)) ++it;
				if (!code.empty() && it == code.end()) {
					int a = std::stoi(code);
					outlet.push_sample(&code);
					cout << "[Info] Sent event: " << a << endl;
				}
				else {
					cout << "[Error] Numeric value expected" << endl;
				}
			}
			else {
				cout << "[Error] Unrecognized command" << endl;
			}
		}
	}
    return 0;
}

