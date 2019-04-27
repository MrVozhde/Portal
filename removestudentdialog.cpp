#include "removestudentdialog.h"
#include "ui_removestudentdialog.h"

RemoveStudentDialog::RemoveStudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveStudentDialog)
{
    ui->setupUi(this);
}

RemoveStudentDialog::~RemoveStudentDialog()
{
    delete ui;
}

void RemoveStudentDialog::on_pushButton_search_clicked()
{
    QSqlQuery qry1;
    QSqlQuery qry2;
    QSqlQuery qry3;
    QString strStuCode;
    QString currID;
    QString fathersName;
    QString name;
    QString nationalCode;
    QString stuCode;

    stuCode = ui->lineEdit_stuCode->text();

    qry1.prepare("Select ID, FathersName, StudentCode From Student.dbo.tblStudent Where Student.dbo.tblStudent.StudentCode = :stuCode");
    qry1.bindValue(":stuCode", stuCode);
    qry1.exec();
    if(qry1.next()){
        currID = qry1.value(0).toString();
        fathersName = qry1.value(1).toString();
        strStuCode = qry1.value(2).toString();
    }

    qry2.prepare("Select FirstName, LastName, NationalCode \
                  From Student.dbo.tblPerson \
                  Where tblPerson.ID = :id");
            qry2.bindValue(":id", currID);
            qry2.exec();
    if(qry2.next()){
        name = qry2.value(0).toString() + " " +qry2.value(1).toString();
        nationalCode = qry2.value(2).toString();
    }

    ui->label_name->setText(name);
    ui->label_nationalCode->setText(nationalCode);
    ui->label_fathersName->setText(fathersName);
    ui->label_stuCode->setText(strStuCode);
}

void RemoveStudentDialog::on_pushButton_remove_clicked()
{

    QSqlQuery qry1;
    QSqlQuery qry2;
    QSqlQuery qry3;
    QString stuCode;
    QString currID;
    QString strQry;

    if(!(ui->label_stuCode->text().isEmpty())){
        stuCode = ui->label_stuCode->text();

        strQry = "SELECT ID FROM Student.dbo.tblStudent WHERE Student.dbo.tblStudent.StudentCode = " + stuCode;

        qry1.exec(strQry);
        while(qry1.next()){
            currID = qry1.value(0).toString();
        }

        qry2.prepare("Delete From Student.dbo.tblStudent\
                     Where Student.dbo.tblStudent.StudentCode = :stucode");
        qry2.bindValue(":stucode", stuCode);
        if(qry2.exec()){
            qry3.prepare("Delete From Student.dbo.tblPerson \
                         Where Student.dbo.tblPerson.ID = :id");
            qry3.bindValue(":id", currID);
            if(qry3.exec()){
                QMessageBox::information(this, "OK", "دانشجوی مورد نظر حذف شد.");
            }else{
                QMessageBox::warning(this,"Error", "There is Something Wrong In Database");
            }
        }else{
            QMessageBox::warning(this,"Error", "There is Something Wrong In Database");
        }
    }else{
        QMessageBox::warning(this, "Warning", "لطفا اول یک کد دانشجویی را جستجو کنید.");
    }
}

void RemoveStudentDialog::on_pushButton_showAllStu_clicked()
{
    showStuDialog = new ShowStudentDialog(this);
    showStuDialog->show();
}
