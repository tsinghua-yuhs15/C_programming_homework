
#include "interact.hpp"
#include <cstring>
using namespace std;
void test_cin_cout(employee &e) {
	cin >> e;
	cout << e;
}

int employee::staff_count=0;
int Manager::manager_count = 0;
int Technician::technician_count = 0;
int Salesman::salesman_count = 0;

int main(void){
    welcome_logo_paint();
    welcome_string_print();
   
    main_action();

}
