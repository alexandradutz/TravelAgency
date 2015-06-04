#ifndef OFFERTABLEMODEL_H
#define OFFERTABLEMODEL_H

#include <QAbstractTableModel>
#include <controller.h>
#include <sstream>


class OfferTableModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	explicit OfferTableModel(Controller* manag, QObject* parent = 0);
	~OfferTableModel();
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
	Qt::ItemFlags flags(const QModelIndex & index) const;

private:
	Controller* manag;

	private slots:
	void on_itemRemoved();
};

#endif // OFFERTABLEMODEL_H
