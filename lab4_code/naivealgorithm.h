#ifndef NAIVEALGORITHM_H
#define NAIVEALGORITHM_H

#include <QWidget>
#include <vector>
#include <QPainter>
#include <QPainterPath>
class NaiveAlgorithm : public QWidget
{
    Q_OBJECT
public:
    explicit NaiveAlgorithm(int, int, int, int, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*)
    {
        // Определение минимальной стороны (width или height) для выбора размера окна
        int side = qMin(width(), height());

        // Создание экземпляра QPainter и определение значений центра окна
        QPainter painter1(this);
        double h = this->height();
        double w = this->width();
        h /= 2;  // Определение координаты y центра окна
        w /= 2;  // Определение координаты x центра окна
        double hScale = 20;  // Масштаб по оси y
        double wScale = 20;  // Масштаб по оси x

        // Смещение начала координат в центр окна
        painter1.translate(w, h);

        // Установка параметров для рисования прямоугольников (точек)
        painter1.setPen(QPen(Qt::red, 3));
        painter1.setBrush(Qt::red);

        // Отображение всех точек (каждая точка представлена прямоугольником)
        for(int i = 0; i < points.size(); i++){
            painter1.drawRect(points[i].x() * wScale, -(points[i].y() + 1) * hScale, wScale, hScale);
        }

        // Настройка параметров для рисования координатной сетки и маркировки
        QPainterPath text;
        QFont f("Times", 8);
        f.setStyleStrategy(QFont::ForceOutline);
        painter1.setPen(QPen(Qt::black, 1));
        painter1.drawLine(-this->width() / 2, 0, this->width() / 2, 0);
        painter1.drawLine(0, -this->height() / 2, 0, this->height() / 2);
        painter1.setPen(QPen(Qt::black, 3));
        text.addText(0, 0, f, QString::number(0));

        // Рисование вертикальных линий и маркировки по оси x
        // а также маркировка значений точек
        for(int i = 1; i < this->width() / (wScale * 2); i++){
            // Отметка оси X
            painter1.setPen(QPen(Qt::black, 3));
            painter1.drawPoint(i * wScale, 0);
            text.addText(i * wScale, 12, f, QString::number(i));
            painter1.drawPoint(-i * wScale, 0);
            text.addText(-i * wScale, 12, f, QString::number(-i));

            // Рисование вертикальной линии
            painter1.setPen(QPen(Qt::black, 1));
            painter1.drawLine(-i * wScale, -this->height() / 2, -i * wScale, this->height() / 2);
            painter1.drawLine(i * wScale, -this->height() / 2, i * wScale, this->height() / 2);
        }

        // Аналогично, рисование горизонтальных линий и маркировка по оси y
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

        // Рисование текста и маркировка значений
        painter1.setPen(QPen(Qt::black, 1));
        painter1.setBrush(QBrush(Qt::black));
        painter1.drawPath(text);
    }
signals:

private:
    std::vector <QPointF> points;
};

#endif // NAIVEALGORITHM_H
