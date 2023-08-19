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
#include "tools.h"





#include <conio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include <WinInet.h>
#pragma comment(lib, "WinInet.lib")






#define INIFILE "config.ini"



using namespace std::chrono;








//Check config

int stdtool::tools::readini()
{
	stdini::readConfig ri;
	bool ret = ri.ReadConfig(INIFILE);
	if (ret == false) {
		cout << "Cannot read the config file :\t" << INIFILE << "\nUsing default config." << endl;
		return DEFAULT;
	}
	string i = ri.ReadString("NOTICE_OUTPUT", "Config", "");
	if (i == "DEFAULT" || "default") {
		return DEFAULT;
	}
	else if (i == "NONOTICE" || "nonotice") {
		return NONOTICE;
	}
	else if (i == "NOANY" || "noany") {
		return NOANY;
	}
	else {
		return DEFAULT;
	}
}




void stdtool::tools::time_count()
{
	timestramp_tmp = stdtool::tools::getTime();
	time_num = 0;
	time_num++;

	timestramp[time_num] = *timestramp;
}

stdtool::tools::tools()
{
	
}

stdtool::tools::~tools()
{
}

char* stdtool::tools::getTime()
{
	system_clock::time_point now = system_clock::now();

	chrono::nanoseconds d = now.time_since_epoch();

	chrono::microseconds mcrosec = chrono::duration_cast<chrono::microseconds>(d);

	chrono::milliseconds millsec = chrono::duration_cast<chrono::milliseconds>(d);

	chrono::seconds sec = chrono::duration_cast<chrono::seconds>(d);

	chrono::minutes minutes = chrono::duration_cast<chrono::minutes>(d);

	chrono::hours hours = chrono::duration_cast<chrono::hours>(d);

	typedef chrono::duration<int, ratio<24 * 60 * 60>> Day;
	Day days = chrono::duration_cast<Day>(d);

	time_t tt = system_clock::to_time_t(now);

	auto timed = ctime(&tt);
	i = 0;
	while (timed[i] != '\n') {
		i++;
	}
	timed[i] = '\0';
	return timed;
}

ifstream ifs;
ofstream ofs;





//string to LPCWSTR Function

LPCWSTR stringToLPCWSTR(string origin)
{
	size_t origsize = origin.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t* wcstring = new wchar_t[sizeof(wchar_t) * (origin.length() - 1)];
	mbstowcs_s(&convertedChars, wcstring, origsize, origin.c_str(), _TRUNCATE);
	return wcstring;
}




//Write File Function
bool stdtool::tools::writeFile(const char* FilePath, const char* STR)
{
	notice_str = (string)"[" + FilePath + (string)"]" + (string)" already exists!!! \nWant to cover it?";
	LPCSTR NSTR = notice_str.c_str();
	//LPCWSTR NSTR = stringToLPCWSTR(notice_str);
	time_count();
	ifs.open(FilePath);
	if (ifs.is_open()) {
		int a = MessageBox(NULL,NSTR , TEXT("Notice"), MB_ICONINFORMATION | MB_OKCANCEL);
		if (a == IDCANCEL) {
			MessageBox(NULL, TEXT("Please choose another file name!!!"), TEXT("Notice"), MB_ICONINFORMATION | MB_OK);
			cout << "File output terminates." << endl;
			return true;
		}
	}
	ifs.close();

	ofs.open(FilePath, ios_base::out | ios_base::app);
	ofs << STR;
	ofs.close();

	cout << "File Output Successfully" << endl;

	//delete cache
	delete NSTR;
	NSTR = nullptr;

	return false;
}

bool stdtool::tools::writeFile(const string cFilePath, const string CSTR)
{
	notice_str = (string)"[" + cFilePath + (string)"]" + (string)" already exists!!! \nWant to cover it?";
	LPCSTR NSTR= notice_str.c_str();
	//LPCWSTR NSTR = stringToLPCWSTR(notice_str);
	time_count();
	ifs.open(cFilePath);
	if (ifs.is_open()) {
		int a = MessageBox(NULL, NSTR, TEXT("Notice"), MB_ICONINFORMATION | MB_OKCANCEL);
		if (a == IDCANCEL) {
			MessageBox(NULL, TEXT("Please choose another file name!!!"), TEXT("Notice"), MB_ICONINFORMATION | MB_OK);
			cout << "File output terminates." << endl;
			return true;
		}
	}
	ifs.close();

	ofs.open(cFilePath, ios_base::out | ios_base::app);
	ofs << CSTR;
	ofs.close();

	//delete cache
	cout << "File Output Successfully" << endl;

	delete NSTR;
	NSTR = nullptr;

	return false;
}

