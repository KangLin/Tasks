/*++
Copyright (c) Kang Lin studio, All Rights Reserved

Author:
    Kang Lin(kl222@126.com）

Module Name:

    DlgAbout.cpp

Abstract:

    This file contains about dialog implement.
 */

#include "DlgAbout.h"
#include "ui_DlgAbout.h"
#include <QFile>
#include <QDir>
/*
 * Author: KangLin(Email:kl222@126.com)
 */
#include <QDateTime>

CDlgAbout::CDlgAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CDlgAbout)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_QuitOnClose, false);
    ui->lbVersion->setText(tr(" Version: ") + BUILD_VERSION + tr(" Arch:") + BUILD_ARCH);
    ui->lbDate->setText(tr("Build date:%1 %2").arg(__DATE__, __TIME__));
    ui->lbAuthor->setText(tr("Author: KangLin\nEmail:kl222@126.com"));
    ui->lbHome->setOpenExternalLinks(true);
    QString szHomePage = "https://github.com/KangLin/Tasks.git";
    ui->lbHome->setText(tr("Home page:") + "<a href=\"" + szHomePage + "\">"
                        + szHomePage + "</a>");
    ui->lbCopyright->setText(tr(" Copyright (C) 2018 - %1 KangLin Studio").arg(
                                 QString::number(QDate::currentDate().year())));
    QString szFile;
#ifdef MOBILE
    szFile = ":/file/ChangeLog";
    AppendFile(ui->txtChange, szFile);
    szFile = ":/file/License";
    AppendFile(ui->txtLicense, szFile);
    szFile = ":/file/Authors";
    AppendFile(ui->txtThinks, szFile);
#else
    szFile = qApp->applicationDirPath() + QDir::separator()
            + "ChangeLog.md";
    AppendFile(ui->txtChange, szFile);
    szFile = qApp->applicationDirPath() + QDir::separator()
            + "LICENSE.md";
    AppendFile(ui->txtLicense, szFile);
    szFile = qApp->applicationDirPath() + QDir::separator()
            + "Authors.md";
    AppendFile(ui->txtThinks, szFile);
#endif
}

CDlgAbout::~CDlgAbout()
{
    delete ui;
}

int CDlgAbout::AppendFile(QTextEdit* pEdit, const QString &szFile)
{
    QFile readme(szFile);
    if(readme.open(QFile::ReadOnly))
    {
        pEdit->append(readme.readAll());
        //把光标移动文档开始处
        QTextCursor cursor =   pEdit->textCursor();
        cursor.movePosition(QTextCursor::Start);
        pEdit->setTextCursor(cursor);
        readme.close();
    }
    return 0;
}

void CDlgAbout::on_pushButton_clicked()
{
    close();
}