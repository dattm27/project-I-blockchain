
    if (current_person.mother_code != "0000000") {
        mother_generation = dfs2(current_person.mother_code, generation + 1);
    }

    //  Trả về thế hệ lớn nhất giữa bố và mẹ
    max_generation[current_code]++;
    return max(father_generation, mother_generation);
}