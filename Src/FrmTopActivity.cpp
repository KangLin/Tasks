#include "FrmTopActivity.h"
#include <QInputDialog>

CFrmTopActivity::CFrmTopActivity(QWidget *parent): CFrmTop(parent)
{
    setAttribute(Qt::WA_DeleteOnClose, true);
    
    m_Menu.addAction(QIcon(":/icon/Close"), tr("Close"),
                     this, SLOT(deleteLater()));
    m_Menu.addAction(tr("Delay 5 Minute"),
                  this, SLOT(slotDelay5Minute(bool)));
    m_Menu.addAction(tr("Customize delay"),
                     this, SLOT(slotDelayCustomize(bool)));
    SetPopupMenu(&m_Menu);
    
    bool check = connect(&m_Timer, SIGNAL(timeout()), this, SLOT(deleteLater()));
    Q_ASSERT(check);
    StartTimer();
}

int CFrmTopActivity::StartTimer(int nMsec)
{
    m_StartTime = QTime::currentTime();
    m_Timer.start(nMsec);
    m_StartTime.start();
    return 0;
}

void CFrmTopActivity::slotDelay5Minute(bool checked)
{
    Q_UNUSED(checked);
    AddDelay(5);
}

void CFrmTopActivity::slotDelayCustomize(bool checked)
{
    Q_UNUSED(checked);
    bool ok = false;
    int n = QInputDialog::getInt(this,
                                 tr("Customize delay"),
                                 tr("Delay minute"),
                                 10,
                                 1,
                                 60 * 60 * 24,
                                 1,
                                 &ok);
    if(!ok)
        return;
    AddDelay(n);
}

int CFrmTopActivity::AddDelay(int nMinute)
{
    StartTimer((nMinute + m_Timer.interval() - m_StartTime.elapsed()) * 60 * 1000);
    return 0;
}
