/********************************************************************************
** Form generated from reading UI file 'launcher.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAUNCHER_H
#define UI_LAUNCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_launcherClass
{
public:
    QWidget *centralWidget;
	QWidget *NavBar;
	QWidget *Apps;
	QWidget *Games;
    QWidget* Settings;
	QWidget *gridLayoutWidget;
	QStackedWidget *Tabs;
    QVBoxLayout *verticalLayout;
	QHBoxLayout *horizontalLayout;
	QGridLayout *gridLayoutApps;
    QGridLayout* gridLayoutGames;
    QGridLayout* gridLayoutSettings;
    QCheckBox *SteamState;
    QPushButton *AppsButton;
    QPushButton *GamesButton;
    QPushButton *AddAppButton;
    QPushButton *AddGameButton;
    QPushButton* SettingButton;
	
    void setupUi(QMainWindow *launcherClass)
    {
        if (launcherClass->objectName().isEmpty())
            launcherClass->setObjectName("launcherClass");
        launcherClass->resize(824, 539);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(launcherClass->sizePolicy().hasHeightForWidth());
        launcherClass->setSizePolicy(sizePolicy);
        launcherClass->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
		"	background-color: black;\n"
		"}"));

        /*
         *
         *                     Central Widget
         *
         */

        centralWidget = new QWidget(launcherClass);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setStyleSheet(QString::fromUtf8(""));
    	verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        

    	/*
		 *
		 *                     Navigation Bar
		 *
		 */

    	NavBar = new QWidget(centralWidget);
        NavBar->setObjectName("NavBar");
        sizePolicy.setHeightForWidth(NavBar->sizePolicy().hasHeightForWidth());
        NavBar->setSizePolicy(sizePolicy);
        NavBar->setMaximumSize(QSize(16777215, 50));
        NavBar->setStyleSheet(QString::fromUtf8("QWidget {\n"
        "   background-color: #121212;\n"
        "   border: 1px solid #121212;\n"
        "   border-top-left-radius: 15px;\n"
        "   border-top-right-radius: 15px;\n"
		"}"));
        horizontalLayout = new QHBoxLayout(NavBar);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
    	verticalLayout->addWidget(NavBar);

        /*
         *                      Navigation Bar Buttons
         */

    	//                          Steam Conection Switch

        SteamState = new QCheckBox(NavBar);
        SteamState->setObjectName("SteamState");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SteamState->sizePolicy().hasHeightForWidth());
        SteamState->setSizePolicy(sizePolicy1);
        SteamState->setMinimumSize(QSize(100, 26));
        SteamState->setStyleSheet(QString::fromUtf8("QCheckBox{ \n"
        "   background-color: #121212;\n"
        "   border: 1px solid #121212; \n"
        "   color: #F2F2F2\n"
        "}\n"
            "QCheckBox::indicator {\n"
		"     width: 50px;\n"
		"     height: 50px;\n"
		" }\n"
		"\n"
		"  QCheckBox::indicator:checked\n"
		"  {\n"
		"    image: url(:/launcher/img/on.png);\n"
		"  }\n"
		"  QCheckBox::indicator:unchecked\n"
		"  {\n"
		"    image: url(:/launcher/img/off.png);\n"
		"  }"));

        horizontalLayout->addWidget(SteamState);

        //                          Apps Tab Button

        AppsButton = new QPushButton(NavBar);
        AppsButton->setObjectName("AppsButton");
        AppsButton->setMaximumSize(QSize(150, 16777215));
        QFont font;
        font.setWeight(QFont::DemiBold);
        font.setKerning(false);
        AppsButton->setFont(font);
        AppsButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
			"font-weight: 600;\n"
			"font-size: 14px;\n"
			"color: #F2F2F2;\n"
			"background-color: #333333;\n"
			"border: 2px solid #222222;\n"
			"border-radius: 1px;\n"
			"text-transform: uppercase;\n"
			"}\n"
			"\n"
			"QPushButton:hover {\n"
			"background-color: #DCDCDC;\n"
			"color: #333333;\n"
			"}"));

        horizontalLayout->addWidget(AppsButton);

        //						    Games Tab Button

        GamesButton = new QPushButton(NavBar);
        GamesButton->setObjectName("GamesButton");
        GamesButton->setMaximumSize(QSize(150, 16777215));
        GamesButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
			"font-weight: 600;\n"
			"font-size: 14px;\n"
			"color: #F2F2F2;\n"
			"background-color: #333333;\n"
			"border: 2px solid #222222;\n"
			"border-radius: 1px;\n"
			"text-transform: uppercase;\n"
			"}\n"
			"\n"
			"QPushButton:hover {\n"
			"background-color: #DCDCDC;\n"
			"color: #333333;\n"
            "}"));

        horizontalLayout->addWidget(GamesButton);

        //						    Settings Tab Button

        SettingButton = new QPushButton(NavBar);
        SettingButton->setObjectName("SettingsButton");
        SettingButton->setMaximumSize(QSize(35, 35));
        SettingButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
			"font-weight: 600;\n"
			"font-size: 14px;\n"
			"color: #F2F2F2;\n"
			"background-color: #333333;\n"
			"border: 2px solid #222222;\n"
			"border-radius: 1px;\n"
			"text-transform: uppercase;\n"
			"}\n"
			"\n"
			"QPushButton:hover {\n"
			"background-color: #DCDCDC;\n"
            "qproperty-icon: url(:/launcher/settings2.png)\n"
			"color: #333333;\n"
            "}"));
        SettingButton->setIcon(QIcon(":/launcher/settings.png"));
        SettingButton->setIconSize(QSize(20, 20));
        horizontalLayout->addWidget(SettingButton);

		/*
		 *				        Tabs
		 */

        Tabs = new QStackedWidget(centralWidget);
        Tabs->setObjectName("Tabs");
        Tabs->setAutoFillBackground(false);
        Tabs->setStyleSheet(QString::fromUtf8("QStackedWidget{"
        "   background-color: #222222;\n"
        "   border: 1px solid #121212;\n"
        "   border-bottom-left-radius: 15px;\n"
        "   border-bottom-right-radius: 15px;\n"
		"}"));
        Tabs->setFrameShape(QFrame::NoFrame);
        Tabs->setFrameShadow(QFrame::Plain);
        Tabs->setCurrentIndex(0);
		verticalLayout->addWidget(Tabs);

        //				            Apps Tab

        Apps = new QWidget();
        Apps->setObjectName("Apps");
        gridLayoutApps = new QGridLayout(Apps);
        gridLayoutApps->setSpacing(6);
        gridLayoutApps->setContentsMargins(15, 15, 15, 15);
        gridLayoutApps->setObjectName("gridLayout");
        Tabs->addWidget(Apps);

        //				            Games Tab

        Games = new QWidget();
        Games->setObjectName("Games");
        gridLayoutGames = new QGridLayout(Games);
        gridLayoutGames->setSpacing(6);
        gridLayoutGames->setContentsMargins(15, 15, 15, 15);
        gridLayoutGames->setObjectName("gridLayout");
		Tabs->addWidget(Games);

        //				            Settings Tab

    	Settings = new QWidget();
        Settings->setObjectName("Settings");
        gridLayoutSettings = new QGridLayout(Settings);
        gridLayoutSettings->setSpacing(6);
        gridLayoutSettings->setContentsMargins(15, 15, 15, 15);
        gridLayoutSettings->setObjectName("gridLayout");
        Tabs->addWidget(Settings);

        //				                Add App Button

        AddAppButton = new QPushButton(Settings);
        AddAppButton->setObjectName("AddAppButton");
        AddAppButton->setMinimumSize(QSize(150, 0));
        AddAppButton->setMaximumSize(QSize(150, 16777215));
        AddAppButton->setStyleSheet(QString::fromUtf8(
            "QPushButton{\n"
            "padding: 10px 15px;\n"
            "background-color: #444444;\n"
            "outline: 3px #121212 solid;\n"
            "outline-offset: -3px;\n"
            "border-radius: 5px;\n"
            "border: none;\n"
            "color: #F2F2F2;\n"
            "font-weight: 600;\n"
            "font-size: 14px;\n"
            "}\n"
            "QPushButton:hover {\n"
            "background-color: #DCDCDC;\n"
            "color: #444444;\n"
            "}\n"));
        gridLayoutSettings->addWidget(AddAppButton, 0, 0);

        //				                Add Game Button

        AddGameButton = new QPushButton(Settings);
        AddGameButton->setObjectName("AddGameButton");
        AddGameButton->setMinimumSize(QSize(150, 0));
        AddGameButton->setMaximumSize(QSize(150, 16777215));
        AddGameButton->setStyleSheet(QString::fromUtf8(
            "QPushButton{\n"
            "padding: 10px 15px;\n"
            "background-color: #444444;\n"
            "outline: 3px #121212 solid;\n"
            "outline-offset: -3px;\n"
            "border-radius: 5px;\n"
            "border: none;\n"
            "color: #F2F2F2;\n"
            "font-weight: 600;\n"
            "font-size: 14px;\n"
            "}\n"
            "QPushButton:hover {\n"
            "background-color: #DCDCDC;\n"
            "color: #444444;\n"
            "}\n"));
        gridLayoutSettings->addWidget(AddGameButton, 1, 0);

        launcherClass->setCentralWidget(centralWidget);
        retranslateUi(launcherClass);
        QMetaObject::connectSlotsByName(launcherClass);
    } // setupUi

    /*
     *
	 *                     Window Texts with translations
	 *
	 */

    void retranslateUi(QMainWindow *launcherClass)
    {
        launcherClass->setWindowTitle(QCoreApplication::translate("launcherClass", "launcher", nullptr));
        SteamState->setText(QCoreApplication::translate("launcherClass", "STEAM", nullptr));
        AppsButton->setText(QCoreApplication::translate("launcherClass", "APPLICACIONES", nullptr));
        GamesButton->setText(QCoreApplication::translate("launcherClass", "JUEGOS", nullptr));
        AddAppButton->setText(QCoreApplication::translate("launcherClass", "Add App", nullptr));
        AddGameButton->setText(QCoreApplication::translate("launcherClass", "Add Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class launcherClass: public Ui_launcherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCHER_H
