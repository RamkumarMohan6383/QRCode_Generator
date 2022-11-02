#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <cmath>
#include <iostream>
// For hex conversion
#include <sstream>
#include <string>
#include <QDebug>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>


QString element1,element2,element3,element4,element5,element6,element7,element8,element9,element10;
QString element11,element12,element13,element14,element15,element16,element17,element18,element19,element20;
QString element21,element22,element23,element24,element25,element26,element27,element28,element29,element30;
QString element31,element32,element33,element34,element35,element36,element37,element38,element39,element40;
QString element41,element42,element43,element44,element45,element46,element47,element48,element49,element50, element51;


static int Val1	,Val2,	Val3,	Val4	,Val5,	Val6	,Val7,	Val8	,Val9,	Val10	,Val11,	Val12	,Val13	,Val14	,Val15	,Val16,	Val17,	Val18,	Val19	,Val20,	Val21,	Val22,	Val23,	Val24,	Val25;
static int Val26	,Val27	,Val28,	Val29	,Val30,	Val31	,Val32	,Val33	,Val34,	Val35,	Val36	,Val37,	Val38	,Val39,	Val40,	Val41	,Val42,	Val43	,Val44	,Val45,	Val46,	Val47	,Val48,	Val49;


QString res1 , res2, res3, res4 , res5 , res6 , res7,	res8	,res9	,res10	,res11	,res12,	res13,	res14,	res15,	res16,	res17,	res18,	res19,	res20,	res21,	res22	,res23,	res24	,res25	,res26,	res27;
QString res28	,res29,	res30	,res31	,res32	,res33,	res34	,res35	,res36	,res37	,res38	,res39,	res40,	res41,	res42,	res43	,res44	,res45,	res46,	res47,	res48,	res49;



static const QString SAVE_TO_PNG(QString("Save imagefile to\nQRCode.png"));
static const QString SAVE_TO_JPG(QString("Save imagefile to\nQRCode.jpg"));
static const QString SAVE_TO_BMP(QString("Save imagefile to\nQRCode.bmp"));
std::ostringstream result;


