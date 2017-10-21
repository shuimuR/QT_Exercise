#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowTitle("Main window");
    QAction *saveAction = new QAction(QIcon(":/images/doc-save"), tr("&Save"), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip("Save file");
    connect(saveAction, &QAction::triggered, this, &MainWindow::save);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(saveAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(saveAction);

    statusBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::save()
{
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");

    msgBox.setInformativeText(tr("Do you want to save your change?"));

    msgBox.setDetailedText("Difference here....");

    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox :: Cancel);

    msgBox.setDefaultButton(QMessageBox::Save);

    int ret = msgBox.exec();

    switch(ret)

    {

    case QMessageBox::Save:

        qDebug() << "Save documwnt";

        break;

    case QMessageBox::Discard:

        qDebug() << "Discard changes!";

        break;

    case QMessageBox::Cancel:

        qDebug() << "Close document;";

        break;

    }
}
