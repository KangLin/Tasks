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
    virtual ~CFrmTop() override;

    void SetText(const QString szText);
    int SetBackgroupImage(const QString szImage);
    int SetPopupMenu(QMenu* pMenu);
    
    enum POSTION
    {
        LeftTop,
        LeftCenter,
        LeftBottom,
        CenterTop,
        Center,
        CenterBottom,
        RightTop,
        RightCenter,
        RightBottom
    };
    int SetPostion(POSTION pos);
    
protected:
    virtual void mousePressEvent(QMouseEvent *e) override;
    virtual void mouseReleaseEvent(QMouseEvent *e) override;
    virtual void mouseMoveEvent(QMouseEvent *e) override;
    virtual void contextMenuEvent(QContextMenuEvent *event) override;
    virtual void showEvent(QShowEvent *event) override;
    virtual void closeEvent(QCloseEvent *event) override;
    
private:
    Ui::CFrmTop *ui;

    bool m_bMoveable;
    QPointF m_oldPos;
    QPoint m_oldTop;
    QRect m_rtDesktop;

    QImage m_bpBackgroup;
    QMenu* m_pPopupMenu;
    
    POSTION m_Postion;
};

#endif // FRMTOP_H
