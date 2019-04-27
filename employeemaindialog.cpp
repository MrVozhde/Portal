#include "employeemaindialog.h"
#include "ui_employeemaindialog.h"

//QString EmployeeChangePasswordDialog::strUser;

EmployeeMainDialog::EmployeeMainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeMainDialog)
{
    ui->setupUi(this);



    QString name;
    QString lastName;
    QString cpyStrUser = EmployeeChangePasswordDialog::strUser;
    QSqlQuery qry1;
    QSqlQuery qry2;
    int currentID;

    qry1.prepare("Select ID \
                  From Student.dbo.tblEmployee \
                  Where tblEmployee.EmployeeCode = :empcode");
            qry1.bindValue(":empcode", cpyStrUser);
            qry1.exec();
    if(qry1.next()){
        currentID = qry1.value(0).toInt();
    }

    qry2.prepare("Select FirstName, LastName \
                  From Student.dbo.tblPerson \
                  Where tblPerson.ID = :id");
            qry2.bindValue(":id", currentID);
            qry2.exec();
    if(qry2.next()){
        name = qry2.value(0).toString();
        lastName = qry2.value(1).toString();
    }

    ui->label_name->setText(name + " " + lastName);
    ui->label_employeeCode->setText(cpyStrUser);
}

EmployeeMainDialog::~EmployeeMainDialog()
{
    delete ui;
}

void EmployeeMainDialog::on_pushButton_addStu_clicked()
{
    addStuDialog = new AddStudentDialog(this);
    addStuDialog->show();
}


void EmployeeMainDialog::on_pushButton_removeStu_clicked()
{
    rmvStuDialog = new RemoveStudentDialog(this);
    rmvStuDialog->show();
}

void EmployeeMainDialog::on_pushButton_editStu_clicked()
{
    editStuDialog = new EditStudentDialog(this);
    editStuDialog->show();
}

void EmployeeMainDialog::on_pushButton_entekhabVahed_clicked()
{
    entekhVahedDialog = new EntekhabVahedDialog(this);
    entekhVahedDialog->show();
}

void EmployeeMainDialog::on_pushButton_setting_clicked()
{
    empChangeDialog = new EmployeeChangePasswordDialog(this);
    empChangeDialog->show();
}
