#include "offermodel.h"


OfferModel::OfferModel(Controller* manag, QObject* parent) :
QAbstractListModel(parent), manag(manag)
{
	QObject::connect(manag, SIGNAL(itemUpdated(int)), this, SLOT(on_itemUpdated(int)));
}

OfferModel::~OfferModel(){
}

int OfferModel::rowCount(const QModelIndex &parent) const{
	return manag->getOffers().size();
}

QVariant OfferModel::data(const QModelIndex &index, int role) const{
	if (!index.isValid()){
		return QVariant();
	}
	if (index.row()>manag->getOffers().size()){
		return QVariant();
	}

	if (role == Qt::DisplayRole){
		using namespace std;

		Offer of = manag->getOffers()[index.row()];

		QString text = QString::fromStdString(of.getDest());
		text.append(" ");
		text.append(QString::fromStdString(of.getType));
		stringstream ss;
		ss << of.getPrice();
		text.append(ss.str().c_str());

		return QVariant(text);
	}

	return QVariant();
}

bool OfferModel::removeRows(int position, int rows, const QModelIndex & parent){
	beginRemoveRows(QModelIndex(), position, position + rows - 1);

	manag->removeOffer(manag->getOffers()[position].getId());

	endRemoveRows();
	return true;
}

void OfferModel::on_itemUpdated(int position){
	QModelIndex lineLeft = createIndex(position, 0);
	QModelIndex lineRight = createIndex(position, 0);
	emit dataChanged(lineLeft, lineRight);
}
