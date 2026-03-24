/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 01:44:52 by aboumall          #+#    #+#             */
/*   Updated: 2026/03/24 16:38:11 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    std::string name;
    int age;
    float height;
};

class Serialize
{
    private:
        Serialize();
        ~Serialize();
        Serialize(const Serialize&);
        Serialize& operator=(const Serialize&);
        
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
