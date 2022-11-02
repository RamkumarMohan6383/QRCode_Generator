/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *qrcodepixmapLabel;
    QLineEdit *lineEdit;
    QPushButton *generateButton;
    QPushButton *saveFileButton;
    QComboBox *comboBox;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_9;
    QPushButton *MergeButton;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_10;
    QLineEdit *lineEdit_10;
    QLabel *label_11;
    QPushButton *SplitButton;
    QPushButton *SplitButton_2;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setSizeGripEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setGeometry(QRect(0, 0, 800, 480));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        qrcodepixmapLabel = new QLabel(centralWidget);
        qrcodepixmapLabel->setObjectName(QString::fromUtf8("qrcodepixmapLabel"));
        qrcodepixmapLabel->setGeometry(QRect(480, 10, 300, 300));
        qrcodepixmapLabel->setFrameShape(QFrame::StyledPanel);
        qrcodepixmapLabel->setFrameShadow(QFrame::Sunken);
        qrcodepixmapLabel->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(260, 20, 201, 26));
        QFont font;
        font.setPointSize(10);
        lineEdit->setFont(font);
        generateButton = new QPushButton(centralWidget);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        generateButton->setGeometry(QRect(20, 440, 441, 31));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        generateButton->setFont(font1);
        saveFileButton = new QPushButton(centralWidget);
        saveFileButton->setObjectName(QString::fromUtf8("saveFileButton"));
        saveFileButton->setGeometry(QRect(480, 370, 301, 91));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        saveFileButton->setFont(font2);
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(660, 330, 71, 22));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        comboBox->setFont(font3);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(490, 330, 171, 21));
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(260, 55, 201, 26));
        lineEdit_2->setFont(font);
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(260, 90, 201, 26));
        lineEdit_3->setFont(font);
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(260, 125, 201, 26));
        lineEdit_4->setFont(font);
        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(260, 160, 201, 26));
        lineEdit_5->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 20, 111, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Lucida Sans"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        label->setFont(font4);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 55, 111, 21));
        label_3->setFont(font4);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 90, 111, 21));
        label_4->setFont(font4);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 125, 111, 21));
        label_5->setFont(font4);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(80, 160, 111, 21));
        label_6->setFont(font4);
        lineEdit_6 = new QLineEdit(centralWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(100, 215, 361, 31));
        lineEdit_6->setFont(font);
        lineEdit_7 = new QLineEdit(centralWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(100, 250, 361, 31));
        lineEdit_7->setFont(font);
        lineEdit_9 = new QLineEdit(centralWidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(100, 290, 361, 31));
        lineEdit_9->setFont(font);
        MergeButton = new QPushButton(centralWidget);
        MergeButton->setObjectName(QString::fromUtf8("MergeButton"));
        MergeButton->setGeometry(QRect(20, 370, 441, 31));
        MergeButton->setFont(font1);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 220, 51, 21));
        label_7->setFont(font4);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 255, 51, 21));
        label_8->setFont(font4);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 295, 81, 21));
        label_10->setFont(font4);
        lineEdit_10 = new QLineEdit(centralWidget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(100, 325, 361, 31));
        lineEdit_10->setFont(font);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 330, 71, 21));
        label_11->setFont(font4);
        SplitButton = new QPushButton(centralWidget);
        SplitButton->setObjectName(QString::fromUtf8("SplitButton"));
        SplitButton->setGeometry(QRect(20, 405, 201, 31));
        SplitButton->setFont(font1);
        SplitButton_2 = new QPushButton(centralWidget);
        SplitButton_2->setObjectName(QString::fromUtf8("SplitButton_2"));
        SplitButton_2->setGeometry(QRect(240, 405, 221, 31));
        SplitButton_2->setFont(font1);

        retranslateUi(MainWindow);

        generateButton->setDefault(true);
        MergeButton->setDefault(true);
        SplitButton->setDefault(true);
        SplitButton_2->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QRCode Generator", nullptr));
        lineEdit->setText(QString());
        generateButton->setText(QApplication::translate("MainWindow", "Generate", nullptr));
        saveFileButton->setText(QApplication::translate("MainWindow", "Save imagefile to\n"
"QRCode.png", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "PNG", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "JPG", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "BMP", nullptr));

        comboBox->setCurrentText(QApplication::translate("MainWindow", "PNG", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "ImageFileType", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_3->setText(QString());
        lineEdit_4->setText(QString());
        lineEdit_5->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Product Code", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Lot No", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Expiry", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Kit No", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "State Code", nullptr));
        lineEdit_6->setText(QString());
        lineEdit_7->setText(QString());
        lineEdit_9->setText(QString());
        MergeButton->setText(QApplication::translate("MainWindow", "Merge && Convert", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Club", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Hex", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Final Hex", nullptr));
        lineEdit_10->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "Shuffle", nullptr));
        SplitButton->setText(QApplication::translate("MainWindow", "Split", nullptr));
        SplitButton_2->setText(QApplication::translate("MainWindow", "Shuffle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
