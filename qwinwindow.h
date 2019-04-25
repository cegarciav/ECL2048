#ifndef QWINWINDOW_H
#define QWINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class QResetButton;

class QWinWindow : public QWidget
{
    Q_OBJECT
public:
    explicit QWinWindow(QWidget *parent = nullptr);
    QResetButton* getResetBtn() const;

private:
    QLabel* gamewon = nullptr;
    QPushButton * continuer_button = nullptr;
    QResetButton * reset_button;

signals:

public slots:
    void continuer_option();
};

#endif // QWINWINDOW_H
