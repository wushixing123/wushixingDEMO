#ifndef SELECTISO_H
#define SELECTISO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <dfilechooseredit.h>
#include <DLabel>


DWIDGET_USE_NAMESPACE
class selectISO : public QWidget
{
    Q_OBJECT
public:
    explicit selectISO(QWidget *parent = nullptr);
    ~selectISO();
signals:
    void sendSignal(int num);

public slots:


private:
    DLabel *m_pDLabel;
};

#endif // SELECTISO_H
