#pragma once

#include "command.hpp"

class PackageReductionDiscountCommand : public Command
{
	public:
		PackageReductionDiscountCommand(
			size_t id,
			Day date,
			const string &client,
			const vector<Article> &articles
		) : Command(id, date, client, articles)
		{}

		float get_total_price() const override
		{
			float total_price = Command::get_total_price();

			if (total_price > 150)
				total_price -= 10;

			return total_price;
		}
};