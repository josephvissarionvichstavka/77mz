//
// Created by 年 on 2024/10/30.
//

#ifndef INC_77MZ_RESULT_H
#define INC_77MZ_RESULT_H
#include <QString>
#include <QJsonObject>

enum ResultCode {
    error = 0,
    success = 1
};
template<class T>
class Result {
private:
    QString message;
    ResultCode code;
    T data;
public:

    static Result<T> jsonToResult(const QJsonObject & object) {
        Result<T> result;
        result.code = static_cast<ResultCode>(object["code"].toInt());
        result.message = object["message"].toString();
        result.data = T(object["data"].toObject());
        return result;
    }

    const QString &getMessage() const {
        return message;
    }

    void setMessage(const QString &message) {
        Result::message = message;
    }

    ResultCode getCode() const {
        return code;
    }

    void setCode(ResultCode code) {
        Result::code = code;
    }

    T getData() const {
        return data;
    }

    void setData(T data) {
        Result::data = data;
    }
};

#endif //INC_77MZ_RESULT_H
