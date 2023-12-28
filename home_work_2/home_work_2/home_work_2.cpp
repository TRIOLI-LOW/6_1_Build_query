
#include <iostream>
#include "sql_query_builder.h"
#include "vector"
#include <map>


int main()
{
       SqlSelectQueryBuilder query_builder;

       std::vector<std::string> vec = { "name", "phone"};
       std::map<std::string, std::string> kv = { {"id","42"}, {"name", "John"} };

       query_builder.AddColumn(vec);
       query_builder.AddFrom("students");
       query_builder.AddWhere(kv);

       query_builder.BuildQuery();
                       
}


