#pragma once
#include <string>

class App
{
private:
	std::string AppsFile;
	std::string name[50];
	std::string dir[50];
	std::string args[50];
	int numApps = 0;
public:
	bool Cargar(const std::string& file);
	std::string getName(int n) const;
	std::string getDir(int n) const;
	std::string getArgs(int n) const;
	std::string getAppsFile() const;
	int getNumApps() const;
};