bool stdtool::tools::writeFile(const char* FilePath, const string CSTR)
{
	notice_str = (string)"[" + FilePath + (string)"]" + (string)" already exists!!! \nWant to cover it?";
	LPCSTR NSTR = notice_str.c_str();
	//LPCWSTR NSTR = stringToLPCWSTR(notice_str);
	ifs.open(FilePath);
	if (ifs.is_open()) {
		int a = MessageBox(NULL, NSTR, TEXT("Notice"), MB_ICONINFORMATION | MB_OKCANCEL);
		if (a == IDCANCEL) {
			MessageBox(NULL, TEXT("Please choose another file name!!!"), TEXT("Notice"), MB_ICONINFORMATION | MB_OK);
			cout << "File output terminates." << endl;
			return true;
		}
	}
	ifs.close();

	ofs.open(FilePath, ios_base::out | ios_base::app);
	ofs << CSTR;
	ofs.close();

	cout << "File Output Successfully" << endl;

	//delete
	delete NSTR;
	NSTR = nullptr;

	return false;
}

bool stdtool::tools::writeFile(const string cFilePath, const char* STR)
{
	notice_str = (string)"[" + cFilePath + (string)"]" + (string)" already exists!!! \nWant to cover it?";
	LPCSTR NSTR = notice_str.c_str();
	//LPCWSTR NSTR = stringToLPCWSTR(notice_str);
	time_count();
	ifs.open(cFilePath);
	if (ifs.is_open()) {
		int a = MessageBox(NULL, NSTR, TEXT("Notice"), MB_ICONINFORMATION | MB_OKCANCEL);
		if (a == IDCANCEL) {
			MessageBox(NULL, TEXT("Please choose another file name!!!"), TEXT("Notice"), MB_ICONINFORMATION | MB_OK);
			cout << "File output terminates." << endl;
			return true;
		}
	}
	ifs.close();

	ofs.open(cFilePath, ios_base::out | ios_base::app);
	ofs << STR;
	ofs.close();

	cout << "File Output Successfully" << endl;

	//delete cache
	delete NSTR;
	NSTR = nullptr;

	return false;
}

bool stdtool::tools::writeFile(const string cFilePath, string CSTR, const int type)
{
	writeFile_q(cFilePath, CSTR, type);
	return false;
}


bool stdtool::tools::writeFile_q(string cFilePath, string CSTR, const int type) {
	time_count();
	
	if (type == ADM) {
		ofs.open(cFilePath, ios_base::out | ios_base::app);
		ofs << CSTR;
	}
	else if (type == CVM) {
		ofs.open(cFilePath, ios_base::out);
		ofs << CSTR;
	}
	ofs.close();
	return false;
}



void stdtool::tools::getPwd(string& str, int size)
{
	char c;
	int count = 0;
	char* password = new char[size];
	while ((c = getch()) != '\r') {

		if (c == 8) {
			if (count == 0) {
				continue;
			}
			putchar('\b');
			putchar(' ');
			putchar('\b');
			count--;
		}
		if (count == size - 1) {
			continue;
		}
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
			putchar('*');
			password[count] = c;
			count++;
		}
	}
	password[count] = '\0';
	str = password;
	delete[] password; // delete cache
	cout << endl;
}

vector<string> stdtool::tools::readFile(const char* FilePath)
{

	vector<string> vArray;
	string temp;
	ifs.open(FilePath);
	
	if (!ifs.is_open()) {
		string str = FilePath + (string)" is not found!!!";
		LPCSTR NSTR = str.c_str();
		//LPCWSTR NSTR = stringToLPCWSTR(str);
		MessageBox(NULL, NSTR, TEXT("FATAL ERROR"), MB_ICONINFORMATION | MB_OK);
		return vArray;
	}
	
	

	while (!ifs.eof()) {
		while (getline(ifs, temp)) {
			vArray.push_back(temp+'\n');
		}
	}
	return vArray;
}

