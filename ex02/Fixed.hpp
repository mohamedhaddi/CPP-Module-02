/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:03:41 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/07 17:06:50 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{

	private:

		int	_value;
		static const int _fractionalBits = 8;

	public:

		Fixed(void);
		Fixed(const Fixed & other);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed & min(Fixed & a, Fixed & b);
		static Fixed const & min(Fixed const & a, Fixed const & b);
		static Fixed & max(Fixed & a, Fixed & b);
		static Fixed const & max(Fixed const & a, Fixed const & b);

		Fixed & operator=(const Fixed & other);
		Fixed & operator+(const Fixed & other);
		Fixed & operator-(const Fixed & other);
		Fixed & operator*(const Fixed & other);
		Fixed & operator/(const Fixed & other);
		Fixed & operator++(void);
		Fixed & operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);
		bool	operator>(const Fixed & other) const;
		bool	operator<(const Fixed & other) const;
		bool	operator>=(const Fixed & other) const;
		bool	operator<=(const Fixed & other) const;
		bool	operator==(const Fixed & other) const;
		bool	operator!=(const Fixed & other) const;

};

std::ostream & operator<<(std::ostream & o, Fixed const & fixedPoint);

#endif
