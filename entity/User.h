//
// Created by 年 on 2024/10/30.
//

#ifndef INC_77MZ_USER_H
#define INC_77MZ_USER_H
#include <QString>
#include <QJsonObject>
class User {
private:
    QString username;
    QString password;
    QString email;
    QString name;

public:
    QJsonObject toJson();
    User();
    User(const QJsonObject & object);

    const QString &getUsername() const;

    void setUsername(const QString &username);

    const QString &getPassword() const;

    void setPassword(const QString &password);

    const QString &getEmail() const;

    void setEmail(const QString &email);

    const QString &getName() const;

    void setName(const QString &name);
};


#endif //INC_77MZ_USER_H
