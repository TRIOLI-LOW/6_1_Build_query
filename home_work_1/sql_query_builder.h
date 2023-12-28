#pragma once
#include<vector>
#include <iostream>


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

	SqlSelectQueryBuilder& AddColumn(std::string column_) noexcept {
		if (sqlquery.column.empty()) {
			sqlquery.column = column_;
		}
		else {
			sqlquery.column = sqlquery.column + ", " + column_;
		}
		return *this;
	}
	SqlSelectQueryBuilder& AddFrom(std::string from_) {
		sqlquery.from = from_;
		return *this;
	}
	SqlSelectQueryBuilder& AddWhere(std::string id_where, std::string res_where) {
		if (sqlquery.where.empty()) {
			sqlquery.where = id_where + "=" + res_where;
		}
		else {
			sqlquery.where = sqlquery.where + " AND " + id_where + "=" + res_where;
		}
		return *this;
	}
	SQLquery BuildQuery() noexcept {
		if (!sqlquery.from.empty() && !sqlquery.where.empty()) {
			if (sqlquery.column.empty()) {
				sqlquery.select = " SELECT *FROM " + sqlquery.from + " WHERE " + sqlquery.where + ";";
				std::cout << sqlquery.select << std::endl;
			}
			else  {
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