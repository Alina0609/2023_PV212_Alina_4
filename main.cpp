#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QPainter>
#include <QtMath>

struct qp //структура для хранения координаты при рисовании
{
    QPoint pos;
    int fl;
};

//главное окно
class mainw: public QFrame
{
public:
    explicit mainw();
    void paintEvent(QPaintEvent *event);
    QPoint pos; //координаты точки для рисования
    void mouseMoveEvent(QMouseEvent *event);
    QVector<qp> vcp; //массив (вектор) для хранения рисунка
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    int f;
};



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
