#include"start.h"



Start::Start()
{
    //set scene
    startscene =new QGraphicsScene(this);
    startscene -> setSceneRect(0,0,500,300);
    //set view to scene
    setScene(startscene);

    //set bg
    // end_bg = new QGraphicsPixmapItem;
    //end_bg->setPixmap(QPixmap(":/Elmo/end_bg.jpeg"));
    //end_bg->setPos(200,100);
    //endscene->addItem(end_bg);

    //set view
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(500,300);

    //add buttom
    bt_start =new QPushButton(this);
    QPixmap pixmap(":/image/play.png");
    QIcon ButtonIcon(pixmap);
    bt_start->setIcon(ButtonIcon);
    bt_start->setIconSize(QSize(400,200));
    bt_start->setFixedSize(QSize(400,200));
    bt_start->setGeometry(QRect(QPoint(50,0),QSize(200,100)));
    connect(bt_start,SIGNAL(clicked(bool)),this,SLOT(OpenGame()));

    bt_exit =new QPushButton(this);
    QPixmap pixmap1(":/image/exit.png");
    QIcon ButtonIcon1(pixmap1);
    bt_exit->setIcon(ButtonIcon1);
    bt_exit->setIconSize(QSize(60,60));
    bt_exit->setFixedSize(QSize(60,60));
    bt_exit->setGeometry(QRect(QPoint(0,0),QSize(60,60)));
    connect(bt_exit,SIGNAL(clicked()),this,SLOT(CloseStartView()));


connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
}

void Start::CloseStartView()
{
    emit quitGame();
    close();
    delete this;

}

void Start::OpenGame()
{
   close();
   delete this;
   MainWindow *w=new MainWindow();
   w->show();
}

void Start::QUITSLOT()
{
      std::cout << "Quit Game Signal receive !" << std::endl ;
}
