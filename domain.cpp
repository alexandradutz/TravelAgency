/*
 * domain.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: Dutzi
 */
#include "domain.h"
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>


Offer::Offer()
{
	this->destination = "";
	this->type = "";
	this->price = 0;
}

Offer::~Offer()
{
//	delete this;
}

Offer::Offer(string destination, string type, float price)
{
	this->destination = destination;
	this->type = type;
	this->price = price;
}

void Offer::setDest(string dest)
{
	this->destination = dest;
}

string Offer::getDest()
{
	return this->destination;
}

int	Offer::getId()
{
	return (this->id);
}


void Offer::setType(string type)
{
	this->type = type;
}

string Offer::getType()
{
	return this->type;
}

void Offer::setPrice(float price)
{
	this->price = price;
}

float Offer::getPrice()
{
	return this->price;
}

void	Offer::operator=(Offer other)
{
	this->destination = other.getDest();
	this->type = other.getType();
	this->price = other.getPrice();
}

bool Offer::operator==(Offer& other)
{
	if (this->destination == other.getDest() &&
		this->type == other.getType() &&
		this->price == other.getPrice())
		return (true);
	return (false);
}


ostream& operator <<(ostream& os, const Offer& o) {
	os << o.destination << " " << o.type << " " << o.price << "\n";
	return os;
}

/*
 * Reads an offer
 */
istream& operator >>(istream &is, Offer& o) {
	string destination, type;
	float price;

	is >> destination >> type >> price;
	o.setDest(destination);
	o.setType(type);
	o.setPrice(price);
	return is;
}


