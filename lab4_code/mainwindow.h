#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <brforcircle.h>
#include <brforsegment.h>
#include <QGridLayout>
#include <naivealgorithm.h>
#include <QPushButton>
#include <QLabel>
#include <dda.h>
#include <dialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void showBrCircle();
    void showBrSegment();
    void showNaive();
    void showDDA();
    void outOfRangeError();
private:
    Ui::MainWindow *ui;
    QGridLayout *l = new QGridLayout;
    BrForCircle *brfc = new BrForCircle(0,0,5);
    BrForSegment *brfs = new BrForSegment(0,0,5,5);
    NaiveAlgorithm *naive = new NaiveAlgorithm(0,0,5,5);
    DDA *dda = new DDA(0,0,5,5);
    QPushButton *pbBrCircle = new QPushButton;
    QPushButton *pbBrSegment= new QPushButton;
    QPushButton *pbNaiveAlgorithm = new QPushButton;
    QLabel* lText = new QLabel;
    QPushButton *pbDDA = new QPushButton;
    Dialog *d;
};
#endif // MAINWINDOW_H
