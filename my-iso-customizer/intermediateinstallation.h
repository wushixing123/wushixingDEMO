#ifndef INTERMEDIATEINSTALLATION_H
#define INTERMEDIATEINSTALLATION_H

#include <QWidget>
#include <dfilechooseredit.h>

DWIDGET_USE_NAMESPACE

class IntermediateInstallation : public QWidget
{
    Q_OBJECT
public:
    explicit IntermediateInstallation(QWidget *parent = nullptr);

signals:
    void sendSignal(int num);

public slots:
};

#endif // INTERMEDIATEINSTALLATION_H
