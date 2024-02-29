#pragma once

#include <QtWidgets/QMainWindow>
#include <QSystemTrayIcon>
#include "ui_launcher.h"
#include <thread>

class launcher :
    
    public QMainWindow
{
	std::thread hotkeyThread;
    std::atomic<bool> isRunning;
    QSystemTrayIcon* trayIcon;
    Q_OBJECT

public:
    void updateSteamState() const;
    launcher(QWidget *parent = nullptr);
    ~launcher();

    void f_showhide_shortcut();
public slots:
    void f_showhide();

private slots:

    void on_AppsButton_clicked() const;
    void on_GamesButton_clicked() const;
    void on_SettingsButton_clicked() const;
    void on_SteamState_clicked(bool checked) const;
    void on_AddAppButton_clicked() const;
    void on_AddGameButton_clicked() const;
	void Add_App_Button(const std::string& name, const std::string& dir, const std::string& args, const std::string& type, int n, const int& cont);
  
private:
    Ui::launcherClass ui;
};
