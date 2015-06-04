
#include "controller.h"
#include "repository.h"
#include <vector>
#include <ostream>

/*
 * Initializes Controller
 */
Controller::Controller(shared_ptr<AbstractRepository<Offer>> repo)
{
	this->repo = repo;
//	this->uList = uList;
};

/*
 * Destroy Controller
 */
Controller::~Controller()
{
	//delete this;
};


/*
 * Get all holiday offers
 * returns: all offers
 */
vector<Offer> Controller::getOffers()
{
	return this->repo->getAll();
}

/*
 * Get the number of offers
 */
int Controller::getSizeof()
{
	return this->repo->size();
}

/*
 * Add a holiday offer
 * param: destination - a string with destination
 * param: type        - a string with offer type
 * param: price       - a float with price
 */
void Controller::addOffer(string destination, string type, float price)
{
	Offer o;
	o.setDest(destination);
	o.setPrice(price);
	o.setType(type);
	this->repo->save(o);
}

/*
 * Remove a holiday offer
 * position: position of the offer in the list
 */
void Controller::removeOffer(int position)
{
	this->repo->remove(position);
}

/*
 * Modify the offer
 * position: position of the offer in the list
 * destination, type, price: given info for a new offer
 */
void Controller::modifyOffer(int id, string destination, string type, float price )
{
	Offer o = Offer(destination, type, price);
		//o(id, destination, type, price);
	this->repo->update(id, o);
}

vector<Offer> Controller::filterbyType(string type, vector<Offer> filtered){
 // vector<Offer> filtered;
  vector<Offer> toBeFiltered = this->repo->getAll();
  if (filtered.size() != 0){
	  toBeFiltered = filtered;
  }
  else
  {
	  toBeFiltered = this->repo->getAll();
  }
  for (auto p : toBeFiltered) {
    if (p.getType() == type){
      filtered.push_back(p);
    }
  }
  return filtered;
}

vector<Offer> Controller::filterbyPrice(float price, vector<Offer> filtered){
	vector<Offer> toBeFiltered;
  if (filtered.size() != 0){
	  toBeFiltered = filtered;
  }
  else
  {
	  toBeFiltered = this->repo->getAll();
  }
  for (auto p : toBeFiltered) {
    if (p.getPrice() == price){
      filtered.push_back(p);
    }
  }
  return filtered;
}

void Controller::printAll(vector<Offer> offers)
{
	for (auto i : offers)
	{
		cout << i.getPrice() << i.getDest() << i.getType() << endl;
	}

}

Offer Controller::getbyId(int id)
{
	return repo->findById(id);
}