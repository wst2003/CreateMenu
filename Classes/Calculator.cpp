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

void Calculator::setResult(const int index, const double result)
{
	results[index] = result;
}

/*����Լ��������ඨ��*/
