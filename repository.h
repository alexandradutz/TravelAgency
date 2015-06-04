
#ifndef __Contest_CPP__Repository__
#define __Contest_CPP__Repository__

#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include "domain.h"
#include "EntityValidator.h"
#include "MyException.h"
#include "AbstractRepository.h"
#include "validator.h"

using namespace std;

template <typename T>
class Repository : public AbstractRepository<T> {
  vector<T> offerList;
  EntityValidator<T> *validator;

public:
  virtual ~Repository();
  Repository();
  Repository(EntityValidator<T> *validator);
  vector<T> getAll();

  virtual void save(T p) throw (MyException);
  virtual void insertAtPosition(int id, T p) throw (MyException);
  virtual void update(int id, T p) throw (MyException);
  virtual void remove(int id) throw (MyException);
  const T findById(int id) throw (MyException);
  int size();
};

template <typename T>
Repository<T>::Repository() {
	/* Initializes repository
	*/

	this->validator = new OfferValidator;
	offerList.resize(0);
}

template <typename T>
Repository<T>::Repository(EntityValidator<T> *validator) {
	offerList.resize(0);
	this->validator = validator;
}


template <typename T>
Repository<T>::~Repository() {
	//  Destroy repository

	//delete this;
}

template <typename T>
vector<T> Repository<T>::getAll() {
	/* Get all the elemts

	returns: a vector with all the elements
	*/
	return this->offerList;
}

template <typename T>
void Repository<T>::save(T p) throw (MyException) {
	/* Save a element

	param: p - add a element of type T to the repository
	*/
	validator->validate(p);
	offerList.push_back(p);
}

template <typename T>
void Repository<T>::insertAtPosition(int id, T p) throw(MyException) {
	/* Insert a new element

	param: id - position of the element
	param: p - element to be saved
	*/
	if ((unsigned)id >= offerList.size()){
		throw MyException("Index error");
	}
	else {
		validator->validate(p);
		offerList.insert(offerList.begin() + id, p);
	}
}

template <typename T>
void Repository<T>::update(int id, T p) throw(MyException) {
	/* Update the repository

	param: id - position to be updated
	param: p - element to replace
	*/
	if ((unsigned)id >= offerList.size()){
		throw MyException("Index error");
	}
	else {
		validator->validate(p);
		offerList[id] = p;
	}
}

template <typename T>
void Repository<T>::remove(int id) throw(MyException) {
	/* Remove element at position

	param: id - position from where to remove an element
	*/
	if ((unsigned)id >= offerList.size()){
		throw MyException("Index error");
	}
	else {
		offerList.erase(offerList.begin() + id);
	}
}

template <typename T>
const T Repository<T>::findById(int id) throw (MyException) {
	/* Find element at position

	param: id - position of the element

	returns: element at the position id
	*/
	if ((unsigned)id >= offerList.size()){
		throw MyException("Index error");
	}
	else {
		return offerList[id];
	}
}

template <class T>
int Repository<T>::size() {
	/* The size of the Repository

	returns: the size of the repository
	*/
	return (int)offerList.size();
}


#endif /* defined(__Contest_CPP__Repository__) */
