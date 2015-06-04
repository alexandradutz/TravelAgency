/********************************************************************************
** Form generated from reading UI file 'travelagencygui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELAGENCYGUI_H
#define UI_TRAVELAGENCYGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TravelAgencyGUIClass
{
public:
    QWidget *centralWidget;
    QPushButton *Exitmadafaca;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TravelAgencyGUIClass)
    {
        if (TravelAgencyGUIClass->objectName().isEmpty())
            TravelAgencyGUIClass->setObjectName(QStringLiteral("TravelAgencyGUIClass"));
        TravelAgencyGUIClass->resize(600, 400);
        centralWidget = new QWidget(TravelAgencyGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Exitmadafaca = new QPushButton(centralWidget);
        Exitmadafaca->setObjectName(QStringLiteral("Exitmadafaca"));
        Exitmadafaca->setGeometry(QRect(130, 50, 75, 23));
        TravelAgencyGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TravelAgencyGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        TravelAgencyGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TravelAgencyGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TravelAgencyGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TravelAgencyGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TravelAgencyGUIClass->setStatusBar(statusBar);

        retranslateUi(TravelAgencyGUIClass);

        QMetaObject::connectSlotsByName(TravelAgencyGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *TravelAgencyGUIClass)
    {
        TravelAgencyGUIClass->setWindowTitle(QApplication::translate("TravelAgencyGUIClass", "TravelAgencyGUI", 0));
        Exitmadafaca->setText(QApplication::translate("TravelAgencyGUIClass", "Exitmdafaca", 0));
    } // retranslateUi

};

namespace Ui {
    class TravelAgencyGUIClass: public Ui_TravelAgencyGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELAGENCYGUI_H
