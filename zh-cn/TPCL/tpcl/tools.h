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
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma once

#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <map>
#include <vector>



using namespace std;


namespace color {
	typedef const int INT;
	INT BLACK = 0;
	INT BLUE = 1;
	INT LIGHTBLUE = 2;
	INT RED = 4;
	INT PURPLE = 5;
	INT YELLOW = 6;
	INT WHITE = 7;
	INT GRAY = 8;
	INT ULTRABULE = 9;
	INT ULTRAGREEN = 10;
	INT ULTRALIGHTBLUE = 11;
	INT ULTRARED = 12;
	INT ULTRAPURPLE = 13;
	INT ULTRAYELLOW = 14;
	INT ULTRAWHITE = 15;
}

namespace stdtool {
	typedef const int INT;
	INT CVM = 1;
	INT ADM = 2;
	class tools {
	public:
		tools();
		~tools();
		char* getTime();
		//write_file function

		bool writeFile(const char* FilePath, const char* STR);
		bool writeFile(const string cFilePath, const string CSTR);
		bool writeFile(const char* FilePath, const string CSTR);
		bool writeFile(const string cFilePath, const char* STR);
		bool writeFile(const string cFilePath, const string CSTR, const int type);

		//password for console

		static void getPwd(string& str, int size);

		vector<string> readFile(const char* FilePath);
		 
		bool setColor(INT color);

		bool bar(const double process);


	private:
		int i = 0;
		int time_num = 0;


		const int DEFAULT = 1;
		const int NONOTICE = 2;
		const int NOANY = 3;


		string notice_str;
		string log_str;
		char* timestramp_tmp = {};
		char* timestramp[1000] = {};


		//private function

		int readini();
		void time_count();
		bool writeFile_q(const string cFilePath, string CSTR, const int type);
	};
}

namespace stdini
{
	class readConfig
	{
	public:
		readConfig()
		{
		}
		~readConfig()
		{
		}
		bool ReadConfig(const string& fileName);
		string ReadString(const char* section, const char* item, const char* default_Value);
		int ReadInt(const char* section, const char* item, const int& default_Value);
		float ReadFloat(const char* section, const char* item, const float& default_Value);
	private:
		bool IsSpace(char c);
		bool IsCommentChar(char c);
		void Trim(string& str);
		bool AnalyseLine(const string& line, string& section, string& key, string& value);
		//std::map<std::string, std::string> settings_;
		map<string, map<string, string> >settings_;
	};
}



namespace network {
	typedef int		BOOL;
	//typedef const string	WORD;

	typedef const char*		CWORD;
	typedef unsigned char       BYTE;
	typedef unsigned long       DWORD;


	class ftp {

	public:
		ftp(){}
		~ftp(){}
		BOOL ftpUpload(CWORD ftpAddress, CWORD fileName, CWORD uploadStr);
		BOOL ftpDownload(CWORD ftpAddress, CWORD ftpFileName);
		BOOL ftpDownload(CWORD ftpAddress, CWORD ftpFileName, CWORD downloadName);

	private:
		BOOL ftpSave(CWORD fileName, BYTE* data, DWORD dataSize);
		BOOL ftpUrlCk(
			CWORD url,
			char* scheme,
			char* hostName,
			char* userName,
			char* pwd,
			char* urlPath,
			char* extraInfo,
			DWORD dwBufferSize);
		BOOL ftpDown(
			CWORD downloadUrl,
			BYTE** downloadData,
			DWORD* downloadDataSize);
		BOOL ftpUp(
			CWORD uploadUrl,
			BYTE* uploadData,
			DWORD uploadDataSize);
	};
}
#endif