#include "dda.h"
#include <QPointF>
#include <cmath>

#define roundf(x) floor(x + 0.5f)

DDA::DDA(int x1, int y1, int x2, int y2, QWidget *parent) : QWidget(parent)
{
    int step;
    int deltaX = x2 - x1;
    int deltaY = y2 - y1;
    QPointF p;

    // Если начальная и конечная точки совпадают
    if (deltaX == 0 && deltaY == 0) {
        p.setX(0);
        p.setY(0);
        points.push_back(p);
        return;
    }

    // Определяем, по какой оси шаг больше
    if (abs(deltaX) >= abs(deltaY)) {
        step = deltaX;
    } else {
        step = deltaY;
    }

    // Вычисляем приращения на каждом шаге
    double dX = deltaX / abs((double)step);
    double dY = deltaY / abs((double)step);
    double x = x1;
    double y = y1;

    // Проходим через каждый шаг и добавляем точки в вектор
    for (int i = 1; i <= abs(step); i++) {
        p.setX(roundf(x));
        p.setY(roundf(y));
        points.push_back(p);
        x = x + dX;
        y = y + dY;
    }
}
