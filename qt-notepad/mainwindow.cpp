#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>
#include<QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    file_path="";
    ui->textEdit->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString file_name=QFileDialog::getOpenFileName(this,"Open the File");
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File Not Open");
        return;
    }
    QTextStream in(&file);
    QString text=in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    QFile file(file_path);

    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File Not Saved Yet");
        return;
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void MainWindow::on_actionSave_as_triggered()
{
    QString file_name=QFileDialog::getSaveFileName(this,"File Not Saved");
    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File Not Open");
        return;
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();

}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionResume_triggered()
{
    QString about_text;
    about_text="~DEEPESH KANSOTIA~\n\n";
    about_text+="I'm a Second Year BTech undergrad Student at Netaji Subhas University of Technology(NSUT/NSIT,Delhi).\nA Freshman with excellent Problem Solving skill and ability to perform well in team. Passionate about Coding and Learning new things.\n\n";
    about_text+="Gmail: deepeshkansotia@gmail.com\nMobile: +91-8826241832\nLinkedin: https://www.linkedin.com/in/deepesh-kansotia-33b05622a/\nGithub: https://github.com/deepeshkans\n\n";
    about_text+="SKILLS --> C++,C,HTML,CSS,Data Structure,Algorithms.\n\n";
    about_text+="PROJECTS:\n(1.)Unofficial University Website\nDeveloped a fully Responsive Unofficial Website for my University NSUT\nCreated using HTML,CSS,JS.\n\n(2.)Simple Scientific Calculator\nThe project is a simple implementaion of a scientific calculator, and how it functions.\nFollowing are the included functions:-\nAdd, Subtract, Multiply, Divide, Sine, Cosine,Tan, arcsin, arccos, arctan, Exponent, log, ln, Square, Squareroot, x to the power y (x^y), Factorial\n\n";
    about_text+="ACHIEVEMNTS:\n1.Completed 230+ various problems on Codechef.\n2.Participated and Qualified for 2nd round in Tata Imagination Challenge.\n3.In a team of three, participated in Flipkart Grid4.0.\n4.Working as a active member in NAKSHATRA'NSUT in departments like : Web Development, Maths, Astronmoy\n";
    QMessageBox::about(this,"RESUME",about_text);
}


void MainWindow::on_actionText_triggered()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok, QFont("Helvetica[Cronyx]",16),this);
    if(ok){
        ui->textEdit->setFont(font);
    }
}

