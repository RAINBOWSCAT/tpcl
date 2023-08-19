/*  Tools Class Library(Version:ALPHA - 0.0.1.8672) ALPHA TEST VERSION
	ALPHA TEST
	PUBLISH BY RAINBOWSCAT
	TPCL Copyright (C) 2023-2024 RAINBOWSCAT. All rights reserved.
	Author: RAINBOWSCAT  <whitecat.this@gmail.com>
	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	http ://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
	Description:



	Create:2023.5.23
*/

#define _CRT_SECURE_NO_WARNINGS
#pragma once


#ifndef ERRORM_H
#define ERRORM_H



#include<iostream>


using namespace std;
typedef const int DEFINE;
typedef const string DEFINE_S;

namespace err {
	class error {
		//system code
		DEFINE_S nStr = "";

		DEFINE FRW_FATAL_ERROR = 1;
		DEFINE OVC_FATAL_ERROR = 2;
		DEFINE ARU_FATAL_ERROR = 3;
		DEFINE UCV_FATAL_ERROR = 4;
		DEFINE SYS_FATAL_ERROR = 5;
		DEFINE CAC_FATAL_ERROR = 6;

		DEFINE_S FRW_FATAL_ERROR_S = "FRW_FATAL_ERROR";
		DEFINE_S OVC_FATAL_ERROR_S = "OVC_FATAL_ERROR";
		DEFINE_S ARU_FATAL_ERROR_S = "ARU_FATAL_ERROR";
		DEFINE_S UCV_FATAL_ERROR_S = "UCV_FATAL_ERROR";
		DEFINE_S SYS_FATAL_ERROR_S = "SYS_FATAL_ERROR";
		DEFINE_S CAC_FATAL_ERROR_S = "CAC_FATAL_ERROR";

		bool dirExists(DEFINE_S& dirName_in);

		DEFINE_S typeF(DEFINE& TYPE);
		
	public:
		//public code

		DEFINE WARNING = 7;
		DEFINE ERROR = 8;
		DEFINE FATAL = 9;

		DEFINE_S WARNING_S = "WARNING";
		DEFINE_S ERROR_S = "ERROR";
		DEFINE_S FATAL_S = "FATAL";


		error() {};
		error(DEFINE_S& message, DEFINE& TYPE);
		~error();

		bool write_log(DEFINE_S& messageOut, DEFINE& level);

	};
}









#endif