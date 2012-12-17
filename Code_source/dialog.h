/**
 * @file dialog.h
 * @brief Fichier header de la classe Dialog
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    Ui::Dialog *ui;

private slots:
    void nbElsPile();
    void clearHistory();

};

#endif // DIALOG_H
