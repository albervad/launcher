#include "apps.h"
#include "launcher.h"
#include <string>
#include <fstream>

using namespace std;

bool App::Cargar(const string& file)
{
    ifstream appFile;
    bool carga = false;
    const string user = string(getenv("username"));
    

    appFile.open("C:/Users/" + user + "/Documents/" + file + ".txt");

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
