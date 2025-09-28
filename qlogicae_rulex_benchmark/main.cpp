#include "pch.hpp"

#include "main.hpp"

void bubble_sort(std::vector<int> data)
{
    bool is_swapped = true;
    size_t index, size = data.size();
    while (is_swapped)
    {
        is_swapped = false;
        for (index = 1; index < size; ++index)
        {
            if (data[index - 1] > data[index])
            {
                std::swap(data[index - 1], data[index]);
                is_swapped = true;
            }
        }
        --size;
    }
}

void selection_sort(std::vector<int> data)
{
    size_t index_a, index_b, minimum_index, size = data.size();
    for (index_a = 0; index_a < size; ++index_a)
    {
        minimum_index = index_a;
        for (index_b = index_a + 1; index_b < size; ++index_b)
        {
            if (data[index_b] < data[minimum_index])
            {
                minimum_index = index_b;
            }
        }
        std::swap(data[index_a], data[minimum_index]);
    }
}

int main(int argc, char** argv)
{
    QLogicaePlotica::RuntimePerformanceBenchmarker& benchmarker =
        QLogicaePlotica::RuntimePerformanceBenchmarker::get_instance();

    benchmarker.execute(
        {
            .title = "Sorting Algorithms",
            .gnuplot_type = QLogicaePlotica::BenchmarkerGraph::LINEPLOT,
            .suspects =
            {
                {
                    .title = "Bubble Sort",
                    .on_setup = [](QLogicaePlotica::BenchmarkerResultData& data)
                    {
                        std::vector<int> items;
                        size_t index, size = data.get_input_size();
                        for (index = 0; index < size; ++index)
                        {
                            items.push_back(
                                QLogicaeCore::GENERATOR.random_int(
                                    1,
                                    static_cast<int>(size)
                                )
                            );
                        }
                        data.set_payload(items);
                    },
                    .on_execution = [](QLogicaePlotica::BenchmarkerResultData& data)
                    {
                        data.set_start_execution_time();
                        bubble_sort(data.get_payload<std::vector<int>>());
                        data.set_end_execution_time();
                    }
                },
                {
                    .title = "Selection Sort",
                    .on_setup = [](QLogicaePlotica::BenchmarkerResultData& data)
                    {
                        std::vector<int> items;
                        size_t index, size = data.get_input_size();
                        for (index = 0; index < size; ++index)
                        {
                            items.push_back(
                                QLogicaeCore::GENERATOR.random_int(
                                    1,
                                    static_cast<int>(size)
                                )
                            );
                        }
                        data.set_payload(items);
                    },
                    .on_execution = [](QLogicaePlotica::BenchmarkerResultData& data)
                    {
                        data.set_start_execution_time();
                        selection_sort(data.get_payload<std::vector<int>>());
                        data.set_end_execution_time();
                    }
                }
            }
        }
    );

    std::cout << "Enter to exit...\n";

    bool exit_code;
    std::cin >> exit_code;


    return 0;
}
