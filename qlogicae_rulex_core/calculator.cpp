#include "pch.hpp"

#include "calculator.hpp"

namespace QLogicaeRulexCore
{
    bool Calculator::is_below_bounds(
        const FuzzyExpertSystemAIInputRange& range,
        const double& value
    )
    {
        return (range.minimum > value);
    }

    bool Calculator::is_within_bounds(
        const FuzzyExpertSystemAIInputRange& range,
        const double& value
    )
    {
        return (range.minimum <= value && value <= range.maximum);
    }
    
    bool Calculator::is_above_bounds(
        const FuzzyExpertSystemAIInputRange& range,
        const double& value
    )
    {
        return (range.maximum < value);
    }

    double Calculator::calculate_degree_of_membership(
        const FuzzyExpertSystemAIInputRange& range,
        const double& value
    )
    {
        double range_minimum = range.minimum;
        double range_middle = range.middle;
        double range_maximum = range.maximum;       

        if (value > range_middle)
        {
            return (range_maximum - value) / (range_maximum - range_middle);
        }
        else if (value == range_middle)
        {
            return 1;
        }
        else
        {
            return (value - range_minimum) / (range_middle - range_minimum);
        }
    }

    double Calculator::calculate_defuzzification(
        const FuzzyExpertSystemAIInputRange& range,
        const double& value
    )
    {
        return
            ((range.maximum - range.minimum) / 2) * ((2 * value) - std::pow(value, 2));
    }

    double Calculator::calculate_centroid(
        const std::unordered_map<std::string, FuzzyExpertSystemAIInputRange>& ranges,
        const std::unordered_map<std::string, double>& values
    )
    {
        double centroid_x = 0, centroid_y = 0;
        for (auto& [key, value] : values)
        {
            centroid_x += ranges.at(key).middle * value;
            centroid_y += value;
        }

        return centroid_x / centroid_y;
    }

    Calculator& Calculator::get_instance()
    {
        static Calculator instance;

        return instance;
    }
}
