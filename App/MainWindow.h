#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QTabWidget>
#include "TasksList.h"
#include "FrmTasksList.h"
#include "FrmStickyList.h"

namespace Ui {
class CMainWindow;
}

class CMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();
    
private Q_SLOTS:
    void slotExit();
    void slotShow();
    void slotAbout();
    void slotStartRun(bool checked);
    
    void slotActivated(QSystemTrayIcon::ActivationReason reason);
    void on_actionExit_E_triggered();
    void on_actionAbout_A_triggered();   
    void on_actionSink_S_triggered();
    void on_actionOption_O_triggered();
    void on_actionUpdate_U_triggered();

    void on_actionSticky_list_L_triggered();
    
    void on_actionTasks_list_A_triggered();
    
protected:
    virtual void closeEvent(QCloseEvent *e);
    
private:
    int LoadStyle();
    int LoadStyle(const QString &szFile);
    
private:
    Ui::CMainWindow *ui;
    QMenu m_TrayIconMenu;
    QSystemTrayIcon m_TrayIcon;
    QAction* m_pShow;
    QAction* m_pStartRun;
    
    QTabWidget m_Table;
    CFrmTasksList m_FrmTasksList;
    CFrmStickyList m_frmStickyList;
};

#endif // MAINWINDOW_H