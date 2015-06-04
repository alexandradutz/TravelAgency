

#ifndef ABSTRACTREPOSITORY_H_
#define ABSTRACTREPOSITORY_H_

template<class T>
class AbstractRepository {

public:
	virtual void save(T e)=0;
	virtual void remove(int id)=0;
	virtual void update(int id, T Ti)=0;
	virtual std::vector<T> getAll()=0;
	virtual ~AbstractRepository(){}
	virtual int size()=0;
	virtual void insertAtPosition(int id,T p)=0;
	virtual const T findById(int id)=0;


};

#endif /* ABSTRACTREPOSITORY_H_ */
