//
// Created by 年 on 2024/10/30.
//

#ifndef INC_77MZ_LOGINDTO_H
#define INC_77MZ_LOGINDTO_H
#include <QString>
#include <QJsonObject>

class LoginDto {
private:
    QString username;
    QString password;
public:
    const QString &getUsername() const;

    void setUsername(const QString &username);

    const QString &getPassword() const;

    void setPassword(const QString &password);

    QJsonObject toJson();
    LoginDto(){}
};


#endif //INC_77MZ_LOGINDTO_H
