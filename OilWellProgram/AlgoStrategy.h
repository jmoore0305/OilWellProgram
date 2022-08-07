#pragma once


class AlgoStrategy
{
public:
	virtual double execute();
	virtual void sendData(double, double);
};