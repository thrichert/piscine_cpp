/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:38:14 by mikim             #+#    #+#             */
/*   Updated: 2018/01/12 20:33:48 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"

ScavTrap::ScavTrap(void)
{
	this->_hp = 100;
	this->_maxHp = 100;
	this->_ep = 50;
	this->_maxEp = 50;
	this->_lv = 1;
	this->_name = "Sargas";
	this->_meleeDmg = 20;
	this->_rangedDmg = 15;
	this->_armor = 3;
	system("afplay sound/summon.mp3 &");
	std::cout << _name << ": Gau'gurah!" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
}

ScavTrap::ScavTrap(std::string name)
{
	this->_hp = 100;
	this->_maxHp = 100;
	this->_ep = 50;
	this->_maxEp = 50;
	this->_lv = 1;
	this->_name = name;
	this->_meleeDmg = 20;
	this->_rangedDmg = 15;
	this->_armor = 3;
	system("afplay sound/summon.mp3 &");
	std::cout << _name << ": Gau'gurah!" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
}

ScavTrap::ScavTrap(ScavTrap const &rhs)
{
	*this = rhs;
	system("afplay sound/summon.mp3 &");
	std::cout << _name << ": Gau'gurah!" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
}

ScavTrap::~ScavTrap(void)
{
	system("afplay sound/death.mp3 &");
	std::cout << _name << ": Gee'hous!" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	_hp = rhs._hp;
	_maxHp = rhs._maxHp;
	_ep = rhs._ep;
	_maxEp = rhs._maxEp;
	_lv = rhs._lv;
	_name = rhs._name;
	_meleeDmg = rhs._meleeDmg;
	_rangedDmg = rhs._meleeDmg;
	_armor = rhs._armor;
	return *this;
}

void	ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "SC4V-TP " << _name << " attacks "
	<< target << " at melee, causing " << _meleeDmg
	<< " points of damage !" << std::endl;
}

void	ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "SC4V-TP " << _name << " attacks "
	<< target << " at ranged, causing " << _rangedDmg
	<< " points of damage !" << std::endl;
}

void	ScavTrap::challengeNewcomer(std::string const &target)
{
	void	(ScavTrap::*challenges[5])(std::string const &target) = {
		&ScavTrap::challenge1,
		&ScavTrap::challenge2,
		&ScavTrap::challenge3,
		&ScavTrap::challenge4,
		&ScavTrap::challenge5
	};

	system("afplay sound/challenge.mp3 &");
	std::cout << _name << ": What battle calls?" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::srand(std::time(NULL));
	int	r = (rand() % 50) / 10;
	(this->*challenges[r])(target);
}

void	ScavTrap::challenge1(std::string const &target)
{
	std::cout << "SYSTEM: New Challenge for " << target << "!" << std::endl
	<< "SYSTEM: Win 1 game using trackpad instead of mouse" << std::endl;
}
void	ScavTrap::challenge2(std::string const &target)
{
	std::cout << "SYSTEM: New Challenge for " << target << "!" << std::endl
	<< "SYSTEM: Win 1 game using inverted monitor" << std::endl;
}

void	ScavTrap::challenge3(std::string const &target)
{
	std::cout << "SYSTEM: New Challenge for " << target << "!" << std::endl
	<< "SYSTEM: Win 1 game without using keyboard" << std::endl;
}
void	ScavTrap::challenge4(std::string const &target)
{
	std::cout << "SYSTEM: New Challenge for " << target << "!" << std::endl
	<< "SYSTEM: Win 1 game using trackpad instead of mouse" << std::endl;
}
void	ScavTrap::challenge5(std::string const &target)
{
	std::cout << "SYSTEM: New Challenge for " << target << "!" << std::endl
	<< "SYSTEM: Win 1 game without repair" << std::endl;
}
