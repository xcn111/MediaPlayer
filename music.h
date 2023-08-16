#ifndef MUSIC_H
#define MUSIC_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class music : public QObject
{
    Q_OBJECT
public:
    explicit music(QObject *parent = nullptr);
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

private:
};

#endif // MUSIC_H
