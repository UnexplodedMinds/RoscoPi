/*
Stratux AHRS Display
(c) 2018 Allen K. Lair, Unexploded Minds
*/

#include <QFont>
#include <QFontMetrics>
#include <QRect>

#include "Canvas.h"


extern QFont wee;
extern QFont tiny;
extern QFont small;
extern QFont med;
extern QFont large;


Canvas::Canvas( double dWidth, double dHeight )
{
	QFontMetrics weeMetrics( wee );
	QRect        weeRect( weeMetrics.boundingRect( "0" ) );
	QFontMetrics tinyMetrics( tiny );
    QRect        tinyRect( tinyMetrics.boundingRect( "0" ) );
    QFontMetrics smallMetrics( small );
    QRect        smallRect( smallMetrics.boundingRect( "0" ) );
    QFontMetrics medMetrics( med );
    QRect        medRect( medMetrics.boundingRect( "0" ) );
    QFontMetrics largeMetrics( large );
    QRect        largeRect( largeMetrics.boundingRect( "0" ) );

    m_preCalc.dH = dHeight;
    m_preCalc.dH2 = dHeight / 2.0;
    m_preCalc.dH4 = dHeight / 4.0;
    m_preCalc.dH5 = dHeight / 5.0;
    m_preCalc.dH7 = dHeight / 7.0;
    m_preCalc.dH10 = dHeight / 10.0;
    m_preCalc.dH20 = dHeight / 20.0;
	m_preCalc.dH30 = dHeight / 30.0;
	m_preCalc.dH40 = dHeight / 40.0;
	m_preCalc.dH160 = dHeight / 160.0;
    m_preCalc.dW = dWidth;
    m_preCalc.dW2 = dWidth / 2.0;
    m_preCalc.dW4 = dWidth / 4.0;
    m_preCalc.dW5 = dWidth / 5.0;
    m_preCalc.dW7 = dWidth / 7.0;
    m_preCalc.dW10 = dWidth / 10.0;
    m_preCalc.dW20 = dWidth / 20.0;
	m_preCalc.dW30 = dWidth / 30.0;
	m_preCalc.dW40 = dWidth / 40.0;

	m_preCalc.iWeeFontHeight = weeRect.height();
	m_preCalc.iTinyFontHeight = tinyRect.height();
    m_preCalc.iSmallFontHeight = smallRect.height();
    m_preCalc.iMedFontHeight = medRect.height();
    m_preCalc.iLargeFontHeight = largeRect.height();
    m_preCalc.iTinyFontWidth = tinyRect.width();

    m_preCalc.dAspectL = m_preCalc.dW / m_preCalc.dH;
    m_preCalc.dAspectP = m_preCalc.dH / m_preCalc.dW;
}


CanvasConstants Canvas::contants()
{
    return m_preCalc;
}


int Canvas::largeWidth( const QString &qsText )
{
    QFontMetrics largeMetrics( large );
    QRect        largeRect( largeMetrics.boundingRect( qsText ) );

    return largeRect.width();
}


int Canvas::medWidth(const QString &qsText)
{
	QFontMetrics medMetrics( med );
	QRect        medRect( medMetrics.boundingRect( qsText ) );

	return medRect.width();
}