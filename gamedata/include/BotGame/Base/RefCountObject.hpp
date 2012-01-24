/*
 * RefCountObject.h
 *
 *  Created on: Jan 25, 2012
 *      Author: alno
 */

#ifndef REFCOUNTOBJECT_H_
#define REFCOUNTOBJECT_H_

namespace BotGame { namespace Base {

class RefCountObject {
public:
	RefCountObject();
	virtual ~RefCountObject();

	/**
	 * Increase reference counter by one
	 */
	void addRef() const;

	/**
	 * Decrease reference counter by one. If it become 0 destroy object.
	 */
	void release() const;
private:
	mutable int refCount;
};

} }

#endif /* REFCOUNTOBJECT_H_ */
