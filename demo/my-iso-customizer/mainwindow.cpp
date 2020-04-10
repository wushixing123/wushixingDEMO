#include "mainwindow.h"
#include <QStandardItemModel>

mainwindow::mainwindow(QWidget *parent)
    : DMainWindow(parent),
      m_pHBoxLayout(new QHBoxLayout()),
      m_pDListView(new DListView()),
      m_pStackedWidget(new QStackedWidget()),

      m_pSelectISO(new selectISO()),
      m_pselectConstruct(new selectConstruct()),
      m_pProgramConfiguration(new ProgramConfiguration()),
      m_pPreliminaryPreparation(new PreliminaryPreparation()),
      m_pIntermediateInstallation(new IntermediateInstallation()),
      m_pPostCleaning(new PostCleaning()),
      m_pSelectKernel(new SelectKernel()),
      m_pOutput(new Output()),

      m_pCentralWidget(new QWidget())
{

    m_pTitleBar = new DTitlebar(this);
    m_pTitleBar->setWindowFlag(Qt::WindowMaximizeButtonHint);
    m_pTitleBar->disableFlags();
    m_pTitleBar->setIcon(QIcon::fromTheme("deepin-editor"));

    connect(m_pSelectISO, &selectISO::sendSignal, this, &mainwindow::windowChange);
    connect(m_pselectConstruct, &selectConstruct::sendSignal, this, &mainwindow::windowChange);
    connect(m_pProgramConfiguration, &ProgramConfiguration::sendSignal, this, &mainwindow::windowChange);
    connect(m_pPreliminaryPreparation, &PreliminaryPreparation::sendSignal, this, &mainwindow::windowChange);
    connect(m_pIntermediateInstallation, &IntermediateInstallation::sendSignal, this, &mainwindow::windowChange);
    connect(m_pPostCleaning, &PostCleaning::sendSignal, this, &mainwindow::windowChange);
    connect(m_pSelectKernel, &SelectKernel::sendSignal, this, &mainwindow::windowChange);
    connect(m_pOutput, &Output::sendSignal, this, &mainwindow::windowChange);


    m_pItemModel = new QStandardItemModel(this);

    QStandardItem *pItem1 = new QStandardItem("1.选择ISO");
    //pItem1->setCheckState(Qt::Checked);
    m_pStackedWidget->addWidget(m_pSelectISO);
    m_has_ItemName_ItemWiget.insert("1.选择ISO", m_pSelectISO);
    m_pItemModel->appendRow(pItem1);


    QStandardItem *pItem2 = new QStandardItem("2.选择架构");
    pItem2->setEnabled(false);
    m_pStackedWidget->addWidget(m_pselectConstruct);
    m_has_ItemName_ItemWiget.insert("2.选择架构", m_pselectConstruct);
    m_pItemModel->appendRow(pItem2);

    QStandardItem *pItem3 = new QStandardItem("3.程序配置");
    pItem3->setEnabled(false);
    m_pStackedWidget->addWidget(m_pProgramConfiguration);
    m_has_ItemName_ItemWiget.insert("3.程序配置", m_pProgramConfiguration);
    m_pItemModel->appendRow(pItem3);

    QStandardItem *pItem4= new QStandardItem("4.前期准备");
    pItem4->setEnabled(false);
    m_pStackedWidget->addWidget(m_pPreliminaryPreparation);
    m_has_ItemName_ItemWiget.insert("4.前期准备", m_pPreliminaryPreparation);
    m_pItemModel->appendRow(pItem4);

    QStandardItem *pItem5= new QStandardItem("5.中期安装");
    pItem5->setEnabled(false);
    m_pStackedWidget->addWidget(m_pIntermediateInstallation);
    m_has_ItemName_ItemWiget.insert("5.中期安装", m_pIntermediateInstallation);
    m_pItemModel->appendRow(pItem5);

    QStandardItem *pItem6= new QStandardItem("6.后期清理");
    pItem6->setEnabled(false);
    m_pStackedWidget->addWidget(m_pPostCleaning);
    m_has_ItemName_ItemWiget.insert("6.后期清理", m_pPostCleaning);
    m_pItemModel->appendRow(pItem6);

    QStandardItem *pItem7= new QStandardItem("7.选择kernel");
    pItem7->setEnabled(false);
    m_pStackedWidget->addWidget(m_pSelectKernel);
    m_has_ItemName_ItemWiget.insert("7.选择kernel", m_pSelectKernel);
    m_pItemModel->appendRow(pItem7);

    QStandardItem *pItem8= new QStandardItem("8.输出");
    pItem8->setEnabled(false);
    //pItem8->setCheckState(Qt::Checked);
    m_pStackedWidget->addWidget(m_pOutput);
    m_has_ItemName_ItemWiget.insert("8.输出", m_pOutput);
    m_pItemModel->appendRow(pItem8);

    m_pDListView->setModel(m_pItemModel);
    m_pStackedWidget->setCurrentWidget(m_pSelectISO);
    connect(m_pDListView, &DListView::clicked, this, &mainwindow::slotListViewItemClicked, Qt::QueuedConnection);

    m_pHBoxLayout = new QHBoxLayout();
    m_pCentralWidget->setLayout(m_pHBoxLayout);
    setCentralWidget(m_pCentralWidget);
    m_pHBoxLayout->addWidget(m_pDListView, 1);
    m_pHBoxLayout->addWidget(m_pStackedWidget, 2);



    connect(m_pDListView, &DListView::clicked,[=](const QModelIndex &index){
        m_pItemModel->item(index.row())->setCheckState(Qt::Checked);
    });
    //m_pHBoxLayout = new QHBoxLayout();
    //m_pHBoxLayout->addWidget(m_pDListView, 2);
    //m_pHBoxLayout->addWidget(m_pStackedWidget, 8);

}


void mainwindow::slotListViewItemClicked(const QModelIndex &index)
{
    QString strItemName = index.data().toString();
    m_pStackedWidget->setCurrentWidget(m_has_ItemName_ItemWiget.value(strItemName));
}

//    if(m_has_ItemName_ItemWiget.value(strItemName) == nullptr)
//    {
//        qDebug() <<"11";
//    }
//    qDebug()<<strItemName;


void mainwindow::slotActionTriggred()
{

    m_oneAction->setIcon(QIcon(":/images/logo.svg"));
}


void mainwindow::windowChange(int num)
{
    QStandardItemModel *tem = m_pItemModel;
    tem->item(num)->setCheckState(Qt::Checked);
    tem->item(num+1)->setEnabled(true);
    m_pDListView->setCurrentIndex(tem->indexFromItem(tem->item(num + 1)));
//    setCurrentWidget()

    m_pStackedWidget->setCurrentIndex(num + 1);
}
