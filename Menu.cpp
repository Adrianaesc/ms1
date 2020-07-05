/* ------------------------------------------------------
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdlib>
#include <cctype>
#include <string>
#include<string.h>
#include <iomanip>
#include "Menu.h"
using namespace std;
namespace sdds {
	//Menuitems implications --------------------------------------
	Menuitem::Menuitem() {
		name = nullptr;
		name_length = 0;
	}
	Menuitem::Menuitem(char *t_name) {
		name = nullptr;
		name_length = 0;
		setMenuitem(t_name);
	}
	void Menuitem::setMenuitem(const char* t_name) {
		if (t_name != nullptr) {
			if(!isempty())
			delete[] name;
			name = nullptr;
			name_length = strlen(t_name) + 1;
			name = new char[name_length];
			strcpy(name, t_name);
		}
		else {
			name_length = 0;
			name = nullptr;
		}
	}

	bool Menuitem::isempty() const{
		//true when this is empty
		//false when valid
		bool flag=true;
		if (name != nullptr) {
			flag = false;
		}
		return flag;
	}
	void Menuitem::setSafe() {
		if (name != nullptr&&!isempty())
			delete[] name;
		name = nullptr;
		name_length = 0;
	}
	std::ostream& Menuitem::displayName(std::ostream& os) const {
		//if (!isempty()) {
			os << name;
		//}
		return os;
	}
	Menuitem::Menuitem(const Menuitem&) {
		//nothing happens when copied
	}
	Menuitem& Menuitem::operator=(const Menuitem& other) {
		//*this = other;
		return *this;
	}
	Menuitem::~Menuitem() {
		delete[] name;
		name = nullptr;
	
	}

	//Menu implications --------------------------------------
	//Menu implications --------------------------------------


	Menu::Menu() {
	//	//construction
		title = nullptr;
		num_of_Menuitems = 0;
		indentation = 0;
		for (int i = 0; i < num_of_Menuitems; i++) {
			arrMenuitems[i] = nullptr;
		}
	}
	Menu::Menu(const char* t_title, int indent) {
		//construction

		safeEmptyState();
		if (t_title != nullptr) {
			num_of_Menuitems = 0;
			indentation = indent;
			//deep copy of title
			//delete[]title;
			//title = nullptr;
			setTitle(t_title); //title_lenght will also be set here
			for (int j = 0; j < MAX_NO_OF_ITEMS; j++) {
				arrMenuitems[j] = nullptr;
			}
		}
		else {
			safeEmptyState();
		}
	}
	Menu::Menu(const Menu& other) {/////////////////////////////////////
		//copy
		//check to see if this and other is the same
			//if (title!=other.title) {
				//safeEmptyState();
				title = nullptr;
				num_of_Menuitems = 0;
				indentation = 0;
				title_length = 0;
				//delete[] title;
				//title = nullptr;
				for (int i = 0; i < num_of_Menuitems; i++) {
					arrMenuitems[i] = nullptr;
				}
				num_of_Menuitems = other.num_of_Menuitems;
				indentation = other.indentation;
				setTitle(other.title);
				setMenuitems(other);

			//}
			//else{
				//nothing happens}
			//}
	}
	void Menu::setTitle(const char* t_title) {
		//if(title!=nullptr)
		delete[] title;
		title = nullptr;
		title_length = 0;
			title_length = strlen(t_title) + 1;
			title = new char[title_length];
			strcpy(title, t_title);
		
		//come back and use to reset title
	}
	void Menu::safeEmptyState() {
		//if ( title !=nullptr) {
		//	delete[] title;
		//}
		title = nullptr;
		num_of_Menuitems = 0;
		indentation = 0;
		title_length = 0;
		for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
			arrMenuitems[i] = nullptr;
		}
	}

	Menu& Menu::operator=(const Menu& other) {
		//assignment
		if (this != &other) {
			if (other.title != nullptr) {
				//*title = *other.title;
				//if (!this->isEmpty()&&title!=nullptr) {
				//	delete[] title;
					//title = nullptr;
				//}
				//*title = '\0';
				num_of_Menuitems = other.num_of_Menuitems;
				indentation = other.indentation;
				if (*title != '\0' || title != nullptr) {
					setTitle(other.title);
				}
				if (num_of_Menuitems > 0) {
					for (int i = 0; i < num_of_Menuitems; i++)
						//arrMenuitems[i].setSafe();/////////
					setMenuitems(other);
				}
			}
			else {
				delete[] title;
				safeEmptyState();
			}
		}
		return *this;
	}

	void Menu::setMenuitems(const Menu& other) {
		for (int j = 0; j < num_of_Menuitems; j++) {
			arrMenuitems[j].name_length = other.arrMenuitems[j].name_length;
				delete[] arrMenuitems[j].name;
				arrMenuitems[j].name = nullptr;

			arrMenuitems[j].name = new char[*other.arrMenuitems[j].name];
			if(arrMenuitems[j].name!=nullptr)
				strcpy(arrMenuitems[j].name, other.arrMenuitems[j].name);
	
		}
	}
	Menu::operator bool()const {
		//bool cast overload
		bool flag = true;
		if (isEmpty()) {
			flag = false;
		}
		return flag;
	}
	bool Menu::isEmpty() const{
		//isEmpty
		bool flag = true;
		if (title != nullptr&&num_of_Menuitems!=0&&title_length!=0) {
			flag = false;
		}
		return flag;
	}
	std::ostream& Menu::display(std::ostream& os) const {
		//display function
		if (title!=nullptr) {
			if (indentation > 0) {

				os << setfill(' ') << setw((indentation*4) + title_length-1);
			}
			os << title << endl;

			if (num_of_Menuitems == 0) {
				os << "No Items to display!" << endl;
			}
			else {

				for (int i = 0; i < num_of_Menuitems; i++) {
					if (indentation > 0) {
						//os << setfill(' ') << setw((indentation * 4)+ arrMenuitems[i].name_length); // +arrMenuitems[i].name_length - 1);
						for (int j = 0; j < (indentation * 4); j++)
							os << ' ';
						os << i + 1 << "- ";
						arrMenuitems[i].displayName(os);
					}
					else {
						os << i + 1 << "- ";
						//menuitem display
						arrMenuitems[i].displayName(os);
						//os << "> ";
					}
					os << endl;
				}
				os << setfill(' ') << setw((indentation * 4)+2);
				os << "> ";
			}

		}
		else {
			os << "Invalid Menu!" << endl;
		}
		return os;

	}

	Menu& Menu::operator=(const char* new_title) {
		//assigned to a const c string
		if (*new_title != '\0') {
			delete[] title;
			title = nullptr;
			setTitle(new_title);
		}
		else {
			delete[] title;
			safeEmptyState();
		}
		//cout << new_title << endl;
		return *this;
	}

	void Menu::add(const char* menuitem) {
		//add function
		if (menuitem == nullptr) {
			delete[] title;

			safeEmptyState();
		}
		else {
			int index;
			for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
				if (arrMenuitems[i].isempty()) {
					index = i;
					break;
				}
			}
			arrMenuitems[index].setMenuitem(menuitem);
			num_of_Menuitems++;
		}
	}

	Menu& Menu::operator<<(const char* menuitem) {
		if (menuitem == nullptr) {
			delete[] title;

			safeEmptyState();
		}
		add(menuitem);
		return *this;
	}
	int Menu::run()const {
		//string s_num;
		int num=0;
		int& p_num=num;
		getNum(p_num);
		return num;
	}
	std::istream& Menu::getNum(int& p_num, std::istream & is)const {
		//temp number
		int t_num;
		bool valid = false;
		this->display();
		if (!isEmpty()) {
			if (num_of_Menuitems > 0) {
				while (valid == false) {
					if (!(is >> t_num)) {
						//cout << endl;
						cout << "Invalid Integer, try again: ";
					}
					else if (t_num <= 0 || t_num > num_of_Menuitems) {
						cout << "Invalid selection, try again: ";
					}
					else {
						valid = true;
						p_num = t_num;
						break; 
					}
					is.clear();
					is.ignore(1000, '\n');
				}
				is.clear();
				is.ignore(1000, '\n');
			}
		} 


		return is;
	}

	

	Menu::operator int()const {
		int c = run();
		return c;
	}

	Menu::~Menu() {
		delete[] title;
		title = nullptr;
		for (int i = 0; i < num_of_Menuitems; i++) {
			arrMenuitems[i].~Menuitem();
	//		delete[] arrMenuitems[i];

		}

	}
}