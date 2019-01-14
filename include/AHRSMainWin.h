/*
Stratux AHRS Display
(c) 2018 Allen K. Lair, Unexploded Minds
*/

#ifndef __AHRSMAINWIN_H__
#define __AHRSMAINWIN_H__

#include <QMainWindow>
#include <QDateTime>

#include "ui_AHRSMainWin.h"


class StreamReader;
class AHRSCanvas;
class MenuDialog;
class QPushButton;


class AHRSMainWin : public QMainWindow, public Ui::AHRSMainWin
{
    Q_OBJECT

public:
    explicit AHRSMainWin( const QString &qsIP, bool bPortrait );
    ~AHRSMainWin();

    bool menuActive() { return (m_pMenuDialog != 0); }

public slots:
    void menu();

protected:
    void keyReleaseEvent( QKeyEvent *pEvent );
    void timerEvent( QTimerEvent *pEvent );

private:
    StreamReader *m_pStratuxStream;
    bool          m_bStartup;
    QDateTime     m_lastStatusUpdate;
    MenuDialog   *m_pMenuDialog;
    QString       m_qsIP;
    bool          m_bPortrait;

private slots:
    void statusUpdate( bool bStratux, bool bAHRS, bool bGPS, bool bTraffic );
    void resetLevel();
    void resetGMeter();
    void upgradeRosco();
    void shutdownStratux();
    void shutdownRoscoPi();
    void trafficToggled( bool bAll );
    void init();
};

#endif // __AHRSMAINWIN_H__
