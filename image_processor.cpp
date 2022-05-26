#include <iostream>
#include "CmdArgs.h"
#include "Serializer.h"
#include "FilterApplier.h"

int main(int argc, char** argv) {
    CmdArgs args(argc, argv);
    args.MakeChain();
    auto src_image = Serializer::ReadBmp(args.GetInput());
    for (const auto& filter : args.GetFilterChain()) {
        auto image = FilterApplier::Apply(*filter, src_image);
        src_image = image;
    }
    Serializer::WriteBmp(src_image, args.GetOutput());
    return 0;
}
