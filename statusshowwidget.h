/**
 * @class   StatusShowWidget
 * @author  github.com/translee
 * @date    2022/04/16
 * @brief   玩家状态窗口
 * @note
*/

#ifndef STATUSSHOWWIDGET_H
#define STATUSSHOWWIDGET_H
#include <QWidget>

class StatusShowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StatusShowWidget(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent*) override;
signals:

};

#endif // STATUSSHOWWIDGET_H
