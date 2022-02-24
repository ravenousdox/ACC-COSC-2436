#include "ArrayBag.h"
#include <iostream>
#include <cstddef>

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
   bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

/*------------------NEW METHOD IMPLEMENTATIONS------------------*/

//private
/******************************************************************************/
/* Method:     binarySearchRecursive
/* Inputs:     A constant reference to a target of type ItemType,
/*             An integer representing the left bound of the partition
/*             being searched, An integer representing the right bound
/*             of the partition being searched.
/* Outputs:    An integer representing the index to the target the
/*             user was searching for or -1 to signify the target 
/*             not being found
/* Purpose:    Searches and attempts to find target in the ArrayBag 
/*             contents using recursive binary search
/******************************************************************************/
template<class ItemType>
int ArrayBag<ItemType>::binarySearchRecursive(const ItemType& target, int leftBound, int rightBound) const {	
	if (leftBound <= rightBound) {
		int mid = leftBound + (rightBound - leftBound) / 2;				//Find the middle element of the partition cleverly to prevent overflow
		
		if (items[mid] == target)										//If the element found at the middle index is the target...
			return mid + 1;												//Return that POSITION (not index)
			
		if (items[mid] > target)										//If the target is less than the element found at the middle index...						
			return binarySearchRecursive(target, leftBound, mid - 1);	//Search the partition to the right of that element				
		
		return binarySearchRecursive(target, mid + 1, rightBound);		//Else search the partition to the left of that element	
	}
	return -1;															//Return -1 if nothing was found
} // end binarySearchRecursive

/******************************************************************************/
/* Method:     binarySearchRecursiveHelper
/* Inputs:     A constant reference to a target of type ItemType
/* Outputs:    The integer value returned by binarySearchRecursive
/* Purpose:    Obtains the leftBound and rightBound arguments for 
/*             the binarySearchRecursive method
/******************************************************************************/
template<class ItemType>
int ArrayBag<ItemType>::binarySearchRecursiveHelper(const ItemType& target) const {
	return binarySearchRecursive(target, 0, itemCount);			//Calls the binary search algorithm, passing parameters related to the implementation
} // end binarySearchRecursiveHelper

/******************************************************************************/
/* Method:     binarySearchIterative
/* Inputs:     A constant reference to a target of type ItemType
/* Outputs:    An integer representing the index to the target the
/*             user was searching for or -1 to signify the target 
/*             not being found
/* Purpose:    Searches and attempts to find target in the ArrayBag 
/*             contents using iterative binary search
/******************************************************************************/
template<class ItemType>
int ArrayBag<ItemType>::binarySearchIterative(const ItemType& target) const {
	int leftBound = 0;
	int rightBound = itemCount;

	while (leftBound <= rightBound) {							//While you have not reached the end of the partition...
		int mid = leftBound + (rightBound - leftBound) / 2;     //Find the middle element of the partition cleverly to prevent overflow
		
		if (items[mid] == target)								//If the element found at the middle index is the target...
			return mid + 1;										//Return that POSITION (not index)
			
		if (items[mid] > target)								//If the target is less than the element found at the middle index...
			rightBound = mid - 1;								//Search the partition to the right of that element
		else
			leftBound = mid + 1;								//Else search the partition to the left of that element
	} 
	return -1;													//Return -1 if nothing was found			
} // end binarySearchIterative


/******************************************************************************/
/* Method:     bubbleSort
/* Inputs:     None
/* Outputs:    None
/* Purpose:    Sorts the contents of ArrayBag using the bubble sort 
/*             algorithm
/******************************************************************************/
template<class ItemType>
void ArrayBag<ItemType>::bubbleSort() {
	ItemType temp;
	bool swapped;
	
	do {
		swapped = false;											//Set swapped to false
		for (int i = 0; i < (itemCount - 1); i++) {					//For each element...
			for (int j = 0; j < (itemCount - i - 1); j++) {			//Compare with the elements not sorted. Last i elements are already sorted.
				if (items[j] > items[j + 1]) {						//If the previous value is greater than the next value
					temp = items[j];								//Swap them
					items[j] = items[j + 1];
					items[j + 1] = temp;
					swapped = true;									//Set swapped to true
				}
			}
		}
	} while (swapped);												//Only continue sorting if a swap has occurred 
} // end bubbleSort



