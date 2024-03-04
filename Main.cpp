#include <iostream>

#include <array>   // статический массив
#include <vector> // динамический массив
#include <deque> // связнный список массивов с произвольным доступом

// колекции языка с++
// требования к вложенным типам и особенности работы 

class DemoGood {
public:
	DemoGood() {
		std::cout << this << " create by defult constructor \n";
	}
	DemoGood(int a, bool b) {
		std::cout << this << " create by parametr constructor \n";
	}
	DemoGood(const DemoGood& other) {
		std::cout << this << " create by copy constructor \n";
		std::cout << "from " << &other << " object\n";
	}

	~DemoGood() {
		std::cout << this << " destroyed\n";
	}

private:

};

class DemoBad {
public:
	DemoBad() = delete;
	DemoBad(const DemoBad& other) {
		std::cout << this << " create by copy constructor \n";
		std::cout << "from " << &other << " object\n";
	}

	~DemoBad() {
		std::cout << this << " destroyed\n";
	}

private:
	DemoBad(int a, bool b) {
		std::cout << this << " create by parametr constructor \n";
	}

};


int main() {
	setlocale(0, "");


	std::array<DemoGood, 10> arrST;
	// статический массив выделяет место под весь необходимый объем памяти и заполняет его объектами созданными 
	// конструктором по умолчанию  

	std::vector<DemoGood> arrDin;
	arrDin.reserve(10);
	// вектор не выделяет памяти, если ему не сказать, но может отдельной командой зарезервировать место 
	// не создавая объекты 

	std::deque<DemoGood> arrDeque(10);
	// деке как и вектору можно при создании сказать на какое кол-во элементов она создана 
	// При этом будет создано необходимое кол-во болванок с помощью конструктора по умолчани. 

	/*std::array< DemoBad, 10> arrST2{
		DemoBad{1, true},
		DemoBad{2, true},
		DemoBad{3, true},
		DemoBad{4, true},
		DemoBad{5, true},
		DemoBad{6, true},
		DemoBad{7, true},
		DemoBad{8, true},
		DemoBad{9, true},
		DemoBad{0, true},
	};*/
	// в случае отсутстваия конструктора по умолчанию для стандартных колекций, которым требуется сразу быть
	// заполненными какими-то объектами, остается вариант конструктора через список инициализации.
	// именно такой список мы отправили {}
	//std::vector<DemoBad> nArr(arrST2.begin(), arrST2.end());

	arrDin.push_back(DemoGood(0, true));
	arrDin.emplace_back(0, true);

	/*std::vector<DemoBad> nArr;
	nArr.push_back(DemoBad(0,true));
	nArr.emplace_back(0, true);*/
	// тк. конструктор с параметрами не доступен, методы категории emplace будут вызывать ошибки сборки
	// с указанием на невозможность обращения к данному конструктору 


	std::cout << "===========================================================\n\n";
	std::vector<DemoGood> example;
	for (int i = 0; i < 17; i++) {
		example.push_back(DemoGood(i, bool(i % 2)));
	}





	return 0;
}