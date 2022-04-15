#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
class DisplayWidget;
class StatusShowWidget;
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void __refreshText();
private:
    Ui::MainWindow *ui;
    DisplayWidget* m_displayWidget;
    StatusShowWidget* m_statusShowWidget;
};

#endif // MAINWINDOW_H
