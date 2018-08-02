/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

//! [0]
#include <QtWidgets>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QtPrintSupport>
#endif
#endif
#include<QTreeWidget>
#include "mainwindow.h"
#include <QMainWindow>
#include <QMdiArea>
//! [0]

//! [1]
MainWindow::MainWindow(QWidget *parent)
    : textEdit(new QTextEdit)
{
   // setCentralWidget(textEdit);

    createActions();
    createStatusBar();
    createDockWindows();
    //QMainWindow *mainwindow = new QMainWindow(this);
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    setWindowTitle(tr("IC虚拟仿真教学系统"));

   // newLetter();
    setUnifiedTitleAndToolBarOnMac(true);
}
//! [1]

//! [2]
//void MainWindow::newLetter()
//{
//    textEdit->clear();

//    QTextCursor cursor(textEdit->textCursor());
//    cursor.movePosition(QTextCursor::Start);
//    QTextFrame *topFrame = cursor.currentFrame();
//    QTextFrameFormat topFrameFormat = topFrame->frameFormat();
//    topFrameFormat.setPadding(16);
//    topFrame->setFrameFormat(topFrameFormat);

//    QTextCharFormat textFormat;
//    QTextCharFormat boldFormat;
//    boldFormat.setFontWeight(QFont::Bold);
//    QTextCharFormat italicFormat;
//    italicFormat.setFontItalic(true);

//    QTextTableFormat tableFormat;
//    tableFormat.setBorder(1);
//    tableFormat.setCellPadding(16);
//    tableFormat.setAlignment(Qt::AlignRight);
//    cursor.insertTable(1, 1, tableFormat);
//    cursor.insertText("The Firm", boldFormat);
//    cursor.insertBlock();
//    cursor.insertText("321 City Street", textFormat);
//    cursor.insertBlock();
//    cursor.insertText("Industry Park");
//    cursor.insertBlock();
//    cursor.insertText("Some Country");
//    cursor.setPosition(topFrame->lastPosition());
//    cursor.insertText(QDate::currentDate().toString("d MMMM yyyy"), textFormat);
//    cursor.insertBlock();
//    cursor.insertBlock();
//    cursor.insertText("Dear ", textFormat);
//    cursor.insertText("NAME", italicFormat);
//    cursor.insertText(",", textFormat);
//    for (int i = 0; i < 3; ++i)
//        cursor.insertBlock();
//    cursor.insertText(tr("Yours sincerely,"), textFormat);
//    for (int i = 0; i < 3; ++i)
//        cursor.insertBlock();
//    cursor.insertText("The Boss", textFormat);
//    cursor.insertBlock();
//    cursor.insertText("ADDRESS", italicFormat);
//}
//! [2]


//! [3]
void MainWindow::print()
{
#if QT_CONFIG(printdialog)
    QTextDocument *document = textEdit->document();
    QPrinter printer;

    QPrintDialog dlg(&printer, this);
    if (dlg.exec() != QDialog::Accepted) {
        return;
    }

    document->print(&printer);
    statusBar()->showMessage(tr("Ready"), 2000);
#endif
}
//! [3]

//! [4]
void MainWindow::save()
{
    QMimeDatabase mimeDatabase;
    QString fileName = QFileDialog::getSaveFileName(this,
                        tr("Choose a file name"), ".",
                        mimeDatabase.mimeTypeForName("text/html").filterString());
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Dock Widgets"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << textEdit->toHtml();
    QApplication::restoreOverrideCursor();

    statusBar()->showMessage(tr("Saved '%1'").arg(fileName), 2000);
}
//! [4]

//! [5]
void MainWindow::undo()
{
    QTextDocument *document = textEdit->document();
    document->undo();
}
//! [5]

//! [6]
//void MainWindow::insertCustomer(const QString &customer)
//{
//    if (customer.isEmpty())
//        return;
//    QStringList customerList = customer.split(", ");
//    QTextDocument *document = textEdit->document();
//    QTextCursor cursor = document->find("NAME");
//    if (!cursor.isNull()) {
//        cursor.beginEditBlock();
//        cursor.insertText(customerList.at(0));
//        QTextCursor oldcursor = cursor;
//        cursor = document->find("ADDRESS");
//        if (!cursor.isNull()) {
//            for (int i = 1; i < customerList.size(); ++i) {
//                cursor.insertBlock();
//                cursor.insertText(customerList.at(i));
//            }
//            cursor.endEditBlock();
//        }
//        else
//            oldcursor.endEditBlock();
//    }
//}
//! [6]

