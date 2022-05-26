#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "FilterFactory.h"

class CmdArgs {
public:
    CmdArgs() = default;
    CmdArgs(int argc, char** argv);
    void MakeChain();
    std::string GetInput() const;
    std::string GetOutput() const;
    const std::vector<IFilter*>& GetFilterChain() const ;

private:
    std::string input_file_name_;
    std::string output_file_name_;
    std::vector<IFilter*> filter_chain_;

    std::unordered_map<std::string, std::vector<float>> filters_params_;
    bool is_empty_ = true;
    void Help();
};