bool stdtool::tools::setColor(INT color)
{
	if (color >= 0 && color <= 15) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	return false;
}

bool stdtool::tools::bar(const double process)
{
	int block = 100;
	if (process >= 100) {
		cout << "\rProcessed![100%]";
		for (int i = 0; i <= 100; i++) {
			std::cout << "█";
			Sleep(15);
		}
	}
	else
	{
		cout << "\rProcessing[" << setw(5) << setprecision(4) << process << "%]";
		for (int i = 0; i <= (int)process; i++) {
			std::cout << "█";
			Sleep(15);
		}
	}
	return false;
}




bool stdini::readConfig::IsSpace(char c)
{
	if (' ' == c || '\t' == c)
		return true;
	return false;
}

bool stdini::readConfig::IsCommentChar(char c)
{
	switch (c) {
	case '#':
		return true;
	default:
		return false;
	}
}

void stdini::readConfig::Trim(string& str)
{
	if (str.empty())
	{
		return;
	}
	int i, start_pos, end_pos;
	for (i = 0; i < str.size(); ++i) {
		if (!IsSpace(str[i])) {
			break;
		}
	}
	if (i == str.size())
	{
		str = "";
		return;
	}
	start_pos = i;
	for (i = str.size() - 1; i >= 0; --i) {
		if (!IsSpace(str[i])) {
			break;
		}
	}
	end_pos = i;
	str = str.substr(start_pos, end_pos - start_pos + 1);
}

bool stdini::readConfig::AnalyseLine(const string& line, string& section, string& key, string& value)
{
	if (line.empty())
		return false;
	int start_pos = 0, end_pos = line.size() - 1, pos, s_startpos, s_endpos;
	if ((pos = line.find("#")) != -1)
	{
		if (0 == pos)
		{
			return false;
		}
		end_pos = pos - 1;
	}
	if (((s_startpos = line.find("[")) != -1) && ((s_endpos = line.find("]"))) != -1)
	{
		section = line.substr(s_startpos + 1, s_endpos - 1);
		return true;
	}
	std::string new_line = line.substr(start_pos, start_pos + 1 - end_pos);
	if ((pos = new_line.find('=')) == -1)
		return false;
	key = new_line.substr(0, pos);
	value = new_line.substr(pos + 1, end_pos + 1 - (pos + 1));
	Trim(key);
	if (key.empty()) {
		return false;
	}
	Trim(value);
	if ((pos = value.find("\r")) > 0)
	{
		value.replace(pos, 1, "");
	}
	if ((pos = value.find("\n")) > 0)
	{
		value.replace(pos, 1, "");
	}
	return true;
}

bool stdini::readConfig::ReadConfig(const string& fileName)
{
	settings_.clear();
	ifstream infile(fileName.c_str());//The constructor calls open by default, so you can omit it
	//std::ifstream infile;
	//infile.open(fileName.c_str());
	//bool ret = infile.is_open()
	if (!infile) {
		return false;
	}
	string line, key, value, section;
	map<string, string> k_v;
	map<string, map<string, string> >::iterator it;
	while (getline(infile, line))
	{
		if (AnalyseLine(line, section, key, value))
		{
			it = settings_.find(section);
			if (it != settings_.end())
			{
				k_v[key] = value;
				it->second = k_v;
			}
			else
			{
				k_v.clear();
				settings_.insert(std::make_pair(section, k_v));
			}
		}
		key.clear();
		value.clear();
	}
	infile.close();
	return true;
}

string stdini::readConfig::ReadString(const char* section, const char* item, const char* default_Value)
{
	string tmp_s(section);
	string tmp_i(item);
	string def(default_Value);
	map<string, string> k_v;
	map<string, string>::iterator it_item;
	map<string, map<string, string> >::iterator it;
	it = settings_.find(tmp_s);
	if (it == settings_.end())
	{
		return def;
	}
	k_v = it->second;
	it_item = k_v.find(tmp_i);
	if (it_item == k_v.end())
	{
		return def;
	}
	return it_item->second;
}

