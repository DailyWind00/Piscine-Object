#pragma once

#include <string>
#include <vector>

using namespace std;

enum class Day
{
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};

struct Article
{
	string name;
	float  price;
	size_t quantity;
};

class Command
{
	protected:
		size_t			_id;
		Day				_date; 
		string			_client;
		vector<Article>	_articles;

	public:
		Command(
			size_t id,
			Day date,
			const string &client,
			const vector<Article> &articles
		) : _id(id),
			_date(date),
			_client(client),
			_articles(articles)
		{}
		virtual ~Command() {};

		virtual float get_total_price() const
		{
			float total_price = 0;

			for (const Article &article : _articles)
			{
				total_price += article.price * article.quantity;
			}

			return total_price;
		}
};