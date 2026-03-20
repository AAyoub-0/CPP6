/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 01:46:10 by aboumall          #+#    #+#             */
/*   Updated: 2026/03/20 02:27:06 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main()
{
    Data data;
    data.name = "John Doe";
    data.age = 30;
    data.height = 1.75f;

    std::cout << "Original Data:" << std::endl;
    std::cout << "Name: " << data.name << std::endl;
    std::cout << "Age: " << data.age << std::endl;
    std::cout << "Height: " << data.height << std::endl;

    uintptr_t raw = Serialize::serialize(&data);
    Data* deserializedData = Serialize::deserialize(raw);

    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "Name: " << deserializedData->name << std::endl;
    std::cout << "Age: " << deserializedData->age << std::endl;
    std::cout << "Height: " << deserializedData->height << std::endl;

    return 0;
}
