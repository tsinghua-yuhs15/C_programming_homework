//
//  interact.hpp
//  Human Resouce Management
//
//  Created by 于海粟 on 2017/4/24.
//  Copyright © 2017年 于海粟. All rights reserved.
//

#ifndef interact_hpp
#define interact_hpp

#include "welcome_logo.hpp"
#include <cstdlib>
#include <fstream>
#include <map>
#include <sstream>


//使用stlmap中转内存中的employee信息

void main_action();
void init_file();
void load_file();
void save_file();
void change_file();
string insert_employee();
string correct_employee();
map<int,string>::iterator search_employee();


#endif /* interact_hpp */
