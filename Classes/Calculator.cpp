#include "Calculator.h"

/*基类若干函数——王诗腾编写*/
double Calculator::results[4] = { 0,0,0,0 };
void Calculator::setLeftNum(int& leftNum)
{
	this->leftNum = leftNum;
}

void Calculator::setRightNum(int& rightNum)
{
	this->rightNum = rightNum;
}

int Calculator::getLeftNum()
{
	return leftNum;
}

int Calculator::getRightNum()
{
	return rightNum;
}

void Calculator::setResult(const int index, const double result)
{
	results[index] = result;
}


/*大家自己的派生类定义*/
/*加法类*/
double AddCalculator::calculate()
{
	return getLeftNum() + getRightNum();
}
/*乘法类*/
double MultiplyCalculator::calculate()
{
	return getLeftNum() * getRightNum();
}
