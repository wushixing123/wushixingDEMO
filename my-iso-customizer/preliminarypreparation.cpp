#include "preliminarypreparation.h"
#include <DLabel>
#include <DFontSizeManager>
#include <DCommandLinkButton>
#include <DPushButton>
#include <DFileDialog>
#include <DMessageManager>
PreliminaryPreparation::PreliminaryPreparation(QWidget *parent) : QWidget(parent)
{
    DLabel *label = new DLabel("前期准备");
    QFont font;
    font.setFamily("SimHei");
    font.setBold(true);
    label->setFont(font);
    DFontSizeManager::instance()->bind(label, DFontSizeManager::T3);


    DLabel *label1 = new DLabel("请选择前期准备");
    QFont font1;
    //font1.setFamily("SimHei");
    //font1.setPointSize(20);
    label1->setAlignment(Qt::AlignCenter);
    label1->setFont(font1);
    DFontSizeManager::instance()->bind(label1, DFontSizeManager::T2);



    DFileChooserEdit *p = new DFileChooserEdit();
    p->setNameFilters(QStringList("file(*.cpp)"));

    DCommandLinkButton *pDCommandLinkButton = new DCommandLinkButton(tr("选择脚本"));
    connect(pDCommandLinkButton, &DCommandLinkButton::clicked, this, [ = ] {
        DFileDialog *pDFileDialog = new DFileDialog();
        pDFileDialog->setAcceptMode(QFileDialog::AcceptOpen);
        pDFileDialog->setFileMode(QFileDialog::ExistingFiles);
        pDFileDialog->show();
        pDFileDialog->exec();

        QStringList strlistSelectedName = pDFileDialog->selectedFiles();
        for (QString strSelectFile : strlistSelectedName)
        {
            QFileInfo fileInfo(strSelectFile);
            DMessageManager::instance()->sendMessage(this, QIcon::fromTheme(":/icons/deepin/builtin/light/icons/progress.svg"), QString("%1").arg(fileInfo.filePath()));
        }
    });


    QPushButton *pButton = new QPushButton("下一步");

    QVBoxLayout *pQVBoxLayout = new QVBoxLayout();

    QHBoxLayout *pQHBoxLayout = new QHBoxLayout();
    QHBoxLayout *pQHBoxLayout1 = new QHBoxLayout();

    pQVBoxLayout->addWidget(label);
    pQVBoxLayout->addStretch();

    pQVBoxLayout->addWidget(label1);
    pQVBoxLayout->addStretch();

    pQHBoxLayout1->addSpacing(220);
    pQHBoxLayout1->addWidget(pDCommandLinkButton);
    pQHBoxLayout1->addSpacing(200);

    pQHBoxLayout->addSpacing(100);
    pQHBoxLayout->addWidget(pButton);
    pQHBoxLayout->addSpacing(100);

    pQVBoxLayout->addLayout(pQHBoxLayout1);
    pQVBoxLayout->addLayout(pQHBoxLayout);
    this->setLayout(pQVBoxLayout);

    connect(pButton, &DPushButton::clicked,[=](){
        emit sendSignal(3);
    });
}
