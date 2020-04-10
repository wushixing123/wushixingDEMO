#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QWidget>

class PushButton : public QWidget
{
    Q_OBJECT
public:
    explicit PushButton(QWidget *parent = nullptr);

signals:
    void sendSignal(int num);

public slots:
};

#endif // PUSHBUTTON_H
