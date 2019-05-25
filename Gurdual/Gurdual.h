#ifndef GRADUAL_H 
#define GRADUAL_H

#include <QtWidgets/QMainWindow>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include "ui_Gurdual.h"

class Gurdual : public QMainWindow
{
	Q_OBJECT

public:
	Gurdual(QWidget *parent = Q_NULLPTR);

	Gurdual::~Gurdual();

private slots:
	void OnShowClicked();

private:
	Ui::GurdualClass ui;

	QGraphicsOpacityEffect* m_pEffect;
	QPropertyAnimation* m_pAnimation;
};

#endif //GRADUAL_H 
