#ifndef POSTCLEANING_H
#define POSTCLEANING_H

#include <QWidget>
#include <DPushButton>
#include <dfilechooseredit.h>

DWIDGET_USE_NAMESPACE
class PostCleaning : public QWidget
{
    Q_OBJECT
public:
    explicit PostCleaning(QWidget *parent = nullptr);

signals:
    void sendSignal(int num);

public slots:
};

#endif // POSTCLEANING_H
