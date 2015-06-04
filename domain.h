/*
 * domain.h
 *
 *  Created on: Apr 5, 2015
 *      Author: Dutzi
 */

#ifndef DOMAIN_H_
#define DOMAIN_H_

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

/*Class*/
class Offer
{
private:
	int id;
	string destination;
	string type;
	float price;

public:
	/*Constructors*/

	Offer(string destination, string type, float price);
	Offer();

	/* Destructor */
	~Offer();

	void	operator=(Offer other);
	bool	operator==(Offer& other);
	friend std::ostream& operator <<(std::ostream&, const Offer&);
	friend std::istream& operator >>(std::istream&, Offer&);

	/*
	 	 Set destination for an offer
	 	 - elem: offer
	 	 - dest: the destination that is added
	 */
	void setDest(string dest);


	/*
		Get destination of an offer
		- elem: offer
		Return the destination
		*/
	string getDest();


	/*
		 Set type for an offer
		 - elem: offer
		 - type: the type that is added
	*/
	void setType(string type);


	/*
		Get type for an offer
		 - elem: offer
		 Return the type of that elem
	*/
	string getType();


	/*
		 Set price for an offer
		 - elem: offer
		 - price: the price that is added
	*/
	void setPrice(float price);


	/*
		 Get price for an offer
		 - elem: offer
		 Return the price of that elem
	*/
	float getPrice();
	int getId();
};

#endif /* DOMAIN_H_ */
