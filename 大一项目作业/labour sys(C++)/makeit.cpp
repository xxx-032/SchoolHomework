#include"public.h"

//用于静态成员各种更新

void renew(char* argv[]) {
	page14 = 1;			//用于删除部门的MODE15
	page17 = 1;
	page4 = 1;
	page5 = 1;
	page8 = 1;
	page88 = 0;
	worker::allmen = 0;
	worker::datapage = 0;
	worker::highestmoney = 0;
	worker::lowestmoney = 0;
	worker::allmoney = 0;
	std::vector<std::string>().swap(worker::dep);
	std::map<std::string, int>().swap(worker::departmentmoney);
	std::map<std::string, int>().swap(worker::departmentpeople);
	std::map<std::string, int>().swap(worker::departmentallmoney);
	std::map<std::string, int>().swap(worker::departmentlowestmoney);
	std::map<std::string, int>().swap(worker::departmenthighestmoney);
	std::map<std::string, int>().swap(worker::departmentsalesmanager);
	std::vector<std::shared_ptr<worker>>().swap(worker::people);
	std::vector<std::shared_ptr<worker>>().swap(worker::deppeople);
	std::vector<std::shared_ptr<worker>>().swap(worker::FINDNAME);
	std::vector<std::shared_ptr<worker>>().swap(worker::FINDID);
	std::vector<std::string>().swap(worker::readfile);
	std::vector<std::string>().swap(worker::data);

	std::string f;
	for (int i = 0; i != strlen(argv[0]) - 15; i++)
		f += argv[0][i];
	getFiles(f, worker::readfile);
	for (auto &a : worker::readfile) {
		auto b = a.end() - 4;
		std::string c{};
		for (auto d=a.end()-10; d != b; d++)
			c += *d;
		worker::data.push_back(c);
	}
	renewdepartment();

}


void openfile(int i) {
	std::ifstream in(worker::readfile[i].c_str());
	std::string pos;
	long id=0;
	int flen = 0,len=0;
	std::string name;
	std::string sex;
	std::vector<std::shared_ptr<worker>>hhh;
	std::string department;
	double curwages=0;
	int year=0, month = 0, day = 0,worktime = 0;
	double salesmoney = 0;
	int fl = 0;
	std::shared_ptr<worker>p = nullptr;
	worker *x = nullptr;
	if(!in) {
		//没有数据处理时
	}
	else {
		in.seekg(0, std::ios::end);
		flen = in.tellg();
		in.seekg(0, std::ios::beg);
		if (flen == in.tellg()) {
		}
		else {
			while (flen - 1 != in.tellg()) {
				//len = in.tellg();
				in >> pos;
				if (pos == "经理")
					fl = MANAGER;
				if (pos == "销售经理")
					fl = SALESMANAGER;
				if (pos == "技术员")
					fl = TECHNICIAN;
				if (pos == "销售员")
					fl = SALESMAN;
				switch (fl) {
				case MANAGER:
					in >> id >> name >> sex >> department >> day >> month >> year;
					p = std::make_shared<manager>(id, name, sex, department, day, month, year);
					worker::people.push_back(p);
					break;
				case SALESMANAGER:
					in >> id >> name >> sex >> department >> day >> month >> year;
					p = std::make_shared<salesmanager>(id, name, sex, department, day, month, year);
					worker::departmentsalesmanager[department]++;
					hhh.push_back(p);
					worker::people.push_back(p);
					break;
				case TECHNICIAN:
					in >> id >> name >> sex >> department >> day >> month >> year >> worktime;
					p = std::make_shared<techman>(id, name, sex, department, day, month, year, worktime);
					worker::people.push_back(p);
					break;
				case SALESMAN:
					in >> id >> name >> sex >> department >> day >> month >> year >> salesmoney;
					p = std::make_shared<salesman>(id, name, sex, department, day, month, year, salesmoney);
					std::dynamic_pointer_cast<salesman>(p)->setcurwages();
					worker::people.push_back(p);
					break;
				}
				if (!in.good())
					break;
			}
			for (auto x : hhh) {
				x->renewsalesmanager();
			}
		}
	}
	in.close();
}


void savefile(int i) {
	std::ofstream out(worker::readfile[i].c_str());
	for (auto &x : worker::people) {
		x->save(out);
	}
	out.close();
}

