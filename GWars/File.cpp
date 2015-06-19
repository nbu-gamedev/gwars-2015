#include <string>
#include <stdlib.h>

#include "File.h"

using namespace std;


File::File(string fileInfo)
{
	_splitpath_s(fileInfo.c_str(), this->drive, this->dir, this->name, this->extension);
}

string File::GetDrive()
{
	return this->drive;
}

string File::GetDir()
{
	return this->dir;
}

string File::GetName()
{
	return this->name;
}

string File::GetExtension()
{
	return this->extension;
}


File::~File()
{
	printf("Destroying file %s%s!", this->name, this->extension);
}
