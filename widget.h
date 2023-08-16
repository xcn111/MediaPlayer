#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QFileDialog>
#include <music.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_chooseButton_clicked();

    void on_playbutton_clicked();

    void Slider_valueChanged(qint64 value);

    void Slider_update(qint64 value);

private:
    Ui::Widget *ui;
    QFileDialog *fd;
    music *ms;

};
#endif // WIDGET_H
