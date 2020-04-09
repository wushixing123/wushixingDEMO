#include "output.h"
#include <DLabel>
#include <DFontSizeManager>

Output::Output(QWidget *parent) : QWidget(parent)
{

    DLabel *label = new DLabel("准备输出");
    QFont font;
    font.setFamily("SimHei");
    font.setBold(true);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    DFontSizeManager::instance()->bind(label, DFontSizeManager::T3);


    m_ptimer = new QTimer();
    m_ptimer->setInterval(100);
    connect(m_ptimer, &QTimer::timeout, this, &Output::slotTimerOut);
    QVBoxLayout *pVBoxLayout = new QVBoxLayout(this);

    pVBoxLayout->addWidget(label);

    pVBoxLayout->setSpacing(20);
    pVBoxLayout->addStretch();

    QHBoxLayout *pHBoxLayout = new QHBoxLayout();
    pHBoxLayout->addStretch();
    m_pDWaterProgress = new DWaterProgress();
    m_pDWaterProgress->setTextVisible(true);
    m_pDWaterProgress->setValue(m_valus);
    pHBoxLayout->addWidget(m_pDWaterProgress);
    pHBoxLayout->addStretch();
    pVBoxLayout->addLayout(pHBoxLayout);

    QHBoxLayout *pHBoxLayout2 = new QHBoxLayout();
    pHBoxLayout2->addStretch();
    m_pDPushButton = new DPushButton(tr("下一步"));
    m_pDPushButton->setCheckable(true);
    connect(m_pDPushButton, &DPushButton::clicked, this, &Output::slotDPuBtnClicked);
    pHBoxLayout2->addWidget(m_pDPushButton);
    pHBoxLayout2->addStretch();
    pVBoxLayout->addLayout(pHBoxLayout2);

    pVBoxLayout->addStretch();
    this->setLayout(pVBoxLayout);

}


void Output::slotDPuBtnClicked()
{
    qDebug() << "m_pDPushButton->isChecked():" << m_pDPushButton->isChecked();
    if(m_pDPushButton->isChecked())
    {
        m_ptimer->start();
        m_pDPushButton->setText(tr("停止加载"));
    }
    else
    {
        m_ptimer->stop();
        m_pDPushButton->setText(tr("开始加载"));
    }


}

void Output::slotTimerOut()
{
    m_valus += 1;
    if(m_valus == 100)
    {
        //m_valus = 0;
        m_ptimer->stop();
    }
    m_pDWaterProgress->setValue(m_valus);
    update();
}
