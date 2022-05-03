#pragma once
/*���ļ�������������͸���������*/

/*��������������ʫ�ڱ�д*/
class Calculator {
public:
	void setLeftNum(int& leftNum);
	void setRightNum(int& rightNum);
	int getLeftNum();
	int getRightNum();
	static void setResult(const int index,const double result);

	virtual double calculate() = 0;//��Ҫ��д

	double* getResult() const;
private:
	int leftNum;
	int rightNum;
	static double results[4];//ÿ���������ͬά��������
};

/*����Լ�������������*/
/*�ӷ���*/
class AddCalculator :public Calculator{
public:
	virtual double calculate();
};
/*�˷���*/
class MultiplyCalculator :public Calculator {
public:
	virtual double calculate();
};

/*������*/
class DivisionCalculator :public Calculator {
public:
	virtual double calculate();
};

/*�����*/
class AllAnswer :public Calculator {
public:
	virtual double calculate();
};