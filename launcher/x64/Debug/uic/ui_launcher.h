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
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *SteamState;
    QPushButton *AppsButton;
    QPushButton *GamesButton;
    QStackedWidget *Tabs;
    QWidget *Apps;
	QWidget *Games;
    QWidget* Settings;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayoutApps;
    QGridLayout* gridLayoutGames;
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
        centralWidget = new QWidget(launcherClass);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMaximumSize(QSize(16777215, 50));
        widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: white;\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        SteamState = new QCheckBox(widget);
        SteamState->setObjectName("SteamState");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SteamState->sizePolicy().hasHeightForWidth());
        SteamState->setSizePolicy(sizePolicy1);
        SteamState->setMinimumSize(QSize(100, 26));
        SteamState->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
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

        AppsButton = new QPushButton(widget);
        AppsButton->setObjectName("AppsButton");
        AppsButton->setMaximumSize(QSize(150, 16777215));
        QFont font;
        font.setWeight(QFont::DemiBold);
        font.setKerning(false);
        AppsButton->setFont(font);
        AppsButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
			"font-weight: 600;\n"
			"font-size: 14px;\n"
			"color: #fff;\n"
			"background-color: #0066CC;\n"
			"border: 5px solid #0066cc;\n"
			"border-radius: 1px;\n"
			"text-transform: uppercase;\n"
			"}\n"
			"\n"
			"QPushButton:hover {\n"
			"background-color: #fff;\n"
			"color: #0066cc;\n"
			"border:  2px solid #0066cc;\n"
			"}"));

        horizontalLayout->addWidget(AppsButton);

        GamesButton = new QPushButton(widget);
        GamesButton->setObjectName("GamesButton");
        GamesButton->setMaximumSize(QSize(150, 16777215));
        GamesButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
			"font-weight: 600;\n"
			"font-size: 14px;\n"
			"color: #fff;\n"
			"background-color: #0066CC;\n"
			"border: 5px solid #0066cc;\n"
			"border-radius: 1px;\n"
			"text-transform: uppercase;\n"
			"}\n"
			"\n"
			"QPushButton:hover {\n"
			"background-color: #fff;\n"
			"color: #0066cc;\n"
			"border:  2px solid #0066cc;\n"
			"}"));

        horizontalLayout->addWidget(GamesButton);

        SettingButton = new QPushButton(widget);
        SettingButton->setObjectName("SettingsButton");
        SettingButton->setMaximumSize(QSize(35, 35));
        SettingButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
			"font-weight: 600;\n"
			"font-size: 14px;\n"
			"color: #fff;\n"
			"background-color: #0066CC;\n"
			"border: 5px solid #0066cc;\n"
			"border-radius: 1px;\n"
			"text-transform: uppercase;\n"
			"}\n"
			"\n"
			"QPushButton:hover {\n"
			"background-color: #fff;\n"
			"color: #0066cc;\n"
			"border:  2px solid #0066cc;\n"
			"}"));

        horizontalLayout->addWidget(SettingButton);

        verticalLayout->addWidget(widget);

        Tabs = new QStackedWidget(centralWidget);
        Tabs->setObjectName("Tabs");
        Tabs->setAutoFillBackground(false);
        Tabs->setStyleSheet(QString::fromUtf8(""));
        Tabs->setFrameShape(QFrame::NoFrame);
        Tabs->setFrameShadow(QFrame::Plain);
        Apps = new QWidget();
        Apps->setObjectName("Apps");
        gridLayoutApps = new QGridLayout(Apps);
        gridLayoutApps->setSpacing(6);
        gridLayoutApps->setContentsMargins(15, 15, 15, 15);
        gridLayoutApps->setObjectName("gridLayout");

        Tabs->addWidget(Apps);
        Games = new QWidget();
        Games->setObjectName("Games");
        Tabs->addWidget(Games);
        gridLayoutGames = new QGridLayout(Games);
        gridLayoutGames->setSpacing(6);
        gridLayoutGames->setContentsMargins(15, 15, 15, 15);
        gridLayoutGames->setObjectName("gridLayout");

        Settings = new QWidget();
        Settings->setObjectName("Games");
        Tabs->addWidget(Settings);

        verticalLayout->addWidget(Tabs);

        launcherClass->setCentralWidget(centralWidget);

        retranslateUi(launcherClass);

        Tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(launcherClass);
    } // setupUi

    void retranslateUi(QMainWindow *launcherClass)
    {
        launcherClass->setWindowTitle(QCoreApplication::translate("launcherClass", "launcher", nullptr));
        SteamState->setText(QCoreApplication::translate("launcherClass", "STEAM", nullptr));
        AppsButton->setText(QCoreApplication::translate("launcherClass", "APPLICACIONES", nullptr));
        GamesButton->setText(QCoreApplication::translate("launcherClass", "JUEGOS", nullptr));
        SettingButton->setIcon(QIcon(":/launcher/settings.png"));
        SettingButton->setIconSize(QSize(25, 25));
    } // retranslateUi

};

namespace Ui {
    class launcherClass: public Ui_launcherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCHER_H
