#include "updateWin.h"

UpdateWin::UpdateWin(Controller* manag, QWidget *parent) :
QWidget(parent), manag(manag)
{
	setupUi();
}

UpdateWin::~UpdateWin()
{
	setupUi();
}

void UpdateWin::setupUi(){
	QListView newList;
	resize(300, 250);
	setWindowTitle("Filtered offers");

	mainWidget = new QWidget(this);
	mainLayout = new QVBoxLayout(mainWidget);

	newList = new QTableView;
	tablemodel = new OfferTableModel(manag);
	newList->setModel(tablemodel);

	mainLayout->addWidget(newList);
}

