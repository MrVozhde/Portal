#include "entekhabvaheddialog.h"
#include "ui_entekhabvaheddialog.h"

EntekhabVahedDialog::EntekhabVahedDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntekhabVahedDialog)
{
    ui->setupUi(this);
}

EntekhabVahedDialog::~EntekhabVahedDialog()
{
    delete ui;
}

void EntekhabVahedDialog::on_pushButton_findStu_clicked()
{
    QString arrStr[3];
    QString strStuCode = ui->lineEdit_stuCode->text();

    QSqlQuery qry("Select FirstName, LastName, StudentCode \
                   From Student.dbo.tblStudent, Student.dbo.tblPerson \
                   Where tblStudent.ID = tblPerson.ID AND \
                   tblStudent.StudentCode like '" + strStuCode + "'");

    while(qry.next()){
        for(int i=0 ; i<3 ; i++){
            arrStr[i] = qry.value(i).toString();
        }
    }

    ui->label_stuName->setText(arrStr[0] + " " + arrStr[1]);
    ui->label_stuCode->setText(arrStr[2]);
}

void EntekhabVahedDialog::on_pushButton_findLesson_clicked()
{
    QString arrStr[2];
    QString strLessonCode = ui->lineEdit_lessonCode->text();

    QSqlQuery qry("Select LessonCode, Title \
                    From Student.dbo.tblLesson \
                    Where tblLesson.LessonCode like '" + strLessonCode + "'");

    while(qry.next()){
        for(int i=0 ; i<2 ; i++){
            arrStr[i] = qry.value(i).toString();
        }
    }

    ui->label_lessonCode->setText(arrStr[0]);
    ui->label_lessonName->setText(arrStr[1]);
}

void EntekhabVahedDialog::on_pushButton_showStu_clicked()
{
    showStuDialog = new ShowStudentDialog(this);
    showStuDialog->show();
}

void EntekhabVahedDialog::on_pushButton_showLesson_clicked()
{

}

void EntekhabVahedDialog::on_pushButton_apply_clicked()
{
    QSqlQuery qry1;
    QSqlQuery qry2;
    QSqlQuery qry3;
    QSqlQuery qry4;
    QString strLessonCode;
    QString strStuCode;
    int lessonID;
    int eraeID;
    int stuID;

    strLessonCode = ui->label_lessonCode->text();
    strStuCode = ui->label_stuCode->text();

    qry1.prepare("Select ID From Student.dbo.tblLesson \
                  Where tblLesson.LessonCode = :lessoncode");

                qry1.bindValue(":lessoncode", strLessonCode);
                qry1.exec();

                while(qry1.next()){
                    lessonID = qry1.value(0).toInt();
                }

    qry2.prepare("Select ID From Student.dbo.tblErae \
                  Where tblErae.ID_Lesson = :lessonid");

                qry2.bindValue(":lessonid", lessonID);
                qry2.exec();

                while(qry2.next()){
                    eraeID = qry2.value(0).toInt();
                }

    qry3.prepare("Select ID From Student.dbo.tblStudent \
                  Where tblStudent.StudentCode = :stucode");

                qry3.bindValue(":stucode", strStuCode);
                qry3.exec();

                while(qry3.next()){
                    stuID = qry3.value(0).toInt();
                }

    qry4.prepare("Insert Into Student.dbo.tblEntekhabVahed \
                  (ID_Erae, ID_Student) \
                  Values(:iderae, :idstu) ");

                 qry4.bindValue(":iderae", eraeID);
                 qry4.bindValue(":idstu", stuID);
                 qry4.exec();


    qDebug() << "StuID =" << stuID << "    StuCode =" <<strStuCode;
    qDebug() <<" LessonID = "<< lessonID <<"   lesson Code=" << strLessonCode;
    qDebug() <<"erae ID = " << eraeID ;
    QMessageBox::information(this, "ok", "یا موفقیت انتخاب شد.");
}
