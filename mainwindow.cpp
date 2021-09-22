#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QDebug>
#include<QGridLayout>
#include <malloc.h>
#include <string.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);

	QObject::connect(ui->decrypt, SIGNAL(clicked()), this, SLOT(DecryFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_inBtn_clicked()
{
        //定义文件对话框类
         QFileDialog *fileDialog = new QFileDialog(this);

         QString strTitle=QString::fromUtf8("选择加密文件夹");
         //定义文件对话框标题
         fileDialog->setWindowTitle(strTitle);

         //设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
         fileDialog->setFileMode(QFileDialog::Directory);
         //设置视图模式
         fileDialog->setViewMode(QFileDialog::Detail);
         //打印所有选择的文件的路径
         QStringList fileNames;
         if (fileDialog->exec())
         {
             fileNames = fileDialog->selectedFiles();
             if (fileNames.length() > 0)
             {
                 ui->inEdit->setText(fileNames[0]);
                 //filepath = fileNames[0];
             }
         }
}


void MainWindow::on_outBtn_clicked()
{
              //定义文件对话框类
             QFileDialog *fileDialog = new QFileDialog(this);

             QString strTitle=QString::fromUtf8("选择保存文件夹");
             //定义文件对话框标题
             fileDialog->setWindowTitle(strTitle);

             //设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
             fileDialog->setFileMode(QFileDialog::Directory);
             //设置视图模式
             fileDialog->setViewMode(QFileDialog::Detail);
             //打印所有选择的文件的路径
             QStringList fileNames;
             if (fileDialog->exec())
             {
                 fileNames = fileDialog->selectedFiles();
                 if (fileNames.length() > 0)
                 {
                     ui->outEdit->setText(fileNames[0]);
                     //filepath = fileNames[0];
                 }
             }
}



void MainWindow::DecryFile()
{
	ui->logText->clear();
	if (ui->inEdit->text()=="" & ui->outEdit->text()=="")
	{
		ui->logText->append("请设置加密文件夹路径 和解密后文件夹路径！！！");
		return;
	}
	QFileInfoList file_info_list = GetAllFile(ui->inEdit->text());

	QString filter;

	QStringList strfileList;
	foreach(QFileInfo fileinfo, file_info_list)
	{
		filter = fileinfo.suffix();    //后缀名
		if ((filter != "jpg") && (filter != "jpeg") && (filter != "png"))
		{
			continue;
		}
		strfileList.append(fileinfo.absoluteFilePath());
	}

	char* sign = (char*)"4meJnPyl";
	char* key = (char*)"34UFXMgtkz";
	xxtea_long keylen, signlen;
	keylen = strlen(key);
	xxtea_long retlen;
	for (int i = 0; i < strfileList.size(); ++i)
	{
		QString tmp = strfileList.at(i);
		ui->logText->append(QString("图片文件：%1").arg(tmp));
		QFileInfo enFileInfo(tmp);
		QString outFileName= enFileInfo.fileName();
		qDebug() << outFileName;
		QFile file(tmp);
		file.open(QIODevice::ReadOnly );
		QByteArray t = file.readAll();

		qDebug() << tmp <<t.size()<<t;
		char* buf =t.data();
		bool flag2 = false;
		for (int i = 0; i < 8; i++)
		{
			flag2 = sign[i] != t[i];
			if (flag2)
			{
				ui->logText->append(QString("不是有效的加密文件：%1").arg(tmp));
				printf("sign file error");
				break;
			}
		}

		if (!flag2)
		{
			unsigned char *data = xxtea_decrypt((unsigned char*)(t.data() + 8), t.size()-8, (unsigned char*)key, keylen, &retlen);
			if (data == NULL) {

				ui->logText->append(QString("解密后失败：%1").arg(outFilePath));
			}
			else
			{
			
				QByteArray binOut = QByteArray((char*)data,retlen);
				QString outFilePath = ui->outEdit->text() + +"/"+outFileName;
				qDebug() << outFilePath << binOut.size();
				ui->logText->append(QString("解密后文件：%1").arg(outFilePath));
				QFile file(outFilePath);
				file.open(QIODevice::WriteOnly);
				file.write(binOut);
				file.close();
			}

		}
	}
	
}

QFileInfoList MainWindow::GetAllFile(const QString & path)
{
	QFileInfoList result;

	QDir dir(path);

	dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks | QDir::Dirs | QDir::NoDotAndDotDot);

	dir.setSorting(QDir::Time | QDir::Reversed);

	QFileInfoList fileInfoList = dir.entryInfoList();

	foreach(QFileInfo fileInfo, fileInfoList)

	{
		if (fileInfo.isDir())

		{
			result.append(GetAllFile(fileInfo.filePath()));

		}

		else

		{
			result.append(fileInfo);

		}

	}

	return result;
}








