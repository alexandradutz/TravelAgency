#ifndef UPDATE_H
#define UPDATE_H

#include <QWidget>
#include <QListWidget>
#include "domain.h"

class Update : public QWidget {
	Q_OBJECT

private:
	vector<Offer> offers;
	QListWidget *offerList;

	void initGUI();
public:
	explicit Update(vector<Offer> offers, QWidget *parent = 0);
	~Update();

	private slots:
	void reload();
};

#endif // UPDATE_H