//! [7]
//void MainWindow::addParagraph(const QString &paragraph)
//{
//    if (paragraph.isEmpty())
//        return;
//    QTextDocument *document = textEdit->document();
//    QTextCursor cursor = document->find(tr("Yours sincerely,"));
//    if (cursor.isNull())
//        return;
//    cursor.beginEditBlock();
//    cursor.movePosition(QTextCursor::PreviousBlock, QTextCursor::MoveAnchor, 2);
//    cursor.insertBlock();
//    cursor.insertText(paragraph);
//    cursor.insertBlock();
//    cursor.endEditBlock();

//}
//! [7]

void MainWindow::about()
{
   QMessageBox::about(this, tr("关于教学系统"),
            tr("IC虚拟仿真教学系统是由河海大学与朗讯科技合作研发"));
}

void MainWindow::createActions()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QToolBar *fileToolBar = addToolBar(tr("File"));

    const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
    QAction *newLetterAct = new QAction(newIcon, tr("&New Letter"), this);
    newLetterAct->setShortcuts(QKeySequence::New);
    newLetterAct->setStatusTip(tr("Create a new form letter"));
//    connect(newLetterAct, &QAction::triggered, this, &MainWindow::newLetter);
//    fileMenu->addAction(newLetterAct);
    fileToolBar->addAction(newLetterAct);

    const QIcon saveIcon = QIcon::fromTheme("document-save", QIcon(":/images/save.png"));
    QAction *saveAct = new QAction(saveIcon, tr("&Save..."), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the current form letter"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);
    fileMenu->addAction(saveAct);
    fileToolBar->addAction(saveAct);

    const QIcon printIcon = QIcon::fromTheme("document-print", QIcon(":/images/print.png"));
    QAction *printAct = new QAction(printIcon, tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print the current form letter"));
    connect(printAct, &QAction::triggered, this, &MainWindow::print);
    fileMenu->addAction(printAct);
    fileToolBar->addAction(printAct);

    fileMenu->addSeparator();

    QAction *quitAct = fileMenu->addAction(tr("&Quit"), this, &QWidget::close);
    quitAct->setShortcuts(QKeySequence::Quit);
    quitAct->setStatusTip(tr("Quit the application"));

    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));
    QToolBar *editToolBar = addToolBar(tr("Edit"));
    const QIcon undoIcon = QIcon::fromTheme("edit-undo", QIcon(":/images/undo.png"));
    QAction *undoAct = new QAction(undoIcon, tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Undo the last editing action"));
    connect(undoAct, &QAction::triggered, this, &MainWindow::undo);
    editMenu->addAction(undoAct);
    editToolBar->addAction(undoAct);

    viewMenu = menuBar()->addMenu(tr("&View"));

    menuBar()->addSeparator();

    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));

    QAction *aboutAct = helpMenu->addAction(tr("&About"), this, &MainWindow::about);
    aboutAct->setStatusTip(tr("Show the application's About box"));

    QAction *aboutQtAct = helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
}

//! [8]
void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}
//! [8]

