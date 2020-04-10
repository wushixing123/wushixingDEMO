#include "selectconstruct.h"
#include <DLabel>
#include <QFont>
#include <DFontSizeManager>
#include <DPushButton>
#include <DKeySequenceEdit>
#include <DMessageManager>
#include <QStandardItemModel>
#include <QStandardItem>

selectConstruct::selectConstruct(QWidget *parent) : QWidget(parent)
{
    DLabel *label = new DLabel("选择架构");
    QFont font;
    font.setFamily("SimHei");
    font.setBold(true);
    label->setFont(font);
    DFontSizeManager::instance()->bind(label, DFontSizeManager::T3);



    QPushButton *pButton = new QPushButton("下一步");

    QVBoxLayout *pQVBoxLayout = new QVBoxLayout();
    QHBoxLayout *pQHBoxLayout = new QHBoxLayout();


    QStandardItemModel *pMainItem = new QStandardItemModel(this);
    QStandardItem *pItem = new QStandardItem("ARM");
    //pItem->setCheckState(Qt::Checked);
    pMainItem->appendRow(pItem);

    QStandardItem *pItem1 = new QStandardItem("X86");
    //pItem1->setCheckState(Qt::Checked);
    pMainItem->appendRow(pItem1);

    QStandardItem *pItem2 = new QStandardItem("MIPS");
    //pItem2->setCheckState(Qt::Checked);
    pMainItem->appendRow(pItem2);


    m_pDListView = new DListView();
    m_pDListView->setModel(pMainItem);


    pQVBoxLayout->addWidget(label);
    pQVBoxLayout->addWidget(m_pDListView);

    pQVBoxLayout->addStretch();

    pQHBoxLayout->addSpacing(100);
    pQHBoxLayout->addWidget(pButton);
    pQHBoxLayout->addSpacing(100);
    pQVBoxLayout->addLayout(pQHBoxLayout);

    this->setLayout(pQVBoxLayout);

    connect(pButton, &DPushButton::clicked,[=](){
        emit sendSignal(1);
    });

    connect(m_pDListView, &DListView::clicked,[=](const QModelIndex &index){
        pMainItem->item(index.row())->setCheckState(Qt::Checked);
    });
}
