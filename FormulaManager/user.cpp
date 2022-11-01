#include "user.h"
#include "ui_user.h"

user::user(QWidget *parent) : QDialog(parent),
                              ui(new Ui::user)
{
    ui->setupUi(this);
//    ui->stackedWidget->setCurrentIndex(1);
    // connecting to mysql database
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("password");
    database.setDatabaseName("formula");

    if (database.open())
    {
        // Retrieve Data from input fields
        QString name;
        QString path;

        // Run our insert Query
        QSqlQuery qry;

        qry.prepare("select * from applied");

        if (!qry.exec())
        {
            QMessageBox::information(this, "Applied", "Query Failed To  Execute");
        }
        else
        {

            while (qry.next())
            {
                QString nameFromDB = qry.value(0).toString();
                QString pathFromDB = qry.value(1).toString();

                QStringList fileName = QFileDialog::getOpenFileNames(this,tr("Open Image"),
                                           "C:\\Users\\atuls\\OneDrive\\Desktop\\project\\formula-encyclopaedia\\formulas\\Applied Mech",
                                           tr("Image Files(*.png)"));
                iterator = new QStringListIterator(fileName);
                label = new QLabel;



                if(iterator->hasNext())
                {
                    label->clear();
                    label->setPixmap(QPixmap(iterator->next()));

                    // need to add a scroll area widget in your ui file
                    // and set layout to it (horizontal, vertical, grid etc.)
                }
//                ui->listWidget->setViewMode(QListWidget::IconMode);
//                ui->listWidget->setIconSize(QSize(500, 500));
//                ui->listWidget->setResizeMode(QListWidget::Adjust);
//                QListWidgetItem *item = new QListWidgetItem(QIcon(pathFromDB), QString(nameFromDB));
//                ui->listWidget->addItem(item);
            }
        }
    }

    else
    {
        QMessageBox::information(this, "Not Connected", "Database is not connected");
    }
    database.close();
}


user::~user()
{
    delete ui;
}

//void user::on_pushButton_clicked()
//{
//    close();
//}

//void user::on_pushButton_2_clicked()
//{
//}

//void user::on_pushButton_3_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(2);
//    // connecting to mysql database
//    database = QSqlDatabase::addDatabase("QMYSQL");
//    database.setHostName("localhost");
//    database.setUserName("root");
//    database.setPassword("password");
//    database.setDatabaseName("formula");

//    if (database.open())
//    {
//        // Retrieve Data from input fields
//        QString name;
//        QString path;

//        // Run our insert Query
//        QSqlQuery qry;

//        qry.prepare("select * from chemistry");

//        if (!qry.exec())
//        {
//            QMessageBox::information(this, "Chemistry", "Query Failed To  Execute");
//        }
//        else
//        {

//            while (qry.next())
//            {
//                QString nameFromDB = qry.value(0).toString();
//                QString pathFromDB = qry.value(1).toString();
//                ui->listWidget_2->setViewMode(QListWidget::IconMode);
//                ui->listWidget_2->setIconSize(QSize(500, 500));
//                ui->listWidget_2->setResizeMode(QListWidget::Adjust);
//                QListWidgetItem *item = new QListWidgetItem(QIcon(pathFromDB), QString(nameFromDB));
//                ui->listWidget_2->addItem(item);
//            }
//        }
//    }

//    else
//    {
//        QMessageBox::information(this, "Not Connected", "Database is not connected");
//    }
//    database.close();

//}

//void user::on_pushButton_4_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(3);
//    // connecting to mysql database
//    database = QSqlDatabase::addDatabase("QMYSQL");
//    database.setHostName("localhost");
//    database.setUserName("root");
//    database.setPassword("password");
//    database.setDatabaseName("formula");

//    if (database.open())
//    {
//        // Retrieve Data from input fields
//        QString name;
//        QString path;

//        // Run our insert Query
//        QSqlQuery qry;

//        qry.prepare("select * from ECT");

//        if (!qry.exec())
//        {
//            QMessageBox::information(this, "ECT", "Query Failed To  Execute");
//        }
//        else
//        {

//            while (qry.next())
//            {
//                QString nameFromDB = qry.value(0).toString();
//                QString pathFromDB = qry.value(1).toString();
//                ui->listWidget_3->setViewMode(QListWidget::IconMode);
//                ui->listWidget_3->setIconSize(QSize(500, 500));
//                ui->listWidget_3->setResizeMode(QListWidget::Adjust);
//                QListWidgetItem *item = new QListWidgetItem(QIcon(pathFromDB), QString(nameFromDB));
//                ui->listWidget_3->addItem(item);
//            }
//        }
//    }

