#include "launcher.h"
#include "apps.h"
#include <QProcess>
#include "./ui_launcher.h"
#include <QCloseEvent>
#include <string>
#include <windows.h>
#include <QMenu>
#include <QSystemTrayIcon>
#include <string>
#include <QUrl>
#include <QDesktopServices>
#include <QGuiApplication>

using namespace std;

QString SetSteam();

/*
 *
 *                              Window creation
 *
 */


launcher::launcher(QWidget *parent)
    : QMainWindow(parent), isRunning(true)
{
    ui.setupUi(this);
    //                          Make the window frameless
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    //						    Update the Steam switch
    updateSteamState();
    //                          Shortcuts
	hotkeyThread = std::thread(&launcher::f_showhide_shortcut, this);
    //                          Tray Icon
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/launcher/img/icono.ico"));
    QMenu* trayIconMenu = new QMenu(this);
    QAction* quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    trayIconMenu->addAction(quitAction);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->show();
    //						    Load Apps and Games
    App Apps, Games;

    if (Apps.Cargar("apps"))
    {
        for (int i = 0; i < Apps.getNumApps(); i++)
        {
            Add_App_Button(Apps.getName(i), Apps.getDir(i), Apps.getArgs(i),"Apps", i, Apps.getNumApps());
        }
    }
    if (Games.Cargar("games"))
    {
        for (int i = 0; i < Games.getNumApps(); i++)
        {
            Add_App_Button(Games.getName(i), Games.getDir(i), Games.getArgs(i), "Games", i, Games.getNumApps());
        }
    }

}

/*
 *
 *                              Window Destructor
 *
 */

launcher::~launcher()
{
    isRunning = false;
    delete trayIcon;
	hotkeyThread.join();
}

/*
 *
 *                              Steam Conection Switch Functions
 *
 */

//						        Current state of the Steam Conection

QString SetSteam()
{
    //Check if steam is online
    QProcess process;
    QStringList args = QStringList("if (((Get-NetFirewallRule -Displayname offlineSteam | select enabled) | where { $_.Enabled -eq $True } | measure ).Count -eq 2) {Write-Host \"ON\"} else {Write-Host \"OFF\"}");
    process.start("powershell", args);
    process.waitForFinished(-1);
    QString state = process.readAllStandardOutput();
    qDebug() << state;
    return state;
}

//						        Update the Steam Conection Switch

void launcher::updateSteamState() const
{
    QString state = SetSteam();
    if (state == "OFF\n") ui.SteamState->setChecked(true);
    else ui.SteamState->setChecked(false);

}

//						        Change the Steam Conection State

void launcher::on_SteamState_clicked(bool checked) const
{
    QProcess process;
    if (!checked)
    {
        QStringList args;
        args = QStringList("start-process  -WindowStyle Hidden powershell -verb runas 'Enable-NetFirewallRule -Displayname offlineSteam'");
        process.start("powershell", args);
        process.waitForFinished(-1);
    }
    else
    {
        QStringList args;
        args = QStringList("start-process  -WindowStyle Hidden powershell -verb runas 'Disable-NetFirewallRule -Displayname offlineSteam'");
        process.start("powershell", args);
        process.waitForFinished(-1);
    }
    if (process.exitCode() == 0) ui.SteamState->setChecked(checked);
    else ui.SteamState->setChecked(!checked);
}

/*
 *
 *                              Navigation Functions
 *
 */

void launcher::on_AppsButton_clicked() const
{
    ui.Tabs->setCurrentIndex(0);
}

void launcher::on_GamesButton_clicked() const
{
    ui.Tabs->setCurrentIndex(1);
}

void launcher::on_SettingsButton_clicked() const
{
	ui.Tabs->setCurrentIndex(2);
}

/*
 *
 *                              Settings Functions
 *
 */

void launcher::on_AddAppButton_clicked() const
{
	QProcess process;
    const string user = string(getenv("username"));
    string AppsFile = "C:/Users/" + user + "/Documents/apps.txt";
    process.start("notepad", QStringList(QString::fromStdString(AppsFile)));
    process.waitForFinished(-1);
}

void launcher::on_AddGameButton_clicked() const
{
	QProcess process;
    const string user = string(getenv("username"));
    string AppsFile = "C:/Users/" + user + "/Documents/games.txt";
    process.start("notepad", QStringList(QString::fromStdString(AppsFile)));
    process.waitForFinished(-1);
}

/*
 *
 *                              App and Game Buttons Creation Functions
 *
 */

void launcher::Add_App_Button(const string& name, const string& dir, const string& args, const string& type, const int n, const int& cont)
{
    QPushButton* Button = nullptr;
    //                          Calculate the size of the grid
    int size = ceil(sqrt(cont));
    //						    Add Button to the layout
    if (type == "Apps")
    {
        Button = new QPushButton(ui.Apps);
        ui.gridLayoutApps->addWidget(Button, n % size, n / size);
    }
    else if(type == "Games")
    {
        Button = new QPushButton(ui.Games);
        ui.gridLayoutGames->addWidget(Button, n % size, n / size);
    }
    //						    Set Button properties
    Button->setObjectName(name + "Button");
    Button->setMinimumSize(QSize(150, 0));
    Button->setMaximumSize(QSize(150, 16777215));
    QFont font;
    font.setWeight(QFont::DemiBold);
    font.setKerning(false);
    Button->setFont(font);
    Button->setText(QCoreApplication::translate("launcherClass", name.c_str(), nullptr));
    Button->setStyleSheet(ui.AddAppButton->styleSheet());
    //						    Set Button actions
    if (0 == dir.compare(dir.length() - 4, 4, ".exe"))
    {
    	connect(Button, &QPushButton::clicked, [dir, args]() {
        QProcess process;
        QStringList argsList = QProcess::splitCommand(QString::fromStdString(args));
        bool started = process.startDetached(QString::fromStdString(dir), argsList);
        if (!started)
        {
            qDebug() << "Failed to start process";
        }
        qDebug() << dir;
        qDebug() << argsList;
        process.waitForFinished(-1);
        });
	}
	else
	{
		connect(Button, &QPushButton::clicked, [dir]()
		{
			QDesktopServices::openUrl(QUrl(QString::fromStdString(dir), QUrl::TolerantMode));
			qDebug() << dir;
		});
	}
}

/*
 *
 *                              Shortcuts Functions
 *
 */

//						        Show/Hide the window with a shortcut
void launcher::f_showhide_shortcut()
{
    // Register the hotkey
    if (!RegisterHotKey(NULL, 1, MOD_CONTROL| MOD_ALT | MOD_NOREPEAT, VK_F12))
    {
        qDebug() << "ERROR: Shorcut not registred properly";
    }
	MSG msg = { 0 };
	// Check isRunning in the loop condition
	while (isRunning) 
    {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
        {
            if (msg.message == WM_HOTKEY)
            {
                QMetaObject::invokeMethod(this, "f_showhide", Qt::QueuedConnection);
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Add a small delay to prevent the loop from running too fast
    }

    UnregisterHotKey(NULL, 1);
}

void launcher::f_showhide()
{
	if (isHidden())
	{
        activateWindow(); 
		show();
        //						  Center the window
        auto screenGeometry = QGuiApplication::primaryScreen()->geometry();
        int x = (screenGeometry.width() - this->geometry().width())/ 2;
        int y = (screenGeometry.height() -this->geometry().height())/ 2;
        this->move(x, y);
        QCursor cursor;
        cursor.setPos(x + this->geometry().width() / 2, y + this->geometry().height() / 2);
	}
	else
	{
		hide();
	}
}