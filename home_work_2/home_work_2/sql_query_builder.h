#pragma once
#include<vector>
#include <iostream>
#include<map>
#include <vector>

struct SQLquery {
	std::string  column = "";
	std::string from = "";
	std::string where = "";
	std::string select = "";
	
};

class SqlSelectQueryBuilder {
private:
	SQLquery sqlquery;
public:

	SqlSelectQueryBuilder& AddColumn(std::vector<std::string>& columns) noexcept {
		std::reverse(columns.begin(), columns.end());
		while(!columns.empty()) {
			if (sqlquery.column.empty()) {
				sqlquery.column = columns.back();
				columns.pop_back();
			}
			else {
				sqlquery.column = sqlquery.column + ", " + columns.back();
				columns.pop_back();
			}
	}
		return *this;
	}
	SqlSelectQueryBuilder& AddFrom(std::string from_)noexcept {
		sqlquery.from = from_;
		return *this;
	}
	SqlSelectQueryBuilder& AddWhere(std::map<std::string, std::string>& mymap) noexcept {
		for (const auto& it : mymap) {
			const auto& key = it.first;
			const auto& value = it.second;
			if (sqlquery.where.empty()) {

				sqlquery.where = key + "=" + value;
			}
			else {
				sqlquery.where = sqlquery.where + " AND " + key + "=" + value;
			}
		}
		return *this;
	}
	SQLquery BuildQuery() noexcept {
		if (!sqlquery.from.empty() && !sqlquery.where.empty()) {
			if (sqlquery.column.empty()) {
				sqlquery.select = " SELECT *FROM " + sqlquery.from + " WHERE " + sqlquery.where + ";";
				std::cout << sqlquery.select << std::endl;
			}
			else {
				sqlquery.select = " SELECT " + sqlquery.column + " FROM " + sqlquery.from + " WHERE " + sqlquery.where + ";";
				std::cout << sqlquery.select << std::endl;
			}
		}
		else {
			std::cout << "Error : 'One parametrs is empty'" << std::endl;
		}
		return sqlquery;

	}
};