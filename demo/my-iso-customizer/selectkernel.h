#ifndef SELECTKERNEL_H
#define SELECTKERNEL_H

#include <QWidget>
#include <dfilechooseredit.h>



DWIDGET_USE_NAMESPACE
class SelectKernel : public QWidget
{
    Q_OBJECT
public:
    explicit SelectKernel(QWidget *parent = nullptr);

signals:
    void sendSignal(int num);

public slots:
};

#endif // SELECTKERNEL_H
