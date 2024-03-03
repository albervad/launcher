#pragma once
#include <string>

class App
{
private:
	std::string* name;
	std::string* dir;
	std::string* args;
	int numApps;
public:
	App();
	~App();
	bool Cargar(const std::string& file);
	std::string getName(int n) const;
	std::string getDir(int n) const;
	std::string getArgs(int n) const;
	int getNumApps() const;
};