#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "end.h"
#include <QDebug>
#include <QPainterPath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setBackgroundBrush(QPixmap(":/image/bg.png").scaled(800,600));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Enable the event Filter
    qApp->installEventFilter(this);
    score_dipl = new QLabel(this);
    score_dipl->setText("<font color=blue>Score : "+QString::number(score));
    score_dipl ->show();

    //add buttom
    bt_restart =new QPushButton(this);
    QPixmap pixmap(":/image/bt_restart.png");
    QIcon ButtonIcon(pixmap);
    bt_restart->setIcon(ButtonIcon);
    bt_restart->setIconSize(QSize(60,60));
    bt_restart->setFixedSize(QSize(60,60));
    bt_restart->setGeometry(QRect(QPoint(700,20),QSize(10,10)));
    connect(bt_restart,SIGNAL(clicked(bool)),this,SLOT(restart()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    setparam();
    setGame();
    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);


}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseevent=static_cast<QMouseEvent*>(event);
        if(m1==1){

            if(mouseevent->button()==1){
                x_1= QCursor::pos().x();
                y_1= QCursor::pos().y();
                x_3= QCursor::pos().x();
                y_3= QCursor::pos().y();
                moveflag=1;
                m2=1;
                m1=0;
            }
        }
            if(mouseevent->button()==2){ qDebug()<<"shoot2";
                    if(m2==1){
                    //extra fuction of birdie
                     birdie[bird_ind]->shoot2();
                    m2=0;
                    }
            }
        //std::cout << "Press !" <<x_1<< std::endl ;
    }

    if(event->type() == QEvent::MouseMove)
    {
        if(moveflag==1){
            x_3= QCursor::pos().x();
            y_3= QCursor::pos().y();
            birdie[bird_ind]->g_body->SetTransform(b2Vec2((QCursor::pos().x()-472)/30,18-(QCursor::pos().y()-246)/30),0);
            m3=1;
            //std::cout << "Move !" <<30-(QCursor::pos().y())/30<< std::endl ;

        }
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {   moveflag=0;
        QMouseEvent *mouseevent=static_cast<QMouseEvent*>(event);
        if(mouseevent->button()==1){
            if(m3==1){
                m3=0;
            birdie[bird_ind]->g_body->SetType(b2_dynamicBody);
            x_2= QCursor::pos().x();
            y_2= QCursor::pos().y();
            birdie[bird_ind]->setLinearVelocity(b2Vec2(GAIN_VX*(x_1-x_2),GAIN_VY*(y_1-y_2)));
            isfly=1;

            m4=1;
            }
        }
        //std::cout << "Release !" << std::endl ;

    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    emit quitGame();

}
/*
void MainWindow::paintEvent(QPaintEvent *event)
{ if(isfly==1){
        qDebug()<<"drawpath";
    QPainter painter(this);
    QPen penbirdpath(Qt::black,20,Qt::DotLine,Qt::RoundCap,Qt::RoundJoin);
    painter.setPen(penbirdpath);
    //connect(&timer,SIGNAL(timeout()),this,SLOT());
   // painter.drawPoint(QPointF(getBirdPosition()));
    painter.drawLine(10,10,600,700);
    painter.drawRect(100, 10, 50, 80);
}

}*/

void MainWindow::setGame()
{
    //param
    bird_ind=0;

    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);

    //set sling pixmap
    sling =new QGraphicsPixmapItem();
    sling->setPixmap(QPixmap(":/image/sling.png").scaled(width()/12,height()/4.0));
    sling->setPos(75,330);
    scene->addItem(sling);

    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));

    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());

    //add contactlistener
    contactlisten =new Mycontactlistener();
    world->SetContactListener(contactlisten);

   while(b2Contact* contact=world->GetContactList()){std::cout<<contact;}
    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));
    //Land *land =new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene);
    //std::cout <<land->g_body->GetPosition().y<<std::endl;
    //std::cout <<land->g_body->GetPosition().x<<std::endl;

    //create wood
   for(int i=0;i<2;i++){
       wood[i]=new Wood(19+3.5*i,6,0.8,4.5,&timer,QPixmap(":/image/wood1.png").scaled(30,150),world,scene);
       itemList.push_back(wood[i]);
   }
    wood1 = new Wood(21,6,0.9,4.5,&timer,QPixmap(":/image/wood1.png").scaled(30,150),world,scene);
    wood1->g_body->SetTransform(b2Vec2(21,10),90*180/3.14159);

    //add pig
    pig[0]=new Pig(20,5,0.3,world,scene);
    pig[1]=new Pig(15,8,0.3,world,scene);
    for(int i=0;i<2;i++)itemList.push_back(pig[i]);

    // Create bird (You can edit here)
    birdie[0] = new Bird(3.0f,8.6f,0.27f,world,scene);
    birdie[1] = new Bird1(3.5f,4.5f,0.27f,world,scene);
    birdie[2] = new Bird2(2.0f,4.5f,0.27f,world,scene);
    birdie[3] = new Bird3(0.3f,4.5f,0.27f,world,scene);
    birdie[4] = new Bird4(0.1f,4.5f,0.27f,world,scene);
    for(int i=0;i<BIRDNUMBER;i++)itemList.push_back(birdie[i]);

}

void MainWindow::setparam()
{

     moveflag=0;
     changeflag=0;
     bird_ind=0;
     m2=0;
     m1=1;
     m3=0;
     m4=0;
     isfly=0;
}



void MainWindow::tick()
{
    score=contactlisten->addscore;
    score_dipl->setText("<font color=blue>Score : "+QString::number(score));

    if(birdie[bird_ind]->g_body->GetPosition().x>32||birdie[bird_ind]->g_body->GetPosition().x<0)changeflag=1;
    if(m4==1&&birdie[bird_ind]->g_body->GetLinearVelocity().x==0)changeflag=1;
    if(changeflag==1)nextbird();
    world->Step(1.0/60.0,6,2);  //timestep/velocityinterations/positoninterations
    scene->update();

}

QPointF MainWindow::getBirdPosition()
{
    QPointF pos;
    pos.setX(birdie[bird_ind]->g_body->GetPosition().x);
    pos.setY(birdie[bird_ind]->g_body->GetPosition().y);
    return  pos;
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}

void MainWindow::restart()
{

    itemList.clear();
    setparam();
    setGame();


}

void MainWindow::nextbird()
{
    std::cout<<"change";
    changeflag=0;
    birdie[bird_ind]->remove();
    delete birdie[bird_ind];
    b[bird_ind]=0;
    bird_ind++;
    m1=1;m4=0;
    if(bird_ind< BIRDNUMBER){
    for(int i=0;i<1000000;i++);
    birdie[bird_ind]->g_body->SetTransform(b2Vec2(3.0f,8.6f),0);
    }else{
         for(int i=0;i<100000000;i++);
        close();
        itemList.clear();



        End *endwindow=new End();
        endwindow->show();
        endwindow->setfinalscore(score);
    }




}
