/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:05:42 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/08 16:21:52 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ; 
}

Fixed::Fixed(Fixed const & other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_fractionalBits;
	return ;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_fractionalBits));
	return ;
}

float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << this->_fractionalBits);
}

int	Fixed::toInt(void) const
{
	return this->_value >> this->_fractionalBits;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
	return ;
}

Fixed & Fixed::operator=(Fixed const & other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

bool Fixed::operator>(Fixed const & other) const
{
	std::cout << "Greater than operator called" << std::endl;
	return (this->_value > other.getRawBits());
}

bool Fixed::operator<(Fixed const & other) const
{
	std::cout << "Less than operator called" << std::endl;
	return (this->_value < other.getRawBits());
}

bool Fixed::operator>=(Fixed const & other) const
{
	std::cout << "Greater than or equal to operator called" << std::endl;
	return (this->_value >= other.getRawBits());
}

bool Fixed::operator<=(Fixed const & other) const
{
	std::cout << "Less than or equal to operator called" << std::endl;
	return (this->_value <= other.getRawBits());
}

bool Fixed::operator==(Fixed const & other) const
{
	std::cout << "Equal to operator called" << std::endl;
	return (this->_value == other.getRawBits());
}

bool Fixed::operator!=(Fixed const & other) const
{
	std::cout << "Not equal to operator called" << std::endl;
	return (this->_value != other.getRawBits());
}

Fixed & Fixed::operator+(Fixed const & other)
{
	std::cout << "Addition operator called" << std::endl;
	this->_value += other.getRawBits();
	return *this;
}

Fixed & Fixed::operator-(Fixed const & other)
{
	std::cout << "Subtraction operator called" << std::endl;
	this->_value -= other.getRawBits();
	return *this;
}

Fixed & Fixed::operator*(Fixed const & other)
{
	std::cout << "Multiplication operator called" << std::endl;
	this->_value = (this->toFloat() * other.toFloat()) * (1 << this->_fractionalBits);
	return *this;
}

Fixed & Fixed::operator/(Fixed const & other)
{
	std::cout << "Division operator called" << std::endl;
	this->_value = (this->toFloat() / other.toFloat()) * (1 << this->_fractionalBits);
	return *this;
}

Fixed & Fixed::operator++(void)
{
	std::cout << "Prefix increment operator called" << std::endl;
	this->_value++;
	return *this;
}

Fixed & Fixed::operator--(void)
{
	std::cout << "Prefix decrement operator called" << std::endl;
	this->_value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	std::cout << "Postfix increment operator called" << std::endl;
	Fixed tmp(*this);
	this->_value++;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	std::cout << "Postfix decrement operator called" << std::endl;
	Fixed tmp(*this);
	this->_value--;
	return tmp;
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return a;
	return b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return a;
	return b;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return a;
	return b;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return a;
	return b;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

std::ostream & operator<<(std::ostream & o, Fixed const & fixedPoint)
{
	o << fixedPoint.toFloat();
	return o;
}
