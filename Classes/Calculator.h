#pragma once
/*���ļ�������������͸���������*/

/*��������������ʫ�ڱ�д*/
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

/*����Լ�������������*/