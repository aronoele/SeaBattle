#pragma once

class IModel
{
	virtual ~IModel() {}
	virtual void changeState() = 0;
};
