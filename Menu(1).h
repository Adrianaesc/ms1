/* ------------------------------------------------------
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.1
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/2  Preliminary release
2020/3/8  Corrected sample output and correct_output.txt
-----------------------------------------------------------*/
// Adriana Escalante
//107690190
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include<iostream>
#include <fstream>
namespace sdds {
	const int MAX_NO_OF_ITEMS=10;

	class Menu;
	class Menuitem {
		//fully private
		char* name;
		int name_length; // length of name+1

		Menuitem();
		Menuitem(char*);
		~Menuitem();
		void setMenuitem(const char*);
		bool isempty()const;
		void setSafe();
		std::ostream& displayName(std::ostream& os) const;
		Menuitem(const Menuitem&); // can no get copied
		Menuitem& operator=(const Menuitem&);// or assigned, must be enforced
		friend class Menu;
	};

	class Menu {
		char* title;
		int title_length;
		Menuitem arrMenuitems[MAX_NO_OF_ITEMS];
		int num_of_Menuitems;
		int indentation; //level 1= 4 spaces

	public:
		Menu();
		Menu(const char*, int=0); // if indentation is not passed set to 0
		~Menu();
		Menu(const Menu&); //copy constructor
		void setTitle(const char*);
		void safeEmptyState();
		Menu& operator=(const Menu&); // allows for assignment aswell
		void setMenuitems(const Menu&);
		operator bool()const; // allows for object to be uses as a bool value to rep if its valid
		bool isEmpty()const; //opposite to ^, so returns true if Menu is empty
		std::ostream& display(std::ostream& = std::cout) const;
		Menu& operator=(const char*);   //reset title of the menu
		void add(const char*);
		Menu& operator<<(const char*);
		int run()const;
		std::istream& getNum(int&, std::istream & = std::cin)const;
		operator int()const;
		friend class Menuitems;
	};

}
#endif