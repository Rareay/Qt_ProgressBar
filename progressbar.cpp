#include "progressbar.h"
#include "ui_progressbar.h"

ProgressBar::ProgressBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressBar)
{
    ui->setupUi(this);

    this->setMinimumHeight(20);

    m_location = 0;
    m_button_pressed = false;
    m_from_set_location = false;

    m_button = new QPushButton(this);
    //m_button->setStyleSheet("border-image: url(:/bar2.png);");
    m_button->setMaximumHeight(14);
    m_button->setMaximumWidth(14);
    m_button->setMinimumHeight(14);
    m_button->setMinimumWidth(14);
    QIcon ico(":/bar2.png");
    m_button->setIcon(ico);
    m_button->setIconSize(QSize(14, 14));
    m_button->setFlat(true);

    connect(m_button, SIGNAL(pressed()), this, SLOT(button_clicked()));
}

ProgressBar::~ProgressBar()
{
    delete ui;
}

void ProgressBar::resizeEvent(QResizeEvent *event)
{
    float x = m_location * ((float)this->geometry().width() - 14) - m_button->width()/2 + 7;
    float y = (this->geometry().height() - ui->label->height())/2 - m_button->height();
    m_button->move((int)x, (int)y);

}

void ProgressBar::mouseReleaseEvent(QMouseEvent *event)
{
    m_button_pressed = false;
}

void ProgressBar::mouseMoveEvent(QMouseEvent *event)
{
    int pos = event->x();
    if (pos < 7 || pos > this->geometry().width() - 7)
        return;
    if (m_button_pressed == true) {
        int x = pos - m_button->width()/2;
        int y = (this->geometry().height() - ui->label->height())/2 - m_button->height();
        m_button->move(x, y);
        m_location = (float)(pos - 7) / (float)(this->geometry().width() - 14);
        if (m_from_set_location == false) {
            emit location_changed(m_location);
        } else {
            m_from_set_location = false;
        }
    }

}

void ProgressBar::button_clicked()
{
    m_button_pressed = true;
}

void ProgressBar::set_location(float p)
{
    m_location = p;
    float x = m_location * ((float)this->geometry().width() - 14) - m_button->width()/2 + 7;
    float y = (this->geometry().height() - ui->label->height())/2 - m_button->height();
    m_from_set_location = true;
    m_button->move((int)x, (int)y);
}
