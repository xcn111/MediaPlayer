#include "music.h"
#include <QMediaPlayer>
#include <QAudioOutput>

music::music(QObject *parent)
    : QObject{parent}
{
    player = new QMediaPlayer();
    audioOutput = new QAudioOutput();
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(50);

}
