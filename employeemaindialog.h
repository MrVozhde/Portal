#ifndef EMPLOYEEMAINDIALOG_H
#define EMPLOYEEMAINDIALOG_H

#include <QDialog>
#include <QtSql>
#include <addstudentdialog.h>
#include <removestudentdialog.h>
#include <editstudentdialog.h>
#include <entekhabvaheddialog.h>
#include <employeechangepassworddialog.h>

namespace Ui {
class EmployeeMainDialog;
}

class EmployeeMainDialog : public QDialog
{
    Q_OBJECT

public:


    explicit EmployeeMainDialog(QWidget *parent = nullptr);
    ~EmployeeMainDialog();

private slots:
    void on_pushButton_addStu_clicked();

    void on_pushButton_removeStu_clicked();

    void on_pushButton_editStu_clicked();

    void on_pushButton_entekhabVahed_clicked();

    void on_pushButton_setting_clicked();

private:
    Ui::EmployeeMainDialog *ui;
    AddStudentDialog *addStuDialog;
    RemoveStudentDialog *rmvStuDialog;
    EditStudentDialog *editStuDialog;
    EntekhabVahedDialog *entekhVahedDialog;
    EmployeeChangePasswordDialog *empChangeDialog;
};

#endif // EMPLOYEEMAINDIALOG_H
