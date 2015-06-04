#ifndef OFFERMANAGER
#define OFFERMANAGER
#include <vector>
#include <string>
using namespace std;

class Offer{
public:
	string destination;
	string type;
	float price;
};

class OfferManager{
public:
	void store(string destination, string type, float price)
	{
		Offer o;
		o.destination = destination;
		o.type = type;
		o.price = price;
		all.push_back(o);
	}
private:
	vector<Offer> all;

};

#endif // OFFERMANAGER
