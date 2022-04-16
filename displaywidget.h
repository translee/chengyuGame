/**
 * @class   DisplayWidget
 * @author  github.com/translee
 * @date    2022/04/16
 * @brief   游戏图形显示区
 * @note
*/

#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H
#include <QWidget>

class DisplayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DisplayWidget(QWidget *parent= nullptr);
    virtual ~DisplayWidget();
    virtual void paintEvent(QPaintEvent*) override;
    inline void setText(const QString& s) { *m_text = s; }
private:
    void __createRect(QPainter* paint);
    void __createPlayerImage(QPainter* paint);
    void __createIdiomImage(QPainter* paint);
    void __createBombLine(QPainter* paint);
private:
    QTimer* m_timer;
    QString* m_text;
};

#endif // DISPLAYWIDGET_H
