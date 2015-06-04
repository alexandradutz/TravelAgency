#include "mainWin.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "controller.h"
#include "repository.h"
#include <vector>
#include "OfferFileRepository.h"
#include "MyException.h"
#include "controller.cpp"

int main (int argc, char *argv[]) {
	QApplication a{argc, argv};
	shared_ptr<AbstractRepository<Offer>> repo{ new OfferFileRepository{ "E:/Faculta/Anul I/Semestrul II/Eclipse Workspace/NewTravelAg/src/offers.txt" } };

	Controller* ctrl = new Controller {repo } ;
	TravelAgencyGUI window{ctrl, 0};
	window.show();


	return a.exec();
}

