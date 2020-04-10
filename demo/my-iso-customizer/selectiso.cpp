#include "selectiso.h"
#include <QFont>
#include <DPushButton>
#include <DLabel>
#include <DFontSizeManager>

selectISO::selectISO(QWidget *parent) : QWidget(parent)
{

    DLabel *label = new DLabel("选择ISO");
    QFont font;
    font.setFamily("SimHei");
    font.setBold(true);
    label->setFont(font);
    DFontSizeManager::instance()->bind(label, DFontSizeManager::T3);

    DFileChooserEdit *p = new DFileChooserEdit();
    p->setNameFilters(QStringList("file(*.cpp)"));

    QPushButton *pButton = new QPushButton("下一步");

    QVBoxLayout *pQVBoxLayout = new QVBoxLayout();
    QHBoxLayout *pQHBoxLayout = new QHBoxLayout();

    pQVBoxLayout->addWidget(label);
    pQVBoxLayout->addWidget(p);
    pQVBoxLayout->addStretch();

    pQHBoxLayout->addSpacing(100);
    pQHBoxLayout->addWidget(pButton);
    pQHBoxLayout->addSpacing(100);
    pQVBoxLayout->addLayout(pQHBoxLayout);

    this->setLayout(pQVBoxLayout);

    connect(pButton, &DPushButton::clicked,[=](){
        emit sendSignal(0);
    });

}


selectISO::~selectISO()
{

}
