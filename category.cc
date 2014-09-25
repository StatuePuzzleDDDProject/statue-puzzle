#include <string>
#include <vector>
#include "ccc_win.h"
#include <iostream>
#include "category.h"

	Category::Category() {
		name = "";
		quantity = -1;
	}

	Category::Category(string name, int quantity) {
		this->name = name;
		this->quantity = quantity;
	}

	std::string Category::getName() const {
		return name;
	}

	int Category::getQuantity() const {
		return quantity;
	}

	void Category::setQuantity(int quantity) {
		this->quantity = quantity;
	}

	void Category::changeQuantity(int change) {
			this->quantity += change;
		}

//	void test() {
//		Category gold("Gold", 100);
//		Category crystal("Crystal", 50);
//		Category score("Score", 0);
//		vector<Category> categories;
//		categories.push_back(gold);
//		categories.push_back(crystal);
//		categories.push_back(score);
//		for(int unsigned i = 0; i < categories.size(); i++) {
//			cout << categories[i].getName() << endl;
//		}
//	}



