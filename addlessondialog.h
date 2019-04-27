#ifndef ADDLESSONDIALOG_H
#define ADDLESSONDIALOG_H

#include <QDialog>

namespace Ui {
class AddLessonDialog;
}

class AddLessonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddLessonDialog(QWidget *parent = nullptr);
    ~AddLessonDialog();

private:
    Ui::AddLessonDialog *ui;
};

#endif // ADDLESSONDIALOG_H
