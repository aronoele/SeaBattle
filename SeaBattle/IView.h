#pragma once

class IView
{
public:
	virtual ~IView() {}
	virtual void show() = 0;
};

