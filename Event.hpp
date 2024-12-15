#pragma once

#include <string>

#include "TimeFormat.hpp"
#include "EventParams.hpp"

class Event
{
	TimeFormat m_time;
	EventID m_id;
	std::string m_name;
	int m_table;
public:
	void Load(const EventParams& pParams)
	{
		m_time = pParams.GetTime();
		m_id = pParams.GetID();
		m_name = pParams.GetName();
		if (pParams.GetTable() != 0) {
			m_table = pParams.GetTable();
		}
	}
};
