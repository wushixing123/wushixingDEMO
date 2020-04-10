#include "selectkernel.h"
#include <QFont>
#include <DPushButton>
#include <DLabel>
#include <DFontSizeManager>

SelectKernel::SelectKernel(QWidget *parent) : QWidget(parent)
{
    DLabel *label = new DLabel("选择Kernel");
    QFont font;
    font.setFamily("SimHei");
    font.setBold(true);
    label->setFont(font);
    DFontSizeManager::instance()->bind(label, DFontSizeManager::T3);

    DLabel *label1 = new DLabel("kernel");
    QFont font1;
    font1.setFamily("SimHei");
    //font.setWeight(20);
    label1->setFont(font1);
    DFontSizeManager::instance()->bind(label1, DFontSizeManager::T5);

    DLabel *label2 = new DLabel("initrd");
    QFont font2;
    font2.setFamily("SimHei");
    label2->setFont(font2);
    DFontSizeManager::instance()->bind(label2, DFontSizeManager::T5);



    DFileChooserEdit *pKernel = new DFileChooserEdit();
    pKernel->setNameFilters(QStringList("file(*.cpp)"));

    DFileChooserEdit *pInitrd = new DFileChooserEdit();
    pKernel->setNameFilters(QStringList("file(*.cpp)"));

    QPushButton *pButton = new QPushButton("下一步");

    QVBoxLayout *pQVBoxLayout = new QVBoxLayout();
    QHBoxLayout *pQHBoxLayout = new QHBoxLayout();

    pQVBoxLayout->addWidget(label);
    pQVBoxLayout->addWidget(label1);
    pQVBoxLayout->addWidget(pKernel);
    pQVBoxLayout->addWidget(label2);
    pQVBoxLayout->addWidget(pInitrd);



    pQVBoxLayout->addStretch();

    pQHBoxLayout->addSpacing(100);
    pQHBoxLayout->addWidget(pButton);
    pQHBoxLayout->addSpacing(100);


    pQVBoxLayout->addLayout(pQHBoxLayout);
    this->setLayout(pQVBoxLayout);

    connect(pButton, &DPushButton::clicked,[=](){
        emit sendSignal(6);
    });
}
