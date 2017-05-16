#include <string>
#include <iostream>

using namespace std;

#define MAX_MANAGER_COUNT 10
#define MAX_TECHNICIAN_COUNT 10

class employee{
private:
	static int staff_count;
	int individualEmpNo;
    string grade,name;
	float accumPay;
protected:
public:
	employee(){
		this->individualEmpNo=staff_count;
		staff_count++;
		this->grade="staff";
		this->accumPay=1000.0;
	}
	employee(string name,string gr,float ap){
		staff_count++;
        this->name = name;
		this->individualEmpNo = staff_count;
		this->grade=gr;
		this->accumPay=ap;
	}
	~employee(){
		/*cout<<this->individualEmpNo<<"     欢迎使用，再见"<<endl;*/
	}
    static void reset(){
        staff_count=0;
    }
	int get_individualEmpNo();
	string get_grade();
    string get_name();
	float get_accumPay();
	//void set_individualEmpNo(int no);
	void set_grade(string gr);
	void set_accumPay(float ap);
	void set_employee_info(string name,string gr,float ap);
	void dis_employee_info();
	void invalid_extends() { staff_count--; }
    virtual double pay();
    virtual void promote();
	friend istream & operator >> (istream& in,employee &e);
	friend ostream & operator <<(ostream& out, employee &e);
};

//revolution
class Manager :virtual public employee {
private:
	string level;//等级
	string department;//部门
	static int manager_count;//经理个数
	int valid;//判断是否有效
public:
	Manager(string name,string l,string d) :employee(name,"manager", 12000.0) {
//		if (manager_count >= MAX_MANAGER_COUNT && d!="Sales Department") {
//			cout << "创建失败，原因：经理超过最大人数"<< endl;
//			valid = 0;
//			invalid_extends();
//			return;
//		}
		valid = 1;
		level = l;
		department = d;
		manager_count++;
	}
	string get_level(){
		return level;
	}
	string get_department() {
		return department;
	}
    void set_manager_info(string name,string l,string d);
	void dis_manager_info();
    double pay();
    void promote();
};
class Technician :virtual public employee {
private:
	string field;//研究领域
	string level;//技术等级
	int work_hours;
	static int technician_count;//技术员个数
	int valid;//判断是否有效
public:
	Technician(string name,int wh,string f,string l) :employee(name,"technician", wh * 260) {
//		if (technician_count >= MAX_TECHNICIAN_COUNT) {
//			cout << "创建失败，原因：技术人员超过最大人数"<<endl;
//			valid = 0;
//			invalid_extends();
//			return;
//		}
		valid = 1;
		work_hours = wh;
		level = l;
		field = f;
		technician_count++;
	}
    void set_technician_info(string name,int wh,string f,string l);
	void dis_technician_info();
    double pay();
    void promote();
};
class Salesman :virtual public employee {
private:
	string products;//负责产品
	double sales;//销售额
	static int salesman_count;//销售员数量
public:
	Salesman(string name,double ap, string p, double s) :employee(name,"salesman", ap + 0.05*s) {
		sales = s;
		products = p;
		salesman_count++;
	}
    void set_salesman_info(string name,string p,double ap, double s);
	void dis_salesman_info();
    double pay();
    void promote();
	string get_products() {
		return products;
	}
	double get_sales(){
		return sales;
	}
};
class Salesmanager :public Manager, public Salesman {
private:
	int branch_num;
    int field_income;
public:
	Salesmanager(string name,string l,  string p, double field_income) :employee(name,"Salesmanager", 8000 + field_income*0.04), Manager(name,l, "Sales Department"), Salesman(name,8000, p, field_income * 4 / 5) {
        this->field_income = field_income;
    }
    void set_salesmanager_info(string name,string l,  string p, double field_income);
	void dis_salesmanager_info();
    double pay();
    void promote();
};
