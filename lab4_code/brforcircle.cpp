#include "brforcircle.h"
#include <QGraphicsItem>
#include <QColor>
#include <vector>
#include <iostream>

BrForCircle::BrForCircle(int x0, int y0, int radius, QWidget *parent) : QWidget(parent)
{
    QPoint p;
    int x = radius;
    int y = 0;
    int radiusError = 1 - x;
    while (x >= y) {
        // Добавляем 8 точек вокруг центральной точки (x0, y0), чтобы нарисовать окружность
        p.setX(x + x0);
        p.setY(y + y0);
        points.push_back(p);  // Добавляем точку в вектор точек
        p.setX(y + x0);
        p.setY(x + y0);
        points.push_back(p);
        p.setX(-x + x0);
        p.setY(y + y0);
        points.push_back(p);
        p.setX(-y + x0);
        p.setY(x + y0);
        points.push_back(p);
        p.setX(-x + x0);
        p.setY(-y + y0);
        points.push_back(p);
        p.setX(-y + x0);
        p.setY(-x + y0);
        points.push_back(p);
        p.setX(x + x0);
        p.setY(-y + y0);
        points.push_back(p);
        p.setX(y + x0);
        p.setY(-x + y0);
        points.push_back(p);
        ++y;
        if (radiusError < 0) {
            // Перемещаемся ближе к окружности
            radiusError += 2 * y + 1;
        } else {
            // Двигаемся диагонально к ближайшей точке окружности
            --x;
            radiusError += 2 * (y - x + 1);
        }
    }
}

