#include "Complex.h"
#include <fstream>
#include <vector>
#include <string>

int main() {

	int swtch = 2; // 1 - 1st part of task, 2 - 2nd part of task

	switch (swtch) {
	case 1: { ///// 1st part of task
		Complex a;
		Complex b;
		Complex c;

		double a_r, a_i, b_r, b_i; //Input
		double r, i; //Output
		char oper; //Operator character

		cout << "Input real and imagine parts of A" << endl;
		cin >> a_r;
		cin >> a_i;
		a.set_complex(a_r, a_i);

		cout << "Choost the operation: + - * /" << endl;
		cin >> oper;

		cout << "Input real and imagine parts of B" << endl;
		cin >> b_r;
		cin >> b_i;
		b.set_complex(b_r, b_i);

		cout << endl;


		switch (oper) {
		case '+': {
			r = a.get_re_complex() + b.get_re_complex();
			i = a.get_im_complex() + b.get_im_complex();
			break;
		}
		case '-': {
			r = a.get_re_complex() - b.get_re_complex();
			i = a.get_im_complex() - b.get_im_complex();
			break;
		}
		case '*': {
			r = a.get_re_complex() * b.get_re_complex() - a.get_im_complex() * b.get_im_complex();
			i = a.get_re_complex() * b.get_im_complex() + b.get_re_complex() * a.get_im_complex();
			break;
		}
		case '/': {
			if (b_r * b_r + b_i * b_i == 0) {
				cout << "Cannot to divide";
			}
			else {
				r = (a.get_re_complex() * b.get_re_complex() + a.get_im_complex() * b.get_im_complex()) / (b.get_re_complex() * b.get_re_complex() + b.get_im_complex() * b.get_im_complex());
				i = (b.get_re_complex() * a.get_im_complex() - a.get_re_complex() * b.get_im_complex()) / (b.get_re_complex() * b.get_re_complex() + b.get_im_complex() * b.get_im_complex());
			}
			break;
		}
		default: {
			cout << "Something went wrong";
			break;
		}
		}

		c.set_complex(r, i);
		c.output_complex();

		break;
	}
	case 2: { ///// 2nd part of task
		int n;
		bool flag = true;
		string s;
		string path = "";
		ifstream file("C:/Users/Dmitriy/source/repos/ConsoleApplication2/ConsoleApplication2/complex.txt");

		vector <Complex> p;


		while (getline(file, s)) {
			Complex a;
			int re;
			int im;

			if (flag) {
				//n = stoi(s);
				flag = false;
			}

			bool re_im = true; // true - before + or -, false - after + or -
			bool pm = false; // Sign of imagine part: + is true, - is false
			string real = ""; // Real part in string
			string imagine = ""; //Imagine part in string

			for (int i = 0; i < s.length(); i++) {





			}
			//cout << real << endl << imagine << endl;
			//re = stoi(real);
			//im = stoi(imagine);
			//if (!pm) im = -im;

			//a.set_complex(re, im);
			//p.push_back(a);

		}

		file.close();

		for (int i = 0; i < p.size(); i++) {
			p[i].output_complex();
			cout << endl;
		}

		break;
	}
	}

}