int stdini::readConfig::ReadInt(const char* section, const char* item, const int& default_Value)
{
	string tmp_s(section);
	string tmp_i(item);
	map<string, string> k_v;
	map<string, string>::iterator it_item;
	map<string, map<string, string> >::iterator it;
	it = settings_.find(tmp_s);
	if (it == settings_.end())
	{
		return default_Value;
	}
	k_v = it->second;
	it_item = k_v.find(tmp_i);
	if (it_item == k_v.end())
	{
		return default_Value;
	}
	return atoi(it_item->second.c_str());
}

float stdini::readConfig::ReadFloat(const char* section, const char* item, const float& default_Value)
{
	string tmp_s(section);
	string tmp_i(item);
	map<string, string> k_v;
	map<string, string>::iterator it_item;
	map<string, map<string, string> >::iterator it;
	it = settings_.find(tmp_s);
	if (it == settings_.end())
	{
		return default_Value;
	}
	k_v = it->second;
	it_item = k_v.find(tmp_i);
	if (it_item == k_v.end())
	{
		return default_Value;
	}
	return atof(it_item->second.c_str());
}


void ftpShowError(const char* text)
{
	char szErr[MAX_PATH] = { 0 };
	::wsprintf(szErr, "%s Error[%d]\n", text, ::GetLastError());
#ifdef _DEBUG
	::MessageBox(NULL, szErr, "ERROR", MB_OK);
#endif
}


BOOL network::ftp::ftpUpload(CWORD ftpAddress, CWORD fileName, CWORD uploadStr)
{	
	char* fullUrl = new char[strlen(ftpAddress) + strlen(fileName)+3];
	strcpy(fullUrl, ftpAddress);
	strcat(fullUrl, "/");
	strcat(fullUrl, fileName);
	if (FALSE == ftpUp(fullUrl, (BYTE*)uploadStr, strlen(uploadStr)))
	{
		cout << "FTP Upload Error." << endl;
	}

	cout << "FTP Upload OK." << endl;
	system("pause");
	delete[]fullUrl;
	return 0;
}

BOOL network::ftp::ftpDownload(CWORD ftpAddress, CWORD ftpFileName)
{
	BYTE* pDownloadData = NULL;
	DWORD dwDownloadDataSize = 0;
	char* fullUrl = new char[strlen(ftpAddress) + strlen(ftpFileName) + 3];
	strcpy(fullUrl, ftpAddress);
	strcat(fullUrl, "/");
	strcat(fullUrl, ftpFileName);

	if (FALSE == ftpDown(fullUrl, &pDownloadData, &dwDownloadDataSize))
	{
		cout << "FTP Download Error!" << endl;
	}
	
	ftpSave(ftpFileName, pDownloadData, dwDownloadDataSize);
	
	delete[]pDownloadData;
	pDownloadData = NULL;
	cout << "FTP Download OK." << endl;
	system("pause");
	delete[]fullUrl;
	return 0;
}

BOOL network::ftp::ftpDownload(CWORD ftpAddress, CWORD ftpFileName, CWORD downloadName)
{
	BYTE* pDownloadData = NULL;
	DWORD dwDownloadDataSize = 0;
	char* fullUrl = new char[strlen(ftpAddress) + strlen(ftpFileName) + 3];
	strcpy(fullUrl, ftpAddress);
	strcat(fullUrl, "/");
	strcat(fullUrl, ftpFileName);

	if (FALSE == ftpDown(fullUrl, &pDownloadData, &dwDownloadDataSize))
	{
		cout << "FTP Download Error!" << endl;
	}

	ftpSave(downloadName, pDownloadData, dwDownloadDataSize);

	delete[]pDownloadData;
	pDownloadData = NULL;
	cout << "FTP Download OK." << endl;
	system("pause");
	delete[]fullUrl;
	return 0;
}

BOOL network::ftp::ftpSave(CWORD fileName, BYTE* data, DWORD dataSize)
{
	HANDLE hFile = ::CreateFile(fileName, GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_ARCHIVE, NULL);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		ftpShowError("CreateFile");
		return FALSE;
	}

	DWORD dwRet = 0;
	::WriteFile(hFile, data, dataSize, &dwRet, NULL);

	::CloseHandle(hFile);
	return TRUE;
}

