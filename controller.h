/*
 * controller.h
 *
 *  Created on: Apr 5, 2015
 *      Author: Dutzi
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <string>
#include <sstream>
#include <vector>
#include "repository.h"
#include "AbstractRepository.h"
#include <memory>

using namespace std;

class Controller
{
private:
	shared_ptr<AbstractRepository<Offer>> repo;
public:
	/*
	* Default constructor
	*/
	//Controller();

	/*
	 *Copy constructor
	 */
	Controller(shared_ptr<AbstractRepository<Offer>> repo);

	/*
	 *Destructor
	 */
	~Controller();

	/*
	 * Get all holiday offers
	 * returns: all offers
	 */
	vector<Offer> getOffers();

	/*
	 * Add a holiday offer
	 * param: destination - a string with destination
	 * param: type        - a string with offer type
	 * param: price       - a float with price
	 */
	void addOffer(string destination, string type, float price);

	/*
	 * Remove a holiday offer
	 * position: position of the offer in the list
	 */
	void removeOffer(int position);

	/*
	 * Modify the offer
	 * position: position of the offer in the list
	 * destination, type, price: given info for a new offer
	 */
	void modifyOffer(int id, string destination, string type, float price );

	/*
	 * Filter the list of offers by type
	 * type: given type for filtering
	 */
	vector<Offer> filterbyType(string type, vector<Offer> filtered =  vector<Offer>());

	/*
	 * Filter the list of offers by price
	 * type: given price for filtering
	 */
	vector<Offer> filterbyPrice(float price, vector<Offer> filtered =  vector<Offer>());

	/*
	 * Get the number of offers
	 */
	int getSizeof();

	Offer getbyId(int id);
	void printAll(vector<Offer> offers);


};

#endif /* CONTROLLER_H_ */
