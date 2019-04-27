#include "addlessondialog.h"
#include "ui_addlessondialog.h"

AddLessonDialog::AddLessonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLessonDialog)
{
    ui->setupUi(this);
}

AddLessonDialog::~AddLessonDialog()
{
    delete ui;
}
