#ifndef SELECTCONSTRUCT_H
#define SELECTCONSTRUCT_H

#include <QWidget>
#include <dfilechooseredit.h>
#include <DListView>

DWIDGET_USE_NAMESPACE
class selectConstruct : public QWidget
{
    Q_OBJECT
public:
    explicit selectConstruct(QWidget *parent = nullptr);

signals:
    void sendSignal(int num);
public slots:
private:
    DListView   *m_pDListView;
};

#endif // SELECTCONSTRUCT_H
