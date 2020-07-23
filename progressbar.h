#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QWidget>
#include <QPushButton>
#include <QtUiPlugin/QDesignerExportWidget>
#include <QDebug>
#include <QMouseEvent>

namespace Ui {
class ProgressBar;
}

class QDESIGNER_WIDGET_EXPORT ProgressBar : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressBar(QWidget *parent = 0);
    ~ProgressBar();
    float m_location;

protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

private:
    Ui::ProgressBar *ui;
    QPushButton * m_button;
    bool m_button_pressed;
    bool m_from_set_location;

private slots:
    void button_clicked();

signals:
    void location_changed(float p);
public slots:
    void set_location(float p);
};

#endif // PROGRESSBAR_H
