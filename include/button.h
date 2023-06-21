#pragma once
#include <QPushButton>
#include <QPixmap>

class ImageButton : public QPushButton
{
    Q_OBJECT
public:
    ImageButton() = default;
    ImageButton(QWidget *parrent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;
public slots:
    void setUp();
    void setDown();
private:
    QPixmap *mCurrentButtonPixmap = new QPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
};
