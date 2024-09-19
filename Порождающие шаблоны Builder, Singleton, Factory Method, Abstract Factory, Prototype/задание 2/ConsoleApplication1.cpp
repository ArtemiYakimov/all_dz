#include <cassert>
#include "sql_query_builder.h"

int main() {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    std::string expected_query = "SELECT name, phone FROM students WHERE id='42' AND name='John';";
    std::string actual_query = query_builder.BuildQuery();
    assert(actual_query == expected_query);

    std::map<std::string, std::string> where_conditions = {
        {"age", "18"},
        {"gender", "male"}
    };
    query_builder.AddWhere(where_conditions);
    expected_query = "SELECT name, phone FROM students WHERE id='42' AND name='John' AND age='18' AND gender='male';";
    actual_query = query_builder.BuildQuery();
    assert(actual_query == expected_query);

    std::vector<std::string> columns = { "id", "name", "phone", "email" };
    query_builder.AddColumns(columns);
    expected_query = "SELECT id, name, phone, email FROM students WHERE id='42' AND name='John' AND age='18' AND gender='male';";
    actual_query = query_builder.BuildQuery();
    assert(actual_query == expected_query);

    return 0;
}

