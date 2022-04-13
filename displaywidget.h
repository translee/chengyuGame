#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H
#include <QWidget>
class DisplayWidget : public QWidget
{
public:
    DisplayWidget();
    ~DisplayWidget();
    virtual void paintEvent(QPaintEvent*) override;
private:
    void __createRect(QPainter* paint);
    void __createPlayerImage(QPainter* paint);
    void __refreshWidget();
private:
    QTimer* m_timer;
};

#endif // DISPLAYWIDGET_H
