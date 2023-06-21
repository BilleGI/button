#include <QApplication>
#include <QVBoxLayout>
#include <QSlider>
#include "button.h"

#include <QMediaPlayer>
#include <QAudioOutput>

int POSITION(30);

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout vbox(&window);

    auto *redButton = new ImageButton (&window);
    redButton->setFixedSize(100,100);
    vbox.addWidget(redButton, Qt::AlignCenter);

    auto *volumeSlider = new QSlider(&window);
    volumeSlider->setOrientation(Qt::Horizontal);
    volumeSlider->setSliderPosition(POSITION);
    volumeSlider->setMaximum(100);
    volumeSlider->setFixedWidth(redButton->width());
    vbox.addWidget(volumeSlider);

    auto *sound = new QMediaPlayer(&window);
    auto *audioOutput = new QAudioOutput;
    audioOutput->setVolume((float)POSITION / 100);
    sound->setAudioOutput(audioOutput);
    sound->setSource(QUrl("qrc:/sound/click.mp3"));

    QObject::connect(redButton, &ImageButton::clicked, [sound]()
                     {
        sound->play();
    });

    QObject::connect(volumeSlider, &QSlider::sliderMoved, [audioOutput](int volume)
                     {
        audioOutput->setVolume((float)volume / 100);
    });

    window.setFixedSize(120,160);
    window.move(1000,400);
    window.show();
    return app.exec();
}
