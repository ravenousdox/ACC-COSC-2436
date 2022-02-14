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

template<class ItemType>
int ArrayBag<ItemType>::binarySearchRecursive(const ItemType& target, int leftBound, int rightBound) const
{	
	if (leftBound <= rightBound) {
		int mid = leftBound + (rightBound - leftBound) / 2;
		
		if (items[mid] == target)
			return mid;
			
		if (items[mid] > target)													//If the target is in left-half
			return binarySearchRecursive(target, leftBound, mid - 1);					//target in [leftBound, mid - 1]
		
		return binarySearchRecursive(target, mid + 1, rightBound);						//Else, target in right-half, [mid + 1, rightBound]
	}
	return -1;
}

template<class ItemType>
int ArrayBag<ItemType>::binarySearchIterative(const ItemType& target) const
{
	int leftBound = 0;
	int rightBound = itemCount;
	//cout << "Left bound is " << leftBound << "\n";
	//cout << "Right bound is " << rightBound << "\n";
	while (leftBound <= rightBound) {
		//cout << "Left bound is " << leftBound << "\n";
		//cout << "Right bound is " << rightBound << "\n";
		int mid = leftBound + (rightBound - leftBound) / 2;
		//cout << "Middle index is " << mid << "\n";
		
		if (items[mid] == target) {
			//cout << "The item at middle index is " << items[mid] << "\n";
			return mid;
		}
			
		if (items[mid] > target)
			rightBound = mid - 1;
		else
			leftBound = mid + 1;
	} 
	return -1;
}
template<class ItemType>
void ArrayBag<ItemType>::bubbleSort() 
{
	int temp;
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < (itemCount - 1); i++) {
			for (int j = 0; j < (itemCount - 1); j++) {
				if (items[i] > items[i + 1]) {
					temp = items[i];
					items[i] = items[i + 1];
					items[i + 1] = temp;
					swapped = true;
				}
			}
		}
	} while (swapped);
}



