/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:03:41 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/05 22:43:27 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

class Fixed
{

	private:

		int	_value;
		static const int _fractionalBits = 8;

	public:

		Fixed(void);
		Fixed(const Fixed & other);
		~Fixed(void);

		Fixed & operator=(const Fixed & other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};

#endif
