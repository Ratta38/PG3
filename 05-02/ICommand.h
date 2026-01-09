#pragma once

class ICommand {
public:
	virtual ~ICommand() = default;
	virtual void Exec() = 0;
};