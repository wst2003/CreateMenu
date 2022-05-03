#pragma once
/*此文件用来声明基类和各个派生类*/

/*基类声明——王诗腾编写*/
class Calculator {
public:
	void setLeftNum(int& leftNum);
	void setRightNum(int& rightNum);
	int getLeftNum();
	int getRightNum();
	static void setResult(const int index,const double result);

	virtual double calculate() = 0;//需要重写

	double* getResult() const;
private:
	int leftNum;
	int rightNum;
	static double results[4];//每个计算机共同维护此数组
};

/*大家自己的派生类声明*/
/*加法类*/
class AddCalculator :public Calculator{
public:
	virtual double calculate();
};
/*乘法类*/
class MultiplyCalculator :public Calculator {
public:
	virtual double calculate();
};

/*除法类*/
class DivisionCalculator :public Calculator {
public:
	virtual double calculate();
};

/*结果类*/
class AllAnswer :public Calculator {
public:
	virtual double calculate();
};