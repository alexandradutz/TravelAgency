#ifndef UPDATEWIN_H
#define UPDATEWIN_H

#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <controller.h>
#include <QtWidgets/QListWidget>
#include "offertablemodel.h"

class UpdateWin : public QWidget
{
	Q_OBJECT

public:
	explicit UpdateWin(Controller* manag, QWidget *parent = 0);
	~UpdateWin();

	QWidget* mainWidget;
	QVBoxLayout* mainLayout;
	QTableView* newList;
	OfferTableModel* tablemodel;

private:
	void setupUi();


};

#endif // UPDATEWIN_H
