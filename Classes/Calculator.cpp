#include "Calculator.h"

/*�������ɺ���������ʫ�ڱ�д*/
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


/*����Լ��������ඨ��*/
/*�ӷ���*/
double AddCalculator::calculate()
{
	return getLeftNum() + getRightNum();
}
/*�˷���*/
double MultiplyCalculator::calculate()
{
	return getLeftNum() * getRightNum();
}
