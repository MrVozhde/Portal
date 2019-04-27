#include "addstudentdialog.h"
#include "ui_addstudentdialog.h"

AddStudentDialog::AddStudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudentDialog)
{
    ui->setupUi(this);
}

AddStudentDialog::~AddStudentDialog()
{
    delete ui;
}

void AddStudentDialog::on_pushButton_add_clicked()
{
    if(ui->lineEdit_name->text().isEmpty() || ui->lineEdit_lastName->text().isEmpty() || ui->lineEdit_nationalCode->text().isEmpty() || ui->lineEdit_saalevoroud->text().isEmpty()){
        QMessageBox::warning(this, "خطا", "لطفا موارد بالا پر کنید.");
    }else{
        QSqlQuery qry1;
        QSqlQuery qry2;
        QSqlQuery qry3;

        QString strName;
        QString strLastname;
        QString strNationalcode;
        QString strFathersname;
        QString strSaalvoroud;
        QVariant correntID;
        QDate birthDate;
        bool blGender;

        strName = ui->lineEdit_name->text();
        strLastname = ui->lineEdit_lastName->text();
        strNationalcode = ui->lineEdit_nationalCode->text();
        strFathersname = ui->lineEdit_fathersName->text();
        strSaalvoroud = ui->lineEdit_saalevoroud->text();
        birthDate.setDate(ui->comboBox_saal->currentText().toInt(), ui->comboBox_maah->currentText().toInt(), ui->comboBox_rouz->currentText().toInt());
        if(ui->radioButton_male->isChecked()){
            blGender =  true;
        }else if(ui->radioButton_female->isChecked()){
            blGender = false;
        }


        qry1.prepare("Insert Into Student.dbo.tblPerson \
                     (FirstName \
                     ,LastName \
                     ,Nationalcode \
                     ,Gender) \
                     Values(:name , :lastname , :nationalcode , :gender)"); //  , :birthdate  ,BirthDate
                    qry1.bindValue(":name", strName);
                    qry1.bindValue(":lastname", strLastname);
                    qry1.bindValue(":nationalcode", strNationalcode);
                    qry1.bindValue(":gender", blGender );
                   // qry1.bindValue(":birthdate", birthDate);
                    qry1.exec();

        correntID = qry3.lastInsertId().toString();

        qry2.prepare("Insert Into Student.dbo.tblStudent \
                     (ID \
                     ,FathersName \
                     ,SaalVoroud \
                     ,Password) \
                     Values(:id , :fathersname , :saalvoroud , :password)");
                    qry2.bindValue(":id" , correntID);
                    qry2.bindValue(":fathersname" , strFathersname );
                    qry2.bindValue(":saalvoroud", strSaalvoroud);
                    qry2.bindValue(":password", strNationalcode);
                    qry2.exec();

        QMessageBox::information(this, "OK", "دانشجو اضافه شد.");
    }
}

void AddStudentDialog::on_pushButton_showAllStu_clicked()
{
    showStuDialog = new ShowStudentDialog(this);
    showStuDialog->show();
}
