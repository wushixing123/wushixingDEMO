#include "output.h"
#include <DLabel>
#include <DFontSizeManager>

Output::Output(QWidget *parent) : QWidget(parent)
{

    label = new DLabel("准备输出");
    QFont font;
    font.setFamily("SimHei");
    font.setBold(true);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    DFontSizeManager::instance()->bind(label, DFontSizeManager::T3);

//    DLabel *label1 = new DLabel("正在输出");
//    QFont font1;
//    font1.setFamily("SimHei");
//    font1.setBold(true);
//    label1->setFont(font1);
//    label1->setAlignment(Qt::AlignCenter);
//    DFontSizeManager::instance()->bind(label1, DFontSizeManager::T3);
//    label1->hide();

    m_plabel = new DLabel(this);
    m_plabel->setAlignment(Qt::AlignCenter);
    //DFontSizeManager::instance()->bind(label1, DFontSizeManager::T3);
    m_plabel->resize(110, 110);
    m_plabel->setPixmap(QPixmap(":/icons/deepin/builtin/light/icons/iso_progress_progress_110px.svg"));

    m_pLabelTips = new DLabel("制作成功", this);
    m_pLabelTips->hide();



    m_ptimer = new QTimer();
    m_ptimer->setInterval(100);
    connect(m_ptimer, &QTimer::timeout, this, &Output::slotTimerOut);
    QVBoxLayout *pVBoxLayout = new QVBoxLayout(this);

    pVBoxLayout->addWidget(label);

    pVBoxLayout->setSpacing(20);
    pVBoxLayout->addStretch();

    QHBoxLayout *pHBoxLayout = new QHBoxLayout();
    QHBoxLayout *pHBoxLayout1 = new QHBoxLayout();
    pHBoxLayout->addStretch();

    m_pDWaterProgress = new DWaterProgress();
    m_pDWaterProgress->setTextVisible(true);
    m_pDWaterProgress->setValue(m_valus);
    pHBoxLayout->addWidget(m_pDWaterProgress);
    pHBoxLayout->addStretch();

    pHBoxLayout1->addWidget(m_plabel);
    m_plabel->hide();
    pVBoxLayout->addLayout(pHBoxLayout);
    pVBoxLayout->addLayout(pHBoxLayout1);

    pVBoxLayout->addStretch();

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
        label->setText("正在制作");
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

        m_pDWaterProgress->hide();
        m_plabel->show();
        label->setText("制作成功");
    }
    m_pDWaterProgress->setValue(m_valus);
    update();
}
