#pragma once

#include "command.hpp"

class ThuesdayDiscountCommand : public Command
{
	public:
		ThuesdayDiscountCommand(
			size_t id,
			Day date,
			const string &client,
			const vector<Article> &articles
		) : Command(id, date, client, articles)
		{}

		float get_total_price() const override
		{
			float total_price = Command::get_total_price();

			if (_date == Day::Tuesday)
				total_price *= 0.90f; // -10%

			return total_price;
		}
};