#pragma once
/*此文件用来声明基类和各个派生类*/

/*基类声明——王诗腾编写*/
class Calculator {
public:
	void setLeftNum(int& leftNum);
	void setRightNum(int& rightNum);
	virtual double calculate()=0;
	void setResult(const int index,const double result);
private:
	int leftNum;
	int rightNum;
	static double results[4];
};

/*大家自己的派生类声明*/