BOOL network::ftp::ftpUrlCk(CWORD url, char* scheme, char* hostName, char* userName, char* pwd, char* urlPath, char* extraInfo, DWORD bufferSize)
{
	BOOL bRet = FALSE;
	URL_COMPONENTS uc = { 0 };

	::RtlZeroMemory(&uc, sizeof(uc));
	::RtlZeroMemory(scheme, bufferSize);
	::RtlZeroMemory(hostName, bufferSize);
	::RtlZeroMemory(userName, bufferSize);
	::RtlZeroMemory(pwd, bufferSize);
	::RtlZeroMemory(urlPath, bufferSize);
	::RtlZeroMemory(extraInfo, bufferSize);

	uc.dwStructSize = sizeof(uc);
	uc.dwSchemeLength = bufferSize - 1;
	uc.dwHostNameLength = bufferSize - 1;
	uc.dwUserNameLength = bufferSize - 1;
	uc.dwPasswordLength = bufferSize - 1;
	uc.dwUrlPathLength = bufferSize - 1;
	uc.dwExtraInfoLength = bufferSize - 1;
	uc.lpszScheme = scheme;
	uc.lpszHostName = hostName;
	uc.lpszUserName = userName;
	uc.lpszPassword = pwd;
	uc.lpszUrlPath = urlPath;
	uc.lpszExtraInfo = extraInfo;

	bRet = ::InternetCrackUrl(url, 0, 0, &uc);
	if (FALSE == bRet)
	{
		ftpShowError("InternetCrackUrl");
		return bRet;
	}

	return bRet;
}

