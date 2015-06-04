

#ifndef ENTITYVALIDATOR_H_
#define ENTITYVALIDATOR_H_

template<class Entity>
class EntityValidator {
public:
  virtual ~EntityValidator() {}
  virtual void validate(Entity&) const=0;
};

#endif /* ENTITYVALIDATOR_H_ */
