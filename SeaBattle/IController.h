#pragma once

class IController
{
	virtual ~IController() {}
	virtual void shut() = 0;
};
