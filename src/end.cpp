#include"end.h"
#include"mainwindow.h"
#include<QGraphicsScene>

End::End()
{
    //set scene
    endscene =new QGraphicsScene();
    endscene->setSceneRect(0,0,500,400);

    //set view to scene
     setScene(endscene);
     //set view
     setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setFixedSize(500,300);

     //add buttom
    bt_end =new QPushButton(this);
    bt_end =new QPushButton(this);
    QPixmap pixmap1(":/image/exit.png");
    QIcon ButtonIcon1(pixmap1);
    bt_end->setIcon(ButtonIcon1);
    bt_end->setIconSize(QSize(60,60));
    bt_end->setFixedSize(QSize(60,60));
    bt_end->setGeometry(QRect(QPoint(400,0),QSize(50,50)));
    connect(bt_end,SIGNAL(clicked(bool)),this,SLOT(exitgame()));


    bt_restart =new QPushButton(this);
    QPixmap pixmap(":/image/bt_restart.png");
    QIcon ButtonIcon(pixmap);
    bt_restart->setIcon(ButtonIcon);
    bt_restart->setIconSize(QSize(60,60));
    bt_restart->setFixedSize(QSize(60,60));
    bt_restart->setGeometry(QRect(QPoint(350,0),QSize(50,50)));
    connect(bt_restart,SIGNAL(clicked()),this,SLOT(restartgame()));

    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
}

void End::setfinalscore(int n)
{
    finalscore=n;
    displscore =new QGraphicsTextItem();
    displscore->setPlainText(QString("Score: ") + QString::number(finalscore)); // Score: 0
    displscore->setDefaultTextColor(Qt::blue);
    displscore->setFont(QFont("times",30));
    displscore->setPos(150,150);
    endscene->addItem(displscore);
}


void End::exitgame()
{
    emit  quitGame();
    close();
    delete this;

}

void End::restartgame()
{
    close();
    delete this;
    start =new Start();
    start->show();
}

void End::QUITSLOT()
{
     // For debug
     std::cout << "Quit Game Signal receive !" << std::endl ;
}
