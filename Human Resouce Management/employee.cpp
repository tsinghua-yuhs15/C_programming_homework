
#include "employee.h"
using namespace std;

int employee::get_individualEmpNo(){
	return this->individualEmpNo;
}
string employee::get_name(){
    return this->name;
}
string employee::get_grade(){
	return this->grade;
}
float employee::get_accumPay(){
	return this->accumPay;
}
/*
void employee::set_individualEmpNo(string no){
	this->individualEmpNo=no;
}*/
void employee::set_grade(string gr){
	this->grade=gr;
}
void employee::set_accumPay(float ap){
	this->accumPay=ap;
}
void employee::set_employee_info(string name,string gr,float ap){
    this->name=name;
	this->staff_count++;
	this->individualEmpNo = staff_count;
	this->grade=gr;
	this->accumPay=ap;
}
void employee::dis_employee_info(){
	cout<<individualEmpNo<<" "<<name<<" "<<grade<<" "<<accumPay<<endl;
}
double employee::pay(){
    return accumPay;//此处如此定义，否则若直接返回accumpay则无法区分pay（）定义为是否virtual的区别
}
void employee::promote(){
    accumPay+=1000.0;
}

istream & operator >> (istream & in,employee &e)
{
	// TODO: 在此处插入 return 语句
	in >>e. individualEmpNo;
	in >> e.grade;
	in >> e.accumPay;
	return in;
}

ostream & operator<<(ostream & out, employee &e)
{
	// TODO: 在此处插入 return 语句
	out << e.individualEmpNo << "		" << e.grade << "		" << e.accumPay << endl;
	return out;
}
void Manager::set_manager_info(string name,string l,string d){
    set_employee_info(name,"Manager",12000);
    level = l;
    department = d;
}
void Manager::dis_manager_info()
{
    if (valid == 0) {
        cout << "无效的MANAGER";
        return;
    }
    this->dis_employee_info();
    cout << "level:" << level << "       " << "department:" <<  department<<endl;
}
double Manager::pay(){
    return this->get_accumPay();//固定工资
}
void Manager::promote(){
    this->set_accumPay(this->get_accumPay()*1.2);
}
void Technician::set_technician_info(string name,int wh,string f,string l){
    set_employee_info(name,"Technician",wh*260);
    work_hours = wh;
    level = l;
    field = f;
}
void Technician::dis_technician_info()
{
	if (valid == 0) {
		cout << "无效的TECHNICIAN";
		return;
	}
	this->dis_employee_info();
	cout << "level:" << level << "       " << "field:" << field << "       " << "workhour:"<<work_hours<<"hours"<<endl;
}
double Technician::pay(){
    return (this->work_hours)*260;
}
void Technician::promote(){
    work_hours+=30;
}
void Salesman::set_salesman_info(string name,string p,double ap, double s){
    set_employee_info(name,"salesman", ap + 0.05*s);
    sales = s;
    products = p;
}
void Salesman::dis_salesman_info() {
	this->dis_employee_info();
	cout << "sales:" << sales << "       " << "products:" << products << endl;
}
double Salesman::pay(){
    return this->get_accumPay();
}
void Salesman::promote(){
    this->set_accumPay(this->get_accumPay()+sales*0.01);
}
void Salesmanager::set_salesmanager_info(string name,string l,  string p, double field_income){
    set_salesman_info(name,p,0,0);
    set_manager_info(name, l, "Sales Department");
    set_employee_info(name, "Salesmanager", 8000 + field_income*0.04);
    this->field_income=field_income;
    
}
void Salesmanager::dis_salesmanager_info()
{
	this->dis_employee_info();
	cout << "level:" << this->get_level() << "       " << "department:" << this->get_department() << endl;
	cout << "sales:" << this->get_sales() << "       " << "products:" << this->get_products() << endl;
}
double Salesmanager::pay(){
    return 8000+field_income*0.04;
}
void Salesmanager::promote(){
    field_income*=1.005;
}
