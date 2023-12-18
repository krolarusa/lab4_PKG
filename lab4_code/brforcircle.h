#ifndef TARGET_H
#define TARGET_H

#include <QWidget>
#include <QPainter>
#include <vector>
#include <QPainterPath>

class BrForCircle : public QWidget
{
    Q_OBJECT
public:
    explicit BrForCircle(int,int, int,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*)
    {
        // Создание экземпляра QPainter для отображения графики в окне
        QPainter painter1(this);

        // Получение высоты (h) и ширины (w) окна, разделение на два для определения центра
        double h = this->height() / 2;
        double w = this->width() / 2;

        // Смещение начала координат в центр окна
        painter1.translate(w, h);

        // Установка масштаба для координатной плоскости
        double hScale = 20;  // Масштаб по оси Y
        double wScale = 20;  // Масштаб по оси X

        // Установка цвета пера и заливки для отрисовки прямоугольников(точек)
        painter1.setPen(QPen(Qt::red, 3));
        painter1.setBrush(Qt::red);

        // Отображение всех точек (каждая точка представлена прямоугольником)
        for(int i = 0; i < points.size(); i++){
            painter1.drawRect(points[i].x() * wScale, (points[i].y() - 1) * hScale, wScale, hScale);
        }

        // Инициализация объекта для отрисовки текста и установка начальных параметров шрифта
        QPainterPath text;
        QFont f("Times", 8);
        f.setStyleStrategy(QFont::ForceOutline);
        painter1.setPen(QPen(Qt::black, 1));

        // Рисование осей координат и маркировка значений на них
        painter1.drawLine(-this->width() / 2, 0, this->width() / 2, 0);
        painter1.drawLine(0, -this->height() / 2, 0, this->height() / 2);
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
            painter1.drawLine(-this->width() / 2, -i * hScale, this->width() / 2, -i * hScale);
            painter1.drawLine(-this->width() / 2, i * hScale, this->width() / 2, i * hScale);
        }

        // Рисование текста и значений на координатной плоскости
        painter1.setPen(QPen(Qt::black, 1));
        painter1.setBrush(QBrush(Qt::black));
        painter1.drawPath(text);
    }
signals:
private:
    std::vector<QPointF> points;
    int radius;
};

#endif // TARGET_H
