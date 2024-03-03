#include "SettingsHover.h"
#include <QPushButton>
#include <QEvent>
ButtonHoverWatcher::ButtonHoverWatcher(QObject* parent) :
    QObject(parent)
{
}

bool ButtonHoverWatcher::eventFilter(QObject* watched, QEvent* event)
{
    QPushButton* button = qobject_cast<QPushButton*>(watched);
    if (!button)
    {
        return false;
    }

    if (event->type() == QEvent::Enter)
    {
        // The push button is hovered by mouse
        button->setIcon(QIcon(":/launcher/settings2.png"));
        return true;
    }

    if (event->type() == QEvent::Leave)
    {
        // The push button is not hovered by mouse
        button->setIcon(QIcon(":/launcher/settings.png"));
        return true;
    }

    return false;
}