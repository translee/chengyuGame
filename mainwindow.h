/**
 * @class   MainWindow
 * @author  github.com/translee
 * @date    2022/04/16
 * @brief   程序主窗口
 * @note:
*/

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
    virtual ~MainWindow();
    void addDanmuText();
private:
    Ui::MainWindow *ui;
    DisplayWidget* m_displayWidget;
    StatusShowWidget* m_statusShowWidget;
    QTimer* m_testTimer;
};

#endif // MAINWINDOW_H
