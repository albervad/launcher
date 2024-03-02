#include "apps.h"
#include "launcher.h"
#include <string>
#include <fstream>
#include <windows.h>
#include <ShlObj.h>

using namespace std;

std::string wstring_to_string(const std::wstring& wstr)
{
	std::string str(wstr.begin(), wstr.end());
	return str;
}

bool App::Cargar(const string& file)
{
    ifstream appFile;
    bool carga = false;
    PWSTR ppszPath;
    HRESULT result = SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &ppszPath);

    if (result == S_OK)
    {
        string my_documents = wstring_to_string(ppszPath);

        appFile.open(my_documents + "\\" + file + ".txt");

	    if (appFile.is_open())
	    {
    		string name;
	        getline(appFile, name, '\n');

	        while (name != "XX")
	        {
	            this->name[this->numApps] = name;
	            getline(appFile, this->dir[this->numApps], '\n');
	            getline(appFile, this->args[this->numApps], '\n');
				this->numApps++;
	            getline(appFile, name, '\n');
	        }

	        carga = true;
	        appFile.close();
	    }
    }


    return carga;
}

string App::getName(int n) const
{
	return this->name[n];
}

string App::getDir(int n) const
{
	return this->dir[n];
}

string App::getArgs(int n) const
{
	return this->args[n];
}

int App::getNumApps() const
{
	return this->numApps;
}
