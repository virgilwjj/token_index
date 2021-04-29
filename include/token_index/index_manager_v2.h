#pragma once

#include "token_index/types.h"

namespace ti
{
    class index_manager_v2
    {
    public:
        index_manager_v2();
        void push_col_file(const path_t &col_file_path);
        void push_doc_line(const line_t &doc_line);
        void print_col() const;
        void print_inverted_index() const;
        //void print_token_frequency();
        //void save_inverted_index(const path_t &path);
        //void load_inverted_index(const path_t &path);
        //void inverted_index_build_collection(); 
        frequency_t calc_frequency(const token_t &token) const;
        const index_info_vec_t retrieve(const token_t &token) const;
        const doc_id_set_t retrieve_union(const query_t &query) const;
        const index_info_vec_t retrieve_intersection(const query_t &query) const;
    private:
        index_manager_v2(const index_manager_v2 &other) = delete;
        index_manager_v2(index_manager_v2 &&other) = delete;
        index_manager_v2 operator=(const index_manager_v2 &other) = delete;
        index_manager_v2 operator=(index_manager_v2 &&other) = delete;
        col_t _col;
        inverted_index_v2_t _inverted_index;
    };
}