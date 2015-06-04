#include "offertablemodel.h"

using namespace std;

OfferTableModel::OfferTableModel(Controller* manag, QObject* parent) :
QAbstractTableModel(parent), manag(manag)
{
	QObject::connect(manag, SIGNAL(itemRemoved()), this, SLOT(on_itemRemoved()));
}


OfferTableModel::~OfferTableModel()
{

}

int OfferTableModel::rowCount(const QModelIndex &parent) const{
	return manag->getOffers().size();
}

int OfferTableModel::columnCount(const QModelIndex &parent) const{
	return 2;
}

QVariant OfferTableModel::data(const QModelIndex &index, int role) const{
	if (!index.isValid()){
		return QVariant();
	}
	if (index.row()>manag->getOffers().size()){
		return QVariant();
	}

	if (role == Qt::DisplayRole){
		Offer of = manag->getOffers()[index.row()];
		if (index.column() == 0){
			QString text = QString::fromStdString(of.getDest());
			return QVariant(text);
		}
		if (index.column() == 1){
			return QVariant(of.getPrice());
		}
	}

	return QVariant();
}

bool OfferTableModel::setData(const QModelIndex & index, const QVariant & value, int role){
	if (role == Qt::EditRole){
		Offer of = manag->getOffers()[index.row()];
		if (index.column() == 0){
			std::string destination = value.toString().toStdString();
			of.setDest(destination);
			manag->modifyOffer(of);
		}
		if (index.column() == 1){
			bool ok;
			float price = value.toFloat(&ok);
			if (!ok){
				return false;
			}
			of.setPrice(price);
			manag->modifyOffer(of);
		}
	}
	return true;
}

Qt::ItemFlags OfferTableModel::flags(const QModelIndex & index) const{
	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void OfferTableModel::on_itemRemoved(){
	int size = manag->getOffers().size();
	QModelIndex lineLeft = createIndex(0, 0);
	QModelIndex lineRight = createIndex(size, 1);
	emit dataChanged(lineLeft, lineRight);
}
