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
    QPalette pl; //объект палитра необходим для задания фона окна
    pl.setColor(QPalette::Background, QColor(100, 200, 200)); //определить цвет
    this->setAutoFillBackground(true); //фон окна заливается автоматически
    this->setPalette(pl); //устанавливаем фон окна
    this->setMouseTracking(true); //отслеживаем движение мыши
    f = 0;
}

//обработка события перерисования окна
void mainw::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setPen (QPen(Qt::black,Qt::SolidLine)); //цвет и тип линий
    for (int i = 1; i < vcp.size(); ++i)
    {
        if(vcp[i-1].fl==1)continue; //от этой координаты не рисуем
        //проводим линию
        p.drawLine(vcp[i-1].pos.x(), vcp[i-1].pos.y(), vcp[i].pos.x(), vcp[i].pos.y());
    }
}

//обработка движения мыши
void mainw::mouseMoveEvent(QMouseEvent *event)
{
    if(!f)return; //запрет на рисование?
    this->pos = event->pos(); //положение курсора мыши
    qp qp1;
    qp1.pos = this->pos;
    qp1.fl = 0;
    vcp.append(qp1); //добавили в массив для рисования
    this->update();  //обновить экран
}

//нажатие кнопки мыши
void mainw::mousePressEvent(QMouseEvent * e)
{
    //кнопка нажата и при движении рисуется линия
    if(e->button() == Qt::LeftButton)f=1;
}
//отпускание кнопки мыши
void mainw::mouseReleaseEvent(QMouseEvent * e)
{
    if(e->button() == Qt::LeftButton)
    {
        f=0;
        //установили флаг запрета оисования
        if(vcp.size()>0)vcp[vcp.size()-1].fl=1;
    }
    if(e->button() == Qt::RightButton)
    {
        //удалить последний элемент линии
        if(vcp.size()>0)vcp.remove(vcp.size()-1);
        //от последней точки линия не проводится
        if(vcp.size()>0)vcp[vcp.size()-1].fl=1;
        //обновить экран
        this->update();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
