#include "employeechangepassworddialog.h"
#include "ui_employeechangepassworddialog.h"

EmployeeChangePasswordDialog::EmployeeChangePasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeChangePasswordDialog)
{
    ui->setupUi(this);
}

EmployeeChangePasswordDialog::~EmployeeChangePasswordDialog()
{
    delete ui;
}

void EmployeeChangePasswordDialog::on_pushButton_clicked()
{
    QString newPass = ui->lineEdit_newPass->text();
    QString repNewPass = ui->lineEdit_repeatNewPass->text();

    if(newPass != repNewPass){
        QMessageBox::warning(this, "warning", "اطلاعات را صحیح وارد کنید.");
        ui->lineEdit_repeatNewPass->text().clear();
    }else{
        QSqlQuery qry;
        qry.prepare("Update Student.dbo.tblEmployee \
                     Set Password = :pass \
                     Where tblEmployee.EmployeeCode = :empcode");
                qry.bindValue(":pass", newPass);
                qry.bindValue(":empcode", strUser);
                qry.exec();

        QMessageBox::information(this, "OK", "رمز عبور شما با موفقیت تغییر کرد.");
    }
}
