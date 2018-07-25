#include <iostream>
#include <fstream>
#include <string>

struct node {
	int value = 0;
	node* prev = nullptr;
	node* next = nullptr;
};

int main(int argc, char** argv) {
	node* cn = new node; //current node
	std::ifstream fcode("codice.txt");
	std::string code = "";
	std::string symbols = ",.+-<>[]";
	/**Convertion in a string that contains only the accepted symbols**/
	for (int i = 0; !fcode.eof(); ++i) {
		char fchar = fcode.get();
		int j = 0;
		for (; j < symbols.length() && fchar != symbols[j]; ++j)
			;
		if (fchar == symbols[j])
			code += fchar;
	}

	/**Execution of the code**/
	for (int i = 0; i < code.length(); ++i) { //i of the Code
		char to_exec = code[i];
		switch (to_exec) {
		case ',':
			char in;
			std::cin >> in;
			cn->value = (int)in;
			break;
		case '.':
			std::cout << (char)cn->value;
			break;
		case '>':
			if (cn->next == nullptr)
				cn->next = new node;
			cn->next->prev = cn;
			cn = cn->next;
			break;
		case '<':
			if (cn->prev == nullptr)
				cn->prev = new node;
			cn->prev->next = cn;
			cn = cn->prev;
			break;
		case '+':
			cn->value++;
			break;
		case '-':
			cn->value--;
			break;
		case ']':
			if (cn->value != 0) {
				int in_sospeso = 0; //Number of suspended parentheses
				do {
					i--;
					if (code[i] == ']')
						in_sospeso++;
					else if (code[i] == '[')
						if (in_sospeso != 0)
							in_sospeso--;
				} while (!(code[i] == '[' && in_sospeso == 0));
			}
			break;
		}
	}

	/**Deletes all the node**/
	node* cn_prev_copy = cn->prev;
	while (cn->next != nullptr) {
		cn = cn->next;
		delete cn->prev;
	}
	delete cn;
	if (cn_prev_copy != nullptr) {
		cn = cn_prev_copy;
		while (cn->prev != nullptr) {
			cn = cn->prev;
			delete cn->next;
		}
		delete cn;
	}

	for (;;);
	return 0;
}