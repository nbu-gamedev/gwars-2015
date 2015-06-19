#pragma once
#include <string>
#include <stdlib.h>

using namespace std;

class File
{
public:
	File();
	File(string fileInfo);
	
	string GetDrive();
	string GetDir();
	string GetName();
	string GetExtension();

	~File();
private:
   char drive[_MAX_DRIVE];
   char dir[_MAX_DIR];
   char name[_MAX_FNAME];
   char extension[_MAX_EXT];
};