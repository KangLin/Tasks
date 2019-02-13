#ifndef FRMTOP_H
#define FRMTOP_H

#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <QMenu>
#include <QSharedPointer>

namespace Ui {
class CFrmTop;
}

class CFrmTop : public QWidget
{
    Q_OBJECT

public:
    explicit CFrmTop(QWidget *parent = nullptr);
    ~CFrmTop();

    void SetText(const QString szText);
    int SetBackgroupImage(const QString szImage);
    int SetPopupMenu(QSharedPointer<QMenu> menu);
    
protected:
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void contextMenuEvent(QContextMenuEvent *event);

private:
    Ui::CFrmTop *ui;

    bool m_bMoveable;
    QPointF m_oldPos;
    QPoint m_oldTop;
    QRect m_rtDesktop;

    QImage m_bpBackgroup;
    QSharedPointer<QMenu> m_popupMenu;
};

#endif // FRMTOP_H