//! [9]
void MainWindow::createDockWindows()
{
    QDockWidget *dock = new QDockWidget(tr("课程目录"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    courseList = new QTreeWidget(dock);
//////////////////////////////////////////////////////
    //QTreeWidget *courseList = new QTreeWidget;  //创建树形控件

    QStringList headers;        //树头
    headers << "课程目录";
    courseList->setHeaderLabels(headers);

    QStringList root1TextList;   //一级目录
    root1TextList << "集成电路工艺";    //添加选项 集成电路工艺
    QTreeWidgetItem *root1 = new QTreeWidgetItem(courseList, root1TextList);
    new QTreeWidgetItem(root1, QStringList() << QString("二极管工艺"));   //以根节点为父控件，添加选项 二极管，二级目录
    //QTreeWidgetItem *leaf2 =
    new QTreeWidgetItem(root1,QStringList() << QString("三极管工艺")); //以根节点为父控件，添加选项 三极管工艺，二级目录
    //leaf2->setCheckState(0, Qt::Checked);  //为Leaf2 设置勾选窗

    QStringList root2TextList;   //一级目录
    root2TextList << "IC晶圆制程";    //添加选项 集成电路工艺
    QTreeWidgetItem *root2 = new QTreeWidgetItem(courseList, root2TextList);
    new QTreeWidgetItem(root2, QStringList() << QString("单晶生长工艺"));   //以根节点为父控件，添加选项 单晶体，二级目录
    //QTreeWidgetItem *leaf2 =
    new QTreeWidgetItem(root2,QStringList() << QString("硅片制备")); //以根节点为父控件，添加选项 硅片制备，二级目录


    QList<QTreeWidgetItem *> root1List;
    root1List << root1;
    courseList->insertTopLevelItems(0, root1List);  //将树形选项 添加入Tree控件

    QList<QTreeWidgetItem *> root2List;
    root2List << root2;
    courseList->insertTopLevelItems(1, root2List);  //将树形选项 添加入Tree控件



///////////////////////////////////////////////////////
    //这段代码用于后来添加目录
//    customerList->addItems(QStringList()
//            << "John Doe, Harmony Enterprises, 12 Lakeside, Ambleton"
//            << "Jane Doe, Memorabilia, 23 Watersedge, Beaton"
//            << "Tammy Shea, Tiblanka, 38 Sea Views, Carlton"
//            << "Tim Sheen, Caraba Gifts, 48 Ocean Way, Deal"
//            << "Sol Harvey, Chicos Coffee, 53 New Springs, Eccleston"
//            << "Sally Hobart, Tiroli Tea, 67 Long River, Fedula");
    dock->setWidget(courseList);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
    viewMenu->addAction(dock->toggleViewAction());
    dock->setMinimumWidth(100);
    dock->setMaximumWidth(220);
    dock = new QDockWidget(tr("用户信息"), this);
/////////////////////////////////////////////////////

////////////////////////////////////////////////
    //userList = new QListWidget(dock);

    QTableWidget *userList = new QTableWidget(5,2); // 构造了一个QTableWidget的对象，并且设置为5行，2列
        //    也可用下面的方法构造QTableWidget对象
        //    QTableWidget *tableWidget = new QTableWidget;
        //    tableWidget->setRowCount(5);     //设置行数为10
        //    tableWidget->setColumnCount(2);   //设置列数为5
        userList->setWindowTitle("QTableWidget & Item");
        //userList->resize(350, 200);  //设置表格
        QStringList header;
        header<<"类目"<<"信息";
        userList->setHorizontalHeaderLabels(header);
        userList->setItem(0,0,new QTableWidgetItem("用户号："));
        userList->setItem(1,0,new QTableWidgetItem("用户名称："));
        userList->setItem(2,0,new QTableWidgetItem("用户类型"));
        userList->setItem(3,0,new QTableWidgetItem("用户ID:"));
        userList->setItem(4,0,new QTableWidgetItem("Email:"));

//        userList->setItem(0,1,new QTableWidgetItem(QIcon("images/IED.png"), "Jan's month"));
//        userList->setItem(1,1,new QTableWidgetItem(QIcon("images/IED.png"), "Feb's month"));
//        userList->setItem(2,1,new QTableWidgetItem(QIcon("images/IED.png"), "Mar's month"));
        userList->show();

    //这段用于添加用户信息
//    userList->addItems(QStringList()
//            << "Thank you for your payment which we have received today."
//            << "Your order has been dispatched and should be with you "
//               "within 28 days."
//            << "We have dispatched those items that were in stock. The "
//               "rest of your order will be dispatched once all the "
//               "remaining items have arrived at our warehouse. No "
//               "additional shipping charges will be made."
//            << "You made a small overpayment (less than $5) which we "
//               "will keep on account for you, or return at your request."
//            << "You made a small underpayment (less than $1), but we have "
//               "sent your order anyway. We'll add this underpayment to "
//               "your next bill."
//            << "Unfortunately you did not send enough money. Please remit "
//               "an additional $. Your order will be dispatched as soon as "
//               "the complete amount has been received."
//            << "You made an overpayment (more than $5). Do you wish to "
//               "buy more items, or should we return the excess to you?");
    dock->setWidget(userList);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
    viewMenu->addAction(dock->toggleViewAction());
    //dock->setMinimumWidth(100);
    dock->setMaximumWidth(220);
   // dock->setMinimumHeight(200);
    dock->setMaximumHeight(204);

//    connect(courseList, &QListWidget::currentTextChanged,
//            this, &MainWindow::insertCustomer);
//    connect(userList, &QListWidget::currentTextChanged,
//            this, &MainWindow::addParagraph);



}
//! [9]
