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
    //文件选择框
    DFileChooserEdit *p = new DFileChooserEdit();
    p->setNameFilters(QStringList("file(*.cpp)"));
    //数字按钮
    DCommandLinkButton *pCleanButton = new DCommandLinkButton(tr("全部清除"));
    pCleanButton->hide();
    DCommandLinkButton *pDCommandLinkButton = new DCommandLinkButton(tr("选择程序dev包"));
    connect(pDCommandLinkButton, &DCommandLinkButton::clicked, this, [ = ] {
        DFileDialog *pDFileDialog = new DFileDialog();
        pDFileDialog->setNameFilter("*.dev");
        pDFileDialog->setAcceptMode(QFileDialog::AcceptOpen);
        pDFileDialog->setFileMode(QFileDialog::ExistingFiles);
        if (pDFileDialog->exec() == QDialog::Accepted) {
            pCleanButton->show();
        }
        m_pDFloatingMessage = new DFloatingMessage(DFloatingMessage::ResidentType, this);
        m_pDFloatingMessage->setIcon(QIcon::fromTheme("iso_progress"));


        QStringList strlistSelectedName = pDFileDialog->selectedFiles();
        for (QString strSelectFile : strlistSelectedName) {
            QFileInfo fileInfo(strSelectFile);
            DMessageManager::instance()->sendMessage(this, QIcon::fromTheme(":/icons/deepin/builtin/light/icons/progress.svg"), QString("%1").arg(fileInfo.filePath()));
        }
    });
    //按钮
    QPushButton *pButton = new QPushButton("下一步");
    //进行整体布局
    QWidget *pWidget = new QWidget(this);
    //主布局
    QVBoxLayout *pQVBoxLayout = new QVBoxLayout();

    QVBoxLayout *pVBoxLayout = new QVBoxLayout();
    QHBoxLayout *pQHBoxLayout = new QHBoxLayout();
    QHBoxLayout *pQHBoxLayout1 = new QHBoxLayout();

    pQVBoxLayout->addWidget(label);
    pQVBoxLayout->addWidget(pWidget);

    pVBoxLayout->addWidget(pWidget);
    pVBoxLayout->addWidget(m_pDFloatingMessage);

    pQVBoxLayout->addStretch();

    pQVBoxLayout->addWidget(label1);
    pQVBoxLayout->addStretch();

    pQVBoxLayout->addStretch();

    pQHBoxLayout1->addSpacing(220);
    pQHBoxLayout1->addWidget(pDCommandLinkButton);
    //pDCommandLinkButton->addAction();
    pQHBoxLayout1->addSpacing(200);

    pQHBoxLayout->addSpacing(100);
    pQHBoxLayout->addWidget(pButton);
    pQHBoxLayout->addSpacing(100);

    pVBoxLayout->addLayout(pVBoxLayout);
    pQVBoxLayout->addLayout(pQHBoxLayout1);
    pQVBoxLayout->addLayout(pQHBoxLayout);

    this->setLayout(pQVBoxLayout);

    connect(pButton, &DPushButton::clicked,[=](){
        emit sendSignal(2);
    });
}
