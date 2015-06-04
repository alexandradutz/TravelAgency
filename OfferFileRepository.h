
#ifndef __OfferFileRepository__
#define __OfferFileRepository__

#include <stdio.h>
#include <iostream>
#include "repository.h"
#include <string>
#include "EntityValidator.h"
#include "MyException.h"
#include <fstream>


using namespace std;

class OfferFileRepository: public Repository<Offer>{
  string filename;
public:
  OfferFileRepository(string filename) : Repository<Offer>() {
    this->filename = filename;
    loadEntities();
  }
  void save(Offer p) throw (MyException);
  void insertAtPosition(int id, Offer p) throw (MyException);
  void update(int id, Offer p) throw (MyException);
  void remove(int id) throw (MyException);
private:
  void loadEntities() throw (MyException);
};

#endif /* defined(__OfferFileRepository__) */
