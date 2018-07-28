#include"public.h"
// 全局变量声明
 int mode = MODE0;
 int qdep = -1;
 int fltell = 0;
 int xxxnum = -1;
 int xxxdata = -1;
 
 //page
 int page14 = 1;			//用于删除部门的MODE15
 int page17 = 1;
 int page4 = 1;
 int page5 = 1;
 int page8 = 1;
 int page88 = 0;
 int worker::allmen=0;
 int worker::datapage = 0;
 int worker::highestmoney = 0;
 int worker::lowestmoney = 0;
 long long worker::allmoney=0;
 std::vector<std::string>worker::dep= std::vector<std::string>();
 std::vector<std::string>worker::post{"经理","技术员","销售员","销售经理"};
 std::map<std::string, int>worker::departmentmoney = std::map<std::string, int>();
 std::map<std::string, int>worker::departmentpeople = std::map<std::string, int>();
 std::map<std::string, int>worker::departmentallmoney = std::map<std::string, int>();
 std::map<std::string, int>worker::departmentlowestmoney = std::map<std::string, int>();
 std::map<std::string, int>worker::departmenthighestmoney = std::map<std::string, int>();
 std::map<std::string, int>worker::departmentsalesmanager = std::map<std::string, int>();
 std::vector<std::shared_ptr<worker>>worker::people = {};
 std::vector<std::shared_ptr<worker>>worker::deppeople = {};
 std::vector<std::string>worker::readfile{};
 std::vector<std::string>worker::data{};
 std::vector<std::shared_ptr<worker>>worker::FINDNAME{};
 std::vector<std::shared_ptr<worker>>worker::FINDID{};
 int worker::salesmangernum = 0;



 int main(int argc, char* argv[])
 {
	 renew(argv);
	 background(2);
	 mode = MODE4;
	 mouse(argv);
	 getch();
	 return 0;
 }