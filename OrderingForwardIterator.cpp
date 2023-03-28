#include "OrderingForwardIterator.h"
#include <iostream>
#include <cassert>

using Forward = OrderingForwardIterator;

Forward::OrderingForwardIterator(const DataWrapper* aCollection) noexcept :
	fCollection (aCollection),
	fIndex(0),
	fMapPosition(0)
{
	setMapPosition();
}

const DataMap& Forward::operator*() noexcept
{
	return (*fCollection)[fMapPosition];
}

OrderingForwardIterator& Forward::operator++() noexcept
{
	fIndex++;
	setMapPosition();
	return *this;
}

OrderingForwardIterator Forward::operator++(int) noexcept
{
	Forward old(*this);
	++(*this);
	return old;
}

bool Forward::operator==(const OrderingForwardIterator& aOther) const noexcept
{
	return fIndex == aOther.fIndex && fCollection == aOther.fCollection;
}

bool Forward::operator!=(const OrderingForwardIterator& aOther) const noexcept
{
	return !(*this == aOther);
}

OrderingForwardIterator Forward::begin() const noexcept
{
	return OrderingForwardIterator(fCollection);
}

OrderingForwardIterator Forward::end() const noexcept
{
	Forward Result = *this;

	Result.fIndex = fCollection->size() - 1;

	return Result;
}

void OrderingForwardIterator::setMapPosition() {
	auto mapIndexToPayload = [this](size_t index) 
	{
		for (size_t i = 0; i < fCollection->size(); ++i) 
		{
			if ( (*fCollection) [i].key() == index) {
				return i;
			}
		}
		return static_cast<size_t>(-1); // Return an invalid index if not found
	};

	fMapPosition = mapIndexToPayload(fIndex);
}