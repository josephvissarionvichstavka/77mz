//
// Created by 年 on 2024/10/30.
//

#ifndef INC_77MZ_MZ77UPLOAD_H
#define INC_77MZ_MZ77UPLOAD_H
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
class MZ77Upload : public QLabel{
public:
    MZ77Upload(QWidget * parent);
    Q_OBJECT
private:
    QPushButton * deleteImage;
private slots:
    void fileSelector();
    void deleteFile();
};


#endif //INC_77MZ_MZ77UPLOAD_H
