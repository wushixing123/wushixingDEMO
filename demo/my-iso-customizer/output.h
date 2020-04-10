#ifndef OUTPUT_H
#define OUTPUT_H

#include <QWidget>
#include <DWaterProgress>
#include <DPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>
#include <QDebug>
#include <DLabel>

DWIDGET_USE_NAMESPACE
class Output : public QWidget
{
    Q_OBJECT
public:
    explicit Output(QWidget *parent = nullptr);

signals:
    void sendSignal(int num);

public slots:
    void slotDPuBtnClicked();
    void slotTimerOut();

private:
    DLabel *label;
    QTimer *m_ptimer;
    DWaterProgress *m_pDWaterProgress;
    int m_valus = 0;
    DPushButton *m_pDPushButton;
    DLabel *m_plabel;
    DLabel *m_pLabelTips;
};

#endif // OUTPUT_H
