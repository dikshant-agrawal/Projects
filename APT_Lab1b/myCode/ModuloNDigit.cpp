/**
 * @file ModuloNDigit.cpp
 * @brief Implementation of the single-digit modulo-N counter.
 */

#include "ModuloNDigit.h"

ModuloNDigit::ModuloNDigit()
    : maxCount(10), currentCount(0)
{
}

ModuloNDigit::ModuloNDigit(int n)
    : maxCount(n), currentCount(0)
{
}

ModuloNDigit::~ModuloNDigit()
{
}

ModuloNDigit& ModuloNDigit::operator++()
{
    currentCount = (currentCount + 1) % maxCount;
    return *this;}

ModuloNDigit ModuloNDigit::operator++(int n)
{
    ModuloNDigit temp = *this;  // store old value
    ++(*this);                  // call prefix increment
    return temp;
}

int ModuloNDigit::getValue() const
{
    return currentCount;
}

void ModuloNDigit::resetCounter()
{
    currentCount = 0;
}
