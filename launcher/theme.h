#pragma once
#include <string>

class theme
{
private:
	std::string navBar;
	std::string navBar_Text;
	std::string navBar_Button;
	std::string navBar_Button_Border;
	std::string navBar_Button_Text;
	std::string navBar_Button_Hover;
	std::string navBarButton_Border_Hover;
	std::string navBar_Button_Text_Hover;
	std::string Tab;
	std::string Tab_border;
	std::string Tab_Button;
	std::string Tab_Button_Border;
	std::string Tab_Button_Text;
	std::string Tab_Button_Hover;
	std::string Tab_Button_Border_Hover;
	std::string Tab_Button_Text_Hover;
public:
		theme();
		~theme();
		void cargar(std::fstream& file);
		std::string getNavBar() const;
		std::string getNavBar_Text() const;
		std::string getNavBar_Button() const;
		std::string getNavBar_Button_Border() const;
		std::string getNavBar_Button_Text() const;
		std::string getNavBar_Button_Hover() const;
		std::string getNavBar_Button_Border_Hover() const;
		std::string getNavBar_Button_Text_Hover() const;
		std::string getTab() const;
		std::string getTab_border() const;
		std::string getTab_Button() const;
		std::string getTab_Button_Border() const;
		std::string getTab_Button_Text() const;
		std::string getTab_Button_Hover() const;
		std::string getTab_Button_Border_Hover() const;
		std::string getTab_Button_Text_Hover() const;
};

