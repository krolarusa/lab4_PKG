#include "naivealgorithm.h"
#include <cmath>

#define roundf(x) floor(x + 0.5f)

NaiveAlgorithm::NaiveAlgorithm(int x1, int y1, int x2, int y2, QWidget *parent) : QWidget(parent)
{
    double dx = ((double)x2-(double)x1);  // Вычисляем разницу между координатами x
    double dy = ((double)y2-(double)y1);  // Вычисляем разницу между координатами y

    // Обработка случая, когда начальная и конечная точки совпадают
    if(dx == 0 && dy == 0){
        QPointF p;
        p.setX(0);
        p.setY(0);
        points.push_back(p);
        return;
    }

    // Выбираем ось с наибольшим шагом, а затем рассчитываем коэффициент наклона a и начальные значения x и y
    if(abs(dx) >= abs(dy)){
        double a = dy / dx;
        double x, y;
        if(x1 <= x2){
            x = x1;
            y = y1;
        } else {
            x = x2;
            y = y2;
            x2 = x1;
            y2 = y1;
        }

        // Проходим через каждую координату x и находим соответствующие значения y по прямой с наклоном a
        while(abs(x) <= abs(x2)){
            QPointF p;
            p.setX(roundf(x));  // Округление и установка координаты x точки
            p.setY(roundf(y + 0.5));  // Округление и установка координаты y точки
            points.push_back(p);  // Добавляем точку в массив точек
            x++;  // Увеличиваем x на 1
            y = y + a;  // Находим следующее y по наклону a
        }
    } else {
        double a = dx / dy;
        double x, y;
        if(y1 <= y2){
            x = x1;
            y = y1;
        } else {
            x = x2;
            y = y2;
            x2 = x1;
            y2 = y1;
        }

        // Аналогично, проходим через каждую координату y и находим соответствующие значения x по прямой с наклоном a
        while(abs(y) <= abs(y2)){
            QPointF p;
            p.setX(roundf(x + 0.5));  // Округление и установка координаты x точки
            p.setY(roundf(y));  // Округление и установка координаты y точки
            points.push_back(p);  // Добавляем точку в массив точек
            y++;  // Увеличиваем y на 1
            x = x + a;  // Находим следующее x по наклону a
        }
    }
}
