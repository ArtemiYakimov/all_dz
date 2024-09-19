#include <string>
#include <vector>
#include <sstream>

class SqlSelectQueryBuilder {
public:
    SqlSelectQueryBuilder& AddColumn(const std::string& column) {
        columns_.push_back(column);
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& table) {
        table_ = table;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) {
        where_.emplace_back(column, value);
        return *this;
    }

    const std::string& BuildQuery() const {
        std::ostringstream query;
        query << "SELECT ";
        if (columns_.empty()) {
            query << "*";
        }
        else {
            query << columns_[0];
            for (size_t i = 1; i < columns_.size(); ++i) {
                query << ", " << columns_[i];
            }
        }
        query << " FROM " << table_;
        if (!where_.empty()) {
            query << " WHERE " << where_[0].first << "='" << where_[0].second << "'";
            for (size_t i = 1; i < where_.size(); ++i) {
                query << " AND " << where_[i].first << "='" << where_[i].second << "'";
            }
        }
        query << ";";
        return query_str_ = query.str();
    }

private:
    std::vector<std::string> columns_;
    std::string table_;
    std::vector<std::pair<std::string, std::string>> where_;
    mutable std::string query_str_;
};
