#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QDebug>
#include <QInputDialog>
#include <QSound>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsPixmapItem>

#include "player.h"
#include "gamescreen.h"
#include "sun.h"
#include "peashooter.h"
#include "sunflower.h"
#include "cherrybomb.h"
#include "wallnut.h"
#include "potatomine.h"
#include "snowpea.h"
#include "chomper.h"
#include "repeater.h"
#include "regular.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    // Button functions.
    void on_quitButton_clicked();

    void on_newButton_clicked();

    void on_startButton_clicked();

    void on_deleteButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_peaShooterButton_clicked();

    void on_sunFlowerButton_clicked();

    void on_cherryBombButton_clicked();

    void on_wallNutButton_clicked();

    void on_potatoMineButton_clicked();

    void on_snowPeaButton_clicked();

    void on_chomperButton_clicked();

    void on_repeaterButton_clicked();

    // Sun functions.
    void createSun();
    void updateSunPoints();

    // Add plant functions.
    void addImage();

private:
    // UI variables.
    Ui::MainWindow *ui;
    GameScreen *gameScreen;
    QGraphicsScene *scene;

    // Plant objects.
    PeaShooter *peaShooter;
    SunFlower *sunFlower;
    Sun *sun;
    CherryBomb *cherryBomb;
    WallNut *wallNut;
    PotatoMine *potatoMine;
    SnowPea *snowPea;
    Chomper *chomper;
    Repeater *repeater;

    // Zombie objects.
    Regular *regular;

    // Timers.
    QTimer *moveTimer;
    QTimer *createTimer;
    QTimer *updateSunPointsTimer;

    QString plantClicked;
    bool buttonClicked;
    bool imageAdded;
};

#endif // MAINWINDOW_H
