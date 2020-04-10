#include "programconfiguration.h"
#include <DLabel>
#include <DFontSizeManager>
#include <QFont>
#include <DPushButton>
#include <DCommandLinkButton>
#include <DFileDialog>
#include <DMessageManager>
#include <QWidget>
#include <DFloatingMessage>

ProgramConfiguration::ProgramConfiguration(QWidget *parent) : QWidget(parent)
{
    //增加标签
    DLabel *label = new DLabel("程序配置");
    QFont font;
    font.setFamily("SimHei");
    font.setBold(true);
    label->setFont(font);
    DFontSizeManager::instance()->bind(label, DFontSizeManager::T3);
    //增加标签
    DLabel *label1 = new DLabel("请选择程序");
    QFont font1;
    label1->setAlignment(Qt::AlignCenter);
    label1->setFont(font1);
    DFontSizeManager::instance()->bind(label1, DFontSizeManager::T2);
    //数字按钮
    DCommandLinkButton *pCleanButton = new DCommandLinkButton(tr("全部清除"),this);
    pCleanButton->hide();
    DCommandLinkButton *pDCommandLinkButton = new DCommandLinkButton(tr("选择程序deb包"));

    //主布局
    QVBoxLayout *pQVBoxLayout = new QVBoxLayout();

    QHBoxLayout *pQHBoxLayout = new QHBoxLayout();
    QHBoxLayout *pQHBoxLayout1 = new QHBoxLayout();
    QHBoxLayout *pQHBoxLayoutcombine = new QHBoxLayout();
//    QHBoxLayout *pQHBoxLayout2 = new QHBoxLayout();

    pQHBoxLayoutcombine->addWidget(label,0,Qt::AlignLeft);
    pQHBoxLayoutcombine->addWidget(pCleanButton,0,Qt::AlignRight);

    pQVBoxLayout->addLayout(pQHBoxLayoutcombine);
    pQVBoxLayout->addStretch();
    pQVBoxLayout->addWidget(label1, 0, Qt::AlignCenter);
    pQVBoxLayout->addStretch();
    //按钮
    QPushButton *pButton = new QPushButton("下一步");

    connect(pDCommandLinkButton, &DCommandLinkButton::clicked, this, [ = ] {
        DFileDialog *pDFileDialog = new DFileDialog();
        pDFileDialog->setNameFilter("*.deb");
        pDFileDialog->setAcceptMode(QFileDialog::AcceptOpen);
        pDFileDialog->setFileMode(QFileDialog::ExistingFiles);
        if (pDFileDialog->exec() == QDialog::Accepted) {
            pCleanButton->show();
            pDCommandLinkButton->hide();
            QStringList listName = pDFileDialog->selectedFiles();
            m_pDFloatingMessage = new DFloatingMessage(DFloatingMessage::ResidentType, this);
            m_pDFloatingMessage->setMessage(listName[0]);
            pQVBoxLayout->addWidget(m_pDFloatingMessage);
        }
        label1->hide();
//        pQHBoxLayout2->addWidget(m_pDFloatingMessage);
//        pQVBoxLayout->addLayout(pQHBoxLayout2);
        //m_pDFloatingMessage->setIcon(QIcon::fromTheme("iso_progress"));
    });

    pQHBoxLayout1->addWidget(pDCommandLinkButton);
    pQHBoxLayout1->setAlignment(pDCommandLinkButton, Qt::AlignCenter);

    pQHBoxLayout->addSpacing(100);
    pQHBoxLayout->addWidget(pButton);
    pQHBoxLayout->addSpacing(100);

    pQVBoxLayout->addLayout(pQHBoxLayout1);
    pQVBoxLayout->addLayout(pQHBoxLayout);

    this->setLayout(pQVBoxLayout);

    connect(pButton, &DPushButton::clicked,[=](){
        emit sendSignal(2);
    });
}