//    else
//    {
//        QMessageBox::information(this, "Not Connected", "Database is not connected");
//    }
//    database.close();
//}

//void user::on_pushButton_5_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(4);
//    // connecting to mysql database
//    database = QSqlDatabase::addDatabase("QMYSQL");
//    database.setHostName("localhost");
//    database.setUserName("root");
//    database.setPassword("password");
//    database.setDatabaseName("formula");

//    if (database.open())
//    {
//        // Retrieve Data from input fields
//        QString name;
//        QString path;

//        // Run our insert Query
//        QSqlQuery qry;

//        qry.prepare("select * from EM");

//        if (!qry.exec())
//        {
//            QMessageBox::information(this, "EM", "Query Failed To  Execute");
//        }
//        else
//        {

//            while (qry.next())
//            {
//                QString nameFromDB = qry.value(0).toString();
//                QString pathFromDB = qry.value(1).toString();
//                ui->listWidget_4->setViewMode(QListWidget::IconMode);
//                ui->listWidget_4->setIconSize(QSize(500, 500));
//                ui->listWidget_4->setResizeMode(QListWidget::Adjust);
//                QListWidgetItem *item = new QListWidgetItem(QIcon(pathFromDB), QString(nameFromDB));
//                ui->listWidget_4->addItem(item);
//            }
//        }
//    }

//    else
//    {
//        QMessageBox::information(this, "Not Connected", "Database is not connected");
//    }
//    database.close();
//}

//void user::on_pushButton_8_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(5);
//    // connecting to mysql database
//    database = QSqlDatabase::addDatabase("QMYSQL");
//    database.setHostName("localhost");
//    database.setUserName("root");
//    database.setPassword("password");
//    database.setDatabaseName("formula");

//    if (database.open())
//    {
//        // Retrieve Data from input fields
//        QString name;
//        QString path;

//        // Run our insert Query
//        QSqlQuery qry;

//        qry.prepare("select * from math");

//        if (!qry.exec())
//        {
//            QMessageBox::information(this, "Math", "Query Failed To  Execute");
//        }
//        else
//        {

//            while (qry.next())
//            {
//                QString nameFromDB = qry.value(0).toString();
//                QString pathFromDB = qry.value(1).toString();
//                ui->listWidget_5->setViewMode(QListWidget::IconMode);
//                ui->listWidget_5->setIconSize(QSize(500, 500));
//                ui->listWidget_5->setResizeMode(QListWidget::Adjust);
//                QListWidgetItem *item = new QListWidgetItem(QIcon(pathFromDB), QString(nameFromDB));
//                ui->listWidget_5->addItem(item);
//            }
//        }
//    }

//    else
//    {
//        QMessageBox::information(this, "Not Connected", "Database is not connected");
//    }
//    database.close();
//}

//void user::on_pushButton_6_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(6);
//    // connecting to mysql database
//    database = QSqlDatabase::addDatabase("QMYSQL");
//    database.setHostName("localhost");
//    database.setUserName("root");
//    database.setPassword("password");
//    database.setDatabaseName("formula");

//    if (database.open())
//    {
//        // Retrieve Data from input fields
//        QString name;
//        QString path;

//        // Run our insert Query
//        QSqlQuery qry;

//        qry.prepare("select * from physics");

//        if (!qry.exec())
//        {
//            QMessageBox::information(this, "Physics", "Query Failed To  Execute");
//        }
//        else
//        {

//            while (qry.next())
//            {
//                QString nameFromDB = qry.value(0).toString();
//                QString pathFromDB = qry.value(1).toString();
//                ui->listWidget_6->setViewMode(QListWidget::IconMode);
//                ui->listWidget_6->setIconSize(QSize(500, 500));
//                ui->listWidget_6->setResizeMode(QListWidget::Adjust);
//                QListWidgetItem *item = new QListWidgetItem(QIcon(pathFromDB), QString(nameFromDB));
//                ui->listWidget_6->addItem(item);
//            }
//        }
//    }

//    else
//    {
//        QMessageBox::information(this, "Not Connected", "Database is not connected");
//    }
//    database.close();
//}

//void user::on_pushButton_9_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//    database.close();
//}

//void user::on_pushButton_10_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//    database.close();
//}

//void user::on_pushButton_11_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//    database.close();
//}

//void user::on_pushButton_12_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//    database.close();
//}

//void user::on_pushButton_13_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//    database.close();
//}

//void user::on_pushButton_14_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//    database.close();
//}
