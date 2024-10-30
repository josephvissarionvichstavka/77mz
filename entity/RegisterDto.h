//
// Created by 年 on 2024/10/30.
//

#ifndef INC_77MZ_REGISTERDTO_H
#define INC_77MZ_REGISTERDTO_H
#include <QString>
#include <QJsonObject>
class RegisterDto {
private:
    QString password;
    QString email;
    QString name;
    QString avatar;
    QString code;
public:
    const QString &getPassword() const;

    void setPassword(const QString &password);

    const QString &getEmail() const;

    void setEmail(const QString &email);

    const QString &getName() const;

    void setName(const QString &name);

    const QString &getAvatar() const;

    void setAvatar(const QString &avatar);

    const QString &getCode() const;

    void setCode(const QString &code);

    QJsonObject toJson();
};


#endif //INC_77MZ_REGISTERDTO_H