BOOL network::ftp::ftpDown(CWORD downloadUrl, BYTE** downloadData, DWORD* downloadDataSize)
{
	char scheme[MAX_PATH] = { 0 };
	char hostName[MAX_PATH] = { 0 };
	char userName[MAX_PATH] = { 0 };
	char pwd[MAX_PATH] = { 0 };
	char urlPath[MAX_PATH] = { 0 };
	char extraInfo[MAX_PATH] = { 0 };
	::RtlZeroMemory(scheme, MAX_PATH);
	::RtlZeroMemory(hostName, MAX_PATH);
	::RtlZeroMemory(userName, MAX_PATH);
	::RtlZeroMemory(pwd, MAX_PATH);
	::RtlZeroMemory(urlPath, MAX_PATH);
	::RtlZeroMemory(extraInfo, MAX_PATH);
	
	if (FALSE == ftpUrlCk(downloadUrl, scheme, hostName, userName, pwd, urlPath, extraInfo, MAX_PATH))
	{
		return FALSE;
	}
	if (0 < ::lstrlen(extraInfo))
	{
		
		::lstrcat(urlPath, extraInfo);
	}

	HINTERNET hInternet = NULL;
	HINTERNET hConnect = NULL;
	HINTERNET hFTPFile = NULL;
	BYTE* pDownloadData = NULL;
	DWORD dwDownloadDataSize = 0;
	DWORD dwBufferSize = 4096;
	BYTE* pBuf = NULL;
	DWORD dwBytesReturn = 0;
	DWORD dwOffset = 0;
	BOOL bRet = FALSE;

	do
	{
		
		hInternet = ::InternetOpen("WinInet Ftp Download V1.0", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
		if (NULL == hInternet)
		{
			ftpShowError("InternetOpen");
			break;
		}
		
		hConnect = ::InternetConnect(hInternet, hostName, INTERNET_INVALID_PORT_NUMBER, userName, pwd, INTERNET_SERVICE_FTP, INTERNET_FLAG_PASSIVE, 0);
		if (NULL == hConnect)
		{
			ftpShowError("InternetConnect");
			break;
		}

		hFTPFile = ::FtpOpenFile(hConnect, urlPath, GENERIC_READ, FTP_TRANSFER_TYPE_BINARY | INTERNET_FLAG_RELOAD, NULL);
		if (NULL == hFTPFile)
		{
			ftpShowError("FtpOpenFile");
			break;;
		}

		dwDownloadDataSize = ::FtpGetFileSize(hFTPFile, NULL);

		pDownloadData = new BYTE[dwDownloadDataSize];
		if (NULL == pDownloadData)
		{
			break;
		}
		::RtlZeroMemory(pDownloadData, dwDownloadDataSize);
		pBuf = new BYTE[dwBufferSize];
		if (NULL == pBuf)
		{
			break;
		}
		::RtlZeroMemory(pBuf, dwBufferSize);

		do
		{
			bRet = ::InternetReadFile(hFTPFile, pBuf, dwBufferSize, &dwBytesReturn);
			if (FALSE == bRet)
			{
				ftpShowError("InternetReadFile");
				break;
			}
			::RtlCopyMemory((pDownloadData + dwOffset), pBuf, dwBytesReturn);
			dwOffset = dwOffset + dwBytesReturn;

		} while (dwDownloadDataSize > dwOffset);

	} while (FALSE);

	if (FALSE == bRet)
	{
		delete[]pDownloadData;
		pDownloadData = NULL;
		dwDownloadDataSize = 0;
	}
	*downloadData = pDownloadData;
	*downloadDataSize = dwDownloadDataSize;

	if (NULL != pBuf)
	{
		delete[]pBuf;
		pBuf = NULL;
	}
	if (NULL != hFTPFile)
	{
		::InternetCloseHandle(hFTPFile);
	}
	if (NULL != hConnect)
	{
		::InternetCloseHandle(hConnect);
	}
	if (NULL != hInternet)
	{
		::InternetCloseHandle(hInternet);
	}

	return bRet;
}

BOOL network::ftp::ftpUp(CWORD uploadUrl, BYTE* uploadData, DWORD uploadDataSize)
{
	char scheme[MAX_PATH] = { 0 };
	char hostName[MAX_PATH] = { 0 };
	char userName[MAX_PATH] = { 0 };
	char pwd[MAX_PATH] = { 0 };
	char urlPath[MAX_PATH] = { 0 };
	char extraInfo[MAX_PATH] = { 0 };
	::RtlZeroMemory(scheme, MAX_PATH);
	::RtlZeroMemory(hostName, MAX_PATH);
	::RtlZeroMemory(userName, MAX_PATH);
	::RtlZeroMemory(pwd, MAX_PATH);
	::RtlZeroMemory(urlPath, MAX_PATH);
	::RtlZeroMemory(extraInfo, MAX_PATH);
	
	if (FALSE == ftpUrlCk(uploadUrl, scheme, hostName, userName, pwd, urlPath, extraInfo, MAX_PATH))
	{
		return FALSE;
	}
	if (0 < ::lstrlen(extraInfo))
	{

		::lstrcat(urlPath, extraInfo);
	}

	HINTERNET hInternet = NULL;
	HINTERNET hConnect = NULL;
	HINTERNET hFTPFile = NULL;
	DWORD dwBytesReturn = 0;
	BOOL bRet = FALSE;

	do
	{
		
		hInternet = ::InternetOpen("WinInet Ftp Upload V1.0", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
		if (NULL == hInternet)
		{
			ftpShowError("InternetOpen");
			break;
		}
		
		hConnect = ::InternetConnect(hInternet, hostName, INTERNET_INVALID_PORT_NUMBER, userName, pwd, INTERNET_SERVICE_FTP, INTERNET_FLAG_PASSIVE, 0);
		if (NULL == hConnect)
		{
			ftpShowError("InternetConnect");
			break;
		}
		
		hFTPFile = ::FtpOpenFile(hConnect, urlPath, GENERIC_WRITE, FTP_TRANSFER_TYPE_BINARY | INTERNET_FLAG_RELOAD, NULL);
		if (NULL == hFTPFile)
		{
			ftpShowError("FtpOpenFile");
			break;;
		}
		
		bRet = ::InternetWriteFile(hFTPFile, uploadData, uploadDataSize, &dwBytesReturn);
		if (FALSE == bRet)
		{
			break;
		}

	} while (FALSE);

	
	if (NULL != hFTPFile)
	{
		::InternetCloseHandle(hFTPFile);
	}
	if (NULL != hConnect)
	{
		::InternetCloseHandle(hConnect);
	}
	if (NULL != hInternet)
	{
		::InternetCloseHandle(hInternet);
	}

	return bRet;
}
