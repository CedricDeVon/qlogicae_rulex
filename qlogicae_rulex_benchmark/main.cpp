#include "pch.hpp"

#include "main.hpp"

int main(int argc, char** argv)
{
    QLogicaePlotica::RuntimePerformanceBenchmarker& benchmarker =
        QLogicaePlotica::RuntimePerformanceBenchmarker::get_instance();

    benchmarker.execute(
        {
            .title = "Fuzzy Expert System AI",
            .gnuplot_type = QLogicaePlotica::BenchmarkerGraph::BOXPLOT,
            .suspects =
            {
                {
                    .title = "evaluate()",
                    .on_setup = [](QLogicaePlotica::BenchmarkerResultData& data)
                    {
                        std::string items = "";
                        size_t index, size = data.get_input_size();
                        for (index = 0; index < size; ++index)
                        {
                            items += "aaaaaaaaaaaaaaaaaaaa\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\n";
                        }
                        data.set_payload(items);
                    },
                    .on_execution = [](QLogicaePlotica::BenchmarkerResultData& data)
                    {
                        data.set_start_execution_time();
                        QLogicaeRulexCore::FUZZY_EXPERT_SYSTEM_AI.evaluate(
                            {
                                .text = data.get_payload<std::string>()                                
                            }
                        );
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
