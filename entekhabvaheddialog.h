#ifndef ENTEKHABVAHEDDIALOG_H
#define ENTEKHABVAHEDDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <showstudentdialog.h>

namespace Ui {
class EntekhabVahedDialog;
}

class EntekhabVahedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EntekhabVahedDialog(QWidget *parent = nullptr);
    ~EntekhabVahedDialog();

private slots:
    void on_pushButton_findStu_clicked();

    void on_pushButton_findLesson_clicked();

    void on_pushButton_showStu_clicked();

    void on_pushButton_showLesson_clicked();

    void on_pushButton_apply_clicked();

private:
    Ui::EntekhabVahedDialog *ui;
    ShowStudentDialog *showStuDialog;
};

#endif // ENTEKHABVAHEDDIALOG_H
