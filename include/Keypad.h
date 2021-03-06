/*
Stratofier Stratux AHRS Display
(c) 2018 Allen K. Lair, Sky Fun
*/

#ifndef __StratofierKEYPAD_H__
#define __StratofierKEYPAD_H__

#include <QDialog>

#include "ui_Keypad.h"


class Keypad : public QDialog, public Ui::Keypad
{
    Q_OBJECT

public:
    explicit Keypad( QWidget *pParent, const QString &qsTitle, bool bTimeMode = false );
    ~Keypad();

    double  value();
    QString textValue();
    void    clear();
    void    setTitle( const QString &qsTitle );

protected:
    void resizeEvent( QResizeEvent* );

private:
    bool    m_bTimeMode;
    int     m_iTimePos;

private slots:
    void keypadClick();
};

#endif // __StratofierKEYPAD_H__
