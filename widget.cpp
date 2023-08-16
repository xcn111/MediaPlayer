#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    fd=new QFileDialog();
    fd->setDirectory("C:/Users");

    ms=new music();

    connect(fd, &QFileDialog::fileSelected, [&](const QString &file) {
            QFileInfo fileInfo(file);
            QString fileName = fileInfo.fileName();
            ui->fileLabel->setText(fileName);
            ms->player->setSource(QUrl::fromLocalFile(file));
        });

//    ui->horizontalSlider->
    connect(ms->player,SIGNAL(positionChanged(qint64)),this,SLOT(Slider_valueChanged(qint64)));
    connect(ms->player,SIGNAL(durationChanged(qint64)),this,SLOT(Slider_update(qint64)));
    connect(ui->horizontalSlider,&QSlider::sliderMoved,[&](){
        disconnect(ms->player,SIGNAL(positionChanged(qint64)),this,SLOT(Slider_valueChanged(qint64)));
    });
    connect(ui->horizontalSlider,&QSlider::sliderReleased,[&](){
        ms->player->pause();
        ms->player->setPosition(ui->horizontalSlider->value());
        qDebug()<<ui->horizontalSlider->value()<<'\n';
        ms->player->play();
        connect(ms->player,SIGNAL(positionChanged(qint64)),this,SLOT(Slider_valueChanged(qint64)));
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_chooseButton_clicked()
{
    fd->show();
}


void Widget::on_playbutton_clicked()
{
    ms->player->play();
}


void Widget::Slider_valueChanged(qint64 value)
{
    ui->horizontalSlider->setValue(value);
}

void Widget::Slider_update(qint64 value)
{
    ui->horizontalSlider->setRange(0,value);
    qDebug()<<value;
}

