#pragma once
#include <QObject>

class ButtonHoverWatcher : public QObject
{
    Q_OBJECT
public:
    explicit ButtonHoverWatcher(QObject* parent = Q_NULLPTR);
    virtual bool eventFilter(QObject* watched, QEvent* event) Q_DECL_OVERRIDE;
};
