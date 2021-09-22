/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *inEdit;
    QPushButton *inBtn;
    QLineEdit *outEdit;
    QPushButton *outBtn;
    QPushButton *decrypt;
    QTextEdit *logText;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(891, 622);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        inEdit = new QLineEdit(centralwidget);
        inEdit->setObjectName(QString::fromUtf8("inEdit"));
        inEdit->setGeometry(QRect(120, 40, 561, 51));
        inBtn = new QPushButton(centralwidget);
        inBtn->setObjectName(QString::fromUtf8("inBtn"));
        inBtn->setGeometry(QRect(720, 40, 91, 51));
        outEdit = new QLineEdit(centralwidget);
        outEdit->setObjectName(QString::fromUtf8("outEdit"));
        outEdit->setGeometry(QRect(120, 140, 561, 51));
        outBtn = new QPushButton(centralwidget);
        outBtn->setObjectName(QString::fromUtf8("outBtn"));
        outBtn->setGeometry(QRect(720, 140, 91, 51));
        decrypt = new QPushButton(centralwidget);
        decrypt->setObjectName(QString::fromUtf8("decrypt"));
        decrypt->setGeometry(QRect(480, 230, 171, 51));
        logText = new QTextEdit(centralwidget);
        logText->setObjectName(QString::fromUtf8("logText"));
        logText->setGeometry(QRect(120, 310, 731, 181));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 81, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 140, 81, 51));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 340, 81, 51));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        inBtn->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\347\233\256\345\275\225", nullptr));
        outBtn->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\347\233\256\345\275\225", nullptr));
        decrypt->setText(QApplication::translate("MainWindow", "\350\247\243\345\257\206", nullptr));
        label->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\350\267\257\345\276\204\357\274\232", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\350\267\257\345\276\204\357\274\232", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\346\227\245\345\277\227\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
