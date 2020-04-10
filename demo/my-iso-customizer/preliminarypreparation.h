#ifndef PRELIMINARYPREPARATION_H
#define PRELIMINARYPREPARATION_H

#include <QWidget>
#include <dfilechooseredit.h>

DWIDGET_USE_NAMESPACE

class PreliminaryPreparation : public QWidget
{
    Q_OBJECT
public:
    explicit PreliminaryPreparation(QWidget *parent = nullptr);

signals:
    void sendSignal(int num);

public slots:
};

#endif // PRELIMINARYPREPARATION_H
