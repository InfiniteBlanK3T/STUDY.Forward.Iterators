#include "SimpleForwardIterator.h"


SimpleForwardIterator::SimpleForwardIterator(const DataWrapper* aCollection) noexcept :
	fCollection(aCollection),
	fIndex(0)
{}

const DataMap& SimpleForwardIterator::operator*() noexcept
{
	return (*fCollection)[fIndex];
}

SimpleForwardIterator& SimpleForwardIterator::operator++() noexcept
{
	fIndex++;

	return *this;
}

SimpleForwardIterator SimpleForwardIterator::operator++(int) noexcept
{
	SimpleForwardIterator old = *this;

	++ (*this);

	return old;
}

bool SimpleForwardIterator::operator==(const SimpleForwardIterator& aOther) const noexcept
{
	return fIndex == aOther.fIndex;
}

bool SimpleForwardIterator::operator!=(const SimpleForwardIterator& aOther) const noexcept
{
	return !(*this == aOther);
}

SimpleForwardIterator SimpleForwardIterator::begin() const noexcept
{
	SimpleForwardIterator Result = *this;

	Result.fIndex = 0;

	return Result;	
}

SimpleForwardIterator SimpleForwardIterator::end() const noexcept
{
	SimpleForwardIterator Result = *this;

	Result.fIndex = fCollection->size() - 1;

	return Result;
}