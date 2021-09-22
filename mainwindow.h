#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<tea.h>
#include<QFileInfoList>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_inBtn_clicked();

    void on_outBtn_clicked();


	void DecryFile();
private:
	QFileInfoList GetAllFile(const QString &path);

private:
    Ui::MainWindow *ui;
    QString inFilePath;
    QString outFilePath;
	QStringList filePathList;
	QStringList fileNameList;
};
#endif // MAINWINDOW_H
