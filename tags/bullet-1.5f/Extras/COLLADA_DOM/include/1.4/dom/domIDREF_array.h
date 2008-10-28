/*
 * Copyright 2006 Sony Computer Entertainment Inc.
 *
 * Licensed under the SCEA Shared Source License, Version 1.0 (the "License"); you may not use this 
 * file except in compliance with the License. You may obtain a copy of the License at:
 * http://research.scea.com/scea_shared_source_license.html
 *
 * Unless required by applicable law or agreed to in writing, software distributed under the License 
 * is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
 * implied. See the License for the specific language governing permissions and limitations under the 
 * License. 
 */
#ifndef __domIDREF_array_h__
#define __domIDREF_array_h__

#include <dom/domTypes.h>
#include <dom/domElements.h>


/**
 * The IDREF_array element declares the storage for a homogenous array of
 * ID reference values.
 */
class domIDREF_array : public daeElement
{
protected:  // Attributes
/**
 *  The id attribute is a text string containing the unique identifier of
 * this element. This value  must be unique within the instance document.
 * Optional attribute. 
 */
	xsID attrId;
/**
 *  The name attribute is the text string name of this element. Optional attribute.
 */
	xsNCName attrName;
/**
 *  The count attribute indicates the number of values in the array. Required
 * attribute. 
 */
	domUint attrCount;

protected:  // Value
	/**
	 * The xsIDREFS value of the text data of this element. 
	 */
	xsIDREFS _value;

public:	//Accessors and Mutators
	/**
	 * Gets the id attribute.
	 * @return Returns a xsID of the id attribute.
	 */
	xsID getId() const { return attrId; }
	/**
	 * Sets the id attribute.
	 * @param atId The new value for the id attribute.
	 */
	void setId( xsID atId ) { attrId = atId; }

	/**
	 * Gets the name attribute.
	 * @return Returns a xsNCName of the name attribute.
	 */
	xsNCName getName() const { return attrName; }
	/**
	 * Sets the name attribute.
	 * @param atName The new value for the name attribute.
	 */
	void setName( xsNCName atName ) { attrName = atName; }

	/**
	 * Gets the count attribute.
	 * @return Returns a domUint of the count attribute.
	 */
	domUint getCount() const { return attrCount; }
	/**
	 * Sets the count attribute.
	 * @param atCount The new value for the count attribute.
	 */
	void setCount( domUint atCount ) { attrCount = atCount; }

	/**
	 * Gets the _value array.
	 * @return Returns a xsIDREFS reference of the _value array.
	 */
	xsIDREFS &getValue() { return _value; }
	/**
	 * Gets the _value array.
	 * @return Returns a constant xsIDREFS reference of the _value array.
	 */
	const xsIDREFS &getValue() const { return _value; }
	/**
	 * Sets the _value array.
	 * @param val The new value for the _value array.
	 */
	void setValue( const xsIDREFS &val ) { _value = val; }

protected:
	/**
	 * Constructor
	 */
	domIDREF_array() : attrId(), attrName(), attrCount(), _value() {}
	/**
	 * Destructor
	 */
	virtual ~domIDREF_array() {}
	/**
	 * Copy Constructor
	 */
	domIDREF_array( const domIDREF_array &cpy ) : daeElement() { (void)cpy; }
	/**
	 * Overloaded assignment operator
	 */
	virtual domIDREF_array &operator=( const domIDREF_array &cpy ) { (void)cpy; return *this; }

public: // STATIC METHODS
	/**
	 * Creates an instance of this class and returns a daeElementRef referencing it.
	 * @param bytes The size allocated for this instance.
	 * @return a daeElementRef referencing an instance of this object.
	 */
	static daeElementRef create(daeInt bytes);
	/**
	 * Creates a daeMetaElement object that describes this element in the meta object reflection framework.
	 * If a daeMetaElement already exists it will return that instead of creating a new one. 
	 * @return A daeMetaElement describing this COLLADA element.
	 */
	static daeMetaElement* registerElement();

public: // STATIC MEMBERS
	/**
	 * The daeMetaElement that describes this element in the meta object reflection framework.
	 */
	static daeMetaElement* _Meta;
};


#endif