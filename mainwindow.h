#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
class PlayerCircle;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent* pe) override;
private:
    void __createRect(QPainter*);
private:
    Ui::MainWindow *ui;
    QWidget* m_widget;
    QTimer timer;
    PlayerCircle* m_player1;
};

#endif // MAINWINDOW_H
