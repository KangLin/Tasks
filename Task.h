#ifndef TASK_H
#define TASK_H

#pragma once

#include <QObject>
#include <QTime>
#include <QTimer>

class CTask : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ GetName WRITE SetName)
    Q_PROPERTY(QString title READ GetTitle WRITE SetTitle)
    Q_PROPERTY(QString content READ GetContent WRITE SetContent)
    Q_PROPERTY(int id READ GetId WRITE SetId)
    Q_PROPERTY(int interval READ GetInterval WRITE SetInterval)
    Q_PROPERTY(int promptInterval READ GetPromptInterval WRITE SetPromptInterval)
    Q_PROPERTY(QString startSound WRITE SetStartSound)
    Q_PROPERTY(QString runSound WRITE SetRunSound)
    
public:
    Q_INVOKABLE explicit CTask(QObject *parent = nullptr);

    /**
     * @brief CTask
     * @param nInterval: The interval between Start() and onRun(), in milliseconds
     * @param nPromptInterval: if is 0, don't prompt
     * @param parent
     */
    Q_INVOKABLE explicit CTask(int nInterval,
                   int nPromptInterval = 0,
                   QObject *parent = nullptr);
    virtual ~CTask();
    
    Q_INVOKABLE virtual int GetId();
    Q_INVOKABLE virtual int SetId(int id);
    Q_INVOKABLE virtual QString GetName();
    Q_INVOKABLE virtual int SetName(QString szName);
    Q_INVOKABLE virtual int SetTitle(QString szTitle);
    Q_INVOKABLE virtual QString GetTitle();
    Q_INVOKABLE virtual int SetContent(QString szContent);
    Q_INVOKABLE virtual QString GetContent();
    Q_INVOKABLE virtual int GetInterval();
    Q_INVOKABLE virtual int SetInterval(int nInterval);
    Q_INVOKABLE virtual int GetPromptInterval();
    Q_INVOKABLE virtual int SetPromptInterval(int interval);
    Q_INVOKABLE virtual int SetStartSound(const QString & szSound = QString());
    Q_INVOKABLE virtual int SetRunSound(const QString & szSound = QString());
    virtual int SetSound(const QString &szStartSound = QString(), const QString &szRunSound = QString());
    virtual int LoadSettings();
    virtual int SaveSettings();

    virtual int Start();

    /**
     * @brief Check if the task can run
     * @return 
     */
    virtual int Check();
    virtual bool End();

protected Q_SLOTS:
    virtual void slotPrompt();
    
protected:
    virtual int onStart();
    /**
     * @brief Run the task
     * @return 
     */
    virtual int onRun();

protected:
    int Elapsed();
    int Remaining();
    QString szRemaining();
    
private:
    int m_nId;
    QString m_szName;
    QString m_szTitle;
    QString m_szContent;
    QTime m_Time;
    int m_nInterval;
    QTimer m_PromptTimer;
    int m_nPromptInterval;
    QString m_szStartSound, m_szRunSound;
    
    int Init();    
};

#endif // TASK_H
