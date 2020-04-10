#ifndef PROGRAMCONFIGURATION_H
#define PROGRAMCONFIGURATION_H

#include <QWidget>
#include <DCommandLinkButton>
#include <dfilechooseredit.h>
#include <DFloatingMessage>

DWIDGET_USE_NAMESPACE
class ProgramConfiguration : public QWidget
{
    Q_OBJECT
public:
    explicit ProgramConfiguration(QWidget *parent = nullptr);

signals:
    void sendSignal(int num);

public slots:

private:
    DFloatingMessage *m_pDFloatingMessage;
};

#endif // PROGRAMCONFIGURATION_H
