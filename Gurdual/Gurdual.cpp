#include "Gurdual.h"

Gurdual::Gurdual(QWidget *parent)
	: QMainWindow(parent)
	, m_pEffect(NULL)
	, m_pAnimation(NULL)
{
	ui.setupUi(this);
	ui.btn->setStyleSheet("QPushButton{border:none; image: url(E:/movies/pics/Emily Bloom/017(11).jpg)}");
	ui.btn->hide();
	ui.btnShow->setText("show");
	connect(ui.btnShow, SIGNAL(clicked()), this, SLOT(OnShowClicked()));

	m_pEffect = new QGraphicsOpacityEffect(ui.btn);
	m_pEffect->setOpacity(1);
	ui.btn->setGraphicsEffect(m_pEffect);

	m_pAnimation = new QPropertyAnimation(m_pEffect, "opacity", this);
	m_pAnimation->setEasingCurve(QEasingCurve::Linear);
	m_pAnimation->setDuration(2500);
}

Gurdual::~Gurdual()
{
	if (m_pEffect) { delete m_pEffect; m_pEffect = NULL; }
	if (m_pAnimation) { delete m_pAnimation; m_pAnimation = NULL; }
}

void Gurdual::OnShowClicked()
{
	QString strShow = ui.btnShow->text();
	if (strShow.compare("show") == 0)
	{
		ui.btnShow->setText("hide");
		m_pAnimation->setStartValue(0);
		m_pAnimation->setEndValue(1);
		m_pAnimation->start(QAbstractAnimation::KeepWhenStopped);
		ui.btn->show();
	}
	else
	{
		ui.btnShow->setText("show");
		m_pAnimation->setStartValue(1);
		m_pAnimation->setEndValue(0);
		m_pAnimation->start(QAbstractAnimation::KeepWhenStopped);
	}
}


