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

//конструктор
mainw::mainw()
{
/* определяем свойства окна */
     this->resize(1000,600);
     this->move(100, 100);
     this->setWindowTitle("Рисунок");
     QPalette pl; //объект палитра необходим для заданимя фона окна
     pl.setColor(QPalette::Background, QColor(100, 200, 200)); //определить цвет
     this->setAutoFillBackground(true); //фон окна заливается автоматически
     this->setPalette(pl); //устанавливаем фон окна
     this->setMouseTracking(true); //отслеживаем движение мыши
     f = 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
