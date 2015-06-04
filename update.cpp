#include "update.h"
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QObject>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <stdio.h>

Update::Update(std::vector<Offer> offers, QWidget *parent) : QWidget(parent) {
	this->offers = offers;
	this->initGUI();
	this->reload();
}

void Update::initGUI() {
	//
	//General layout of the window
	//
	QHBoxLayout* layout = new QHBoxLayout(this);

	//
	// Prepare left side components
	//
	QWidget* leftWidget = new QWidget();
	QVBoxLayout* lLeft = new QVBoxLayout(leftWidget);

	QLabel* lbl = new QLabel("Offers");
	lLeft->addWidget(lbl);
	offerList = new QListWidget();
	lLeft->addWidget(offerList);
	layout->addWidget(leftWidget);
}

void Update::reload() {
	offerList->clear();
	for (vector<Offer>::iterator p = this->offers.begin(); p != this->offers.end(); ++p) {
		offerList->addItem(QString::fromStdString(p->getDest() + " " + p->getType() + ": " + std::to_string(p->getPrice())));
	}
}

Update::~Update() {

}
