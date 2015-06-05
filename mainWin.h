#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include "AbstractRepository.h"
#include  "repository.h"
#include "ui_travelagencygui.h"
#include "controller.h"

class TravelAgencyGUI : public QWidget
{
	Q_OBJECT

public:
	explicit TravelAgencyGUI(shared_ptr<Controller> ctrl = 0, QWidget *parent = 0);
	~TravelAgencyGUI();

private:
	void initGUI();
	void connectSignal();

	Ui::TravelAgencyGUIClass *ui;

	shared_ptr<Controller> ctrl;
	QListWidget* offerList;
	QLineEdit* txtPrice, *txtDestination, *txtType;

	int getSelectedIndex();
private slots:
	void selectionChanged();
	void addOffer();
	void removeOffer();
	void updateOffer();
	void reload(vector<Offer> offers = vector<Offer>());
	void filter();
	void sortPrice();
	void sortType();
	void sortDest();
};

#endif // MAINWIN_H
