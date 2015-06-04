#ifndef __NewTravelAg__
#define ___NewTravelAg__

#include <stdio.h>
#include "MyException.h"
#include "EntityValidator.h"
#include "domain.h"
#include <string>
#include <stdexcept>

using namespace std;

class OfferStoreException: public MyException {
public:
	OfferStoreException(const string& msg = "productStore exception") : MyException ( msg ) {};
	OfferStoreException(const exception& ex) : MyException ( ex ) {};
};

class OfferValidator: public EntityValidator<Offer> {
	//virtual void validate(const Offer& p) const;
	virtual void validate(Offer&) const;
};

#endif /* defined(___NewTravelAg__) */