string dec2hex(long a);
long hex2dec(const string & hexstr);
string hexadd(const string & hex1, const string & hex2);

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sumSoFar = "0";
    //ui->qrcodepixmapLabel->setScaledContents(true);
    if ((ui->qrcodepixmapLabel->pixmap() != NULL)
            && (ui->qrcodepixmapLabel->pixmap()->isNull() != true)){
        ui->saveFileButton->setEnabled(true);
    }
    else{
        ui->saveFileButton->setEnabled(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_saveFileButton_pressed()
{
#if 0
    QByteArray tempstring = ui->lineEdit->text().toLatin1().constData();

    QRController* controller = new QRController(tempstring.constData(), eclMedium, 250, 250, evAuto);

    vector<char> tempBitmapArray;
    controller->SaveToByteArray(tempBitmapArray);
    QByteArray tempQArray(tempBitmapArray.data(), tempBitmapArray.size());

    QPixmap QRCodeBitmap;
    bool loadresult = false;
    loadresult = QRCodeBitmap.loadFromData(tempQArray, "BMP");

    delete controller;

    if (true == loadresult){
        //qDebug("QRCodeImage Load Complete.");

        ui->qrcodepixmapLabel->setPixmap(QRCodeBitmap);

        QString imageType = ui->comboBox->currentText();

        QString filetypeStr;
        if (imageType == QString("BMP")){
            filetypeStr = QString(".bmp");
        }
        else if (imageType == QString("JPG")){
            filetypeStr = QString(".jpg");
        }
        else if (imageType == QString("PNG")){
            filetypeStr = QString(".png");
        }
        else{
            filetypeStr = QString(".bmp");
        }

        bool saveResult;
        QString savefileName = QString("QRCode") + filetypeStr;
        saveResult = QRCodeBitmap.save(savefileName);

        if (true == saveResult){
            QMessageBox::information(this, tr("QRCode Generator"), QString("Save to ") + savefileName + QString(" success"));

#ifdef DEBUG_LOGOUT_ON
            qDebug().nospace().noquote() << "Save QRCode to " << imageType << " file success.";
#endif
        }
        else{
            QMessageBox::warning(this, tr("QRCode Generator"), QString("Save to ") + savefileName + QString(" failure"));

#ifdef DEBUG_LOGOUT_ON
            qDebug().nospace().noquote() << "Save QRCode to " << imageType << " file failure.";
#endif
        }
    }
    else{
        QMessageBox::warning(this, tr("QRCode Generator"), tr("QRCodeImage Load Failure!!!"));
        //qDebug("QRCodeImage Load Failed!!!");
    }
#else
    if ((ui->qrcodepixmapLabel->pixmap() != NULL)
            && (ui->qrcodepixmapLabel->pixmap()->isNull() != true)){
        const QPixmap *QRCodePixmap = ui->qrcodepixmapLabel->pixmap();

        QString imageType = ui->comboBox->currentText();

        QString filetypeStr;
        if (imageType == QString("BMP")){
            filetypeStr = QString(".bmp");
        }
        else if (imageType == QString("JPG")){
            filetypeStr = QString(".jpg");
        }
        else if (imageType == QString("PNG")){
            filetypeStr = QString(".png");
        }
        else{
            filetypeStr = QString(".bmp");
        }

        bool saveResult;
        QString savefileName = QString("QRCode") + filetypeStr;
        saveResult = QRCodePixmap->save(savefileName);

        if (true == saveResult){
            QMessageBox::information(this, tr("QRCode Generator"), QString("Save to ") + savefileName + QString(" success"));
        }
        else{
            QMessageBox::warning(this, tr("QRCode Generator"), QString("Save to ") + savefileName + QString(" failure"));
        }
    }
    else{
        QMessageBox::warning(this, tr("QRCode Generator"), tr("Invalid QRCode Image"));
    }
#endif

}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString savetofile_buttonStr;

    QString filetypeStr;
    if (arg1 == QString("BMP")){
        savetofile_buttonStr = SAVE_TO_BMP;
    }
    else if (arg1 == QString("JPG")){
        savetofile_buttonStr = SAVE_TO_JPG;
    }
    else if (arg1 == QString("PNG")){
        savetofile_buttonStr = SAVE_TO_PNG;
    }
    else{
        savetofile_buttonStr = SAVE_TO_PNG;
    }

    ui->saveFileButton->setText(savetofile_buttonStr);
}

void MainWindow::on_generateButton_clicked()
{

}

void MainWindow::on_MergeButton_clicked()
{
    QString Merge = ui->lineEdit->text()+ui->lineEdit_2->text()+ui->lineEdit_3->text()+ui->lineEdit_4->text()+ui->lineEdit_5->text();
    ui->lineEdit_6->setText(Merge);


    char value1 = 'M';
    char value2 = 'B';
    char value3 = '1';


    char n1= value1 + 1;
    char n2= value2 + 2;
    char n3= value3 + 3;

    qDebug()<<n1 <<n2<<n3;
    /* char str;
    char num = '1';
    QString path;
    QByteArray ba;
    ba = Merge. toLatin1();
    str = *ba. data();

    qDebug()<<strx1;*/

    /* QByteArray ba = Merge.toLocal8Bit();
    unsigned char *res = (unsigned char *)strdup(ba.constData());
    std::cout << res << std::endl;




    qDebug()<<res.toInt() ;*/


    /* string operand = ui->lineEdit_6->text().toUtf8().constData();
    const std::string test=operand;
    std::ostringstream result;
    result << std::setw(2) << std::setfill('0') << std::hex << std::uppercase;
    std::copy(test.begin(), test.end(), std::ostream_iterator<unsigned int>(result, " "));
    std::cout << test << ":" << result.str() << std::endl;
    ui->lineEdit_7->setText(QString::fromStdString(result.str()));*/
}


void MainWindow::on_generateButton_pressed()
{
    bool image_loadfailure = false;
    bool invalid_qrimage = false;

    int qrcode_width = ui->qrcodepixmapLabel->width();
    int qrcode_height = ui->qrcodepixmapLabel->height();
    QRController* controller = new QRController(ui->lineEdit_10->text().toUtf8().constData(), eclMedium, qrcode_width, qrcode_height, evAuto);
    // controller1 = new QRController(ui->lineEdit_1->text().toUtf8().constData(), eclMedium, qrcode_width, qrcode_height, evAuto);
    int suitablepixlength = 0;
    bool checkresult = controller->getSuitablePixLength(suitablepixlength);
    if (true == checkresult){
        delete controller;

        controller = new QRController(ui->lineEdit_10->text().toUtf8().constData(), eclMedium, suitablepixlength, suitablepixlength, evAuto) ;
        //controller1 = new QRController (ui->lineEdit_2->text().toUtf8().constData(), eclMedium, suitablepixlength, suitablepixlength, evAuto)  ;
#ifdef DEBUG_LOGOUT_ON
        qDebug("Resize QRCode pixlength from (%d) to (%d)", qrcode_width, suitablepixlength);
#endif
    }
    else{
        qDebug("Resize QRCode to suitablepixlength failure!!!");
    }

    vector<char> tempBitmapArray;
    bool result;
    result = controller->SaveToByteArray(tempBitmapArray)  ;


    if (true == result){
        QByteArray tempQArray(tempBitmapArray.data(), tempBitmapArray.size());

        QPixmap QRCodeBitmap;
        bool loadresult = false;
        loadresult = QRCodeBitmap.loadFromData(tempQArray, "BMP");

        if (true == loadresult){
#ifdef DEBUG_LOGOUT_ON
            qDebug("QRCodeImage width(%d) height(%d) Load Complete.", QRCodeBitmap.width(), QRCodeBitmap.height());
#endif

            ui->qrcodepixmapLabel->setPixmap(QRCodeBitmap);
        }
        else{
            image_loadfailure = true;
            //QMessageBox::warning(this, tr("QRCode Generator"), tr("QRCodeImage Load Failure."));
            //qDebug("QRCodeImage Load Failed!!!");
        }
    }
    else{
        invalid_qrimage = true;
        ui->qrcodepixmapLabel->setPixmap(QPixmap());
        //QMessageBox::warning(this, tr("QRCode Generator"), tr("Invalid QRCodeImage."));
    }

    if ((ui->qrcodepixmapLabel->pixmap() != NULL)
            && (ui->qrcodepixmapLabel->pixmap()->isNull() != true)){
        ui->saveFileButton->setEnabled(true);
    }
    else{
        ui->saveFileButton->setEnabled(false);
    }

    delete controller;

    if (true == image_loadfailure){
        QMessageBox::warning(this, tr("QRCode Generator"), tr("QRCodeImage Load Failure."));
    }
    else if (true == invalid_qrimage){
        QMessageBox::warning(this, tr("QRCode Generator"), tr("Invalid QRCodeImage."));
    }
    else{
        // do nothing.
    }
}

void MainWindow::on_SplitButton_clicked()
{
    QString str2 = ui->lineEdit_6->text().toLocal8Bit().constData();

   // QString StrData = "abcd";
    qDebug()<<"before "<< str2;
    QStringList numberString;
    for(const auto character: str2)
    {
        numberString << QString::number(character.unicode(), 10);
    }
    QString HexStrData= numberString.join(" ");
    qDebug()<<HexStrData<<"Hex";
    QString Hex_Last = numberString.last();
    qDebug()<<Hex_Last;
 ui->lineEdit_7->setText(HexStrData);
 QString Data = ui->lineEdit_7->text();
  QStringList list_str2 = Data.split(" ");
  QString Last = list_str2.last();
  qDebug()<<Last;
  int last_val = Last.toInt();
  Val33=last_val+3;
  qDebug()<<Val33<<"a"<<last_val;
  std::ostringstream ss;
  ss << std::hex << Val33;
  std::string results = ss.str();
  //  std::cout << results << std::endl;
   res32= QString::fromStdString(results);

    // qDebug()<<QString::fromStdString(res)<<endl;
    /*QStringList numberString;
    for(const auto character: str2)
    {
        numberString << QString::number(character.unicode(), 10);
    }

    qDebug()<<numberString<<"NumberString";
    numberString = str2.split(",");*/

    //QString HexStrData= numberString.split(" ");
    // qDebug()<<HexStrData<<"HEX";


    //  QByteArray ba1 = HexStrData.toLocal8Bit().constData();

   // QStringList list_str2 = str2.split(" ");

    for (int i = 1; i < list_str2.size(); ++i)
    {
        QString ele=list_str2.at(i).toLocal8Bit().constData();

        if(i==1)
        {
            element1=list_str2.at(0).toLocal8Bit().constData();
            int a=list_str2.at(0).toInt();
            Val1 = a+1;
            qDebug()<<a<<Val1<<"a";
            std::ostringstream ss;
            ss << std::hex << Val1;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
            res1= QString::fromStdString(results);
            //ui->lineEdit_9->setText(QString::fromStdString(results));

        }
        else if(i==2)
        {
            element2=list_str2.at(1).toLocal8Bit().constData();
            int b=list_str2.at(1).toInt();
            Val2= b+2;
            qDebug()<<b<<Val2<<"b";
            std::ostringstream ss;
            ss << std::hex << Val2;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res2= QString::fromStdString(results);
        }

        else if(i==3)
        {
            element3=list_str2.at(2).toLocal8Bit().constData();
            int c=list_str2.at(2).toInt();
            Val3 = c+3;
            qDebug()<<c<<Val3<<"c";
            std::ostringstream ss;
            ss << std::hex << Val3;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
            res3= QString::fromStdString(results);
        }

        else if(i==4)
        {
            element4=list_str2.at(3).toLocal8Bit().constData();
            int d=list_str2.at(3).toInt();
            Val4 = d-1;
            qDebug()<<d<<Val4<<"d";
            std::ostringstream ss;
            ss << std::hex << Val4;
            std::string results = ss.str();
            res4= QString::fromStdString(results);
        }

        else if(i==5)
        {
            element5=list_str2.at(4).toLocal8Bit().constData();
            int e=list_str2.at(4).toInt();
            Val5= e-2;
            qDebug()<<e<<Val5<<"e";
            std::ostringstream ss;
            ss << std::hex << Val5;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
            res5= QString::fromStdString(results);
        }

        else if(i==6)
        {
            element6=list_str2.at(5).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            Val6 = f-3;
            qDebug()<<f<<Val6<<"f";
            std::ostringstream ss;
            ss << std::hex << Val6;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res6= QString::fromStdString(results);
        }

        else if(i==7)
        {
            element7=list_str2.at(6).toLocal8Bit().constData();
            int g=list_str2.at(6).toInt();
            Val7 = g+1;
             qDebug()<<g<<Val7<<"g";
            std::ostringstream ss;
            ss << std::hex << Val7;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
            res7= QString::fromStdString(results);
        }

        else if(i==8)
        {
            element8=list_str2.at(7).toLocal8Bit().constData();
            int h=list_str2.at(7).toInt();
            Val8 = h-2;
              qDebug()<<h<<Val8<<"h";
            std::ostringstream ss;
            ss << std::hex << Val8;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
            res8= QString::fromStdString(results);
        }

        else if(i==9)
        {
            element9=list_str2.at(8).toLocal8Bit().constData();
            int i=list_str2.at(8).toInt();
            Val9 = i-3;
              qDebug()<<i<<Val9<<"i";
            std::ostringstream ss;
            ss << std::hex << Val9;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
            res9= QString::fromStdString(results);
        }

        else if(i==10)
        {
            element10=list_str2.at(9).toLocal8Bit().constData();
            int j=list_str2.at(9).toInt();
            Val10 = j+1;
              qDebug()<<j<<Val10<<"j";
            std::ostringstream ss;
            ss << std::hex << Val10;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
            res10= QString::fromStdString(results);

        }

        else if(i==11)
        {
            element11=list_str2.at(10).toLocal8Bit().constData();
            int k=list_str2.at(10).toInt();
            Val11 = k-2;
              qDebug()<<k<<Val11<<"k";
            std::ostringstream ss;
            ss << std::hex << Val11;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res11= QString::fromStdString(results);
        }

        else if(i==12)
        {
            element12=list_str2.at(11).toLocal8Bit().constData();
            int l=list_str2.at(11).toInt();
            Val12 = l-3;
              qDebug()<<l<<Val12<<"l";
            std::ostringstream ss;
            ss << std::hex << Val12;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res12= QString::fromStdString(results);
        }

        else if(i==13)
        {
            element13=list_str2.at(12).toLocal8Bit().constData();
            int m=list_str2.at(12).toInt();
            Val13 = m-1;
              qDebug()<<m<<Val13<<"m";
            std::ostringstream ss;
            ss << std::hex << Val13;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res13= QString::fromStdString(results);
        }

        else if(i==14)
        {
            element14=list_str2.at(13).toLocal8Bit().constData();
            int n=list_str2.at(13).toInt();
            Val14 = n+2;
              qDebug()<<n<<Val14<<"n";
            std::ostringstream ss;
            ss << std::hex << Val14;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res14= QString::fromStdString(results);
        }

        else if(i==15)
        {
            element15=list_str2.at(14).toLocal8Bit().constData();
            int o=list_str2.at(14).toInt();
            Val15 = o+3;
             qDebug()<<o<<Val15<<"o";
            std::ostringstream ss;
            ss << std::hex << Val15;
            std::string results = ss.str();
            res15= QString::fromStdString(results);
        }

        else if(i==16)
        {
            element16=list_str2.at(15).toLocal8Bit().constData();
            int p=list_str2.at(15).toInt();
            Val16 = p+1;
             qDebug()<<p<<Val16<<"p";
            std::ostringstream ss;
            ss << std::hex << Val16;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res16= QString::fromStdString(results);
        }

        else if(i==17)
        {
            element17=list_str2.at(16).toLocal8Bit().constData();
            int q=list_str2.at(16).toInt();
            Val17 = q+2;
             qDebug()<<q<<Val17<<"q";
            std::ostringstream ss;
            ss << std::hex << Val17;
            std::string results = ss.str();
            res17= QString::fromStdString(results);
        }

        else if(i==18)
        {
            element18=list_str2.at(17).toLocal8Bit().constData();
            int r=list_str2.at(17).toInt();
            Val18 = r+3;
             qDebug()<<r<<Val18<<"r";
            std::ostringstream ss;
            ss << std::hex << Val18;
            std::string results = ss.str();
             res18= QString::fromStdString(results);
        }

        else if(i==19)
        {
            element19=list_str2.at(18).toLocal8Bit().constData();
            int s=list_str2.at(18).toInt();
            Val19 = s-1;
             qDebug()<<s<<Val19<<"s";
            std::ostringstream ss;
            ss << std::hex << Val19;
            std::string results = ss.str();
             res19= QString::fromStdString(results);
        }

        else if(i==20)
        {
            element20=list_str2.at(19).toLocal8Bit().constData();
            int t=list_str2.at(19).toInt();
            Val20 = t+2;
             qDebug()<<t<<Val20<<"t";
            std::ostringstream ss;
            ss << std::hex << Val20;
            std::string results = ss.str();
             res20= QString::fromStdString(results);
        }

        else if(i==21)
        {
            element21=list_str2.at(20).toLocal8Bit().constData();
            int u=list_str2.at(20).toInt();
            Val21 = u+3;
             qDebug()<<u<<Val21<<"u";
            std::ostringstream ss;
            ss << std::hex << Val21;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res21= QString::fromStdString(results);
        }

        else if(i==22)
        {
            element22=list_str2.at(21).toLocal8Bit().constData();
            int v=list_str2.at(21).toInt();
            Val22 = v+1;
             qDebug()<<v<<Val22<<"v";
            std::ostringstream ss;
            ss << std::hex << Val22;
            std::string results = ss.str();
             res22= QString::fromStdString(results);
        }

        else if(i==23)
        {
            element23=list_str2.at(22).toLocal8Bit().constData();
            int w=list_str2.at(22).toInt();
            Val23 = w-2;
             qDebug()<<w<<Val23<<"w";
            std::ostringstream ss;
            ss << std::hex << Val23;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res23= QString::fromStdString(results);
        }

        else if(i==24)
        {
            element24=list_str2.at(23).toLocal8Bit().constData();
            int x=list_str2.at(23).toInt();
            Val24 = x-3;
             qDebug()<<x<<Val24<<"x";
            std::ostringstream ss;
            ss << std::hex << Val24;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res24= QString::fromStdString(results);
        }

        else if(i==25)
        {
            element25=list_str2.at(24).toLocal8Bit().constData();
            int y=list_str2.at(24).toInt();
            Val25 = y-1;
             qDebug()<<y<<Val25<<"y";
            std::ostringstream ss;
            ss << std::hex << Val25;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res25= QString::fromStdString(results);
        }

        else if(i==26)
        {
            element26=list_str2.at(25).toLocal8Bit().constData();
            int z=list_str2.at(25).toInt();
            Val26 = z-2;
             qDebug()<<z<<Val26<<"z";
            std::ostringstream ss;
            ss << std::hex << Val26;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res26= QString::fromStdString(results);
        }

        else if(i==27)
        {
            element27=list_str2.at(26).toLocal8Bit().constData();
            int aa=list_str2.at(26).toInt();
            Val27 = aa-3;
             qDebug()<<aa<<Val27<<"aa";
            std::ostringstream ss;
            ss << std::hex << Val27;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res27= QString::fromStdString(results);
        }

        else if(i==28)
        {
            element28=list_str2.at(27).toLocal8Bit().constData();
            int ab=list_str2.at(27).toInt();
            Val28= ab+1;
             qDebug()<<ab<<Val28<<"ab";
            std::ostringstream ss;
            ss << std::hex << Val28;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res28= QString::fromStdString(results);
        }

        else if(i==29)
        {
            element29=list_str2.at(28).toLocal8Bit().constData();
            int ac=list_str2.at(28).toInt();
            Val29 = ac-2;
             qDebug()<<ac<<Val29<<"ac";
            std::ostringstream ss;
            ss << std::hex << Val29;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res29= QString::fromStdString(results);
        }

        else if(i==30)
        {
            element30=list_str2.last();
            int ad=list_str2.last().toInt();
            Val30 = ad+3;
             qDebug()<<ad<<Val30<<"ad";
            std::ostringstream ss;
            ss << std::hex << Val30;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res30= QString::fromStdString(results);
        }

        else if(i==31)
        {
            element31=list_str2.at(30).toLocal8Bit().constData();
            int ae=list_str2.at(30).toInt();
            Val31 = ae+1;
             qDebug()<<ae<<Val31<<"ae";
            std::ostringstream ss;
            ss << std::hex << Val31;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res31= QString::fromStdString(results);
        }

        else if(i==32)
        {
            element32=list_str2.at(31).toLocal8Bit().constData();
            int af=list_str2.at(31).toInt();
            Val32= af+2;
            qDebug()<<af<<Val32<<"af";
            std::ostringstream ss;
            ss << std::hex << Val32;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
            res32= QString::fromStdString(results);
        }

        else if(i==33)
        {
            element33=list_str2.at(32).toLocal8Bit().constData();
            int ag=list_str2.at(32).toInt();
            Val33 = ag+3;
            qDebug()<<Val33<<"a"<<ag;
            std::ostringstream ss;
            ss << std::hex << Val33;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res33= QString::fromStdString(results);
        }

        else if(i==34)
        {
            element34=list_str2.at(33).toLocal8Bit().constData();
            int ah=list_str2.at(33).toInt();
            Val34 = ah-1;
            qDebug()<<Val34<<"a"<<ah;
            std::ostringstream ss;
            ss << std::hex << Val34;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res34= QString::fromStdString(results);
        }

        else if(i==35)
        {
            element35=list_str2.at(34).toLocal8Bit().constData();
            int ai=list_str2.at(34).toInt();
            Val35 = ai-3;
            qDebug()<<Val31<<"a"<<ai;
            std::ostringstream ss;
            ss << std::hex << Val35;
            std::string results = ss.str();
            //  std::cout << results << std::endl;
             res35= QString::fromStdString(results);
        }

        else if(i==36)
        {
            element36=list_str2.at(35).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }

        else if(i==37)
        {
            element37=list_str2.at(36).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }

        else if(i==38)
        {
            element38=list_str2.at(37).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }

        else if(i==39)
        {
            element39=list_str2.at(38).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }

        else if(i==40)
        {
            element40=list_str2.at(39).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }

        else if(i==41)
        {
            element41=list_str2.at(40).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }

        else if(i==42)
        {
            element42=list_str2.at(41).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }

        else if(i==43)
        {
            element43=list_str2.at(42).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }

        else if(i==44)
        {
            element44=list_str2.at(43).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }

        else if(i==45)
        {
            element45=list_str2.at(44).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }
        else if(i==46)
        {
            element46=list_str2.at(45).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }

        else if(i==47)
        {
            element47=list_str2.at(46).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }

        else if(i==48)
        {
            element48=list_str2.at(47).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }

        else if(i==49)
        {
            element49=list_str2.at(48).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }
        else if(i==50)
        {
            element50=list_str2.at(49).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }

        else if(i==51)
        {
            element51=list_str2.at(50).toLocal8Bit().constData();
            int f=list_str2.at(5).toInt();
            qDebug()<<f-3;
        }


    }


    QString fr= QString::number(Val1);
    // qDebug()<<fr<<"fr";
    QString se= QString::number(Val2);
    // qDebug()<<se<<"se";
    int a[] = {Val1 ,Val2};
    int total = accumulate(begin(a), end(a), 0, plus<int>());
   // ui->lineEdit_8->setText(QString::number(Val1));
   // QString vv= ui->lineEdit_8->text();
   // int vvv= ui->lineEdit_8->text().toInt();
    // qDebug()<<vvv;


    int i = 78;
  //  QStringList list_str3 = vv.split(" ");

    // qDebug()<<list_str3<<"THis is list ";
   // std::ostringstream ss;
  //  ss << std::hex << Val1;
  //  std::string results = ss.str();

    //  std::cout << results << std::endl;
  QString Final_Hex = res1+res2+res3+res4+res5+res6+res7+res8+res9+res10+res11+res12+res13+res14+res15+res16+res17+res18+res19+res20+res21+res22+res23+res24+res25+res26+res27+res28+res29+res30+res31+res32+res33+res34;
    ui->lineEdit_9->setText(Final_Hex);
   /* QList<QString> list;
    list.append(res1);
    list.append(res2);
    list.append(res3);
    list.append(res4);
    list.append(res5);
    list.append(res6);
    list.append(res7);
    list.append(res8);
    list.append(res9);
    list.append(res10);
    list.append(res11);
    list.append(res12);
    list.append(res13);
    list.append(res14);
    list.append(res15);
    list.append(res16);
    list.append(res17);
    list.append(res18);
    list.append(res19);
    list.append(res20);
    list.append(res21);
    list.append(res22);
    list.append(res23);
    list.append(res24);
    list.append(res25);
    list.append(res26);
    list.append(res27);
    list.append(res28);
    list.append(res29);
    list.append(res30);
    list.append(res31);
    list.append(res32);
  list.append(res33);
    qDebug()<<list<<"List Append";

    QString HexStrDatas= list.join(" ");

qDebug()<<HexStrDatas;*/


}
    // ui->lineEdit_9->setText(QString::s
    //tring Value =
    //ui->lineEdit_9->setText(list);
   // QString split = Final_Hex.split(" ");
    //ui->lineEdit_9->setText(Final_Hex.append(res1,res2));//.toUtf8().constData();


    /*const std::string test=operand;
    std::ostringstream result;
    result << std::setw(2) << std::setfill('0') << std::hex << std::uppercase;
    std::copy(test.begin(), test.end(), std::ostream_iterator<unsigned int>(result, " "));
    std::cout << test << ":" << result.str() << std::endl;
    ui->lineEdit_9->setText(QString::fromStdString(result.str()));*/

    /* int demo = ba1.toInt();
   int  val =demo + 1;
    qDebug()<<"Val"<<val;

    unsigned char *res1 = (unsigned char *)strdup(ba1.constData());*/
    //  std::cout << res1 << std::endl;
    //qDebug()<<res1;


    /* QList<QByteArray> lines = HexStrData. split('\r\n');
    foreach ( const QByteArray &line, lines)
    qDebug() << line;*/


    //    QList<QByteArray> line = ba1. split(" ");
    //    foreach( const QByteArray &field, line)
    //    qDebug() << field;




    /* qDebug()<<HexStrData;
    dummy=(unsigned char)res.at(ind).toLatin1();

     QByteArray baa(4,0);
      baa[0]=0x4D;

      QString test("test");
      QChar c = test.at(0);
      int v_latin = c.toLatin1();
      int v_ascii = c.toAscii();
      qDebug() << v_latin << " " << v_ascii;

qDebug()<<hex<<ba[0]+1;*/



    //  unsigned char* test1 = (unsigned char*) str2.data();
    //    unsigned char test2[10];
    //    memcpy(test2,test1,str2.size());
    //    std::cout<<test2;

    //qDebug()<<res<<endl;

    /*   QStringList list_str2 = str2.split(" ");
    QByteArray ba (50, 0);
    QString temp , temp1 , temp2 , temp3 , temp4 , temp5 , temp6 , temp7 , temp8 , temp9 , temp10 , temp11, temp12, temp13 , temp14, temp15, temp16, temp17, temp18, temp19, temp20, temp21;
    QString  temp22, temp23, temp24, temp25, temp26, temp27, temp28 , temp29 , temp30, temp31;
    QString t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43,t44,t45,t46,t47,t48,t49,t50,t51;

    for (int i = 0; i < list_str2.size(); ++i)
    {
        // QString ele=list_str2.at(i).toLocal8Bit().constData();
        if(i==1)
        {
            element1=list_str2.at(0).toLocal8Bit().constData();
             ba[1]=0x4D;
             qDebug()<<hex<<ba[0]+1;

        }
        else if(i==2)
        {
            element2=list_str2.at(1).toLocal8Bit().constData();
            ba[1]=0x42;
            qDebug()<<hex<<ba[1]+2;
        }

        else if(i==3)
        {
            element3=list_str2.at(2).toLocal8Bit().constData();
            ba[2]=0x31;
            qDebug()<<hex<<ba[2]+3;
        }

        else if(i==4)
        {
            element4=list_str2.at(3).toLocal8Bit().constData();
            ba[3]=0x30;
            qDebug()<<hex<<ba[3]-1;
        }

        else if(i==5)
        {
            element5=list_str2.at(4).toLocal8Bit().constData();
            qDebug()<<"5"<<element5;
        }

        else if(i==6)
        {
            element6=list_str2.at(5).toLocal8Bit().constData();
            qDebug()<<"6"<<element6;
        }

        else if(i==7)
        {
            element7=list_str2.at(6).toLocal8Bit().constData();
            qDebug()<<"7"<<element7;
        }

        else if(i==8)
        {
            element8=list_str2.at(7).toLocal8Bit().constData();
            qDebug()<<"8"<<element8;
        }

        else if(i==9)
        {
            element9=list_str2.at(8).toLocal8Bit().constData();
            qDebug()<<"9"<<element9;
        }

        else if(i==10)
        {
            element10=list_str2.at(9).toLocal8Bit().constData();
            qDebug()<<"10"<<element10;
        }

        else if(i==11)
        {
            element11=list_str2.at(10).toLocal8Bit().constData();
            qDebug()<<"11"<<element11;
        }

        else if(i==12)
        {
            element12=list_str2.at(11).toLocal8Bit().constData();
            qDebug()<<"12"<<element12;
        }

        else if(i==13)
        {
            element13=list_str2.at(12).toLocal8Bit().constData();
            qDebug()<<"13"<<element13;
        }

        else if(i==14)
        {
            element14=list_str2.at(13).toLocal8Bit().constData();
            qDebug()<<"14"<<element14;
        }

        else if(i==15)
        {
            element15=list_str2.at(14).toLocal8Bit().constData();
            qDebug()<<"15"<<element15;
        }

        else if(i==16)
        {
            element16=list_str2.at(15).toLocal8Bit().constData();
            qDebug()<<"16"<<element16;
        }

        else if(i==17)
        {
            element17=list_str2.at(16).toLocal8Bit().constData();
            qDebug()<<"17"<<element17;
        }

        else if(i==18)
        {
            element18=list_str2.at(17).toLocal8Bit().constData();
            qDebug()<<"18"<<element18;
        }

        else if(i==19)
        {
            element19=list_str2.at(18).toLocal8Bit().constData();
            qDebug()<<"19"<<element19;
        }

        else if(i==20)
        {
            element20=list_str2.at(19).toLocal8Bit().constData();
            qDebug()<<"20"<<element20;
        }

        else if(i==21)
        {
            element21=list_str2.at(20).toLocal8Bit().constData();
            qDebug()<<"21"<<element21;
        }

        else if(i==22)
        {
            element22=list_str2.at(21).toLocal8Bit().constData();
            qDebug()<<"22"<<element22;
        }

        else if(i==23)
        {
            element23=list_str2.at(22).toLocal8Bit().constData();
            qDebug()<<"23"<<element23;
        }

        else if(i==24)
        {
            element24=list_str2.at(23).toLocal8Bit().constData();
            qDebug()<<"24"<<element24;
        }

        else if(i==25)
        {
            element25=list_str2.at(24).toLocal8Bit().constData();
            qDebug()<<"25"<<element25;
        }

        else if(i==26)
        {
            element26=list_str2.at(25).toLocal8Bit().constData();
            qDebug()<<"26"<<element26;
        }

        else if(i==27)
        {
            element27=list_str2.at(26).toLocal8Bit().constData();
            qDebug()<<"27"<<element27;
        }

        else if(i==28)
        {
            element28=list_str2.at(27).toLocal8Bit().constData();
            qDebug()<<"28"<<element28;
        }

        else if(i==29)
        {
            element29=list_str2.at(28).toLocal8Bit().constData();
            qDebug()<<"29"<<element29;
        }

        else if(i==30)
        {
            element30=list_str2.at(29).toLocal8Bit().constData();
            qDebug()<<"30"<<element30;
        }

        else if(i==31)
        {
            element31=list_str2.at(30).toLocal8Bit().constData();
            qDebug()<<"31"<<element31;
        }

        else if(i==32)
        {
            element32=list_str2.at(31).toLocal8Bit().constData();
            qDebug()<<"32"<<element32;
        }

        else if(i==33)
        {
            element33=list_str2.at(32).toLocal8Bit().constData();
            qDebug()<<"33"<<element33;
        }

        else if(i==34)
        {
            element34=list_str2.at(33).toLocal8Bit().constData();
            qDebug()<<"34"<<element34;
        }

        else if(i==35)
        {
            element35=list_str2.at(34).toLocal8Bit().constData();
            qDebug()<<"35"<<element35;
        }

        else if(i==36)
        {
            element36=list_str2.at(35).toLocal8Bit().constData();
            qDebug()<<"36"<<element36;
        }

        else if(i==37)
        {
            element37=list_str2.at(36).toLocal8Bit().constData();
            qDebug()<<"37"<<element37;
        }

        else if(i==38)
        {
            element38=list_str2.at(37).toLocal8Bit().constData();
            qDebug()<<"38"<<element38;
        }

        else if(i==39)
        {
            element39=list_str2.at(38).toLocal8Bit().constData();
            qDebug()<<"39"<<element39;
        }

        else if(i==40)
        {
            element40=list_str2.at(39).toLocal8Bit().constData();
            qDebug()<<"40"<<element40;
        }

        else if(i==41)
        {
            element41=list_str2.at(40).toLocal8Bit().constData();
            qDebug()<<"41"<<element41;
        }

        else if(i==42)
        {
            element42=list_str2.at(41).toLocal8Bit().constData();
            qDebug()<<"42"<<element42;
        }

        else if(i==43)
        {
            element43=list_str2.at(42).toLocal8Bit().constData();
            qDebug()<<"43"<<element43;
        }

        else if(i==44)
        {
            element44=list_str2.at(43).toLocal8Bit().constData();
            qDebug()<<"44"<<element44;
        }

        else if(i==45)
        {
            element45=list_str2.at(44).toLocal8Bit().constData();
            qDebug()<<"45"<<element45;
        }
        else if(i==46)
        {
            element46=list_str2.at(45).toLocal8Bit().constData();
            qDebug()<<"46"<<element46;
        }

        else if(i==47)
        {
            element47=list_str2.at(46).toLocal8Bit().constData();
            qDebug()<<"47"<<element47;
        }

        else if(i==48)
        {
            element48=list_str2.at(47).toLocal8Bit().constData();
            qDebug()<<"48"<<element48;
        }

        else if(i==49)
        {
            element49=list_str2.at(48).toLocal8Bit().constData();
            qDebug()<<"49"<<element49;
        }
        else if(i==50)
        {
            element50=list_str2.at(49).toLocal8Bit().constData();
            qDebug()<<"50"<<element50;
        }

        else if(i==51)
        {
            element51=list_str2.at(50).toLocal8Bit().constData();
            qDebug()<<"51"<<element51;
        }

    }

    // First Four////

    temp=element1;
    t1=element4;
    temp1=element2;
    t2=element3;
    t3=temp1;
    t4=temp;


    // Sec Four //

    temp2=element5;
    t5=element8;
    temp3=element6;
    t6=element7;
    t7=temp3;
    t8=temp2;


    //Third Four///

    temp4=element9;
    t9=element12;
    temp5=element10;
    t10=element11;
    t11=temp5;
    t12=temp4;


    //Fourth Four ///

    temp6=element13;
    t13=element16;
    temp7=element14;
    t14=element15;
    t15=temp7;
    t16=temp6;


    //Five


    temp8=element17;
    t17=element20;
    temp9=element18;
    t18=element11;
    t19=temp9;
    t20=temp8;


    // First Four////

    temp10=element21;
    t21=element24;
    temp11=element22;
    t22=element23;
    t23=temp11;
    t24=temp10;


    // Sec Four //

    temp12=element25;
    t25=element28;
    temp13=element26;
    t26=element27;
    t27=temp13;
    t28=temp12;


    //Third Four///

    temp14=element29;
    t29=element32;
    temp15=element30;
    t30=element31;
    t31=temp15;
    t32=temp14;


    //Fourth Four ///

    temp16=element33;
    t33=element36;
    temp17=element34;
    t34=element35;
    t35=temp17;
    t36=temp16;


    //Five


    temp18=element37;
    t37=element40;
    temp19=element38;
    t38=element39;
    t39=temp19;
    t40=temp18;


    //Fourth Four ///

    temp20=element41;
    t41=element44;
    temp21=element42;
    t42=element43;
    t43=temp21;
    t44=temp;


    //Five


    temp22=element45;
    t45=element48;
    temp23=element46;
    t46=element47;
    t47=temp23;
    t48=temp22;

    temp24=element49;
    t49=element51;
    temp25=element50;
    t50=temp24;
    t51=temp25;


    qDebug()<<t1<<t2<<t3<<t4<<t5<<t6<<t7<<t8<<t9<<t10<<t11<<t12<<t13<<t14<<t15<<t16<<t17<<t18<<t19<<t20<<t21<<t22<<t23<<t24<<t25<<t26<<t27<<t28<<t29<<t30<<t31<<t32<<t33<<t34<<t35<<t36<<t37<<t38<<t39<<t40<<t41<<t42<<t43<<t44<<t45<<t46<<t47<<t48<<t49<<t50<<t51;

    QString Data = t1+t2+t3+t4+t5+t6+t7+t8+t9+t10+t11+t12+t13+t14+t15+t16+t17+t18+t19+t20+t21+t22+t23+t24+t25+t26+t27+t28+t29+t30+t31+t32+t33+t34+t35+t36+t37+t38+t39+t40+t41+t42+t43+t44+t45+t46+t47+t48+t49+t50+t51;
    Data.simplified().remove(" ") ;
    ui->lineEdit_10->setText(Data);
    qDebug()<<Data;
*/



void MainWindow::on_MergeButton_pressed()
{

}



void MainWindow::on_SplitButton_2_clicked()
{

    QString temp , temp1 , temp2 , temp3 , temp4 , temp5 , temp6 , temp7 , temp8 , temp9 , temp10 , temp11, temp12, temp13 , temp14, temp15, temp16, temp17, temp18, temp19, temp20, temp21;
    QString  temp22, temp23, temp24, temp25, temp26, temp27, temp28 , temp29 , temp30, temp31;
    QString t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t40,t41,t42,t43,t44,t45,t46,t47,t48,t49,t50,t51;
    // First Four////

    temp=res1;
    t1=res4;
    temp1=res2;
    t2=res3;
    t3=temp1;
    t4=temp;


    // Sec Four //

    temp2=res5;
    t5=res8;
    temp3=res6;
    t6=res7;
    t7=temp3;
    t8=temp2;


    //Third Four///

    temp4=res9;
    t9=res12;
    temp5=res10;
    t10=res11;
    t11=temp5;
    t12=temp4;


    //Fourth Four ///

    temp6=res13;
    t13=res16;
    temp7=res14;
    t14=res15;
    t15=temp7;
    t16=temp6;


    //Five


    temp8=res17;
    t17=res20;
    temp9=res18;
    t18=res19;
    t19=temp9;
    t20=temp8;


    // First Four////

    temp10=res21;
    t21=res24;
    temp11=res22;
    t22=res23;
    t23=temp11;
    t24=temp10;


    // Sec Four //

    temp12=res25;
    t25=res28;
    temp13=res26;
    t26=res27;
    t27=temp13;
    t28=temp12;


    //Third Four///

    temp14=res29;
    t29=res32;
    temp15=res30;
    t30=res31;
    t31=temp15;
    t32=temp14;


  /* QList<QString> list;
    list.append(t1);
    list.append(t2);
    list.append(t3);
    list.append(t4);
    list.append(t5);
    list.append(t6);
    list.append(t7);
    list.append(t8);
    list.append(t10);
    list.append(t11);
    list.append(t12);
    list.append(t13);
    list.append(t14);
    list.append(t15);
    list.append(t16);
    list.append(t17);
    list.append(t18);
    list.append(t19);
    list.append(t20);
    list.append(t21);
    list.append(t22);
    list.append(t23);
    list.append(t24);
    list.append(t25);
    list.append(t26);
    list.append(t27);
    list.append(t28);
    list.append(t29);
    list.append(t30);
    list.append(t31);
    list.append(t32);
    list.append(t33);

    qDebug()<<list<<"List Append";

    QString HexStrDatas= list.join(" ");

qDebug()<<HexStrDatas;

ui->lineEdit_10->setText(HexStrDatas);*/
QString Data = t1+t2+t3+t4+t5+t6+t7+t8+t9+t10+t11+t12+t13+t14+t15+t16+t17+t18+t19+t20+t21+t22+t23+t24+t25+t26+t27+t28+t29+t30+t31+t32;
ui->lineEdit_10->setText(Data);
 /*   //Fourth Four ///

    temp16=element33;
    t33=element36;
    temp17=element34;
    t34=element35;
    t35=temp17;
    t36=temp16;


    //Five


    temp18=element37;
    t37=element40;
    temp19=element38;
    t38=element39;
    t39=temp19;
    t40=temp18;


    //Fourth Four ///

    temp20=element41;
    t41=element44;
    temp21=element42;
    t42=element43;
    t43=temp21;
    t44=temp;


    //Five


    temp22=element45;
    t45=element48;
    temp23=element46;
    t46=element47;
    t47=temp23;
    t48=temp22;

    temp24=element49;
    t49=element51;
    temp25=element50;
    t50=temp24;
    t51=temp25;*/



   /* string dec2hex(long a);
    long hex2dec(const QString & hexstr);*/

    // QString str2 = ui->lineEdit_7->text();
    //unsigned char* test1 = (unsigned char*) str2.data();

    /*QString test =  ui->lineEdit_7->text();
    QByteArray ba = test.toLocal8Bit();
    unsigned char *res = (unsigned char *)strdup(ba.constData());
    std::cout << res << std::endl;
    qDebug()<<res<<""<<ba;*/

    /*const char *str;
      QByteArray ba;
        QString test =  ui->lineEdit_7->text();
     ba = test.toLatin1();
                    str = ba.data();
                    qDebug()<<str;*/

    /*   QByteArray ba (4,0);
    ba[0]=0x41;
     ba[1]=0x4D;
      ba[2]=0x43;
       ba[3]=0x44;

       qDebug()<<char(ba[0]+1)<<" "<<ba[0]+4;
       qDebug()<<hex<<ba[1]+1;
        qDebug()<<hex<<ba[2]+4;
         qDebug()<<hex<<ba[3]+4;*/

    /*QString test = "ABCD";
 QByteArray b;
 b+=test;
 qDebug()<<char(b[3]+2)<<"Final";*/





}


/*QString hexadd(const string & hex1, const string & hex2)
{
    long n1, n2;
    n1 = hex2dec(hex1);
    n2 = hex2dec(hex2);
    return dec2hex(n1-n2);
}*/
