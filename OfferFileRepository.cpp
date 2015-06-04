#include "OfferFileRepository.h"
#include "repository.cpp"

void OfferFileRepository::save(Offer p) throw (MyException) {
  Repository<Offer>::save(p);
  ofstream fout(filename.c_str(), ios::app);
  fout << p;
  fout.close();
}

void OfferFileRepository::loadEntities() throw (MyException) {
//string line;
  ifstream fin(filename.c_str());
  if (!fin.is_open()) {
    throw RepositoryException("could not open file");
  }
  while (fin.good()) {
    Offer p { };
    fin >> p;
    if (p.getDest() != "") {
      Repository<Offer>::save(p);
    }
  }
  fin.close();
}

void OfferFileRepository::insertAtPosition(int id, Offer p) throw(MyException) {
  Repository<Offer>::insertAtPosition(id, p);
  ofstream fout(filename.c_str(), ios::out);
  for(int i = 0; i < this->size(); i++) {
    Offer p = this->findById(i);
    fout << p;
  }
  fout.close();  fout.close();
}

void OfferFileRepository::update(int id, Offer p) throw(MyException) {
  Repository<Offer>::update((unsigned) id, p);
  ofstream fout(filename.c_str(), ios::out);
  for(int i = 0; i < this->size(); i++) {
    Offer p = this->findById(i);
    fout << p;
  }
  fout.close();
}

void OfferFileRepository::remove(int id) throw(MyException) {
  Repository<Offer>::remove((unsigned) id);
  ofstream fout(filename.c_str(), ios::out);
  for(int i = 0; i < this->size(); i++) {
    Offer p = this->findById(i);
    fout << p;
  }
  fout.close();
}
