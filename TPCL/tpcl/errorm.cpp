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

#include "errorm.h"

#include <fstream>
#include <Windows.h>
#include <ctime>


 

ifstream infs;
ofstream outfs;




LPCWSTR estringToLPCWSTR(string origin)
{
	size_t origsize = origin.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t* wcstring = new wchar_t[sizeof(wchar_t) * (origin.length() - 1)];
	mbstowcs_s(&convertedChars, wcstring, origsize, origin.c_str(), _TRUNCATE);
	return wcstring;
}

bool err::error::dirExists(DEFINE_S& dirName_in)
{
	DWORD ft = GetFileAttributesA(dirName_in.c_str());
	if (ft == INVALID_FILE_ATTRIBUTES)
		return true;  //something is wrong with your path!

	if (ft & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}

DEFINE_S err::error::typeF(DEFINE& TYPE) {
	string error_type;
	switch (TYPE)
	{
	case 1:
		error_type = FRW_FATAL_ERROR_S;
		break;
	case 2:
		error_type = OVC_FATAL_ERROR_S;
		break;
	case 3:
		error_type = ARU_FATAL_ERROR_S;
		break;
	case 4:
		error_type = UCV_FATAL_ERROR_S;
		break;
	case 5:
		error_type = SYS_FATAL_ERROR_S;
		break;
	case 6:
		error_type = CAC_FATAL_ERROR_S;
		break;
	case 7:
		error_type = WARNING_S;
		break;
	case 8:
		error_type = ERROR_S;
		break;
	case 9:
		error_type = FATAL_S;
		break;
	default:
		error_type = WARNING_S;
		break;
	}
	return error_type;
}



err::error::error(DEFINE_S& message, DEFINE& TYPE)
{
	DEFINE_S error_type = typeF(TYPE);

	//LPCWSTR MESSAGE = estringToLPCWSTR(message+"\nError Code:  " + error_type);
	char* MESSAGE = new char[strlen(message.c_str()) + strlen(error_type.c_str()) + 16];
	strcpy(MESSAGE, message.c_str());
	strcpy(MESSAGE, "\nError Code:  ");
	strcpy(MESSAGE, error_type.c_str());
	MessageBox(NULL, MESSAGE, TEXT("From System"), MB_OK | MB_ICONERROR);
	delete[]MESSAGE;
}

err::error::~error()
{
}

bool err::error::write_log(DEFINE_S& messageOut,DEFINE& level)
{
	time_t now = time(nullptr);
	tm* timec_t = localtime(&now);
	char timec[100] = { 0 };
	strftime(timec, 100, "%Y-%m-%d %H", timec_t);



	const char* direc = ".\\log";
	string direcS = ".\\log";


	if (dirExists(direcS)) {

		bool flag = CreateDirectory(direc, NULL);
		if (flag == 0) {
			DEFINE_S nStr = "The directory already exists or has a fatal read/write error!!!";
			error(nStr, WARNING);
		}
	}

	DEFINE_S LOG_PATH = direcS + '\\' + timec + (string)".log";
	
	
	char time_full[100] = { 0 };
	strftime(time_full, 100, "%Y-%m-%d %H:%M:%S",timec_t);

	outfs.open(LOG_PATH, ios_base::out | ios_base::app);
	outfs << "[" << time_full << "]" << " \t" << "(" << typeF(level) << ")" << "\t" << messageOut << endl;

	outfs.open(LOG_PATH, ios_base::out);
	outfs.close();
	return false;
}
