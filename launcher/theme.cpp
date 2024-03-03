#include "theme.h"
#include <fstream>

theme::theme()
{
	this->navBar = "#121212";
	this->navBar_Text = "#F2F2F2";
	this->navBar_Button = "#333333";
	this->navBar_Button_Border = "#222222";
	this->navBar_Button_Text = "#F2F2F2";
	this->navBar_Button_Hover = "#DCDCDC";
	this->navBarButton_Border_Hover = "#DCDCDC";
	this->navBar_Button_Text_Hover = "#333333";
	this->Tab = "#222222";
	this->Tab_border = "#121212";
	this->Tab_Button = "#444444";
	this->Tab_Button_Border = "#121212";
	this->Tab_Button_Text = "#F2F2F2";
	this->Tab_Button_Hover = "#DCDCDC";
	this->Tab_Button_Border_Hover = "#DCDCDC";
	this->Tab_Button_Text_Hover = "#444444";
}

theme::~theme()
{
}

void theme::cargar(std::fstream& file)
{
	int n = 0;
	std::string temp[16];
	while (file)
	{
		file >> temp[n];
		n++;
	}
	this->navBar = temp[0];
	this->navBar_Text = temp[1];
	this->navBar_Button = temp[2];
	this->navBar_Button_Border = temp[3];
	this->navBar_Button_Text = temp[4];
	this->navBar_Button_Hover = temp[5];
	this->navBarButton_Border_Hover = temp[6];
	this->navBar_Button_Text_Hover = temp[7];
	this->Tab = temp[8];
	this->Tab_border = temp[9];
	this->Tab_Button = temp[10];
	this->Tab_Button_Border = temp[11];
	this->Tab_Button_Text = temp[12];
	this->Tab_Button_Hover = temp[13];
	this->Tab_Button_Border_Hover = temp[14];
	this->Tab_Button_Text_Hover = temp[15];
}


std::string theme::getNavBar() const
{
	return navBar;
}

std::string theme::getNavBar_Text() const
{
	return navBar_Text;
}

std::string theme::getNavBar_Button() const
{
	return navBar_Button;
}
std::string theme::getNavBar_Button_Border() const
{
	return navBar_Button_Border;
}
std::string theme::getNavBar_Button_Text() const
{
	return navBar_Button_Text;
}

std::string theme::getNavBar_Button_Hover() const
{
	return navBar_Button_Hover;
}
std::string theme::getNavBar_Button_Border_Hover() const
{
	return navBarButton_Border_Hover;
}
std::string theme::getNavBar_Button_Text_Hover() const
{
	return navBar_Button_Text_Hover;
}
std::string theme::getTab() const
{
	return Tab;
}
std::string theme::getTab_border() const
{
	return Tab_border;
}
std::string theme::getTab_Button() const
{
	return Tab_Button;
}
std::string theme::getTab_Button_Border() const
{
	return Tab_Button_Border;
}
std::string theme::getTab_Button_Text() const
{
	return Tab_Button_Text;
}
std::string theme::getTab_Button_Hover() const
{
	return Tab_Button_Hover;
}
std::string theme::getTab_Button_Border_Hover() const
{
	return Tab_Button_Border_Hover;
}
std::string theme::getTab_Button_Text_Hover() const
{
	return Tab_Button_Text_Hover;
}
