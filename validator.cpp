#include "validator.h"

void OfferValidator::validate(Offer& p) const{
  string err;
  if (p.getDest().empty()) {
    err += "Destination cannot be empty! ";
  }
  if (p.getType().empty()) {
    err += "Type cannot be empty! ";
  }
  if (p.getPrice() < 0) {
    err += "Price cannot be negative! ";
  }
  if (!err.empty()) {
    throw OfferStoreException(err) ;
  }
}
