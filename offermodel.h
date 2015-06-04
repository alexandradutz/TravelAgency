#ifndef __OFFER_MODEL__
#define __OFFER_MODEL__

#include <QAbstractListModel>
#include <controller.h>
#include <sstream>

class OfferModel : public QAbstractListModel
{
	Q_OBJECT

public:
	explicit OfferModel(Controller* manag, QObject* parent = 0);
	~OfferModel();
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	bool removeRows(int row, int count, const QModelIndex & parent = QModelIndex());

private:
	Controller* manag;

};

#endif // __OFFER_MODEL__