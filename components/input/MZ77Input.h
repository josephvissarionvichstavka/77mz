//
// Created by 年 on 2024/10/30.
//

#ifndef INC_77MZ_MZ77INPUT_H
#define INC_77MZ_MZ77INPUT_H
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
class MZ77Input : public QLineEdit{
public:
    Q_OBJECT

private:
    QPushButton * showPasswordIcon;
    QPushButton * clearIcon;
    QLabel * leftIcon;
private slots:
    void clearText(const QString & text);
    void clearToButton();
    void showPassword();
public:
    MZ77Input(QWidget *parent);
};


#endif //INC_77MZ_MZ77INPUT_H
