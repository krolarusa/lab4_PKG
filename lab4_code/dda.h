#ifndef DDA_H
#define DDA_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <vector>
#include <iostream>

class DDA : public QWidget
{
public:
    DDA(int,int,int,int,QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*)
    {
        // Определение минимальной стороны (width или height) для выбора размера окна
        int side = qMin(width(), height());

        // Создание экземпляра QPainter для отображения графики в окне
        QPainter painter1(this);

        // Определение высоты (h) и ширины (w) окна, разделение на два для определения центра
        double h = this->height() / 2;
        double w = this->width() / 2;

        // Установка масштаба для координатной плоскости
        double hScale = 20;  // Масштаб по оси Y
        double wScale = 20;  // Масштаб по оси X

        // Смещение начала координат в центр окна
        painter1.translate(w, h);

        // Установка параметров для рисования и заполнения прямоугольников (точек)
        painter1.setPen(QPen(Qt::red, 3));
        painter1.setBrush(Qt::red);

        // Отображение всех точек (каждая точка представлена прямоугольником)
        for(int i = 0; i < points.size(); i++){
            painter1.drawRect((points[i].x()) * wScale, -(points[i].y() + 1) * hScale, wScale, hScale);
        }

        // Инициализация объекта для отрисовки текста и маркировки значений
        QPainterPath text;
        QFont f("Times", 8);
        f.setStyleStrategy(QFont::ForceOutline);
        painter1.setPen(QPen(Qt::black, 1));

        // Рисование осей координат и маркировка значений на них
        painter1.drawLine(-this->width()/2, 0, this->width()/2, 0);
        painter1.drawLine(0, -this->height()/2, 0, this->height()/2);
        painter1.setPen(QPen(Qt::black, 3));
        text.addText(0, 0, f, QString::number(0));

        // Рисование вертикальных линий и маркировка по оси X
        for(int i = 1; i < this->width() / (wScale * 2); i++){
            painter1.setPen(QPen(Qt::black, 3));
            painter1.drawPoint(i * wScale, 0);
            text.addText(i * wScale, 12, f, QString::number(i));
            painter1.drawPoint(-i * wScale, 0);
            text.addText(-i * wScale, 12, f, QString::number(-i));
            painter1.setPen(QPen(Qt::black, 1));
            painter1.drawLine(-i * wScale, -this->height() / 2, -i * wScale, this->height() / 2);
            painter1.drawLine(i * wScale, -this->height() / 2, i * wScale, this->height() / 2);
        }

        // Рисование горизонтальных линий и маркировка по оси Y
        for(int i = 1; i < this->height() / (hScale * 2); i++){
            painter1.setPen(QPen(Qt::black, 3));
            painter1.drawPoint(0, i * hScale);
            text.addText(0, -i * hScale, f, QString::number(i));
            painter1.drawPoint(0, -i * hScale);
            text.addText(0, i * hScale, f, QString::number(-i));
            painter1.setPen(QPen(Qt::black, 1));
            painter1.drawLine(-this->width()/2, -i*hScale, this->width()/2, -i*hScale);
            painter1.drawLine(-this->width()/2, i*hScale, this->width()/2, i*hScale);
        }
        painter1.setPen(QPen(Qt::black, 1));
        painter1.setBrush(QBrush(Qt::black));
        painter1.drawPath(text);
    }
private:
    std::vector <QPointF> points;
};

#endif // DDA_H
