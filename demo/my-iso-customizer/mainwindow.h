#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <DMenu>
#include <DListView>
#include "selectiso.h"
#include <QStackedWidget>
#include <QStandardItemModel>
#include <DMainWindow>
#include <DTitlebar>
#include "selectconstruct.h"
#include "programconfiguration.h"
#include "preliminarypreparation.h"
#include "intermediateinstallation.h"
#include "postcleaning.h"
#include "selectkernel.h"
#include "output.h"
#include "pushbutton.h"

#include <QtDebug>

DWIDGET_USE_NAMESPACE

class mainwindow : public DMainWindow
{
    Q_OBJECT
public:
    explicit mainwindow(QWidget *parent = nullptr);
    //DTitlebar *titlebar() const;
signals:

public slots:
    void windowChange(int n);
    void slotListViewItemClicked(const QModelIndex &index);
    void slotActionTriggred();
private:
    QHBoxLayout *m_pHBoxLayout;
    DListView   *m_pDListView;
    QStackedWidget *m_pStackedWidget;
    QStandardItemModel *m_pItemModel;
    QMap<QString, QWidget *> m_has_ItemName_ItemWiget;

    PushButton *m_pPushButtonWidget;
    QWidget *m_pCentralWidget;
    selectISO *m_pSelectISO;
    selectConstruct *m_pselectConstruct;
    ProgramConfiguration *m_pProgramConfiguration;
    PreliminaryPreparation *m_pPreliminaryPreparation;
    IntermediateInstallation *m_pIntermediateInstallation;
    PostCleaning *m_pPostCleaning;
    SelectKernel *m_pSelectKernel;
    Output *m_pOutput;


    QAction *m_oneAction;
    DTitlebar *m_pTitleBar;
};

#endif // MAINWINDOW_H
