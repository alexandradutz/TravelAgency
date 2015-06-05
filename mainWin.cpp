#include  "mainWin.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "domain.h"
#include "controller.h"
#include "update.h"

TravelAgencyGUI::TravelAgencyGUI(shared_ptr<Controller> ctrl, QWidget *parent) :
	QWidget(parent), ui(new Ui::TravelAgencyGUIClass)
{
	this->ctrl = ctrl;

	initGUI();
//	ui->setupUi(this);
	reload();
}

void TravelAgencyGUI::initGUI()
{


	//
	//General layout of the window
	//
	QHBoxLayout* layout = new QHBoxLayout(this);

	//
	// Prepare left side components
	//
	QWidget* leftWidget = new QWidget();
	QVBoxLayout* lLeft = new QVBoxLayout(leftWidget);
	
	QLabel* lbl = new QLabel("List of offers");
	lLeft->addWidget(lbl);
	offerList = new QListWidget();
	QObject::connect(offerList, SIGNAL(itemSelectionChanged()), this, SLOT(selectionChanged()));
	lLeft->addWidget(offerList);

	QPushButton* btnSortPrice = new QPushButton("Sort by Price");
	QObject::connect(btnSortPrice, SIGNAL(clicked()), this, SLOT(sortPrice()));
	lLeft->addWidget(btnSortPrice);

	QPushButton* btnSortDest = new QPushButton("Sort by Destination");
	QObject::connect(btnSortDest, SIGNAL(clicked()), this, SLOT(sortDest()));
	lLeft->addWidget(btnSortDest);

	QPushButton* btnSortType = new QPushButton("Sort by Type");
	QObject::connect(btnSortType, SIGNAL(clicked()), this, SLOT(sortType()));
	lLeft->addWidget(btnSortType);

	//
	// Prepare right side components
	//
	QWidget* rightWidget = new QWidget();
	QVBoxLayout* lRight = new QVBoxLayout(rightWidget);

	lbl = new QLabel("Destination");
	lRight->addWidget(lbl);
	txtDestination = new QLineEdit();
	lRight->addWidget(txtDestination);

	lbl = new QLabel("Type");
	lRight->addWidget(lbl);
	txtType = new QLineEdit();
	lRight->addWidget(txtType);

	lbl = new QLabel("Price");
	lRight->addWidget(lbl);
	txtPrice = new QLineEdit();
	lRight->addWidget(txtPrice);

	QPushButton* btnAdd = new QPushButton("Add");
	QObject::connect(btnAdd, SIGNAL(clicked()), this, SLOT(addOffer()));
	QObject::connect(btnAdd, SIGNAL(clicked()), this, SLOT(reload()));
	lRight->addWidget(btnAdd);

	QPushButton* btnUpdate = new QPushButton("Update");
	QObject::connect(btnUpdate, SIGNAL(clicked()), this, SLOT(updateOffer()));
	lRight->addWidget(btnUpdate);

	QPushButton* btnRemove = new QPushButton("Remove");
	QObject::connect(btnRemove, SIGNAL(clicked()), this, SLOT(removeOffer()));
	lRight->addWidget(btnRemove);

	QPushButton* btnFilterType = new QPushButton("Filter");
	QObject::connect(btnFilterType, SIGNAL(clicked()), this, SLOT(filter()));
	lRight->addWidget(btnFilterType);

	QPushButton* btnExit = new QPushButton("Exit");
	QObject::connect(btnExit, SIGNAL(clicked()), this, SLOT(close()));
	lRight->addWidget(btnExit);

	layout->addWidget(leftWidget);
	layout->addWidget(rightWidget);
}

void TravelAgencyGUI::addOffer()
{
	//Offer* of = new Offer(txtDestination->text().toStdString(), txtType->text().toStdString(), txtPrice->text().toInt());
	try
	{
		ctrl->addOffer(txtDestination->text().toStdString(), txtType->text().toStdString(), txtPrice->text().toFloat());
	}
	catch (MyException ex)
	{
		QMessageBox::information(this, "Can't add offer", QString::fromStdString(ex.what()));
	}
}

int TravelAgencyGUI::getSelectedIndex()
{
	QModelIndexList indexes = offerList->selectionModel()->selectedIndexes();
	if (indexes.size() == 0)
	{
		return -1;
	}
	return indexes.at(0).row();
}

void TravelAgencyGUI::reload(vector<Offer> offers)
{
	vector<Offer> vectorOffers;
	offerList->clear();
	if (offers.size() != 0){
		vectorOffers = offers;
	}
	else
	{
		vectorOffers = ctrl->getOffers();
	}
	for (int i = 0; i < ctrl->getSizeof(); i++)
	{
		Offer of = vectorOffers.at(i);
		offerList->addItem(QString::fromStdString((of.getDest() + " : " + of.getType() + " : " + to_string(of.getPrice()))));
	}
}

void TravelAgencyGUI::selectionChanged()
{
	int i = getSelectedIndex();
	if (i < 0)
	{
		return;
	}
	Offer of = ctrl->getbyId(i);

	txtDestination->setText(QString::fromStdString((of.getDest())));
	txtType->setText(QString::fromStdString((of.getType())));
	txtPrice->setText(QString::number((of.getPrice())));
}

void TravelAgencyGUI::removeOffer()
{
	int index = getSelectedIndex();
	if (index<0) {
		return;
	}
	ctrl->removeOffer(index);
	reload();
	txtDestination->clear();
	txtType->clear();
	txtPrice->clear();
}

void TravelAgencyGUI::updateOffer()
{
	int i = getSelectedIndex();

	if (i < 0) {
		if (QMessageBox::Yes == QMessageBox::question(this, "No offer selected.", "Want to add it?", QMessageBox::Yes, QMessageBox::No)) {
			addOffer();
			reload();
		}
		return;
	}

	string destination = txtDestination->text().toStdString();
	string type = txtType->text().toStdString();
	float price = txtPrice->text().toFloat();
	ctrl->modifyOffer(i, destination, type, price);
	reload();
}

void TravelAgencyGUI::filter() {
	vector<Offer> offers; //= ctrl->getOffers();
	if (txtType->text() != "") {
		string type = txtType->text().toStdString();
		offers = ctrl->filterbyType(type, offers);
		ctrl->printAll(offers);
	}
	if (txtPrice->text() != "") {
		float price = txtPrice->text().toFloat();
		offers = ctrl->filterbyPrice(price, offers);
		ctrl->printAll(offers);
	}
	Update* updateW = new Update(offers, 0);
	updateW->show();
}

void TravelAgencyGUI::sortPrice()
{
	vector<Offer> offers = ctrl->getOffers();
	sort(offers.begin(), offers.end(), [](Offer a, Offer b)
	{
		return a.getPrice() < b.getPrice();});
		reload(offers);
}

void TravelAgencyGUI::sortDest()
{
	vector<Offer> offers = ctrl->getOffers();
	sort(offers.begin(), offers.end(), [](Offer a, Offer b)
	{
		return a.getDest() < b.getDest(); });
		reload(offers);
}

void TravelAgencyGUI::sortType()
{
	vector<Offer> offers = ctrl->getOffers();
	sort(offers.begin(), offers.end(), [](Offer a, Offer b)
	{
		return a.getType() < b.getType(); });
		reload(offers);
}


TravelAgencyGUI::~TravelAgencyGUI()
{
	
}

