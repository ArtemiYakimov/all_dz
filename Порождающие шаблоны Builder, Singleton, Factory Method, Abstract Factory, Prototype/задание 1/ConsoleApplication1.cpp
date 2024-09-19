#include "sql_query_builder.h"
#include <cassert> // Add this line

int main() {
	SqlSelectQueryBuilder query_builder;
	query_builder.AddColumn("name").AddColumn("phone");
	query_builder.AddFrom("students");
	query_builder.AddWhere("id", "42").AddWhere("name", "John");

	std::string expected_query = "SELECT name, phone FROM students WHERE id='42' AND name='John';";
	std::string actual_query = query_builder.BuildQuery();
	assert(actual_query == expected_query);

	return 0;
}
